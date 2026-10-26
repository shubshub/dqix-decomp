#include <globaldefs.h>

struct Struct_ov023_021f8960 {
    char pad[0xc];
    short a;
    short b;
};

// USA: func_ov023_021f8960
extern "C" ARM void func_ov023_021f8960(char* base, short a, unsigned short b) {
    struct Struct_ov023_021f8960 *obj = (struct Struct_ov023_021f8960 *)(base + 0x100);
    obj->a = a;
    obj->b = b;
}
