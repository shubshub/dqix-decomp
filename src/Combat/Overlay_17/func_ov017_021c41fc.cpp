#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0x150 };
#else
enum { kRegionalFieldOffset = 0x15c };
#endif
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
struct U16Field0x6_020375f8;
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c41fc {
    unsigned char flags;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 4;
    unsigned short field6;
    unsigned short field8;
};

struct Struct_ov017_021c41fc_2 {
    unsigned char tag;
    unsigned char pad1[3];
    struct Struct_ov017_021c41fc payload;
    unsigned char pad2[0xa];
};

// USA: func_ov017_021c41fc
extern "C" ARM void func_ov017_021c41fc(int combatantId, int mode) {
    GameState* battleStruct = GameState::GetInstance();
    ((int)GetGameResources());
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(combatantId);
    if (combatant == NULL) return;

    void* data = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021c41fc_2 evt;
    struct Struct_ov017_021c41fc* p = &evt.payload;
    evt.tag = 0;
    p->unknown_1_0_ = combatantId;
    p->field6 = ((Object3D*)((struct U16Field0x6_020375f8*)combatant))->GetField06();
    p->flags = 0;
    if (mode >= 0) {
        p->unknown_1_4_ = mode;
        p->flags |= 1;
    } else {
        p->unknown_1_4_ = 0;
    }

    int v = *(int*)((char*)combatant + kRegionalFieldOffset);
    if (v < 0) {
        p->field8 = 0;
    } else {
        p->field8 = (unsigned short)v;
        p->flags |= 2;
    }

    GameObject* target = battleStruct->GetLeader();
    if (target != NULL && combatantId == target->obj3D_.actorIndex_) {
        if (p->field6 == 0x2710) {
            p->field6 = 0x170c;
        } else if (p->field6 == 0x2710 + 0x64) {
            p->field6 = 0x1901;
        }

        if (p->field8 != 0) {
            if (p->field8 == 0x2710) {
                p->field8 = 0x170c;
            } else if (p->field8 == 0x2710 + 0x64) {
                p->field8 = 0x1901;
            }
        }
    }

    func_0205e330(data, &evt, 0);
}
