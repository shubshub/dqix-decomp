#include <globaldefs.h>

struct Struct_ov031_02226f68 { unsigned char pad[0x116]; unsigned char unknown_116_; };
struct Struct_ov031_02250c04_3 { unsigned char field0; unsigned char pad1[3]; Struct_ov031_02226f68* field4; };
extern Struct_ov031_02250c04_3 data_ov031_02250c04;

extern "C" int func_ov031_0221c4bc(void*);

// USA: func_ov031_02226f68
extern "C" ARM int func_ov031_02226f68(void) {
    if (func_ov031_0221c4bc(data_ov031_02250c04.field4) == 0) {
        data_ov031_02250c04.field0 = 1;
        return 1;
    }
    unsigned char v = data_ov031_02250c04.field4->unknown_116_;
    if (v == 1) {
        goto ret0;
    }
    {
        unsigned char w = v + 0xfd;
        if (w > 2) {
            goto ret2;
        }
    }
ret0:
    return 0;
ret2:
    return 2;
}
