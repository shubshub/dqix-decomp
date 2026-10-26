#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02175fd4_4088 = 0xf74 };
enum { Enum_ov003_02175fd4_4094 = 0xf7a };
enum { Enum_ov003_02175fd4_2204 = 0x818 };
enum { Enum_ov003_02175fd4_4064 = 0xf5c };
enum { kRegionValue7D8_754 = 0x754 };
#else
enum { Enum_ov003_02175fd4_4088 = 0xff8 };
enum { Enum_ov003_02175fd4_4094 = 0xffe };
enum { Enum_ov003_02175fd4_2204 = 0x89c };
enum { Enum_ov003_02175fd4_4064 = 0xfe0 };
enum { kRegionValue7D8_754 = 0x7d8 };
#endif

struct Struct_0207fdcc_2;
struct Struct_0207fdcc;
extern "C" Struct_0207fdcc* func_02081da8(Struct_0207fdcc_2* obj, int key);

extern "C" int WindowPane_IsOpen(unsigned char* obj);

struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc* o);

extern "C" void func_020809c4(void* obj, int id, int id2, short* out1, short* out2);

struct Struct_020e263c_2;
extern "C" void func_020e263c(struct Struct_020e263c_2* obj, int value);

struct Struct_020e28f0;
extern "C" void func_020e28f0(struct Struct_020e28f0* obj, short a, short b);

extern "C" void SpriteContext_DrawEntries(void* obj);

// USA: func_ov003_02175fd4
extern "C" ARM void func_ov003_02175fd4(unsigned char* self) {
    if (*(void**)(self + Enum_ov003_02175fd4_4088) == NULL) {
        return;
    }
    if (*(short*)(self + Enum_ov003_02175fd4_4094) < 0) {
        return;
    }
    Struct_0207fdcc* elem = func_02081da8(*(Struct_0207fdcc_2**)(self + Enum_ov003_02175fd4_2204), *(short*)(self + Enum_ov003_02175fd4_4094));
    if (elem == NULL) {
        return;
    }
    if (WindowPane_IsOpen((unsigned char*)elem) == 0 || *(void**)(self + 0x0) == NULL) {
        return;
    }
    if (func_020e28dc(*(Struct_020e28dc**)(self + 0x0)) != 0) {
        return;
    }
    short valA, valB;
    func_020809c4(*(Struct_0207fdcc_2**)(self + Enum_ov003_02175fd4_2204), *(short*)(self + Enum_ov003_02175fd4_4094), *(short*)*(void**)(self + Enum_ov003_02175fd4_4088), &valA, &valB);
    func_020e263c(*(Struct_020e263c_2**)(self + 0x0), *(int*)(self + Enum_ov003_02175fd4_4064));
    valA = valA - 0x10;
    valB = valB - 3;
    func_020e28f0(*(Struct_020e28f0**)(self + 0x0), valA, valB);
    SpriteContext_DrawEntries(self + kRegionValue7D8_754);
}
