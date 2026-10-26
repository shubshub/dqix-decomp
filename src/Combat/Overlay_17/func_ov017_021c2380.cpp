#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct BitField020340d4;
struct Struct_020340c4;
struct Struct_020340b4;
struct BitField0203402c;

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* search);
extern "C" void func_ov017_021d360c(int kind, int index, int id, Vector3s vec);

struct Spot_021c2380 {
    unsigned short id;
    Vector3s pos;
};

extern "C" Spot_021c2380* GameState_GetPlayerLocation(char* base, unsigned int index);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" int func_020340d4(BitField020340d4* obj);
extern "C" void func_020340c4(Struct_020340c4* obj);
extern "C" void func_020340b4(Struct_020340b4* obj);
extern "C" int GameObject_IsSinking(BitField0203402c* obj);
extern "C" void func_02034044(unsigned char* obj, int value);
extern "C" unsigned char GameObject_IsClimbingLadder(char* obj);
extern "C" void GameObject_EnableControl(void* obj);

// USA: func_ov017_021c2380
extern "C" ARM int func_ov017_021c2380(int spotIdx, int monIdx) {
    GameState* gs = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    Spot_021c2380* spot = GameState_GetPlayerLocation((char*)gs, spotIdx);
    if (spot == NULL) {
        return 0;
    }
    if (spot->id == 0) {
        return 0;
    }

    GameObject* mon = gs->GetWanderingMonsterByIndex(monIdx);
    GameObject* member = gs->GetPartyMemberByIndex(monIdx);
    if (mon == NULL) {
        return 0;
    }

    int var5 = 0;
    if (spotIdx == GameState_GetProtagonistIndex(gs) && func_020340d4((BitField020340d4*)mon)) {
        var5 = func_020340d4((BitField020340d4*)mon);
        func_020340c4((Struct_020340c4*)mon);
    }
    if (GameObject_IsSinking((BitField0203402c*)mon)) {
        return 0;
    }
    if (member != NULL && GameObject_IsClimbingLadder((char*)member)) {
        return 0;
    }
    if (spot->id != mon->obj3D_.GetField06()) {
        return 0;
    }

    Vector3fix target;
    target.x = spot->pos.x << 4;
    target.y = spot->pos.y << 4;
    target.z = spot->pos.z << 4;
    Vector3fix pos = mon->obj3D_.position_;
    if (fix32abs(target.x - pos.x) > 0x800) {
        return 0;
    }
    if (fix32abs(target.y - pos.y) > 0x800) {
        return 0;
    }
    if (fix32abs(target.z - pos.z) > 0x800) {
        return 0;
    }
    if (Vector3fix_Distance(&target, &pos) > 0x800) {
        return 0;
    }
    if (var5) {
        func_020340b4((Struct_020340b4*)mon);
        return 0;
    }

    if (LinkSession_IsHostOrSolo(search)) {
        func_02034044((unsigned char*)mon, 5000);
        if (member != NULL) {
            GameObject_EnableControl(member);
        }
    }
    Vector3s zero = {0};
    func_ov017_021d360c(1, (unsigned char)spotIdx, (unsigned short)monIdx, zero);
    spot->id = 0;
    return 1;
}
