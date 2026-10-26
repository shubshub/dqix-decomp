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
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
struct U16Field0x6_020375f8;
void EnqueueEventTag154_021d0860(int a, int b, int c);

// USA: func_ov017_0219949c
extern "C" ARM void func_ov017_0219949c(void* ctx, int combatantId, int matchType, unsigned char slotId, signed char threshold) {
    struct SearchStruct0202c1a4* search = (struct SearchStruct0202c1a4*)LinkSession_GetInstance();
    signed char arrEntry = LinkSession_GetOwnSlot(search);

    if (arg2 != var1 && arg2 != 4) {
        return;
    }

    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetGameObjectByIndex(combatantId);
    GameObject* target = battle->GetLeader();
    unsigned short v1 = ((Object3D*)((struct U16Field0x6_020375f8*)combatant))->GetField06();
    unsigned short v2 = ((Object3D*)((struct U16Field0x6_020375f8*)target))->GetField06();

    if (var5 != var6) {
        func_ov017_021d0860(arg3, 1, 1);
        return;
    }

    if (arg4 != *(signed char*)((char*)arg0 + Enum_ov017_0219949c_17479)) {
        GetGameResources();
        func_ov017_021d0860(arg3, 1, 1);
        return;
    }

    unsigned char arrEntry2 = (unsigned char)LinkSession_GetOwnSlot(search);
    if (slotId < arrEntry2) {
        EnqueueEventTag154_021d0860(slotId, 1, 1);
        return;
    }
    func_ov017_021d0860(arg3, 1, 0);
}
