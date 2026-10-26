#if defined(jpn)
enum { Enum_ov017_021b996c_22308 = 0x54c4, RegionOffset6fc = 0x4ec, RegionOffset998 = 0x868 };
#else
enum { Enum_ov017_021b996c_22308 = 0x5724, RegionOffset6fc = 0x6fc, RegionOffset998 = 0x998 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void* ctx);
struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
struct U16Field0x6_020375f8;
struct ListHead02046b60;
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);
extern "C" int MessageSystem_GetInstance();
extern "C" void func_ov017_021d079c(unsigned char a, unsigned char b, unsigned short c);

struct Struct_ov017_021b996c { char pad[0x12c]; int field12c; };

// USA: func_ov017_021b996c
extern "C" ARM void func_ov017_021b996c(struct Struct_ov017_021b996c* self, int combatantId, int arg2, unsigned char tag, unsigned short arg4) {
    void* search = LinkSession_GetInstance(self);
    signed char cur = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search);
    if (arg2 != cur && arg2 != 4) return;

    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetGameObjectByIndex(combatantId);
    GameObject* combatant2 = battle->GetLeader();
    unsigned short var5 = ((Object3D*)((struct U16Field0x6_020375f8*)combatant))->GetField06();
    unsigned short u2 = ((Object3D*)((struct U16Field0x6_020375f8*)combatant2))->GetField06();
    if (var5 != u2) {
        func_ov017_021d079c(tag, 1, 1);
        return;
    }

    int var7;
    if (self->field12c != arg4 && (var7 = *(int*)((char*)battle + Enum_ov017_021b996c_22308)) != arg4) {
        void* p = GetGameResources();
        struct ListHead02046b60* list = *(struct ListHead02046b60**)((char*)p + 0x3000 + RegionOffset6fc);
        if (func_02046b60(list, 4)) {
            func_ov017_021d079c(tag, 1, 0);
        } else {
            func_ov017_021d079c(tag, 1, 1);
        }
        return;
    }

    int g = MessageSystem_GetInstance();
    if (*(int*)(g + RegionOffset998) != 0) {
        func_ov017_021d079c(tag, 1, 0);
        return;
    }

    unsigned char cur2 = (unsigned char)LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search);
    if (tag < cur2) {
        func_ov017_021d079c(tag, 1, 1);
    } else {
        func_ov017_021d079c(tag, 1, 0);
    }
}
