#include <globaldefs.h>
#if defined(jpn)
enum { Enum_0207fdf0_48 = 0x24 };
#else
enum { Enum_0207fdf0_48 = 0x30 };
#endif

extern "C" void func_0204c804(void*);

struct Struct_0207fdf0 { char pad[0xc4]; unsigned char key; char pad2[0x1b]; };

struct Struct_0207fdf0_2 {
    char pad0[Enum_0207fdf0_48];
    Struct_0207fdf0* elems;
    char unknown_34_[0x39 - 0x34];
    unsigned char unknown_39_;
};

// USA: func_0207fdf0
extern "C" ARM void func_0207fdf0(Struct_0207fdf0_2* obj, int key) {
    unsigned char count;
    unsigned char i;
    if (obj->elems == NULL) return;
    count = obj->unknown_39_;
    for (i = 0; i < count; i++) {
        if (key != obj->elems[i].key) {
            func_0204c804((void*)(&obj->elems[i]));
        }
    }
}
