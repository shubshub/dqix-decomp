#include "Input/Input.h"
#include "NitroSDK/Input.h"
#include "Resource/Brightness.h"
#include <std_library_functions.h>

unsigned short ComputeCurrentKeys();

#if defined(jpn)

#define data_020fb3cc data_020fb0f8
#endif

extern "C"
{
    // calculates a square root, but not sure if this is libc sqrt?
    // could it be a compiler intrinsic (it's between other compiler intrinsics)?
    double sqrt(double);

    void* Scenario_GetInstance();
    // set flag in some big flag mask
    void Scenario_SetFlag(void*, void*, int, bool);
    // get signed brightness
    int GXx_GetMasterBrightness_(volatile unsigned short*);

    // abort() or similar
    void HaltSystem();
}

extern TouchInput* data_020fb3cc;

// Every key bit the game reads: KEY_A..KEY_Y (REG_KEYINPUT's ten, ARM7_KEYINDATA's X and Y) and ARM7_KEYINDATA's 0x2000
// (EXTKEYIN bit 3 shifted up 10, set while idle like X and Y: 0x2c00). The hardware bits are active low.
#define ALL_KEYS_MASK (KEY_A | KEY_B | KEY_SELECT | KEY_START | KEY_DPAD | KEY_R | KEY_L | KEY_X | KEY_Y | 0x2000)

// |main| + |sub| master brightness reaches this only when both screens are fully faded (Brightness_White or
// Brightness_Black each); input is ignored and the touch screen paused while it is
enum { kBothScreensFadedBrightness = 2 * Brightness_White };

enum {
    kKeyRepeatDelay = 8,        // frames from a key press to its first repeat (KeyManager::TestKeyRepeat); then every frame
    kTouchRepeatDelay = 12,     // frames from a touch to its first repeat (TouchInput::TestTouchRepeat)
    kTouchRepeatInterval = 2,   // frames between the touch repeats after that
};

// The touch screen commands the ARM7 reports back on (TouchScreenIPCCommandReceiveProc passes them to the callback;
// an operation in progress is bit 1 << command of WaitForTouchScreenOperations' mask)
enum {
    TouchCommand_Enable = 1,        // EnableTouchScreen: auto-sampling on
    TouchCommand_Disable = 2,       // DisableTouchScreen: auto-sampling off
    TouchCommand_AutoSample = 16,   // a new auto-sample landed in the sample buffer
};

// IsTouchPointAtEdge: within this many pixels of the 256x192 screen's border
enum { kScreenWidth = 256, kScreenHeight = 192, kTouchEdgeMargin = 2 };

void KeyManager::Initialize()
{
    unknown_4_ = 1;
    unknown_6_ = 2;
    unknown_8_ = 3;
    unknown_a_ = 4;
    unknown_c_ = 5;
    unknown_e_ = 6;
    unknown_10_ = 7;
    unknown_12_ = 0;
    unknown_14_ = 1000;
    receivingInput_ = true;
    keyRepeatCountdown_ = 0;
}

KeyManager::KeyManager()
{
}

void KeyManager::RefreshKeys()
{
    bool ignoreInput = false;
    int subBrightness, mainBrightness;

    if (!receivingInput_ || IsLidDown())
        goto do_ignore;

    subBrightness = GXx_GetMasterBrightness_(&REG_MASTER_BRIGHT_SUB);
    mainBrightness = GXx_GetMasterBrightness_(&REG_MASTER_BRIGHT);
    if (abs(mainBrightness) + abs(subBrightness) < kBothScreensFadedBrightness)
        goto dont_ignore;

do_ignore:
    ignoreInput = true;
dont_ignore:
    if (ignoreInput)
    {
        previousKeys_ = 0;
        currentKeys_ = 0;
    }
    else
    {
        previousKeys_ = currentKeys_;
        currentKeys_ = ComputeCurrentKeys();
        if (currentKeys_ != 0)
        {
            void* flagManager = Scenario_GetInstance();
            Scenario_SetFlag(flagManager, (unsigned char*)flagManager + 0x8c, 0x113e, true);
        }
    }
}

unsigned short ComputeCurrentKeys()
{
    return ((REG_KEYINPUT | ARM7_KEYINDATA) ^ ALL_KEYS_MASK) & ALL_KEYS_MASK;
}

KeyManager::~KeyManager()
{
}

bool KeyManager::IsLeftHeld() const 
{
    return currentKeys_ & KEY_LEFT;
}

bool KeyManager::IsRightHeld() const
{
    return currentKeys_ & KEY_RIGHT;
}

bool KeyManager::IsUpHeld() const   
{
    return currentKeys_ & KEY_UP;
}

bool KeyManager::IsDownHeld() const 
{
    return currentKeys_ & KEY_DOWN;
}

bool KeyManager::IsAHeld() const
{
    return currentKeys_ & KEY_A;
}

bool KeyManager::IsBHeld() const
{
    return currentKeys_ & KEY_B;
}

bool KeyManager::IsXHeld() const
{
    return currentKeys_ & KEY_X;
}

bool KeyManager::IsYHeld() const
{
    return currentKeys_ & KEY_Y;
}

