#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "World/Object3D.h"
#include "World/Zone3D.h"
#include "GameState/GameState.h"

struct Obj02033874;
struct Bytes02033b88;
struct Obj020397cc;
struct Struct_02000c9c_21;
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" void* GameState_GetZoneTransition(GameState*);
extern "C" void* Zone3D_GetInstance();
extern "C" void GameObject_ResetTrail(unsigned char*);
extern "C" int GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void func_ov017_021d440c(int);
int fix32cos(int);
int fix32sin(int);
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
#if defined(jpn)
#define data_020efb4e data_020efa3e
#endif
extern const char data_020efb4e[];

#if defined(jpn)
enum { kActorTailDelta = 12 };
#else
enum { kActorTailDelta = 0 };
#endif

// data_020efb4e is "hasigo_loop" (ROM), the climbing animation GameObject_UpdateLadderClimb also plays
enum {
    GameObject_speed = 0xb2,                 // GameObject_Update's speed
    GameObject_flagsE0 = 0xe0,
    PartyMember_linePosition = 0x1c9,        // usa offsets; 0 = the walking line's leader
    PartyMember_trailWriteIndex = 0x1cb,
    PartyMember_trailReadIndex = 0x1cc,
    PartyMember_followFlags = 0x1ce,
    PartyMember_ladderClimb = 0x26c,
    FollowFlag_FadeInOnMove = 4,             // GameObject_UpdatePartyMember fades it in once it moves
    Object3DFlag_PauseAnimation = 0x1000,    // flags_ bit 12: the animation clock stops
    LadderStep_Climb = 2,                    // GameObject_UpdateLadderClimb's climbing step ("hasigo_loop")
    LadderNodeId_None = 9999,
};

// GameState's zone transition settings, as far as this reads them (FieldTask_ShipPrompt's ZoneTransitionSettings)
enum {
    ZoneTransition_resetLadder = 0x66,       // nonzero: drop any climb in progress
    ZoneTransition_ladderHeight = 0x6a,      // fx32 fraction of the way up the ladder
    ZoneTransition_ladderNodeId = 0x6c,      // the ladder node to put the actor on; negative: stand, 9999: none
};

#define SET_LADDER_POINTS(firstNode, secondNode, reverseValue) \
    climb.endNode = secondNode; \
    climb.startNode = firstNode; \
    climb.start.vec = firstNode->unk_8.vec; \
    climb.end.vec = secondNode->unk_8.vec; \
    climb.startControl.vec = firstNode->unk_8.vec; \
    climb.endControl.vec = secondNode->unk_8.vec; \
    climb.startHeading = firstNode->angle; \
    climb.endHeading = secondNode->angle; \
    climb.startHeading -= 0x3243; \
    climb.reversed = reverseValue; \
    climb.endControl.vec.x = direction.x + climb.endControl.vec.x; \
    climb.endControl.vec.z += direction.z; \
    climb.end.vec.y -= 0x1000; \
    if (climb.startHeading < 0) climb.startHeading += 0x6487

// Main, originally func_020399b0 (USA 0x020399b0, EUR 0x020399c0, JPN 0x02039408)
extern "C" ARM void GameObject_PlaceInZone(GameObject* self, unsigned short zoneId, const Vector3i* position, int heading) {
    self->obj3D_.SetField06(zoneId);
    self->obj3D_.position_ = *position;
    GameObject_SnapFacing(reinterpret_cast<Obj02033874*>(self), heading);
    *(short*)((char*)self + GameObject_speed) = 0;
    if (((signed char*)self)[PartyMember_linePosition - kActorTailDelta] > 0) ((unsigned char*)self)[PartyMember_followFlags - kActorTailDelta] |= FollowFlag_FadeInOnMove;
    ((signed char*)self)[PartyMember_trailWriteIndex - kActorTailDelta] = -1;
    ((unsigned char*)self)[PartyMember_trailReadIndex - kActorTailDelta] = 0;
    unsigned char* settings = static_cast<unsigned char*>(GameState_GetZoneTransition(GameState::GetInstance()));
    Zone3D* zone = static_cast<Zone3D*>(Zone3D_GetInstance());
    GameObject_ResetTrail(reinterpret_cast<unsigned char*>(self));
    if (settings[ZoneTransition_resetLadder]) {
        LadderClimb_Reset((SubBlock02038508*)((char*)self + PartyMember_ladderClimb - kActorTailDelta));
        ((ActorActionFlags*)((char*)self + GameObject_flagsE0))->active = 0;
        self->obj3D_.DisableFlag(0x1180);  // 0x80 and 0x100 (not known yet) and Object3DFlag_PauseAnimation
        GameObject_ForceMotionState(reinterpret_cast<Bytes02033b88*>(self), 0);
        LinkMessageQueue_SendLadderClimb((SubBlock02038508*)((char*)self + PartyMember_ladderClimb - kActorTailDelta), 0, 1);
    }
    if (*reinterpret_cast<short*>(settings + ZoneTransition_ladderNodeId) < 0) {
        GameObject_ForceMotionState(reinterpret_cast<Bytes02033b88*>(self), 0);
        return;
    }
    if (*reinterpret_cast<short*>(settings + ZoneTransition_ladderNodeId) == LadderNodeId_None) {
        self->obj3D_.DisableFlag(Object3DFlag_PauseAnimation);
        func_ov017_021d440c(-1);
        LinkMessageQueue_SendLadderClimb((SubBlock02038508*)((char*)self + PartyMember_ladderClimb - kActorTailDelta), 0, 1);
        return;
    }
    SubBlock02038508 climb;
    LadderClimb_Reset(&climb);
    ZoneFeatures::Opcode6aEntry* node = ZoneFeatures_FindLadderNode(&zone->substruct_6c_, *reinterpret_cast<short*>(settings + ZoneTransition_ladderNodeId));
    if (!node) return;
    int cosine = fix32cos(node->angle);
    Vector3i direction;
    direction.x = fix32sin(node->angle);
    direction.y = 0;
    direction.z = cosine;
    Vector3fix_Normalize(&direction, &direction);
    ZoneFeatures::Opcode6aEntry* linked = ZoneFeatures_FindLadderNode(&zone->substruct_6c_, node->unk_2c.type9.unk_2);
    if (!linked) return;
    if (node->unk_2c.type9.unk_5 & 1) {
        SET_LADDER_POINTS(linked, node, 1);
    } else {
        SET_LADDER_POINTS(node, linked, 0);
    }
    climb.command = LadderStep_Climb;
    climb.active = 1;
    climb.heading = node->angle;
    GameObject_SetLadderClimb(self, &climb);
    int difference = climb.end.vec.y - climb.start.vec.y;
    int y = climb.start.vec.y + FIX32_MULTIPLY(difference, *reinterpret_cast<short*>(settings + ZoneTransition_ladderHeight));
    Vector3i var9;
    var9 = self->obj3D_.position_;
    var9.y = y;
    self->obj3D_.position_ = var9;
    GameObject_SnapFacing(reinterpret_cast<Obj02033874*>(self), node->angle);
    self->obj3D_.SetAnimationByName(data_020efb4e, 0);
    self->obj3D_.EnableFlag(0x180);
    ((ActorActionFlags*)((char*)self + GameObject_flagsE0))->active = 1;
    GameObject_DisableControl(reinterpret_cast<Obj020397cc*>(self), 1);
}
