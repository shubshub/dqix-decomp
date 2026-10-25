#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
struct Struct_020e4ce8 {
    unsigned int unknown_0_0_:6, unknown_0_6_:6, unknown_1_4_:6, unknown_2_2_:6, unknown_3_0_:2, unknown_3_2_:1, unknown_3_3_:1, unknown_3_4_:1, unknown_3_5_:2, unknown_3_7_:1;
};
struct Description020e4ce8 { int field_0x0; int field_0x4; union { unsigned int raw; Packed020e4ce8 bits; } field_0x8; };
struct Detail020e4ce8 { char pad[0x14]; void* stats; Packed020e4ce8 bits; };
struct Source020e4ce8 { char pad[0x144]; Detail020e4ce8* detail; char pad148[4]; char name[1]; };
struct Struct0200fb08;
unsigned char GameState_GetLanguage(Struct0200fb08*);
int STD_GetStringLength(const char*);
extern "C" void func_020e4b34(void*, const char*, void*, unsigned int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
// USA: func_020e4ce8
extern "C" ARM void func_020e4ce8(Description020e4ce8* dest, Source020e4ce8* src, int flag) {
    memset(dest, 0, 12);
    if (src) {
        Detail020e4ce8* detail = src->detail;
        const char* name = src->name;
        func_020e4b34(dest, name, detail->stats, (unsigned char)detail->bits.field_0x0_0,
            detail->bits.field_0x0_6, detail->bits.field_0x0_12, detail->bits.field_0x0_18,
            detail->bits.field_0x0_24, detail->bits.field_0x0_26, detail->bits.field_0x0_27,
            detail->bits.field_0x0_28, 0);
        int count = STD_GetStringLength(name);
        int suffix;
        if (count && name[count - 1] >= 'A' && name[count - 1] <= 'Z') suffix = name[count - 1];
        else suffix = 0;
        if (suffix && flag) {
            if (GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance()) == 1) {
                dest->field_0x8.bits.field_0x0_12 = 0;
                dest->field_0x8.bits.field_0x0_0 = 0;
            }
            arg0->unknown_8_.unknown1_0_.unknown_3_7_ = 1;
        }
    }
}