bool KeyManager::TestKeysHeld(unsigned short mask) const
{
    if (currentKeys_ & mask)
        return true;
    return false;
}

bool KeyManager::TestKeysPressed(unsigned short mask) const
{
    if ((currentKeys_ & mask) && !(previousKeys_ & mask))
        return true;
    return false;
}

bool KeyManager::TestKeysReleased(unsigned short mask) const
{
    if (!(currentKeys_ & mask) && (previousKeys_ & mask))
        return true;
    return false;
}

bool KeyManager::TestKeyRepeat(unsigned short mask)
{
    if (TestKeysHeld(mask))
    {
        unsigned int countdown = keyRepeatCountdown_;
        if (countdown == 0)
        {
            if (TestKeysPressed(mask))
            {
                keyRepeatCountdown_ = kKeyRepeatDelay;
                return true;
            }
            else
            {
                keyRepeatCountdown_ = 0;
                return true;
            }
        }
        keyRepeatCountdown_ = countdown - 1;
    }
    else if (!TestKeysHeld(~KEY_START))
    {
        keyRepeatCountdown_ = 0;
    }
    return false;
}

void KeyManager::CancelCurrentKeyRepeat()
{
    keyRepeatCountdown_ = -1;
}

void KeyManager::Clear()
{
    currentKeys_ = previousKeys_ = 0;
}

void KeyManager::SetInputEnabled(bool enabled)
{
    receivingInput_ = enabled;
}

void TouchInputMessageHandler(int command, unsigned char result, unsigned char sampleIndex);

TouchInput::TouchInput()
{
}

TouchInput::~TouchInput()
{
}

bool TouchInput::RefreshState()
{
    if (!enabled_)
    {
        InternalClearCurrentInput();
        return false;
    }

    int subBrightness = GXx_GetMasterBrightness_(&REG_MASTER_BRIGHT_SUB);
    int mainBrightness = GXx_GetMasterBrightness_(&REG_MASTER_BRIGHT);

    if (abs(mainBrightness) + abs(subBrightness) >= kBothScreensFadedBrightness)
        Pause();
    else if (paused_)
        Unpause();

    if (IsLidDown())
        return false;

    if (currentReading_.isHeld) // check the stale reading
    {
        pressed_ = false;
        prevX_ = currentReading_.x;
        prevY_ = currentReading_.y;
        if (!UpdateCurrentReading())
            return false;
        heldLastFrame_ = heldThisFrame_;
        if (!currentReading_.isHeld)
        {
            released_ = true;
            heldThisFrame_ = false;
        }
        else
            heldThisFrame_ = true;
        ComputeMoveFlags();
        repeatFired_ = TestTouchRepeat();
        return currentReading_.isHeld;
    }
    else
    {
        prevX_ = currentReading_.x;
        prevY_ = currentReading_.y;
        heldLastFrame_ = heldThisFrame_;
        heldThisFrame_ = true;
        released_ = false;
        if (!UpdateCurrentReading())
            return false;
        ComputeMoveFlags();
        if (currentReading_.isHeld)
        {
            pressed_ = true;
            if (savedPressX_ >= 0 || savedPressY_ >= 0)
            {
                pressX_ = savedPressX_;
                pressY_ = savedPressY_;
            }
            else
                GetTouchPoint(&pressX_, &pressY_);
            heldThisFrame_ = true;
        }
        else
        {
            prevX_ = currentReading_.x;
            prevY_ = currentReading_.y;
            heldThisFrame_ = false;
        }

        if (!isSavedPressPointValid_)
            savedPressX_ = savedPressY_ = -1;
        savedIsRepeatValid_ = false;
        repeatFired_ = TestTouchRepeat();
        return currentReading_.isHeld;
    }
}

bool TouchInput::TestPressInRectangle(int x, int y, int w, int h) const
{
    int pointX = pressX_;
    int pointY = pressY_;
    if (pointX < x)
        return false;
    if (pointX > x + w)
        return false;
    if (pointY < y)
        return false;
    if (pointY > y + h)
        return false;
    return true;
}

bool TouchInput::TestHoldInRectangle(int x, int y, int w, int h) const
{
    unsigned short pointX = currentReading_.x;
    unsigned short pointY = currentReading_.y;
    if (pointX < x)
        return false;
    if (pointX > x + w)
        return false;
    if (pointY < y)
        return false;
    if (pointY > y + h)
        return false;
    return true;
}

void TouchInput::ClearMoveFlags()
{
    movedDown_ = false;
    movedRight_ = false;
    movedLeft_ = false;
    movedUp_ = false;
}

int TouchInput::GetMovementLength() const
{
    int dx = prevX_ - currentReading_.x;
    int dy = prevY_ - currentReading_.y;
    return sqrt(dx * dx + dy * dy);
}

void TouchInput::ComputeMoveFlags() 
{
    ClearMoveFlags();
    if (prevX_ < currentReading_.x)
        movedRight_ = true;
    if (prevX_ > currentReading_.x)
        movedLeft_ = true;
    if (prevY_ < currentReading_.y)
        movedDown_ = true;
    if (prevY_ > currentReading_.y)
        movedUp_ = true;
}

