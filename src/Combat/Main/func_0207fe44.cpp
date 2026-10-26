#include <globaldefs.h>
extern "C" void func_0204c804(void*);

struct Struct_0207fe44_2 { char b[0xe0]; };

struct Struct_0207fe44 {
#if defined(jpn)
    char pad0[0x24];
#else
    char pad0[0x30];
#endif
    Struct_0207fe44_2* elems;
    char unknown_34_[0x39 - 0x34];
    unsigned char unknown_39_;
};

// USA: func_0207fe44
extern "C" ARM void func_0207fe44(Struct_0207fe44* obj) {
    unsigned char count;
    Struct_0207fe44_2* p = obj->elems;
    unsigned char i;
    if (p == NULL) return;
    count = obj->unknown_39_;
    for (i = 0; i < count; i++) {
        func_0204c804((void*)(p));
        p++;
    }
}
