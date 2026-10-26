#include <globaldefs.h>

struct Struct_020e1568;
extern "C" void func_020e1354(unsigned char* p);
extern "C" void func_020e1568(struct Struct_020e1568* s);

// USA: func_020e1588
extern "C" ARM void func_020e1588(unsigned char* p) {
    *(int*)(p + 0x0) = 0;
    *(int*)(p + 0x4) = 0;
    *(int*)(p + 0x8) = 0;
    func_020e1354(p + 0xc);
    func_020e1354(p + 0x18);
    func_020e1568((struct Struct_020e1568*)(p + 0x24));
    *(int*)(p + 0x30) = 0;
    *(int*)(p + 0x34) = 0;
    p[0x39] = 0;
    p[0x38] = 0;
    p[0x3b] = 0;
    p[0x3a] = 0;
    p[0x3c] = 0;
    p[0x3d] = 0;
    p[0x3e] = 0;
    struct Struct_020e1588 { unsigned char bit0 : 1; unsigned char unknown_0_1_ : 1; unsigned char rest : 6; };
    struct Struct_020e1588* f = (struct Struct_020e1588*)(p + 0x3f);
    f->bit0 = 0;
    f->unknown_0_1_ = 0;
}
