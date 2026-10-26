#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov000_02174c14_7520 = 0x1f98, Enum_ov000_02174c14_7528 = 0x1fa0, Enum_ov000_02174c14_7538 = 0x1faa };
#else
enum { Enum_ov000_02174c14_7520 = 0x1d60, Enum_ov000_02174c14_7528 = 0x1d68, Enum_ov000_02174c14_7538 = 0x1d72 };
#endif
#include "std_library_functions.h"

struct Entry_0205d6a0;
extern "C" void Window_ClosePane(struct Entry_0205d6a0* a, int flag);
extern "C" int func_ov000_021719f8(int* obj);
extern "C" void func_0204c804(void* obj);

struct Struct_ov000_02174c14 {
    char pad0[0xc];
    short fieldC;
    char pad1[0x44 - 0xe];
    int posX;
    int unknown_48_;
    int field4c;
#if defined(jpn)
    char pad2[0xc7 - 0x50];
#else
    char pad2[0x87 - 0x50];
#endif
    unsigned char unknown_87_;
    char pad3[0x448 - 0x88];
};

struct Struct_ov000_02174c14_2 {
    char pad0[0xac];
    short x;
    short y;
    char pad1[0xc2 - 0xb0];
    short unknown_c2_;
};

// USA: func_ov000_02174c14
extern "C" ARM void func_ov000_02174c14(char* obj) {
    struct Struct_ov000_02174c14* c;
    int i;

    Window_ClosePane((struct Entry_0205d6a0*)(obj + 0x188), 1);
    memset(obj + Enum_ov000_02174c14_7520, 0, 8);
    *(signed char*)(obj + Enum_ov000_02174c14_7528) = 0;
    (obj + *(signed char*)(obj + Enum_ov000_02174c14_7528))[Enum_ov000_02174c14_7520] = 1;

    for (i = 0; i < 4; i++) {
        c = (struct Struct_ov000_02174c14*)(obj + 0x958) + *(signed char*)(obj + 0x6c + i);
        if (c->field4c < 0) continue;
        if (c->fieldC == 0) continue;
        if (func_ov000_021719f8((int*)c)) continue;
        if (c->unknown_87_ == 0) continue;

        struct Struct_ov000_02174c14_2* elem = (struct Struct_ov000_02174c14_2*)(obj + 0x284);
        int x = c->posX;
        int y = c->unknown_48_;
        func_0204c804(elem);
        elem->x = (x >> 3) + 9;
        elem->y = y >> 3;
        elem->unknown_c2_ = 0;
        *(unsigned short*)(obj + Enum_ov000_02174c14_7538) |= 2;
        return;
    }
}
