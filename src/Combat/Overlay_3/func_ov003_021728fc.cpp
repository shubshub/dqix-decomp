#include <globaldefs.h>
#include "Resource/Brightness.h"

#if defined(jpn)
enum { Enum_ov003_021728fc_236 = 0xe8 };
enum { Enum_ov003_021728fc_288 = 0x12c };
enum { Enum_ov003_021728fc_239 = 0xeb };
enum { Enum_ov003_021728fc_250 = 0x108 };
enum { Enum_ov003_021728fc_969 = 0x139 };
#else
enum { Enum_ov003_021728fc_236 = 0xec };
enum { Enum_ov003_021728fc_288 = 0x120 };
enum { Enum_ov003_021728fc_239 = 0xef };
enum { Enum_ov003_021728fc_250 = 0xfa };
enum { Enum_ov003_021728fc_969 = 0x3c9 };
#endif

extern "C" int MessageSystem_GetInstance();

extern "C" int GameState_UpdatePlayClocks(int commit);
struct Struct_02074af4;
extern "C" ARM void func_02074af4(struct Struct_02074af4* obj);
extern "C" void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);
extern "C" int* func_020936f8(void);
extern "C" void func_020941b0(struct Struct_02093b90_2* p);
extern "C" void func_020939dc(void* obj);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);

struct Struct_ov003_021728fc {
    char unknown_0_[Enum_ov003_021728fc_236];
    unsigned char unknown_ec_;
    unsigned char unknown_ed_;
    unsigned char unknown_ee_;
    char unknown_ef_[Enum_ov003_021728fc_288 - Enum_ov003_021728fc_239];
    int unknown_120_;
};

// USA: func_ov003_021728fc
extern "C" ARM void func_ov003_021728fc(Struct_ov003_021728fc* obj) {
    GameResources* field4 = GetGameResources();
    if (obj->unknown_ee_ != 0) return;

    GameState_UpdatePlayClocks(0);
#if defined(jpn)
    *(int*)((char*)obj + 0xf0) = *(int*)(MessageSystem_GetInstance() + 0x28);
#endif
    func_02074af4((struct Struct_02074af4*)((char*)obj + Enum_ov003_021728fc_250));

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    unsigned int v = (*dispcnt & 0x1f00) >> 8;
    obj->unknown_120_ = v;
    unsigned int mask = 4;
    *dispcnt = (*dispcnt & ~0x1f00) | 0x1300;

    volatile unsigned short* bg = (volatile unsigned short*)((char*)dispcnt + 8);
    bg[0] = bg[0] & ~3;
    bg[1] = (bg[1] & ~3) | 1;
    bg[2] = (bg[2] & ~3) | 2;
    bg[3] = (bg[3] & ~3) | 3;
    bg[1] = (bg[1] & 0x43) | 0xf00;

    SetFlags00(field4, mask);
    SetFlags04(field4, 0x8de);

    Set3DClearColor(0, 0, 0x7fff, 0, 0);

    int* g = func_020936f8();
    func_020941b0((struct Struct_02093b90_2*)g);
    ((unsigned char*)g)[Enum_ov003_021728fc_969] = (((unsigned char*)g)[Enum_ov003_021728fc_969] & ~1) | 1;
    func_020939dc(g);

    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x1000);

    obj->unknown_ec_ = 1;
    obj->unknown_ee_ = 0;
}
