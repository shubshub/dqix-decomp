#include <globaldefs.h>

extern int data_ov031_02249418;
extern int data_ov031_02290f08;

struct Struct_ov031_0223edb4;
extern "C" int func_ov031_0223ede0(void** out0, void** out1, void* a2, void* a3, int a4, int a5);
extern "C" int func_ov031_0223f188(void* p0, struct Struct_ov031_0223edb4* p1);

struct Struct_ov031_0223f1e8 { unsigned char pad[4]; int field4; unsigned char pad2[8]; int field10; };

// USA: func_ov031_0223f1e8
extern "C" ARM int func_ov031_0223f1e8(int a0) {
    Struct_ov031_0223f1e8* p0;
    struct Struct_ov031_0223edb4* p1;
    int k1 = 0x80;
    int k2 = 0;
    if (func_ov031_0223ede0((void**)&p0, (void**)&p1, &data_ov031_02249418, &data_ov031_02290f08, k1, k2) == 0) {
        return 0;
    }
    p0->field4 = 1;
    p0->field10 = a0;
    int r = func_ov031_0223f188((void*)p0, p1);
    return r != 0;
}
