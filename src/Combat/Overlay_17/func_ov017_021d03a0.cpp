#if defined(jpn)
enum { Enum_ov017_021d03a0_17237 = 0x4135 };
#else
enum { Enum_ov017_021d03a0_17237 = 0x4355 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_020dc548(int a, signed char* arr, signed char* count);
extern "C" void func_0203979c(unsigned char* obj, unsigned int mask);
extern "C" int func_02039790(void* obj, int mask);
extern "C" void func_020397ac(unsigned char* obj, unsigned int mask);

struct Struct_ov017_021d03a0 {
    unsigned char pad0[4];
    unsigned char flag4;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
};

// USA: func_ov017_021d03a0
extern "C" ARM void func_ov017_021d03a0(int bit, struct Struct_ov017_021d03a0* tag, GameState* battleStruct, unsigned char* base) {
    GameObject* combatant;
    GameObject* c2;
    signed char arr[7];
    signed char count;
    int i;

    combatant = battleStruct->GetPartyMemberByIndex(tag->unknown_5_);
    if (combatant == 0) {
        return;
    }
    if (tag->flag4 != 0) {
        ((Object3D*)((unsigned char*)combatant))->EnableFlag(0x400);
        if (tag->unknown_6_ != 0) {
            func_0203979c((unsigned char*)combatant, 0x20);
        }
        return;
    }

    func_020dc548((signed char)bit, arr, &count);
    for (i = 0; i < count; i++) {
        c2 = battleStruct->GetPartyMemberByIndex(arr[i]);
        if (c2 != 0) {
            ((Object3D*)((unsigned char*)c2))->DisableFlag(0x400);
            if (func_02039790((void*)c2, 0x20) != 0) {
                func_020397ac((unsigned char*)c2, 0x20);
                *(base + Enum_ov017_021d03a0_17237) |= 1 << (bit & 0xff);
            }
        }
    }
}
