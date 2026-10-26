#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
struct Struct_020e4ce8 {
    unsigned int unknown_0_0_:6, unknown_0_6_:6, unknown_1_4_:6, unknown_2_2_:6, unknown_3_0_:2, unknown_3_2_:1, unknown_3_3_:1, unknown_3_4_:1, reserved:2, flag:1;
};
struct Struct_020e4ce8_2 { int field_0x0; int unknown_4_; union { unsigned int raw; Struct_020e4ce8 bits; } unknown_8_; };
struct Struct_020e4ce8_3 { char pad[0x14]; void* stats; Struct_020e4ce8 bits; };
struct Struct_020e4ce8_4 { char pad[0x144]; Struct_020e4ce8_3* detail; char unknown_148_[4]; char name[1]; };
struct Struct0200fb08;
extern "C" unsigned char GameState_GetLanguage(Struct0200fb08*);
extern "C" int STD_GetStringLength(const char*);
extern "C" void func_020e4b34(void*, const char*, void*, unsigned int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
// USA: func_020e4ce8
extern "C" ARM void func_020e4ce8(Struct_020e4ce8_2* dest, Struct_020e4ce8_4* src, int flag) {
    memset(dest, 0, 12);
    if (src) {
        Struct_020e4ce8_3* detail = src->detail;
        const char* name = src->name;
        func_020e4b34(dest, name, detail->stats, (unsigned char)detail->bits.unknown_0_0_,
            detail->bits.unknown_0_6_, detail->bits.unknown_1_4_, detail->bits.unknown_2_2_,
            detail->bits.unknown_3_0_, detail->bits.unknown_3_2_, detail->bits.unknown_3_3_,
            detail->bits.unknown_3_4_, 0);
        int count = STD_GetStringLength(name);
        int suffix;
        if (count && name[count - 1] >= 'A' && name[count - 1] <= 'Z') suffix = name[count - 1];
        else suffix = 0;
        if (suffix && flag) {
            if (GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance()) == 1) {
                dest->unknown_8_.bits.unknown_1_4_ = 0;
                dest->unknown_8_.bits.unknown_0_0_ = 0;
            }
            dest->unknown_8_.bits.flag = 1;
        }
    }
}
