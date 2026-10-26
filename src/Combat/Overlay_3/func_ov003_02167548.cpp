// USA: func_ov003_02167548
#include <globaldefs.h>

struct Struct_0207fcb8;
extern "C" void func_0207fcb8(Struct_0207fcb8* obj);
struct Struct_0207fd00;
extern "C" void func_0207fd00(Struct_0207fd00* obj);
struct Struct_0207fd44_2;
extern "C" void func_0207fd44(Struct_0207fd44_2* obj);

struct Struct_ov003_02160134 {
    char pad0[0x10];
    void* field10;
#if defined(jpn)
    char unknown_14_[0x44 - 0x14];
#else
    char unknown1_14_[0x74 - 0x14];
#endif
    unsigned char unknown_74_;
};

extern "C" ARM void func_ov003_02167548(Struct_ov003_02160134* obj) {
    if (obj->unknown_74_ && obj->field10) {
        func_0207fcb8((Struct_0207fcb8*)obj->field10);
        func_0207fd00((Struct_0207fd00*)obj->field10);
        func_0207fd44((Struct_0207fd44_2*)obj->field10);
    }
}
