#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

extern "C" void LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void GameObject_UpdateFollower(void* obj);
extern "C" void GameObject_HandleWalkInput(void* obj);
extern "C" void GameObject_UpdateLadderClimb(void* obj);

struct Vector3i;

struct S02037418;

struct Struct020372b8;

struct Obj02039df4;
void GameObject_HideInCelestialAreas(struct Obj02039df4* obj);

struct Obj02052ae8;
void StepValueTowardTarget02052ae8(struct Obj02052ae8* obj);

int GameObject_IsGesturing(signed char* obj);
int IsCountAtLeast4_0219a370(unsigned char* base);
int FieldTaskQueue_IsEmpty(void** obj);

struct BitField0203402c;
int GameObject_IsSinking(struct BitField0203402c* p);

int MessageSystem_GetInstance();

unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
int GameState_GetFollowCamera(char* obj);

struct S020a2c70;
int MarkStateIfFlag020a2c70(struct S020a2c70* p);

struct Obj02052e44;
int GameObject_StartGesture(Obj02052e44*, signed char);

struct Obj02052f44;
int GameObject_StartGestureSequence(struct Obj02052f44* obj, signed char* src, int len);

int LoadBattleBlock020ac4c0(void* dst);

struct S_a06b0;
void AddClamped10BitFieldMidAt0x28_020a06b0(struct S_a06b0* p, unsigned int amount);

struct S_a0140;
void AddClamped10BitFieldAt0x14_020a0140(struct S_a0140* p, unsigned int amount);

int CopyInBattleField0x7540_020ac494(void* src);

void SetByte0x2c4To2IfByte0x2c5Set_020a2c8c(unsigned char* obj);

#if defined(jpn)
enum { ActorRegionOffset = 12, BattleRegionOffset = 0x2d4, StatusRegionOffset = 0x1d0,
       ContextFlagOffset = 0x444, OverlayValueBase = 0x3000, OverlayValueOffset = 0xe60,
       OverlayPointerOffset = 0x4ec };
#else
enum { ActorRegionOffset = 0, BattleRegionOffset = 0, StatusRegionOffset = 0,
       ContextFlagOffset = 0x424, OverlayValueBase = 0x4000, OverlayValueOffset = 0x80,
       OverlayPointerOffset = 0x6fc };
#endif

struct SubAt1000_020421a0 {
    char pad[0x9b1 - StatusRegionOffset];
    unsigned char flag;
};
struct GlobalOuter020421a0 {
    char pad[0x1000];
    struct SubAt1000_020421a0 sub;
};

// A party member's GameObject: Object3D's actorIndex_, position_ and rotation_, GameObject_Update's speed fields,
// GameState.h's savedState_130_, and the party member fields GameObject_InitPartyMember initialises
struct FieldPartyMember {
    char unknown0[4];
    short actorIndex;
    char unknown6[0x44 - 6];
    int position[3];
    int rotationX;
    int rotationY;
    char unknown58[0xb2 - 0x58];
    short speed;
    short maximumSpeed;
    char unknownB6[0xc2 - 0xb6];
    unsigned char unknownC2Low : 5;
    unsigned char unknownC2Bit5 : 1;
    unsigned char unknownC2High : 2;
    char unknownC3[0x130 - 0xc3];
    void* savedState;
    char unknown134[0x1ce - ActorRegionOffset - 0x134];
    unsigned char followFlags;
    char unknown1cf[0x260 - 0x1cf];
    int gestureSlot;
};

enum {
    ObjectIndex_Follower = 0xce,            // the guest FieldTask_SpawnFollower builds
    GameState_followerRotationY = 0x7f5c,   // where this keeps the guest's facing and position (usa offsets)
    GameState_followerPosition = 0x7f60,
    FollowFlag_FadeInOnMove = 4,            // set by GameObject_PlaceInZone, GameObject_UpdateFollower and GameObject_HideInCelestialAreas
    Object3DFlag_SkipWalkInput = 0x1000000, // func_ov017_02190884 clears it on the line leader it gives control
    Party_gestureUp = 0x2c8d,               // the gestures set on B + D-pad (7 bytes Party_Init clears)
    Party_gestureLeft = 0x2c8e,
    Party_gestureRight = 0x2c8f,
    Party_gestureDownSequence = 0x2c90,     // up to 4, played one after another
    GameResourcesFlags04_Unknown80 = 0x80,     // set and cleared around the follow camera; meaning not known
};

// The gestureSlot values (GameObject_GetGestureSlot's callers read them back)
enum { GestureSlot_None = -1, GestureSlot_Up = 0, GestureSlot_Left = 1, GestureSlot_Right = 2, GestureSlot_Down = 3 };

