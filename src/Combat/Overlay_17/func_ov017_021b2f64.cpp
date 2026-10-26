#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

struct Struct_ov017_021b2f64 {
    unsigned char pad0[0x10];
    int arr[14];
};

// USA: func_ov017_021b2f64
extern "C" ARM void func_ov017_021b2f64(unsigned char* self) {
    func_0204693c((struct ByteHeader0204693c*)self);
    self[0] = 0x13;
    *(short*)(self + 8) = 0x13 - 0x14;
    self[0xa] = 0;
    self[0xb] = 0;
    *(int*)(self + 0xc) = 0;
    Struct_ov017_021b2f64* obj = (Struct_ov017_021b2f64*)self;
    for (int i = 0; i < 14; i++) {
        obj->arr[i] = 0x13 - 0x14;
    }
}
