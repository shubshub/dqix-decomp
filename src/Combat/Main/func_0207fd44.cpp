#include <globaldefs.h>
#if defined(jpn)
enum { Enum_0207fd44_44 = 0x20 };
#else
enum { Enum_0207fd44_44 = 0x2c };
#endif

extern "C" void Background_FlushMap(void* p, int flag);

struct Struct_0207fd44 { char b[0x20]; };

struct Struct_0207fd44_2 {
    char pad0[Enum_0207fd44_44];
    Struct_0207fd44* unknown_2c_;
    char unknown_30_[0x38 - 0x30];
    unsigned char unknown_38_;
};

// USA: func_0207fd44
extern "C" ARM void func_0207fd44(Struct_0207fd44_2* obj) {
    unsigned char count;
    Struct_0207fd44* p = obj->unknown_2c_;
    unsigned char i;
    if (p == NULL) return;
    count = obj->unknown_38_;
    for (i = 0; i < count; i++) {
        Background_FlushMap(p, 0);
        p++;
    }
}
