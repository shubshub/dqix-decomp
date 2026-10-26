#if defined(jpn)
enum { RegionOffset2a8 = 0x224, Enum_ov025_021dc590_16644 = 0x40c0, Enum_ov025_021dc590_16568 = 0x4074, Enum_ov025_021dc590_1096 = 0x488 };
#else
enum { RegionOffset2a8 = 0x2a8, Enum_ov025_021dc590_16644 = 0x4104, Enum_ov025_021dc590_16568 = 0x40b8, Enum_ov025_021dc590_1096 = 0x448 };
#endif

#include <globaldefs.h>

extern "C" void* func_ov000_02160f20(void* obj);
extern "C" void func_ov025_021e9778(void* obj);
extern "C" int func_ov025_021e9528(char* obj);
extern "C" int func_ov025_021dc940(void* obj);
extern "C" void func_ov025_021e9558(void* obj);
extern "C" ARM void func_ov025_021def30(unsigned char* obj);

struct Struct_ov025_021dc590 {
    char pad0[0x20];
    unsigned short id;
};

struct Struct_ov025_021dc590_2 {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

struct Struct_ov025_021dc590_3 {
    char pad0[0xb];
    struct Struct_ov025_021dc590_2 flags;
    char pad1[4];
    struct Struct_ov025_021dc590* node;
};

// USA: func_ov025_021dc590
extern "C" ARM void func_ov025_021dc590(void* obj) {
    struct Struct_ov025_021dc590_3* slot = (struct Struct_ov025_021dc590_3*)func_ov000_02160f20(obj);
    func_ov025_021e9778((char*)obj + RegionOffset2a8);
    if (!func_ov025_021e9528((char*)obj + RegionOffset2a8)) {
        return;
    }
    if (!func_ov025_021dc940(obj)) {
        return;
    }
    func_ov025_021e9558((char*)obj + RegionOffset2a8);

    struct Struct_ov025_021dc590* node = slot->node;
    if (node != NULL) {
        int id = node->id;
        int flag1 = (id >= 0 && id <= 3) ? 1 : 0;
        if (flag1) {
            void* result;
            int flag2 = (id >= 0 && id <= 3) ? 1 : 0;
            if (flag2) {
                for (int i = 0; i < 4; i++) {
                    int cur = *(int*)((char*)obj + i * Enum_ov025_021dc590_1096 + Enum_ov025_021dc590_16644);
                    if (id == cur) {
                        result = (char*)obj + Enum_ov025_021dc590_16568 + i * Enum_ov025_021dc590_1096;
                        goto found;
                    }
                }
            }
            result = 0;
            found:
            if (result != 0) {
                if (slot->flags.bit2 == 0) {
                    signed char off = *(signed char*)((char*)result + 0x18);
                    *((unsigned char*)result + off + 0x10) = 0x66;
                }
            }
        }
    }
    func_ov025_021def30((unsigned char*)obj);
}
