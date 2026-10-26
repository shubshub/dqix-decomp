#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_020340d4;
struct Struct_020340c4;
struct Struct_020340b4;
struct Struct_0203402c;

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* search);
extern "C" void func_ov017_021d360c(int kind, int index, int id, Vector3s vec);

struct Struct_ov017_021c2380 {
    unsigned short unknown_0_;
    Vector3s unknown_2_;
};

Spot_021c2380* GameState_GetPlayerLocation(char* base, unsigned int index);
int GameState_GetProtagonistIndex(GameState* battleStruct);
int GetFlag0x80At0xc2(BitField020340d4* obj);
void ClearFlag0x80At0xc2(Flags020340c4* obj);
void SetFlag0x80At0xc2(Flags020340b4* obj);
int GameObject_IsSinking(BitField0203402c* obj);
void SetField0xc4Low15Bits_02034044(unsigned char* obj, int value);
unsigned char GameObject_IsClimbingLadder(char* obj);
void GameObject_EnableControl(void* obj);

// USA: func_ov017_021c2380
extern "C" ARM int func_ov017_021c2380(int spotIdx, int monIdx) {
    GameState* gs = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    Spot_021c2380* spot = GameState_GetPlayerLocation((char*)gs, spotIdx);
    if (spot == NULL) {
        return 0;
    }
    if (var2->unknown_0_ == 0) {
        return 0;
    }

    GameObject* mon = gs->GetWanderingMonsterByIndex(monIdx);
    GameObject* member = gs->GetPartyMemberByIndex(monIdx);
    if (mon == NULL) {
        return 0;
    }

    int wasFlagged = 0;
    if (spotIdx == GameState_GetProtagonistIndex(gs) && GetFlag0x80At0xc2((BitField020340d4*)mon)) {
        wasFlagged = GetFlag0x80At0xc2((BitField020340d4*)mon);
        ClearFlag0x80At0xc2((Flags020340c4*)mon);
    }
    if (GameObject_IsSinking((BitField0203402c*)mon)) {
        return 0;
    }
    if (member != NULL && GameObject_IsClimbingLadder((char*)member)) {
        return 0;
    }
    if (var2->unknown_0_ != var3->obj3D_.GetField06()) {
        return 0;
    }

    Vector3fix var6;
    var6.x = var2->unknown_2_.x << 4;
    var6.y = var2->unknown_2_.y << 4;
    var6.z = var2->unknown_2_.z << 4;
    Vector3fix var7 = var3->obj3D_.position_;
    if (fix32abs(var6.x - var7.x) > 0x800) {
        return 0;
    }
    if (fix32abs(var6.y - var7.y) > 0x800) {
        return 0;
    }
    if (fix32abs(var6.z - var7.z) > 0x800) {
        return 0;
    }
    if (Vector3fix_Distance(&var6, &var7) > 0x800) {
        return 0;
    }
    if (var5) {
        func_020340b4((Struct_020340b4*)var3);
        return 0;
    }

    if (LinkSession_IsHostOrSolo(search)) {
        SetField0xc4Low15Bits_02034044((unsigned char*)mon, 5000);
        if (member != NULL) {
            GameObject_EnableControl(member);
        }
    }
    Vector3s var8 = {0};
    func_ov017_021d360c(1, (unsigned char)arg0, (unsigned short)arg1, var8);
    var2->unknown_0_ = 0;
    return 1;
}
