#include <globaldefs.h>

extern "C" void func_ov031_0223e2c0(int, void*);
extern "C" ARM void *func_ov031_0223e218(void *a, void *b, void *c, int d);
extern "C" void func_ov031_022384bc(int a);

struct Struct_ov031_02237e58 { unsigned char pad[0x14]; void* field14; };
extern Struct_ov031_02237e58* data_ov031_02290d10;

// USA: func_ov031_02237e58
extern "C" ARM void func_ov031_02237e58(void) {
    func_ov031_0223e2c0(0, data_ov031_02290d10->field14);
    data_ov031_02290d10->field14 = func_ov031_0223e218((void*)1, (void*)func_ov031_022384bc, 0, 0x78);
}
