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
extern "C" Struct_0207fdcc* func_02081da8(Struct_0207fdcc_2* arg0, int arg1);

int WindowPane_IsOpen(unsigned char* obj);

struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc* arg0);

extern "C" void func_020809c4(void* arg0, int arg1, int arg2, short* arg3, short* arg4);

struct Struct_020e263c_2;
extern "C" void func_020e263c(struct Struct_020e263c_2* arg0, int arg1);

struct Struct_020e28f0;
extern "C" void func_020e28f0(struct Struct_020e28f0* arg0, short arg1, short arg2);

extern "C" void SpriteContext_DrawEntries(void* obj);

// USA: func_ov003_0215501c
extern "C" ARM void func_ov003_0215501c(unsigned char* arg0) {
    if (*(void**)(arg0 + 8) == NULL) {
        return;
    }
    if (*(short*)(arg0 + Enum_ov003_0215501c_486) < 0) {
        return;
    }
    Struct_0207fdcc* var0 = func_02081da8(*(Struct_0207fdcc_2**)(arg0 + 0x18), *(short*)(arg0 + Enum_ov003_0215501c_486));
    if (var0 == NULL) {
        return;
    }
    if (WindowPane_IsOpen((unsigned char*)elem) == 0 || *(void**)(self + 0x1c) == NULL) {
        return;
    }
    if (func_020e28dc(*(Struct_020e28dc**)(arg0 + 0x1c)) != 0) {
        return;
    }
    short valA, valB;
    GetLookAndTurnOffsets020809c4(*(Obj2081**)(self + 0x18), *(short*)(self + kRegionValue1E6_1E2), *(short*)*(void**)(self + 8), &valA, &valB);
    UpdateEntryStateAndPosition(*(Ctx020e263c**)(self + 0x1c), *(int*)(self + kRegionValue1DC_1D8));
    valA = valA - 0x10;
    valB = valB - 3;
    SetEntryPositionFromObject(*(WinObj020e28f0**)(self + 0x1c), valA, valB);
    SpriteContext_DrawEntries(self + 0x2c);
}
