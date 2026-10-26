#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e82a0_12 = 0x4 };
#else
enum { Enum_ov025_021e82a0_12 = 0xc };
#endif

struct Struct_ov025_021ef988_35 {
    char pad[Enum_ov025_021e82a0_12];
    void* ptr;
};

extern Struct_ov025_021ef988_35 data_ov025_021ef988;

struct Struct_ov025_021e82a0 {
    char pad1[0x8];
    short a;
    short b;
    short c;
    unsigned char d;
};

// USA: func_ov025_021e82a0
extern "C" ARM int func_ov025_021e82a0(struct Struct_ov025_021e82a0* obj) {
    char* p = (char*)data_ov025_021ef988.ptr + 0x540;
    *(unsigned short*)(p + 0x28) |= 2;
    *(unsigned char*)(p + 0x35) = obj->d;
    *(short*)(p + 0x2e) = obj->a;
    *(short*)(p + 0x30) = obj->b;
    *(short*)(p + 0x32) = obj->c;
    return 1;
}
