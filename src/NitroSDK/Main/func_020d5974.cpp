#include <globaldefs.h>

extern "C" int func_020d5900(int, void*);

extern "C" void func_020ca3ec(int value, void* dst, int size);

struct Struct_020d5974 {
    unsigned int size;
    unsigned char pad4[0xe];
    unsigned short a;
    unsigned short b;
    unsigned char pad16[0x6];
};

// USA: func_020d5974
extern "C" ARM int func_020d5974(void* obj, int a, int b) {
    Struct_020d5974 p;
    func_020ca3ec(0, &p, 0x1c);
    p.size = 0x180;
    p.a = a;
    p.b = b;
    return func_020d5900((int)(obj), (void*)(&p));
}
