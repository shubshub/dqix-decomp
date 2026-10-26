#include <globaldefs.h>

struct Struct_ov031_022063ec_2 { char pad[0x100]; unsigned short head; unsigned short tail; };
struct Struct_ov031_022063ec { char pad[0x68]; Struct_ov031_022063ec_2* unknown_68_; };

// USA: func_ov031_022063ec
extern "C" ARM int func_ov031_022063ec(Struct_ov031_022063ec* obj) {
    Struct_ov031_022063ec_2* var0 = obj->unknown_68_;
    int capacity = *(int*)((char*)var0 + 0xf8);
    volatile unsigned short* var2 = &var0->head;
    unsigned short head = *var2;
    int diff = var0->tail - head - 1;
    if (diff < 0) diff += capacity;
    return diff;
}
