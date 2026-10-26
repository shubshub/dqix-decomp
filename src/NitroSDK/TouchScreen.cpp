#include "NitroSDK/TouchScreen.h"
#include "NitroSDK/IPC.h"
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/BiosData.h"
#include "NitroSDK/HWRegisters.h"
#include "NitroSDK/Input.h"


struct LinearCoefficients
{
    int offset;
    int scale;
    int invScale;
};

struct
{
    unsigned short unknown_0_;
    char unknown_2_[2];
    TouchScreenCallback unknown_4_;
    // this isn't used anywhere but is written to.
    // maybe other functions used it but were removed by the linker?
    TouchScreenSample unknown_8_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    TouchScreenSample* unknown_14_;
    unsigned short unknown_18_;
    char unknown_1a_[2];
    LinearCoefficients unknown_1c_[2];
    unsigned short unknown_34_;
    // also written to but never read
    unsigned short unknown_36_;
    unsigned short unknown_38_;
    volatile unsigned short unknown_3a_;
} static s_touchData;

extern "C"
{
    // abort() or similar
    void HaltSystem();
}

int ComputeCalibrationCoefficients(TouchScreenCalibration* dst,
    unsigned short inX1, unsigned short inY1, unsigned short outX1, unsigned short outY1,
    unsigned short inX2, unsigned short inY2, unsigned short outX2, unsigned short outY2);

static inline void QueueDivision(unsigned int numerator, unsigned int denominator)
{
    DIVCNT = 0;
    DIV_NUMER_LOW = numerator;
    DIV_DENOM_64 = denominator;
}

static inline unsigned int GetDivisionResult()
{
    while (DIVCNT & 0x8000) {}
    return DIV_RESULT_LOW;
}

static inline void CopyTouchScreenSample(TouchScreenSample* dst, const TouchScreenSample* src)
{
    struct RawFormat { unsigned short x[4]; };
    *(RawFormat*)dst = *(const RawFormat*)src;
}

static inline void GetTouchScreenSampleFromArm7(TouchScreenSample* dst)
{
    union
    {
        struct
        {
            unsigned int unknown_0_0_ : 12;
            unsigned int unknown_1_4_ : 12;
            unsigned int unknown_3_0_ : 1;
            unsigned int unknown_3_1_ : 2;
        };
        unsigned short unknown_0_[2];
    } arm7data;

    arm7data.unknown_0_[0] = ARM7_TOUCHDATAA;
    arm7data.unknown_0_[1] = ARM7_TOUCHDATAB;

    dst->x = arm7data.unknown_0_0_;
    dst->y = arm7data.unknown_1_4_;
    dst->isHeld = (unsigned char)arm7data.unknown_3_0_;
    dst->missingCoordFlags = (unsigned char)arm7data.unknown_3_1_;
}

