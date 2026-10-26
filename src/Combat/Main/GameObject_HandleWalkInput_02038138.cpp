#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Matrix.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#define data_020e780c data_020e8150
#else
#define RG(usa, jpn) (usa)
#endif

struct Vec3 { int x; int y; int z; };
struct Bytes02033b88;
struct Obj02033b68;
struct Foo02033b58;
struct Obj02033834;
struct Container0201e8fc;
struct ShortField0x22e_020968c4;

struct Box0201e8fc {
    char pad0[0x18];
    short angle;
};

// What GameResources_GetTouchWalk returns: the touch-screen walking state (GameObject_UpdateLadderClimb reads the drag's start and end
// at +0x220..+0x223; TouchWalk_GetHeading gives the drag's heading)
struct Field4328 {
    char unknown0[0x224];
    unsigned char active;
    unsigned char enabled;
};

// A party member: Object3D's position_, the motion state GameObject_SetMotionState keeps, and the party member
// fields GameObject_InitPartyMember initialises
struct Actor02038138 {
    char unknown0[0x44];
    struct Vec3 position;
    char unknown50[0xbe - 0x50];
    unsigned char motionState;          // 0 standing, 1 walking (GameObject_SetMotionState)
    char previousMotionState;
    unsigned char unknownC0;
    char unknownC1[RG(0x250, 0x244) - 0xc1];
    unsigned char walkDirection;        // a WalkDirection while held, minus 8 once released
    char unknown251;
    unsigned char controlEnabled;       // GameObject_DisableControl clears it
    char controlPending;
    char unknown254;
    signed char lockedDirection;        // the direction held when a heading-lock area took over, -1 for none
    short lockedAngle;                  // the area's angle (or that + pi) it locked to
};

// What each held direction sets walkDirection to; data_020e780c[direction - 8] is its angle from the camera's yaw
// (ROM: up pi, down 0, left 3pi/2, right pi/2, up-left 5pi/4, up-right 3pi/4, down-left 7pi/4, down-right pi/4)
enum WalkDirection {
    WalkDirection_Up = 8, WalkDirection_Down = 9, WalkDirection_Left = 10, WalkDirection_Right = 11,
    WalkDirection_UpLeft = 12, WalkDirection_UpRight = 13, WalkDirection_DownLeft = 14, WalkDirection_DownRight = 15,
};

// What moves the actor this frame
enum WalkInput { WalkInput_None = 0, WalkInput_DPad = 1, WalkInput_Touch = 2 };

enum {
    MotionState_Standing = 0,
    MotionState_Walking = 1,
    TouchHoldFrames = 5,                // the stylus must be held this long before it walks
    TouchDeadZone = 0x8000,             // 8 pixels between press point and current point
    HeadingLockTolerance = 0xc91,       // pi/4
    HalfTurn = 0x3244,                  // pi
};

extern "C" char* Zone3D_GetInstance();
struct Field4328* GameResources_GetTouchWalk(void*);
void GameObject_ForceMotionState(struct Bytes02033b88*, int);
void GameObject_SetMotionState(struct Obj02033b68*, int);
void GameObject_StoreMotionState(struct Foo02033b58*, unsigned char);
int Camera_GetOrbitYaw(void*);
int fix32ReduceAngle0To2Pi(int);
struct Box0201e8fc* ZoneFeatures_FindHeadingLockArea(struct Container0201e8fc*, struct Vec3*);
int fix32SignedAngleDistance(int, int);
int fix32abs(int);
void GameObject_SetFacing(struct Obj02033834*, int);
short TouchWalk_GetHeading(struct ShortField0x22e_020968c4*);

extern int data_020e780c[8];

