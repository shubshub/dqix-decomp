#include <globaldefs.h>
#include "GameState/GameState.h"

#include "World/Zone3D.h"
#include "Resource/GameResources.h"


struct FlagWord02046708 { unsigned int flags; };

extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);
extern "C" int func_02094b5c(void* self, int combatantId);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
extern "C" void func_020a8ac8(unsigned char* obj, int bit);
extern "C" void func_020a8c4c(void* obj, unsigned char axis);
extern "C" void func_020a8b0c(void* obj, int bit);
extern "C" void func_020a8d08(void* obj, int bit);
extern "C" void func_020a87d0(void* obj);
struct Struct_020a84e0 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
};
extern "C" void func_020a8874(struct Struct_020a84e0* obj);
extern "C" void func_020a88e8(void* obj);
extern "C" void func_020aeb34(void);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);

// USA: func_020a84e0
extern "C" ARM void func_020a84e0() {
    GameState* gs = GameState::GetInstance();
    GetGameResources();
    struct FlagWord02046708* fw = (struct FlagWord02046708*)GlobalFlags_GetInstance();
    Zone3D* zone = (Zone3D*)Zone3D_GetInstance();
    int ctx = (int)Scenario_GetInstance();
    unsigned char* list;
    int j;
    GameObject* po;
    int i = 0;
    for (;;) {
        ZoneFeatures::Opcode6aEntry* entry = ZoneFeatures_GetEntry(&zone->substruct_6c_, i);
        i++;
        if (!entry) {
            break;
        }
        if (entry->maybeType != 0xc) {
            continue;
        }
        unsigned char* sub = (unsigned char*)&entry->unk_2c.type12;
        list = (unsigned char*)GameState_GetParty(gs);
        j = 0;
        while (j < *(unsigned char*)(list + 0xf7c)) {
            po = gs->GetPartyMemberByIndex(*(unsigned char*)(list + 0xf78 + j));
            if (po) {
                if (!FlagWord_TestBits(fw, 0x200000) &&
                    func_02094b5c(entry, po->obj3D_.actorIndex_) != 0) {
                    switch (sub[0]) {
                    case 2:
                        func_020a8ac8(sub, po->obj3D_.actorIndex_ & 0xff);
                        break;
                    case 3:
                        func_020a8c4c(sub, po->obj3D_.actorIndex_ & 0xff);
                        break;
                    }
                }
                switch (sub[0]) {
                case 2:
                    func_020a8b0c(sub, po->obj3D_.actorIndex_ & 0xff);
                    break;
                case 3:
                    func_020a8d08(sub, po->obj3D_.actorIndex_ & 0xff);
                    break;
                }
            }
            j++;
        }
        if (!FlagWord_TestBits(fw, 0x200000) &&
            func_02094b5c(entry, GameState_GetLeaderIndex(gs)) != 0) {
            if (sub[0] == 1) {
                func_020a87d0(sub);
            }
        } else {
            if (sub[0] == 1) {
                func_020a8874((struct Struct_020a84e0*)sub);
            }
        }
        if (sub[0] == 1) {
            func_020a88e8(sub);
        }
    }
    if (zone->currentZoneID_ != 0x1644) {
        return;
    }
    if (Scenario_TestFlag(ctx, (unsigned char*)ctx + 0x8c, 0x384) == 0) {
        return;
    }
    func_020aeb34();
}