void TouchScreenIPCCommandReceiveProc(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned short arg2Word = b;
    unsigned short arg2WordUpper = (arg2Word & 0x7f00) >> 8;

    if (c != 0)
    {
        s_touchData.unknown_38_ |= 1 << arg2WordUpper;
        if (s_touchData.unknown_4_ != NULL)
            s_touchData.unknown_4_(arg2WordUpper, 4, 0);
        return;
    }

    if (arg2WordUpper == 16)
    {
        s_touchData.unknown_10_++;
        if (s_touchData.unknown_10_ >= s_touchData.unknown_18_)
            s_touchData.unknown_10_ = 0;

        GetTouchScreenSampleFromArm7(&s_touchData.unknown_14_[s_touchData.unknown_10_]);

        if (s_touchData.unknown_4_ != NULL)
            s_touchData.unknown_4_(arg2WordUpper, 0, s_touchData.unknown_10_);
        return;
    }

    if (!(b & 0x1000000))
        return;

    unsigned short callbackArg2;
    switch (arg2Word & 0xff)
    {
    case 0:
        switch (arg2WordUpper)
        {
        case 0:
            GetTouchScreenSampleFromArm7(&s_touchData.unknown_8_);
            s_touchData.unknown_36_ = 0;
            break;
        case 1:
            s_touchData.unknown_36_ = 2;
            break;
        case 2:
            s_touchData.unknown_36_ = 0;
            break;
        }

        s_touchData.unknown_3a_ &= ~(1 << arg2WordUpper);
        if (s_touchData.unknown_4_ != NULL)
            s_touchData.unknown_4_(arg2WordUpper, 0, 0);
        break;
    case 4:
        callbackArg2 = 3;
        goto common;
    case 2:
        callbackArg2 = 1;
        goto common;
    case 3:
        callbackArg2 = 2;
        goto common;
    common:
        s_touchData.unknown_38_ |= 1 << arg2WordUpper;
        s_touchData.unknown_3a_ &= ~(1 << arg2WordUpper);

        if (s_touchData.unknown_4_ != NULL)
            s_touchData.unknown_4_(arg2WordUpper, callbackArg2, 0);
        break;
    case 1:
    default:
        HaltSystem();
        break;
    }
}

void InitializeTouchSystem()
{
    if (s_touchData.unknown_0_)
        return;

    s_touchData.unknown_0_ = true;
    InitializeInterProcessorCommunication();
    s_touchData.unknown_10_ = 0;
    s_touchData.unknown_4_ = 0;
    s_touchData.unknown_14_ = 0;
    s_touchData.unknown_36_ = 0;
    s_touchData.unknown_34_ = false;
    s_touchData.unknown_3a_ = 0;
    s_touchData.unknown_38_ = 0;

    while (!IsIPCCommandHandlerRegistered(6, IPCSide_Arm7)) {}
    SetArm9IPCCommandHandler(6, TouchScreenIPCCommandReceiveProc);
}

CBool GetTouchScreenCalibration(TouchScreenCalibration* dst)
{
    const FirmwareSettings* settings = &CURRENT_FIRMWARE_SETTINGS;

    unsigned short inX1 = settings->rawCalibrationPointX1;
    unsigned short inY1 = settings->rawCalibrationPointY1;
    unsigned short inX2 = settings->rawCalibrationPointX2;
    unsigned short inY2 = settings->rawCalibrationPointY2;

    unsigned char outX1 = settings->calibrationPixelX1;
    unsigned char outY1 = settings->calibrationPixelY1;
    unsigned char outX2 = settings->calibrationPixelX2;
    unsigned char outY2 = settings->calibrationPixelY2;

    if ((inX1 == 0 && inX2 == 0 && inY1 == 0 && inY2 == 0) ||
        ComputeCalibrationCoefficients(dst, inX1, inY1, outX1, outY1, inX2, inY2, outX2, outY2))
    {
        dst->xOffset = 0;
        dst->yOffset = 0;
        dst->xScale = 0;
        dst->yScale = 0;
        return true;
    }
    return true;
}

void SaveTouchScreenCalibration(TouchScreenCalibration* tsc)
{
    if (tsc == NULL)
    {
        s_touchData.unknown_34_ = false;
        return;
    }

    int priorState = DisableIRQInterrupts();

    if (tsc->xScale != 0)
    {
        QueueDivision(1 << 28, tsc->xScale);
        s_touchData.unknown_1c_[0].offset = tsc->xOffset;
        s_touchData.unknown_1c_[0].scale = tsc->xScale;
        s_touchData.unknown_1c_[0].invScale = GetDivisionResult();
    }
    else
    {
        s_touchData.unknown_1c_[0].offset = 0;
        s_touchData.unknown_1c_[0].scale = 0;
        s_touchData.unknown_1c_[0].invScale = 0;
    }

    if (tsc->yScale != 0)
    {
        QueueDivision(1 << 28, tsc->yScale);
        s_touchData.unknown_1c_[1].offset = tsc->yOffset;
        s_touchData.unknown_1c_[1].scale = tsc->yScale;
        s_touchData.unknown_1c_[1].invScale = GetDivisionResult();
    }
    else
    {
        s_touchData.unknown_1c_[1].offset = 0;
        s_touchData.unknown_1c_[1].scale = 0;
        s_touchData.unknown_1c_[1].invScale = 0;
    }

    SetIRQInterruptState(priorState);
    s_touchData.unknown_34_ = true;
}

