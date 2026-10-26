#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov003_021580d8_512 = 0x118 };
#else
enum { Enum_ov003_021580d8_512 = 0x200 };
#endif

extern "C" int STD_GetStringLength(const char* s);
extern char data_ov003_0217fce0;

struct Struct_ov003_021580d8 {
    int field0;
    char* field4;
    int field8;
    char blockA[0x38];
    char blockB[0x200];
};

struct Struct_ov003_021580d8_2 {
    int f0;
    char* f4;
    int f8;
};

// USA: func_ov003_021580d8
extern "C" ARM void func_ov003_021580d8(struct Struct_ov003_021580d8* dst, struct Struct_ov003_021580d8_2* src) {
    char* text;
    if (src == 0) {
        return;
    }
    dst->field0 = src->f0;
    dst->field4 = src->f4;
    dst->field8 = src->f8;
    dst->field4 = dst->blockB;
    text = src->f4;
    if (text == 0) {
        return;
    }
    memset(dst->blockB, 0, Enum_ov003_021580d8_512);
    sprintf(dst->blockB + STD_GetStringLength(dst->blockB), &data_ov003_0217fce0, text);
}
