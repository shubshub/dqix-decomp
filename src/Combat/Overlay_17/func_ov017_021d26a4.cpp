#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021d26a4 {
    unsigned char pad[4];
    unsigned char id;
    unsigned char unknown_5_0_ : 1;
    unsigned char flag1 : 1;
};

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_ov017_0218d4b8(unsigned char* base, int bit);
extern "C" void func_ov017_0218d4d0(void* obj, int bit);
extern "C" void func_ov017_02191aac(void* obj, int mode, int idx, unsigned char mask);

// USA: func_ov017_021d26a4
extern "C" ARM void func_ov017_021d26a4(void* unused, Struct_ov017_021d26a4* info, GameState* battleStruct, void* base) {
    int var0 = ((int)GetGameResources());
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(info->id);
    if (combatant == 0) {
        return;
    }
    unsigned char* field150 = (unsigned char*)func_02053c6c((unsigned char*)combatant);
    if (field150 == 0) {
        return;
    }
    bool bit0 = info->unknown_5_0_;
    field150[0x56c] = bit0;
    if (field150[0x56c]) {
        func_ov017_02191aac(base, 1, info->id, 2);
    }
    if (info->flag1) {
        func_ov017_0218d4b8((unsigned char*)var0, info->id);
    } else {
        func_ov017_0218d4d0((void*)var0, info->id);
    }
}