void SetTouchScreenCallback(TouchScreenCallback callback)
{
    int priorState = DisableIRQInterrupts();
    s_touchData.unknown_4_ = callback;
    SetIRQInterruptState(priorState);
}

void EnableTouchScreen(int arg1, int arg2, TouchScreenSample* sampleBuffer, int sampleCount)
{
    s_touchData.unknown_14_ = sampleBuffer;
    s_touchData.unknown_10_ = 0;
    s_touchData.unknown_12_ = arg2;
    s_touchData.unknown_18_ = sampleCount;

    for (unsigned int i = 0; i < sampleCount; i++)
        s_touchData.unknown_14_[i].isHeld = false;

    int priorState = DisableIRQInterrupts();

    CBool success;
    if (SendCommandToArm7(6, (arg2 & 0xff) | 0x02000100, false) < 0)
        success = false;
    else if (SendCommandToArm7(6, arg1 | 0x01010000, false) < 0)
        success = false;
    else
        success = true;
   
    if (!(unsigned char)success)
    {
        SetIRQInterruptState(priorState);
        s_touchData.unknown_38_ |= 2;
        if (s_touchData.unknown_4_ != NULL)
            s_touchData.unknown_4_(1, 4, 0);
        return;
    }

    s_touchData.unknown_3a_ |= 2;
    s_touchData.unknown_38_ &= ~2;
    SetIRQInterruptState(priorState);
}

void DisableTouchScreen()
{
    int priorState = DisableIRQInterrupts();

    CBool success;
    if (SendCommandToArm7(6, 0x03000200, false) >= 0)
        success = true;
    else
        success = false;

    if (!success)
    {
        SetIRQInterruptState(priorState);
        s_touchData.unknown_38_ |= 4;
        if (s_touchData.unknown_4_ != NULL)
            s_touchData.unknown_4_(2, 4, 0);
        return;
    }

    s_touchData.unknown_3a_ |= 4;
    s_touchData.unknown_38_ &= ~4;
    SetIRQInterruptState(priorState);
}

void GetTouchScreenData(TouchScreenSample* output)
{
    int i;
    
    output->missingCoordFlags = 3;
    int current = s_touchData.unknown_10_;
    if (s_touchData.unknown_12_ == 1 || s_touchData.unknown_18_ == 1)
    {
        CopyTouchScreenSample(output, &s_touchData.unknown_14_[current]);
        return;
    }

    for (i = 0; i < s_touchData.unknown_12_ && i < s_touchData.unknown_18_ - 1; i++)
    {
        int sourceIndex = current - i;
        if (sourceIndex < 0)
            sourceIndex += s_touchData.unknown_18_;
        
        TouchScreenSample* entry = &s_touchData.unknown_14_[sourceIndex];
        if (!entry->isHeld)
        {
            CopyTouchScreenSample(output, entry);
            return;
        }

        if ((output->missingCoordFlags & TOUCH_SCREEN_SAMPLE_MISSING_X) &&
            !(entry->missingCoordFlags & TOUCH_SCREEN_SAMPLE_MISSING_X))
        {
            output->x = entry->x;
            if (i != 0)
                output->missingCoordFlags &= ~TOUCH_SCREEN_SAMPLE_MISSING_X;
        }

        if ((output->missingCoordFlags & TOUCH_SCREEN_SAMPLE_MISSING_Y) &&
            !(entry->missingCoordFlags & TOUCH_SCREEN_SAMPLE_MISSING_Y))
        {
            output->y = entry->y;
            if (i != 0)
                output->missingCoordFlags &= ~TOUCH_SCREEN_SAMPLE_MISSING_Y;
        }

        if (output->missingCoordFlags == 0)
        {
            output->isHeld = true;
            return;
        }
    }
    output->isHeld = true;
}

