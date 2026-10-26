#include <globaldefs.h>

struct Struct_0208df10;
extern "C" void func_0208df10(struct Struct_0208df10* l);
struct Struct_020727d8;
extern "C" void func_020727d8(struct Struct_020727d8* list);
struct BackgroundGraphics;
extern "C" void Background_Init(struct BackgroundGraphics* obj);
struct Struct_02074af4;
extern "C" void func_02074af4(struct Struct_02074af4* obj);
struct Struct_02074b64;
extern "C" void func_02074b64(struct Struct_02074b64* obj);

// USA: func_ov013_02186eec
extern "C" ARM void func_ov013_02186eec(void* obj, unsigned char flag) {
    unsigned char* o = (unsigned char*)obj;
    unsigned int v;
#if defined(jpn)
    enum { stateOffset = 0x48, Enum_ov013_02186eec_96 = 0x4c, flagOffset = 0x50 };
#else
    enum { stateOffset = 0x5c, Enum_ov013_02186eec_96 = 0x60, flagOffset = 0x64 };
#endif

    *(int*)(o + 0x0) = 0;
    func_0208df10((struct Struct_0208df10*)(o + 0xc));
    func_020727d8((struct Struct_020727d8*)(o + 0x4));
    o[0x24] = 0;
    o[0x25] = 0;
    Background_Init((struct BackgroundGraphics*)(o + 0x28));
    *(int*)(o + stateOffset) = -1;
    o[flagOffset] = flag;
    o[flagOffset + 1] = 0;
    o[flagOffset + 2] = 0;
    *(signed char*)(o + flagOffset + 3) = -1;
    o[flagOffset + 4] = 0;
    o[flagOffset + 5] = 0;
#if !defined(jpn)
    *(int*)(o + 0x48) = 0;
    *(int*)(o + 0x4c) = 0;
    *(int*)(o + 0x50) = 0;
    *(int*)(o + 0x54) = 0;
    *(int*)(o + 0x58) = 0;
    *(signed char*)(o + 0x6a) = -1;
#endif

    if (o[flagOffset] == 0) {
        func_02074af4((struct Struct_02074af4*)(o + 0x14));
        v = *(volatile unsigned int*)0x4000000;
    } else {
        func_02074b64((struct Struct_02074b64*)(o + 0x14));
        v = *(volatile unsigned int*)0x4001000;
    }
    *(int*)(o + Enum_ov013_02186eec_96) = (v & 0x1f00) >> 8;
}
