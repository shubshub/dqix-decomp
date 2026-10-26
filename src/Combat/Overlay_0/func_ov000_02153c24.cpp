#include <globaldefs.h>
#include "Util/Random.h"

extern "C" void __clear(void* buf, int size);

struct Struct_ov000_02153c24 { char pad[0xa]; unsigned char unknown_a_0_:4; unsigned char kind:4; char pad2[0x18 - 0xa - 1]; };
struct Struct_ov000_02153c24_2 { char pad[0x1b1]; unsigned char unknown_1b1_0_:4; unsigned char limit:2; unsigned char unknown_1b1_6_:2; };

// USA: func_ov000_02153c24
extern "C" ARM void func_ov000_02153c24(void* obj, int* out) {
    struct Struct_ov000_02153c24* table = (struct Struct_ov000_02153c24*)((char*)obj + 0x1b4 + 0x8000);
    int idx = *out;
    if (table[idx].kind != 0) return;

    int buf[3];
    __clear(buf, 0xc);
    int count = 0;
    int i;
    int* bufPtr = buf;
    for (i = 0; i < ((struct Struct_ov000_02153c24_2*)((char*)obj + 0x8000))->limit; i++) {
        if (table[i].kind != 0) {
            bufPtr[count] = i;
            count++;
        }
    }
    int r = NextRandomMax((struct Random*)obj, count);
    *out = bufPtr[r];
}