// Main, originally func_02038138 (USA 0x02038138, EUR 0x02038148, JPN 0x02037b90)
extern "C" ARM void GameObject_HandleWalkInput(struct Actor02038138* self) {
    char* zone;
    void* camera;
    GameResources* resources;
    int input;
    camera = GameState::GetInstance()->GetCamera();
    resources = GetGameResources();
    zone = Zone3D_GetInstance();
    input = WalkInput_None;

    if (g_keyManager.IsUpHeld() && g_keyManager.IsLeftHeld()) {
        self->walkDirection = WalkDirection_UpLeft;
        input = WalkInput_DPad;
    } else if (g_keyManager.IsUpHeld() && g_keyManager.IsRightHeld()) {
        self->walkDirection = WalkDirection_UpRight;
        input = WalkInput_DPad;
    } else if (g_keyManager.IsDownHeld() && g_keyManager.IsLeftHeld()) {
        self->walkDirection = WalkDirection_DownLeft;
        input = WalkInput_DPad;
    } else if (g_keyManager.IsDownHeld() && g_keyManager.IsRightHeld()) {
        self->walkDirection = WalkDirection_DownRight;
        input = WalkInput_DPad;
    } else if (g_keyManager.IsUpHeld()) {
        self->walkDirection = WalkDirection_Up;
        input = WalkInput_DPad;
    } else if (g_keyManager.IsDownHeld()) {
        self->walkDirection = WalkDirection_Down;
        input = WalkInput_DPad;
    } else if (g_keyManager.IsLeftHeld()) {
        self->walkDirection = WalkDirection_Left;
        input = WalkInput_DPad;
    } else if (g_keyManager.IsRightHeld()) {
        self->walkDirection = WalkDirection_Right;
        input = WalkInput_DPad;
    }

    struct Field4328* touchWalk = GameResources_GetTouchWalk(resources);
    if (g_touchInput.timeHeld_ >= TouchHoldFrames && touchWalk->enabled != 0 && touchWalk->active != 0) {
        input = WalkInput_Touch;
        int x;
        int y;
        g_touchInput.GetTouchPoint(&x, &y);
        Vector3fix touchPoint;
        Vector3fix pressPoint;
        touchPoint.x = x << 12;
        touchPoint.y = y << 12;
        touchPoint.z = 0;
        x = g_touchInput.pressX_;
        y = g_touchInput.pressY_;
        pressPoint.x = x << 12;
        pressPoint.y = y << 12;
        pressPoint.z = 0;
        if (Vector3fix_Distance(&touchPoint, &pressPoint) < TouchDeadZone) {
            input = WalkInput_None;
        }
    }

    if (self->controlEnabled == 0 || IsMainBrightnessTransitionActive(resources) != 0) {
        input = WalkInput_None;
    }

    if (input == WalkInput_None) {
        if (self->walkDirection >= WalkDirection_Up) {
            self->walkDirection -= 8;
        }
        if (self->controlEnabled != 0 && self->motionState == MotionState_Walking) {
            GameObject_ForceMotionState((struct Bytes02033b88*)self, MotionState_Standing);
        }
        self->lockedDirection = -1;
    } else if (input == WalkInput_DPad) {
        if (self->unknownC0 == 0 || self->unknownC0 == 0xa) {
            GameObject_SetMotionState((struct Obj02033b68*)self, MotionState_Walking);
        } else {
            GameObject_StoreMotionState((struct Foo02033b58*)self, MotionState_Walking);
        }
        int directionAngle = data_020e780c[self->walkDirection - WalkDirection_Up];
        int angle = fix32ReduceAngle0To2Pi(directionAngle + Camera_GetOrbitYaw(camera));
        if (self->lockedDirection == self->walkDirection) {
            angle = self->lockedAngle;
        } else {
            struct Box0201e8fc* lockArea = ZoneFeatures_FindHeadingLockArea((struct Container0201e8fc*)(zone + RG(0x6c, 0x8c)), &self->position);
            if (lockArea) {
                if (fix32abs(fix32SignedAngleDistance(angle, lockArea->angle)) < HeadingLockTolerance) {
                    self->lockedDirection = self->walkDirection;
                    self->lockedAngle = lockArea->angle;
                } else {
                    short flipped = fix32ReduceAngle0To2Pi(lockArea->angle + HalfTurn);
                    if (fix32abs(fix32SignedAngleDistance(angle, flipped)) < HeadingLockTolerance) {
                        self->lockedDirection = self->walkDirection;
                        self->lockedAngle = flipped;
                        angle = self->lockedAngle;
                    }
                }
            } else {
                self->lockedDirection = -1;
            }
        }
        GameObject_SetFacing((struct Obj02033834*)self, angle);
    } else if (input == WalkInput_Touch) {
        if (self->unknownC0 == 0) {
            GameObject_SetMotionState((struct Obj02033b68*)self, MotionState_Walking);
        } else {
            GameObject_StoreMotionState((struct Foo02033b58*)self, MotionState_Walking);
        }
        if (touchWalk->active != 0) {
            GameObject_SetFacing((struct Obj02033834*)self, TouchWalk_GetHeading((struct ShortField0x22e_020968c4*)touchWalk));
        }
        self->lockedDirection = -1;
    }
}
