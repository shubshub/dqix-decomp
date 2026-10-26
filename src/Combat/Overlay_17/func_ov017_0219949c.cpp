#if defined(jpn)
enum { Enum_ov017_0219949c_17479 = 0x4197 };
#else
enum { Enum_ov017_0219949c_17479 = 0x4447 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void);
struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
struct U16Field0x6_020375f8;
extern "C" void func_ov017_021d0860(int a, int b, int c);

// USA: func_ov017_0219949c
extern "C" ARM void func_ov017_0219949c(void* ctx, int combatantId, int arg2, unsigned char arg3, signed char threshold) {
    struct SearchStruct0202c1a4* search = (struct SearchStruct0202c1a4*)LinkSession_GetInstance();
    signed char arrEntry = LinkSession_GetOwnSlot(search);

    if (arg2 != arrEntry && arg2 != 4) {
        return;
    }

    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetGameObjectByIndex(combatantId);
    GameObject* target = battle->GetLeader();
    unsigned short v1 = ((Object3D*)((struct U16Field0x6_020375f8*)combatant))->GetField06();
    unsigned short v2 = ((Object3D*)((struct U16Field0x6_020375f8*)target))->GetField06();

    if (v1 != v2) {
        func_ov017_021d0860(arg3, 1, 1);
        return;
    }

    if (threshold != *(signed char*)((char*)ctx + Enum_ov017_0219949c_17479)) {
        GetGameResources();
        func_ov017_021d0860(arg3, 1, 1);
        return;
    }

    unsigned char arrEntry2 = (unsigned char)LinkSession_GetOwnSlot(search);
    if (arg3 < arrEntry2) {
        func_ov017_021d0860(arg3, 1, 1);
        return;
    }
    func_ov017_021d0860(arg3, 1, 0);
}
