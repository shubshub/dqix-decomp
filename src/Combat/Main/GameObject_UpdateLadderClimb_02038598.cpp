#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/ActorAction.h"
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "World/ZoneObjectResourceLoading.h"
#include "World/Zone3D.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Memory.h"
#include "World/FieldTask.h"

// The ladder animations (ROM strings): data_020efb44 "hasigo_in", data_020efb4e "hasigo_loop",
// data_020efb5a "hasigo_out"
#if defined(jpn)
#define data_020efb44 data_020efa34
#define data_020efb4e data_020efa3e
#define data_020efb5a data_020efa4a
#endif

static inline fix32_t FX_MulInline(fix32_t v1, fix32_t v2) {
    return ((long long)v1 * v2 + 0x800LL) >> 12;
}

// The party member climbing: only the line's leader runs the climb (the others follow it, GameObject_UpdateFollower)
struct LadderClimber {
    GameObject object;
#if defined(jpn)
    char unknown_13c_[0x1be - 0x13c];
#else
    char unknown1_13c_[0x1ca - 0x13c];
#endif
    signed char lineLeader;         // +0x1ca: the walking line leader's index (GameObject_SetLineLeader)
    char unknown_1cb_[0x252 - 0x1cb];
    unsigned char controlEnabled;   // GameObject_DisableControl clears both
    unsigned char controlPending;
    char unknown254[0x26c - 0x254];
    SubBlock02038508 ladderClimb;
};
// GameObject +0xac on: the facing and speeds GameObject_Update's GameObjectFields names, then the +0xe0 flags
struct GameObjectMotion {
    char unknownAc[2];
    short facing;
    short turnSpeed;
    short speed;
    short maximumSpeed;
    char unknownB6[0xe0 - 0xb6];
    ActorActionFlags flagsE0;       // active: set while it climbs (also by GameObject_PlaceInZone)
};
// GameState's zone transition settings (the layout FieldTask_ShipPrompt's ZoneTransitionSettings names): a ladder
// that leads to another zone leaves the destination ladder node and the height on it for GameObject_PlaceInZone
struct ZoneTransitionSettings {
    unsigned short zoneId;
    char unknown2[2];
    unsigned char unknown4;
    char unknown5[2];
    unsigned char applyPosition;
    unsigned char unknown8;
    unsigned char unknown9;
    char unknownA;
    signed char unknownB;
    unsigned char unknownC;
    char unknownD[3];
    Vector3fix position;
    short heading;
    short unknown1E;
    int unknown20[4];
    Vector3fix start;               // the four ladder points, as SubBlock02038508 has them
    Vector3fix end;
    Vector3fix startControl;
    Vector3fix endControl;
    char unknown60[0xa];
    short ladderHeight;             // fx32 fraction of the way up (GameObject_PlaceInZone)
    short ladderNodeId;             // the node to put the climber on; 9999 for none, negative to stand
    char unknown_6e_[2];
};
// What GameResources_GetTouchWalk returns: the touch-screen walking state (GameObject_HandleWalkInput reads +0x224/+0x225)
struct ActorTouch02038598 {
    char unknown0[0x220];
    unsigned char startX;
    unsigned char startY;
    unsigned char endX;
    unsigned char endY;
};
struct Vec3038500;
struct Obj02033834;
struct Obj02033874;
struct Obj020397cc;
struct Bytes02033b88;
struct Foo02033b58;
struct ShortField02033ec8;
struct FlagWord020466f4 { unsigned int flags; };
struct ListHead02046b60;
struct TailList020469b4;
struct TailNode020469b4;
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void Party_ReformLine(void*, int, int, int, int);
extern "C" void* GlobalFlags_GetInstance();
extern "C" void GameObject_SetFacing(Obj02033834*, int);
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" int GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void GameObject_StoreMotionState(Foo02033b58*, unsigned char);
extern "C" int GameObject_IsGlideDone(ShortField02033ec8*);
extern "C" void func_02038500(Vec3038500*, int, int, int);
extern "C" void GameObject_StartGlide(void*, int*, short);
extern "C" int GameResources_GetTouchWalk(void*);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" int func_02046b60(ListHead02046b60*, int);
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
extern "C" void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" void FieldTask_InitEnterZone(unsigned char*, int);
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);
extern const char data_020efb44[];
extern const char data_020efb4e[];
extern const char data_020efb5a[];

