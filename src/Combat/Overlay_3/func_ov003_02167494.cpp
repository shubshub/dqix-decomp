#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02167494_104 = 0x38 };
enum { Enum_ov003_02167494_116 = 0x44 };
enum { Enum_ov003_02167494_112 = 0x40 };
#else
enum { Enum_ov003_02167494_104 = 0x68 };
enum { Enum_ov003_02167494_116 = 0x74 };
enum { Enum_ov003_02167494_112 = 0x70 };
#endif


struct Struct_0207fc6c;
extern "C" void func_0207fc6c(struct Struct_0207fc6c* obj, int arg);

struct Struct_ov003_02167494 {
    char pad0[0x10];
    void* field10;
    char unknown_14_[Enum_ov003_02167494_104 - 0x14];
    int field68;
    int unknown_6c_;
    char unknown_70_[Enum_ov003_02167494_116 - Enum_ov003_02167494_112];
    unsigned char unknown_74_;
};

// USA: func_ov003_02167494
extern "C" ARM void func_ov003_02167494(struct Struct_ov003_02167494* obj, int arg) {
    if (obj->unknown_74_ == 0 || obj->field10 == 0) return;

    if (arg == 0) arg = 1;
    func_0207fc6c((struct Struct_0207fc6c*)obj->field10, arg);

    *(volatile int*)0x4001010 = 0;

    obj->field68 -= arg << 11;
    obj->unknown_6c_ += arg << 11;

    if (obj->field68 < -0x100000) {
        obj->field68 += 0x100000;
    }
    if (obj->unknown_6c_ > 0x100000) {
        obj->unknown_6c_ -= 0x100000;
    }

    int mask = 0x1ff;
    int var1 = obj->unknown_6c_ >> 12;
    int var2 = mask << 16;
    int hi = var2 & (var1 << 16);
    int lo = mask & (obj->field68 >> 12);
    *(volatile int*)0x4001014 = lo | hi;
}
