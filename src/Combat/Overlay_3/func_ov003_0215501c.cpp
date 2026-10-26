#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_0215501c_486 = 0x1e2 };
enum { Enum_ov003_0215501c_476 = 0x1d8 };
#else
enum { Enum_ov003_0215501c_486 = 0x1e6 };
enum { Enum_ov003_0215501c_476 = 0x1dc };
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

// USA: func_ov003_0215501c
extern "C" ARM void func_ov003_0215501c(unsigned char* self) {
    if (*(void**)(self + 8) == NULL) {
        return;
    }
    if (*(short*)(self + Enum_ov003_0215501c_486) < 0) {
        return;
    }
    Struct_0207fdcc* elem = func_02081da8(*(Struct_0207fdcc_2**)(self + 0x18), *(short*)(self + Enum_ov003_0215501c_486));
    if (elem == NULL) {
        return;
    }
    if (WindowPane_IsOpen((unsigned char*)elem) == 0 || *(void**)(self + 0x1c) == NULL) {
        return;
    }
    if (func_020e28dc(*(Struct_020e28dc**)(self + 0x1c)) != 0) {
        return;
    }
    short valA, valB;
    func_020809c4(*(Struct_0207fdcc_2**)(self + 0x18), *(short*)(self + Enum_ov003_0215501c_486), *(short*)*(void**)(self + 8), &valA, &valB);
    func_020e263c(*(Struct_020e263c_2**)(self + 0x1c), *(int*)(self + Enum_ov003_0215501c_476));
    valA = valA - 0x10;
    valB = valB - 3;
    func_020e28f0(*(Struct_020e28f0**)(self + 0x1c), valA, valB);
    SpriteContext_DrawEntries(self + 0x2c);
}