// USA: GameObject_UpdateLadderClimb
// The climb's steps (SubBlock02038508::command)
enum LadderStep {
    LadderStep_Approach = 0,        // face the ladder; once facing it, start "hasigo_in"
    LadderStep_GetOn = 1,           // move onto the bottom (or top) point while "hasigo_in" plays
    LadderStep_Climb = 2,           // "hasigo_loop": up/down from the D-pad or a vertical drag
    LadderStep_GetOffTop = 4,       // "hasigo_out" at the top
    LadderStep_StepOff = 5,         // glide to the control point, then give control back
    LadderStep_ChangeZone = 6,      // the end node leads to another zone
};

// Which way the climber moves this frame (also passed to LinkMessageQueue_SendLadderClimb and kept in unknown54)
enum ClimbDirection { ClimbDirection_None = 0, ClimbDirection_Down = 1, ClimbDirection_Up = 2 };

enum {
    LadderStepHeight = 0xf5,                // how far one frame of climbing moves (fx32)
    ClimbTouchDeadZone = 0x8000,            // 8 pixels of drag
    ClimbTouchVertical = 1638,              // 0.4: a drag whose normalised x is within this counts as vertical
    Object3DFlag_PauseAnimation = 0x1000,   // flags_ bit 12: AdvanceAnimations_v0/_v1 do nothing while set
    LadderNodeFlag_LeadsToZone = 2,         // the node's type9.unk_5 bit: reaching it changes zone
    LadderNodeFlag_HasLadderTarget = 4,     // type9.unk_5: unk_42/unk_40 give the destination ladder node and height
    LadderNodeId_None = 9999,
};

