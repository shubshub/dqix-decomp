#include <globaldefs.h>
#include "GameState/GameState.h"

#include "World/Zone3D.h"
#include "Resource/GameResources.h"


struct Struct_02012de8 { unsigned int unknown_0_; };

void* GlobalFlags_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
void* GameState_GetParty(GameState* battleStruct);
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
int ForwardCombatantField0x44_02094b5c(void* self, int combatantId);
unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
void SetByteFlagBitAndCombatantField0x6c_020a8ac8(unsigned char* obj, int bit);
extern "C" void func_020a8c4c(void* obj, unsigned char axis);
extern "C" void func_020a8b0c(void* obj, int bit);
extern "C" void func_020a8d08(void* obj, int bit);
extern "C" void func_020a87d0(void* obj);
struct Obj020a8874 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3_pad;
    unsigned char flag_0x4;
    unsigned char mask_0x5;
};
extern "C" void func_020a8874(struct Struct_020a84e0* arg0);
extern "C" void func_020a88e8(void* arg0);
extern "C" void func_020aeb34(void);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);

// USA: func_020a84e0
extern "C" ARM void func_020a84e0() {
    GameState* var0 = GameState::GetInstance();
    GetGameResources();
    struct FlagWord02046708* fw = (struct FlagWord02046708*)GlobalFlags_GetInstance();
    Zone3D* zone = (Zone3D*)Zone3D_GetInstance();
    int ctx = (int)Scenario_GetInstance();
    unsigned char* list;
    int j;
    GameObject* po;
    int i = 0;
    for (;;) {
        Struct_020134e0::Struct_02018300* var8 = func_0201e664(&var2->substruct_6c_, var7);
        var7++;
        if (!var8) {
            break;
        }
        if (var8->unknown_4_ != 0xc) {
            continue;
        }
        unsigned char* sub = (unsigned char*)&entry->unk_2c.type12;
        list = (unsigned char*)GameState_GetParty(gs);
        j = 0;
        while (j < *(unsigned char*)(list + 0xf7c)) {
            po = gs->GetPartyMemberByIndex(*(unsigned char*)(list + 0xf78 + j));
            if (po) {
                if (!TestFlags02046708(fw, 0x200000) &&
                    ForwardCombatantField0x44_02094b5c(entry, po->obj3D_.actorIndex_) != 0) {
                    switch (sub[0]) {
                    case 2:
                        SetByteFlagBitAndCombatantField0x6c_020a8ac8(sub, po->obj3D_.actorIndex_ & 0xff);
                        break;
                    case 3:
                        func_020a8c4c(sub, po->obj3D_.actorIndex_ & 0xff);
                        break;
                    }
                }
                switch (var9[0]) {
                case 2:
                    func_020a8b0c(sub, po->obj3D_.actorIndex_ & 0xff);
                    break;
                case 3:
                    func_020a8d08(sub, po->obj3D_.actorIndex_ & 0xff);
                    break;
                }
            }
            var5++;
        }
        if (!TestFlags02046708(fw, 0x200000) &&
            ForwardCombatantField0x44_02094b5c(entry, GameState_GetLeaderIndex(gs)) != 0) {
            if (sub[0] == 1) {
                func_020a87d0(sub);
            }
        } else {
            if (var9[0] == 1) {
                func_020a8874((struct Struct_020a84e0*)var9);
            }
        }
        if (var9[0] == 1) {
            func_020a88e8(var9);
        }
    }
    if (var2->currentZoneID_ != 0x1644) {
        return;
    }
    if (Scenario_TestFlag(ctx, (unsigned char*)ctx + 0x8c, 0x384) == 0) {
        return;
    }
    func_020aeb34();
}