// Main, originally func_02037d88 (USA 0x02037d88, EUR 0x02037d98, JPN 0x020377e4)
extern "C" ARM void GameObject_UpdatePartyMember(struct FieldPartyMember* member) {
    void* gameState = GameState::GetInstance();
    LinkSession_GetInstance();
    unsigned char* resources = (unsigned char*)((int)GetGameResources());

    int fadeInOnMove = (member->followFlags & FollowFlag_FadeInOnMove) != 0;
    if (fadeInOnMove) {
        if (member->speed > 0) {
            member->followFlags &= ~FollowFlag_FadeInOnMove;
            ((Object3D*)((struct S02037418*)member))->SetInheritedAlpha(0);
            ((Object3D*)((struct Struct020372b8*)member))->TransitionInheritedAlpha(31, 100);
        }
    }
    GameObject_HideInCelestialAreas((struct Obj02039df4*)member);

    if (member->actorIndex == ObjectIndex_Follower) {
        *(int*)((char*)gameState + GameState_followerRotationY - BattleRegionOffset) = member->rotationY;
        *(Vector3i*)((int*)((char*)gameState + GameState_followerPosition - BattleRegionOffset)) = *(Vector3i const*)member->position;
    }

    {
        char* bytesFrom100 = (char*)member + 0x100;
        signed char linePosition = ((signed char*)bytesFrom100)[0xc9 - ActorRegionOffset];  // +0x1c9: 0 = line leader
        if (linePosition != 0) {
            StepValueTowardTarget02052ae8((struct Obj02052ae8*)member);
            GameObject_UpdateFollower(member);
            return;
        }
    }

    {
        void* game = GameState::GetInstance();
        void* camera = ((GameState*)game)->GetCamera();
        void* zone = Zone3D_GetInstance();
        int* savedState = (int*)member->savedState;

        if ((*savedState & 1) != 0
            || GameObject_IsGesturing((signed char*)member) != 0
            || *(int*)((char*)zone + ContextFlagOffset) != 0
            || camera == 0
            || member->unknownC2Bit5) {
            StepValueTowardTarget02052ae8((struct Obj02052ae8*)member);
            return;
        }

        {
            short maximumSpeed = member->maximumSpeed;
            StepValueTowardTarget02052ae8((struct Obj02052ae8*)member);
            member->maximumSpeed = maximumSpeed;
        }

        unsigned int* resourcesHigh = (unsigned int*)(resources + OverlayValueBase);
        int unknown4080 = *(int*)((char*)resourcesHigh + OverlayValueOffset);  // GameResources::unknown_4080
        unsigned int* resources3000 = (unsigned int*)(resources + 0x3000);
        void* fieldTaskQueue = *(void**)((char*)resources3000 + OverlayPointerOffset);  // GameResources::fieldTaskQueue_

        if (unknown4080 != 0
            && IsCountAtLeast4_0219a370(resources) != 0
            && FieldTaskQueue_IsEmpty((void**)fieldTaskQueue) != 0
            && g_keyManager.TestKeysHeld(KEY_B) != 0
            && GameObject_IsSinking((struct BitField0203402c*)member) == 0
            && ((struct GlobalOuter020421a0*)MessageSystem_GetInstance())->sub.flag == 0) {

            unsigned char* party = (unsigned char*)GameState_GetParty((GameState*)game);

            void* gameState2 = GameState::GetInstance();
            short actorIndex = member->actorIndex;
            unsigned char leaderIndex = GameState_GetLeaderIndex((GameState*)gameState2);
            if (leaderIndex == actorIndex) {
                int followCamera = GameState_GetFollowCamera((char*)gameState2);
                if (followCamera != 0) {
                    if (IsCountAtLeast4_0219a370(resources) != 0) {
                        if (MarkStateIfFlag020a2c70((struct S020a2c70*)followCamera) != 0) {
                            SetFlags04((GameResources*)resources, GameResourcesFlags04_Unknown80);
                        }
                    }
                }
            }

            int gestureStarted = 0;
            if (g_keyManager.TestKeysPressed(KEY_UP)) {
                signed char gesture = party[Party_gestureUp];
                gestureStarted = GameObject_StartGesture((struct Obj02052e44*)member, gesture);
                member->gestureSlot = GestureSlot_Up;
            } else if (g_keyManager.TestKeysPressed(KEY_RIGHT)) {
                signed char gesture = party[Party_gestureRight];
                gestureStarted = GameObject_StartGesture((struct Obj02052e44*)member, gesture);
                member->gestureSlot = GestureSlot_Right;
            } else if (g_keyManager.TestKeysPressed(KEY_LEFT)) {
                signed char gesture = party[Party_gestureLeft];
                gestureStarted = GameObject_StartGesture((struct Obj02052e44*)member, gesture);
                member->gestureSlot = GestureSlot_Left;
            } else if (g_keyManager.TestKeysPressed(KEY_DOWN)) {
                gestureStarted = GameObject_StartGestureSequence((struct Obj02052f44*)member, (signed char*)(party + Party_gestureDownSequence), 4);
                member->gestureSlot = GestureSlot_Down;
            }

            if (gestureStarted != 0) {
                char record[0xb0];  // a 0xb0-byte block LoadBattleBlock020ac4c0 reads and CopyInBattleField0x7540_020ac494 stores back
                LoadBattleBlock020ac4c0(record);
                AddClamped10BitFieldMidAt0x28_020a06b0((struct S_a06b0*)record, 1);
                AddClamped10BitFieldAt0x14_020a0140((struct S_a0140*)(record + 0x68), 1);
                CopyInBattleField0x7540_020ac494(record);
                return;
            }
        } else {
            void* gameState3 = GameState::GetInstance();
            short actorIndex = member->actorIndex;
            unsigned char leaderIndex = GameState_GetLeaderIndex((GameState*)gameState3);
            if (leaderIndex == actorIndex) {
                int followCamera = GameState_GetFollowCamera((char*)gameState3);
                if (followCamera != 0) {
                    unsigned char* cameraState = (unsigned char*)followCamera + 0x2c4;
                    if (cameraState != 0) {
                        unsigned char stateByte = cameraState[0];
                        if (stateByte == 1) {
                            SetByte0x2c4To2IfByte0x2c5Set_020a2c8c((unsigned char*)followCamera);
                        } else if (stateByte == 2) {
                            short cameraValue = *(short*)(cameraState + 2);
                            if (cameraValue < 0x199) {
                                ClearFlags04((GameResources*)resources, GameResourcesFlags04_Unknown80);
                            }
                        }
                    }
                }
            }
        }

        member->gestureSlot = GestureSlot_None;
        if (((Object3D*)member)->GetFlag(Object3DFlag_SkipWalkInput) == 0) {
            GameObject_HandleWalkInput(member);
        }
        GameObject_UpdateLadderClimb(member);
    }
}
