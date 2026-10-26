#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { Enum_ov004_021654a8_2292=0x9f4,Enum_ov004_021654a8_6144=0x1900 };
#else
enum { Enum_ov004_021654a8_2292=0x8f4,Enum_ov004_021654a8_6144=0x1800 };
#endif

extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" unsigned int func_ov023_021f6f10(void* self);
#define NODE_KIND_CALL func_ov023_021f6f10
#else
extern "C" int func_ov024_021f6f10(void* self);
#define NODE_KIND_CALL func_ov024_021f6f10
#endif
struct Struct_ov004_02164670;
extern char* data_ov004_02171010;
struct Struct_ov004_0216351c;
extern "C" void func_ov004_0216351c(struct Struct_ov004_0216351c* src, short* out1, short* out2);
extern "C" void func_ov004_02164084(void* a1);

// USA: func_ov004_021654a8
extern "C" ARM int func_ov004_021654a8(void* a1) {
    GameState::GetInstance();
    struct Struct_ov004_02164670* axis = ((struct Struct_ov004_02164670*)GetGameResources());
    void* obj = func_ov023_021f6880(func_ov011_021849c8(a1), 0xa);
    if (obj == NULL) return 0;
    if (NODE_KIND_CALL(obj) != 7) return 0;

    unsigned char count = *(unsigned char*)(data_ov004_02171010 + 0x1000 + Enum_ov004_021654a8_2292);
    if (count <= 8) goto fastpath;
    if (IsBrightnessZero((GameResources*)axis, false) != 0) goto swappath;

fastpath: {
    char* base = data_ov004_02171010 + Enum_ov004_021654a8_6144;
    short f8 = *(short*)(base + 0xf8);
    short var5 = *(short*)(base + 0xf6);
    *(short*)((char*)obj + 0x5c) = var5;
    *(short*)((char*)obj + 0x5e) = f8;
    return 0;
}

swappath: {
    char* base2 = data_ov004_02171010;
    short* p1 = (short*)(base2 + 0xf6 + Enum_ov004_021654a8_6144);
    #if defined(jpn)
    short* p2 = (short*)(base2 + 0x1f8 + 0x1800);
#else
    short* p2 = (short*)(base2 + 0xf8 + Enum_ov004_021654a8_6144);
#endif
    func_ov004_0216351c((struct Struct_ov004_0216351c*)obj, p1, p2);
    func_ov004_02164084(a1);
    return 0;
}
}
