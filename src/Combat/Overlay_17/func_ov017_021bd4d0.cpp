#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_020dc548(int a, signed char* arr, signed char* count);

struct Obj_021bd3a4;
extern "C" int func_ov017_021bd3a4(struct Obj_021bd3a4* obj);
struct U16Field0x6_020375f8;

struct Struct_ov017_021bd4d0 {
    unsigned char pad0[0x16];
    unsigned short unknown_16_;
#if defined(jpn)
    unsigned char pad1[0xfd - 0x18];
#else
    unsigned char pad1[0x101 - 0x18];
#endif

    unsigned char unknown_101_;
};

// USA: func_ov017_021bd4d0
extern "C" ARM void func_ov017_021bd4d0(struct Struct_ov017_021bd4d0* obj, int id, int arg2, int arg3) {
    GameState* battleStruct;
    GameObject* combatant;
    GameObject* combatant2;
    signed char arr[7];
    signed char count;
    int i;
    int keep;
    unsigned short g;
    unsigned short u;

    battleStruct = GameState::GetInstance();
    combatant = battleStruct->GetPartyMemberByIndex(id);
    if (combatant != 0) {
        keep = 1;
        g = *(unsigned short*)Zone3D_GetInstance();
        u = ((Object3D*)((struct U16Field0x6_020375f8*)combatant))->GetField06();
        if (u != g) {
            if (arg2 == 0) {
                keep = 0;
            }
        }
        if (func_ov017_021bd3a4((struct Obj_021bd3a4*)obj)) {
            if (obj->unknown_16_ == 0x2972 || obj->unknown_101_ == 0) {
                arg3 = 0;
            }
        }
        if (keep != 0) {
            if (arg3 == 0 || !func_ov017_021bd3a4((struct Obj_021bd3a4*)obj)) {
                func_020dc548((signed char)id, arr, &count);
                for (i = 0; i < count; i++) {
                    combatant2 = battleStruct->GetPartyMemberByIndex(arr[i]);
                    if (combatant2 != 0) {
                        if (arg2) {
                            ((Object3D*)((unsigned char*)combatant2))->MakeVisible();
                        } else {
                            ((Object3D*)((unsigned char*)combatant2))->MakeHidden();
                        }
                    }
                }
            }
        }
    }
}