void GetTouchScreenDataAsPixels(TouchScreenSample* output)
{
    GetTouchScreenData(output);
    ConvertTouchScreenSampleToPixels(output, output);
}

unsigned short GetCurrentTouchScreenSampleIndex()
{
    return s_touchData.unknown_10_;
}

int ComputeCalibrationCoefficients(TouchScreenCalibration* dst,
    unsigned short inX1, unsigned short inY1, unsigned short outX1, unsigned short outY1,
    unsigned short inX2, unsigned short inY2, unsigned short outX2, unsigned short outY2)
{
    if (inX1 >= 0x1000 || inY1 >= 0x1000 || inX2 >= 0x1000 || inY2 >= 0x1000)
        return 1;
    
    if (outX1 >= 256 || outX2 >= 256 || outY1 >= 192 || outY2 >= 192)
        return 1;
    
    if (outX1 == outX2 || outY1 == outY2 || inX1 == inX2 || inY1 == inY2)
        return 1;

    int rawWidth = inX1 - inX2;
    int width = outX1 - outX2;

    int priorState = DisableIRQInterrupts();

    QueueDivision(rawWidth << 8, width);

    int inDeltaY = inY1 - inY2;
    int outDeltaY = outY1 - outY2;

    int ratio = GetDivisionResult();
    QueueDivision(inDeltaY << 8, outDeltaY);

    if (ratio >= 0x8000 || ratio < -0x8000)
    {
        SetIRQInterruptState(priorState);
        return 1;
    }
    dst->xScale = ratio;

    int offset = (short)((((inX1 + inX2) << 8) - ((outX1 + outX2) * dst->xScale)) >> 7);
    if (offset >= 0x8000 || offset < -0x8000)
    {
        SetIRQInterruptState(priorState);
        return 1;
    }
    dst->xOffset = offset;

    ratio = GetDivisionResult();
    SetIRQInterruptState(priorState);

    if (ratio >= 0x8000 || ratio < -0x8000)
        return 1;
    dst->yScale = ratio;

    ratio = (short)((((inY1 + inY2) << 8) - ((outY1 + outY2) * dst->yScale)) >> 7);
    if (ratio >= 0x8000 || ratio < -0x8000)
        return 1;
    
    dst->yOffset = ratio;

    return 0;
}

void ConvertTouchScreenSampleToPixels(TouchScreenSample* dst, const TouchScreenSample* src)
{
    if (!s_touchData.unknown_34_)
    {
        CopyTouchScreenSample(dst, src);
        return;
    }

    LinearCoefficients* coeffs = s_touchData.unknown_1c_;
    dst->isHeld = src->isHeld;
    dst->missingCoordFlags = src->missingCoordFlags;

    if (!src->isHeld)
    {
        dst->x = 0;
        dst->y = 0;
        return;
    }

    dst->x = (((long long)(src->x * 4) - coeffs[0].offset) * coeffs[0].invScale) >> 22;
    if ((short)dst->x < 0)
        dst->x = 0;
    else if ((short)dst->x > 255)
        dst->x = 255;

    dst->y = (((long long)(src->y * 4) - coeffs[1].offset) * coeffs[1].invScale) >> 22;
    if ((short)dst->y < 0)
        dst->y = 0;
    else if ((short)dst->y > 191)
        dst->y = 191;
}

void WaitForTouchScreenOperations(int mask)
{
    while (s_touchData.unknown_3a_ & mask) {}
}

int GetTouchScreenErrors(int mask)
{
    return s_touchData.unknown_38_ & mask;
}