// Main, originally func_02038598 (USA 0x02038598, EUR 0x020385a8, JPN 0x02037ff0)
extern "C" ARM void GameObject_UpdateLadderClimb(LadderClimber* self) {
    GameResources* resources;
    Zone3D* zone;
    GameObjectMotion* motion;
    struct SubBlock02038508* climb;
    unsigned int* inputFlags;
    unsigned char direction;
    ListHead02046b60* list;
    resources = GetGameResources();
    list = (ListHead02046b60*)resources->fieldTaskQueue_;
    zone = Zone3D_GetInstance();
    motion = (GameObjectMotion*)self->object.unk_ac;
    climb = &self->ladderClimb;
    inputFlags = (unsigned int*)GlobalFlags_GetInstance();

    if (self->object.obj3D_.actorIndex_ != self->lineLeader) return;
    if (climb->active == 0) return;

    unsigned char step = climb->command;

    if (step == LadderStep_Approach) {
        ZoneFeatures::Opcode6aEntry* node = (climb->reversed == 0) ? climb->startNode : climb->endNode;
        Vector3fix direction;
        Vector3fix_Subtract(&node->unk_8.vec, &self->object.obj3D_.position_, &direction);
        Vector3fix_Normalize(&direction, &direction);
        int angle = fix32ReduceAngle0To2Pi(fix32_Atan2(direction.x, direction.z));
        GameObject_SetFacing((struct Obj02033834*)self, angle);
        GameObject_DisableControl((struct Obj020397cc*)self, 1);
        motion->flagsE0.active = 1;
        self->object.obj3D_.EnableFlag(0x180);
        GameObject_ForceMotionState((struct Bytes02033b88*)self, 0);
        climb->unknown4c = climb->startNode->unk_8.vec.y;
        climb->unknown50 = zone->substruct_c_.unknown_30_;
        if (fix32abs(motion->facing) - angle >= 0x333) goto Exit;
        LinkMessageQueue_SendLadderClimb(climb, 0, 0);
        climb->command = LadderStep_GetOn;
        climb->unknown24.vec = self->object.obj3D_.position_;
        if (climb->reversed == 0) {
            self->object.obj3D_.SetAnimationByName(data_020efb44, 1);
            goto Exit;
        }
        if (climb->reversed != 1) goto Exit;
        self->object.obj3D_.SetAnimationByName(data_020efb44, 1);
        goto Exit;
    }

    if (step == LadderStep_GetOn) {
        GameObject_SetFacing((struct Obj02033834*)self, climb->heading);
        GameObject_DisableControl((struct Obj020397cc*)self, 1);
        int animationProgress = self->object.obj3D_.normalizedAnimationTime_;

        if (climb->reversed == 0) {
            if (!self->object.obj3D_.HasAnimationStopped()) {
                self->object.obj3D_.AdvanceAnimations();
            }
            if (!self->object.obj3D_.HasAnimationStopped()) {
                self->object.obj3D_.AdvanceAnimations();
            }
        }

        if (climb->reversed == 1) {
            int tick = zone->substruct_c_.unknown_30_;
            int fixResult = (int)(((float)animationProgress / 4096.0f) * (float)(unsigned int)tick);
            climb->unknown50 = tick - (fixResult << 2);
            if (climb->unknown50 < 0) climb->unknown50 = 0;
        }

        Vector3fix nextPosition;
        Vector3fix targetPosition;
        if (climb->reversed == 0) {
            func_02038500((Vec3038500*)&targetPosition, climb->start.entries[0], climb->start.entries[1] + 0x51, climb->start.entries[2]);
        } else if (climb->reversed == 1) {
            func_02038500((Vec3038500*)&targetPosition, climb->end.entries[0], climb->end.entries[1] - 0xa3, climb->end.entries[2]);
        }

        if (!self->object.obj3D_.HasAnimationStopped()) {
            int dz = targetPosition.z - climb->unknown24.entries[2];
            int dy = targetPosition.y - climb->unknown24.entries[1];
            int dx = targetPosition.x - climb->unknown24.entries[0];
            int rz = FX_MulInline(dz, animationProgress);
            int ry = FX_MulInline(dy, animationProgress);
            int rx = FX_MulInline(dx, animationProgress);
            func_02038500((Vec3038500*)&nextPosition, climb->unknown24.entries[0] + rx, climb->unknown24.entries[1] + ry, climb->unknown24.entries[2] + rz);
            self->object.obj3D_.position_ = nextPosition;
        }

        if (self->object.obj3D_.HasAnimationStopped()) {
            func_02038500((Vec3038500*)&nextPosition, targetPosition.x, targetPosition.y, targetPosition.z);
            self->object.obj3D_.position_ = nextPosition;
            climb->command = LadderStep_Climb;
            self->object.obj3D_.SetAnimationByName(data_020efb4e, 0);
            goto Exit;
        }

        LinkMessageQueue_SendLadderClimb(climb, 0, 0);
        goto Exit;
    }

    if (step == LadderStep_Climb) {
        FlagWord_ClearBits((struct FlagWord020466f4*)inputFlags, 0x400);
        GameObject_SnapFacing((struct Obj02033874*)self, climb->heading);
        GameObject_DisableControl((struct Obj020397cc*)self, 1);

        Vector3fix position = self->object.obj3D_.position_;
        Vector3fix var23, touchEnd;

        GameResources* touchResources = GetGameResources();
        ActorTouch02038598* touch = (ActorTouch02038598*)GameResources_GetTouchWalk(touchResources);

        direction = ClimbDirection_None;
        if (g_keyManager.IsDownHeld()) {
            direction = ClimbDirection_Down;
        } else if (g_keyManager.IsUpHeld()) {
            direction = ClimbDirection_Up;
        }

        if ((unsigned int)g_touchInput.timeHeld_ > 5) {
            fix32_t var27 = touch->endX << 12;
            int startX = touch->startX;
            int startY = touch->startY;
            fix32_t var30 = touch->endY << 12;
            touchEnd.x = var27;
            touchEnd.y = var30;
            touchEnd.z = 0;
            var23.x = startX << 12;
            var23.y = startY << 12;
            var23.z = 0;
            Vector3fix_Subtract(&touchEnd, &var23, &touchEnd);
            if (Vector3fix_Length(&touchEnd) >= ClimbTouchDeadZone) {
                Vector3fix_Normalize(&touchEnd, &touchEnd);
                if (touchEnd.x >= -ClimbTouchVertical && touchEnd.x <= ClimbTouchVertical) {
                    if (touchEnd.y >= 0)
                        direction = ClimbDirection_Down;
                    else
                        direction = ClimbDirection_Up;
                }
            }
        }

        int taskQueued = 0;
        if (func_02046b60(list, FieldTaskKind_ScriptedEvent) ||
            func_02046b60(list, 0x26 /* kind 38, not named yet */) ||
            func_02046b60(list, FieldTaskKind_Zoom) ||
            func_02046b60(list, FieldTaskKind_EnterZone) ||
            func_02046b60(list, FieldTaskKind_WarpToStarflight)) {
            taskQueued = 1;
            direction = ClimbDirection_None;
        }

        if (climb->unknown53 == 0) direction = ClimbDirection_None;

        if (direction == ClimbDirection_Down) {
            position.y -= LadderStepHeight;
        } else if (direction == ClimbDirection_Up) {
            position.y += LadderStepHeight;
        }

        int fraction = fix32_Divide(position.y - climb->start.entries[1], climb->end.entries[1] - climb->start.entries[1]);
        func_02038500((Vec3038500*)&position,
            climb->start.entries[0] + FX_MulInline(climb->end.entries[0] - climb->start.entries[0], fraction), position.y,
            climb->start.entries[2] + FX_MulInline(climb->end.entries[2] - climb->start.entries[2], fraction));
        self->object.obj3D_.position_ = position;

        int heightDelta = self->object.obj3D_.MaybeGetShadowSource().y - climb->unknown4c;
        int var34 = FX_MulInline(heightDelta, 0x14000);
        int t2 = (int)((float)var34 / 4096.0f);
        int tick2 = zone->substruct_c_.unknown_30_;
        climb->unknown50 = tick2 - t2;
        if (climb->unknown50 < 0) climb->unknown50 = 0;

        if (climb->startNode->unk_2c.type9.unk_5 & LadderNodeFlag_LeadsToZone) {
            climb->unknown50 = 0;
        }

        climb->unknown4 = (unsigned short)(climb->unknown4 + GameState::GetInstance()->GetTickCount());

        if (direction == ClimbDirection_Down) {
            self->object.obj3D_.DisableFlag(Object3DFlag_PauseAnimation);
            self->object.obj3D_.SetAnimationByName(data_020efb4e, 0);
            if (climb->unknown54 != direction || climb->unknown4 > 6) {
                LinkMessageQueue_SendLadderClimb(climb, direction, 0);
                climb->unknown4 = 0;
            }
            if (climb->unknown48 != 0) {
                self->object.obj3D_.SetCurrentAnimationTime(climb->unknown48);
                climb->unknown48 = 0;
            }
        } else if (direction == ClimbDirection_Up) {
            self->object.obj3D_.DisableFlag(Object3DFlag_PauseAnimation);
            self->object.obj3D_.SetAnimationByName(data_020efb4e, 4);
            if (climb->unknown54 != direction || climb->unknown4 > 6) {
                LinkMessageQueue_SendLadderClimb(climb, direction, 0);
                climb->unknown4 = 0;
            }
            if (climb->unknown48 != 0) {
                self->object.obj3D_.SetCurrentAnimationTime(climb->unknown48);
                climb->unknown48 = 0;
            }
        } else {
            self->object.obj3D_.EnableFlag(Object3DFlag_PauseAnimation);
            climb->unknown48 = self->object.obj3D_.animationTime_;
            if (climb->unknown54 != direction || climb->unknown4 > 6) {
                LinkMessageQueue_SendLadderClimb(climb, direction, 0);
                climb->unknown4 = 0;
            }
        }
        climb->unknown54 = (unsigned char)direction;

        if (taskQueued != 0) goto Exit;

        if (position.y < climb->start.entries[1]) {
            FlagWord_SetBits(inputFlags, 0x400);
            ZoneFeatures::Opcode6aEntry* node = climb->startNode;
            if (node->unk_2c.type9.unk_5 & LadderNodeFlag_LeadsToZone) {
                climb->unknown60 = node;
                climb->command = LadderStep_ChangeZone;
                goto Exit;
            }
            climb->command = LadderStep_StepOff;
            climb->unknown24.vec = climb->startControl.vec;
            GameObject_StartGlide(self, climb->startControl.entries, motion->maximumSpeed);
            GameObject_ForceMotionState((struct Bytes02033b88*)self, 1);
            GameObject_SetFacing((struct Obj02033834*)self, climb->startHeading);
            LinkMessageQueue_SendLadderClimb(climb, 0, 0);
            goto Exit;
        }

        if (position.y <= climb->end.entries[1]) goto Exit;

        FlagWord_SetBits(inputFlags, 0x400);
        ZoneFeatures::Opcode6aEntry* endNode = climb->endNode;
        if (endNode->unk_2c.type9.unk_5 & LadderNodeFlag_LeadsToZone) {
            climb->unknown60 = endNode;
            climb->command = LadderStep_ChangeZone;
            goto Exit;
        }
        position.y = climb->end.entries[1];
        self->object.obj3D_.position_ = position;
        climb->unknown24.vec = position;
        self->object.obj3D_.SetAnimationByName(data_020efb5a, 1);
        climb->command = LadderStep_GetOffTop;
        LinkMessageQueue_SendLadderClimb(climb, 0, 0);
        goto Exit;
    }

    if (step == LadderStep_GetOffTop) {
        GameObject_DisableControl((struct Obj020397cc*)self, 1);
        int animationProgress = self->object.obj3D_.normalizedAnimationTime_;
        if (animationProgress != 0) {
            Vector3fix fallPosition;
            fallPosition = self->object.obj3D_.position_;
            fallPosition.y = climb->unknown24.entries[1] + FX_MulInline(climb->endControl.entries[1] - climb->unknown24.entries[1], 0x199);
            self->object.obj3D_.position_ = fallPosition;
            climb->unknown24.vec = fallPosition;

            int tick = zone->substruct_c_.unknown_30_;
            climb->unknown50 = (int)((float)(unsigned int)tick *
                (((float)animationProgress / 4096.0f) * ((float)animationProgress / 4096.0f)));
            if (climb->unknown50 < 0) climb->unknown50 = 0;
        }

        if (self->object.obj3D_.HasAnimationStopped()) {
            climb->command = LadderStep_StepOff;
            climb->unknown24.vec = climb->endControl.vec;
            GameObject_StartGlide(self, climb->endControl.entries, motion->maximumSpeed);
            GameObject_ForceMotionState((struct Bytes02033b88*)self, 1);
            GameObject_SetFacing((struct Obj02033834*)self, climb->endHeading);
            LinkMessageQueue_SendLadderClimb(climb, 0, 0);
            FlagWord_ClearBits((struct FlagWord020466f4*)inputFlags, 0x400);
        }
        goto Exit;
    }

    if (step == LadderStep_StepOff) {
        GameObject_DisableControl((struct Obj020397cc*)self, 1);
        self->object.obj3D_.EnableFlag(0x80);
        GameObject_StoreMotionState((struct Foo02033b58*)self, 1);
        if (!GameObject_IsGlideDone((struct ShortField02033ec8*)self)) goto Exit;
        unsigned char reformLineOnFinish = climb->unknown52;  // Party_ReformLine sets it when it was called mid-climb

        LadderClimb_Reset(climb);
        self->controlPending = 1;
        motion->flagsE0.active = 0;
        self->object.obj3D_.DisableFlag(0x1180);
        LinkMessageQueue_SendLadderClimb(climb, 0, 1);
        FlagWord_ClearBits((struct FlagWord020466f4*)inputFlags, 0x400);
        if (reformLineOnFinish == 0) goto Exit;

        self->controlEnabled = 1;
        Party_ReformLine(resources, 1, 1, 1, 1);
        GameObject* leader = GameState::GetInstance()->GetLeader();
        if (leader == 0) goto Exit;
        leader->obj3D_.TransitionInheritedAlpha(31, 100);
        goto Exit;
    }

    if (step == LadderStep_ChangeZone) {
        GameState* gameState = GameState::GetInstance();
        ZoneTransitionSettings* event = (ZoneTransitionSettings*)GameState_GetZoneTransition(gameState);
        GameResources* transitionResources = GetGameResources();
        GameState_GetProtagonistIndex(gameState);
        VectorizedMemset(event, 0, 0x70);
        event->unknown4 = 1;
        event->unknown8 = 1;
        event->unknown9 = 1;
        event->unknownB = -1;
        event->unknown20[0] = -1;
        event->unknown20[1] = -1;
        event->unknown20[2] = -1;
        event->unknown20[3] = -1;
        event->unknown1E = -1;
        event->unknownC = 0;
        event->ladderNodeId = -1;

        event->zoneId = climb->unknown60->unk_2c.type9.maybeZone;
        event->position = climb->unknown60->unk_2c.type9.vector_c;
        event->heading = climb->unknown60->unk_2c.type9.unk_3c;
        event->unknownB = (unsigned char)climb->unknown60->unk_2c.type9.unk_3e;
        event->start = climb->unknown60->unk_2c.type9.vector_c;
        event->end = climb->unknown60->unk_2c.type9.vector_18;
        event->startControl = climb->unknown60->unk_2c.type9.vector_24;
        event->endControl = climb->unknown60->unk_2c.type9.vector_30;
        event->unknownC = 1;

        if (climb->unknown60->unk_2c.type9.unk_5 & LadderNodeFlag_HasLadderTarget) {
            event->ladderNodeId = (const short&)climb->unknown60->unk_2c.type9.unk_42;
            event->ladderHeight = climb->unknown60->unk_2c.type9.unk_40;
        }
        if (event->ladderNodeId == -1) {
            event->ladderNodeId = LadderNodeId_None;
        }
        event->applyPosition = 1;
        GameState_SetZoneTransition(gameState, event);

        FieldTask_InitEnterZone((unsigned char*)transitionResources->unknown_ptr_array_3700[3], 0);
        func_020469b4((struct TailList020469b4*)transitionResources->fieldTaskQueue_,
            (struct TailNode020469b4*)transitionResources->unknown_ptr_array_3700[3]);
        FlagWord_ClearBits((struct FlagWord020466f4*)inputFlags, 0x400);

        LadderClimb_Reset(climb);
        self->controlPending = 1;
        motion->speed = 0;
        motion->flagsE0.active = 0;
        self->object.obj3D_.EnableFlag(Object3DFlag_PauseAnimation);
        self->object.obj3D_.DisableFlag(0x180);
        goto Exit;
    }
    Exit:;
}