void TouchInput::Initialize()
{
    data_020fb3cc = this;
    InternalClearCurrentInput();
    enabled_ = true;
    InitializeTouchSystem();
    if (!GetTouchScreenCalibration(&calibration_))
        HaltSystem();

    SaveTouchScreenCalibration(&calibration_);
    Unpause();
    paused_ = 0;
    savedTimeHeld_ = 0;
    savedPressX_ = -1;
    savedPressY_ = -1;
    isSavedPressPointValid_ = false;
    pressX_ = -1;
    pressY_ = -1;
}

void TouchInput::InternalClearCurrentInput()
{
    pressX_ = pressY_ = -1;
    ClearMoveFlags();
    timeSinceLastTouch_ = 0;
    timeHeld_ = 0;
    prevTimeHeld_ = 0;
    resetStillTimerOnMove_ = false;
    repeatTimer_ = 0;
    heldThisFrame_ = false;
    isRepeatValid_ = false;
}

void TouchInput::Pause()
{
    savedIsRepeatValid_ = isRepeatValid_;
    savedTimeHeld_ = timeHeld_;
    if (pressX_ >= 0)
        savedPressX_ = pressX_;
    if (pressY_ >= 0)
        savedPressY_ = pressY_;
    DisableTouchScreen();
    WaitForTouchScreenOperations(1 << TouchCommand_Disable);
    (void)GetTouchScreenErrors(1 << TouchCommand_Disable);
    SetTouchScreenCallback(NULL);
    InternalClearCurrentInput();
    paused_ = true;
}

void TouchInput::Unpause()
{
    SetTouchScreenCallback(&TouchInputMessageHandler);
    isSavedPressPointValid_ = true;
    InternalClearCurrentInput();
    EnableTouchScreen(0, 1, sampleBuffer_, sizeof(sampleBuffer_) / sizeof(sampleBuffer_[0]));
    WaitForTouchScreenOperations(1 << TouchCommand_Enable);
    (void)GetTouchScreenErrors(1 << TouchCommand_Enable);
    paused_ = false;
    isRepeatValid_ = savedIsRepeatValid_;
    timeHeld_ = savedTimeHeld_;

    if (savedPressX_ >= 0)
        pressX_ = savedPressX_;
    if (savedPressY_ >= 0)
        pressY_ = savedPressY_;
}

bool TouchInput::UpdateCurrentReading()
{
    GetTouchScreenDataAsPixels(&currentReading_);
    if (!isRepeatValid_)
    {
        if (currentReading_.isHeld)
            return false;
        isRepeatValid_ = true;
    }

    if (currentReading_.isHeld && currentReading_.missingCoordFlags == 0)
    {
        timeHeld_++;
        timeSinceLastTouch_ = 0;
        if (resetStillTimerOnMove_ && GetMovementLength() > 1)
            timeHeldStill_ = 0;
        else if (GetMovementLength() < 1)
            timeHeldStill_++;
    }
    else
    {
        currentReading_.isHeld = false;
        if (timeHeld_ != 0)
            prevTimeHeld_ = timeHeld_;
        timeHeld_ = 0;
        timeSinceLastTouch_++;
    }

    return true;
}

void TouchInput::GetTouchPoint(int* outX, int* outY) const 
{
    if (currentReading_.isHeld)
    {
        *outX = currentReading_.x;
        *outY = currentReading_.y;
    }
    else
    {
        *outX = prevX_;
        *outY = prevY_;
    }
}

bool TouchInput::IsPressed() const
{
    if (heldThisFrame_ && !heldLastFrame_)
        return true;
    return false;
}

bool TouchInput::TestTouchRepeat()
{
    bool validHold = false;
    if (isRepeatValid_ && currentReading_.isHeld)
        validHold = true;

    if (validHold)
    {
        if (repeatTimer_ == 0)
        {
            if (IsPressed())
            {
                repeatTimer_ = kTouchRepeatDelay;
                return true;
            }
            else
            {
                repeatTimer_ = kTouchRepeatInterval;
                return true;
            }
        }
        repeatTimer_--;
    }
    else if (!isRepeatValid_ || !currentReading_.isHeld)
        repeatTimer_ = 0;

    return false;
}

bool TouchInput::IsTouchPointAtEdge() const
{
    int x, y;
    GetTouchPoint(&x, &y);
    if (x < kTouchEdgeMargin)
        return true;
    if (x > kScreenWidth - 1 - kTouchEdgeMargin)
        return true;
    if (y < kTouchEdgeMargin)
        return true;
    if (y > kScreenHeight - 1 - kTouchEdgeMargin)
        return true;
    return false;
}

void TouchInput::SetInputEnabled(bool enabled)
{
    enabled_ = enabled;
}

void TouchInput::ClearCurrentInput()
{
    InternalClearCurrentInput();
}

void TouchInputMessageHandler(int command, unsigned char result, unsigned char sampleIndex)
{
    if (command == TouchCommand_AutoSample)
    {
        data_020fb3cc->isSavedPressPointValid_ = false;
    }
}