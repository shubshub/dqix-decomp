#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021dc0d8_668 = 0x218, Enum_ov025_021dc0d8_22865 = 0x5b41 };
#else
enum { Enum_ov025_021dc0d8_668 = 0x29c, Enum_ov025_021dc0d8_22865 = 0x5951 };
#endif

struct Struct_ov000_0215440c_2;
struct Struct_ov000_02160094;

extern "C" void* func_ov000_02160f20(void* obj);
extern "C" struct Struct_ov000_02160094* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int index);
extern "C" int func_ov000_0215fc60(char* base);
extern "C" void func_ov025_021dfce0(void* obj);
extern "C" int func_ov025_021dffac(void* obj);
extern "C" void func_ov025_021e0638(void* obj);

struct Struct_ov025_021dc0d8 {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char bit2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

// USA: func_ov025_021dc0d8
extern "C" ARM void func_ov025_021dc0d8(void* obj) {
    void* base = *(void**)((char*)obj + Enum_ov025_021dc0d8_668);
    void* slot = func_ov000_02160f20(obj);
    func_ov025_021dfce0(obj);
    if (func_ov000_0215fc60((char*)base) != 0) {
        struct Struct_ov000_02160094* node = func_ov000_02160094((struct Struct_ov000_0215440c_2*)slot, 0);
        if (node != NULL) {
            if (*(unsigned short*)((char*)node + 0x20) == 0) {
                return;
            }
        }
    }
    {
        int result = func_ov025_021dffac(obj);
        unsigned char var4 = (unsigned char)result;
        struct Struct_ov025_021dc0d8* flags = (struct Struct_ov025_021dc0d8*)((char*)obj + Enum_ov025_021dc0d8_22865);
        flags->bit2 = var4;
        if (flags->bit2 != 1) {
            return;
        }
    }
    func_ov025_021e0638(obj);
}
