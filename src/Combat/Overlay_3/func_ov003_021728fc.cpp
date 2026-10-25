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

int MessageSystem_GetInstance();

int UpdatePlayClocks020ac4f8(int commit);
struct MainBgControlBackup02074af4;
extern "C" ARM void func_02074af4(struct MainBgControlBackup02074af4* obj);
void Set3DClearColor_020c5588(int color, int alpha, int depth, int polygonId, int fogEnable);
int* GetGlobal02109030_020936f8(void);
void ReleaseHandleAndClearFlags(struct Obj020941b0* p);
void ResetAndSetFlag0x3c9Bit0_020939dc(void* obj);
void* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);

struct Struct_ov003_021728fc {
    char unknown_0_[Enum_ov003_021728fc_236];
    unsigned char unknown_ec_;
    unsigned char unknown_ed_;
    unsigned char unknown_ee_;
    char unknown_ef_[Enum_ov003_021728fc_288 - Enum_ov003_021728fc_239];
    int unknown_120_;
};

// USA: func_ov003_021728fc
extern "C" ARM void func_ov003_021728fc(Struct_ov003_021728fc* arg0) {
    GameResources* var0 = GetGameResources();
    if (arg0->unknown_ee_ != 0) return;

    func_020ac4f8(0);
#if defined(jpn)
    *(int*)((char*)obj + 0xf0) = *(int*)(MessageSystem_GetInstance() + 0x28);
#endif
    func_02074af4((struct Struct_02074af4*)((char*)arg0 + Enum_ov003_021728fc_250));

    volatile unsigned int* var1 = (volatile unsigned int*)0x4000000;
    unsigned int var2 = (*var1 & 0x1f00) >> 8;
    arg0->unknown_120_ = var2;
    unsigned int var3 = 4;
    *var1 = (*var1 & ~0x1f00) | 0x1300;

    volatile unsigned short* var4 = (volatile unsigned short*)((char*)var1 + 8);
    var4[0] = var4[0] & ~3;
    var4[1] = (var4[1] & ~3) | 1;
    var4[2] = (var4[2] & ~3) | 2;
    var4[3] = (var4[3] & ~3) | 3;
    var4[1] = (var4[1] & 0x43) | 0xf00;

    SetFlags00(var0, var3);
    SetFlags04(var0, 0x8de);

    func_020c5588(0, 0, 0x7fff, 0, 0);

    int* var5 = func_020936f8();
    func_020941b0((struct Struct_02093b90_2*)var5);
    ((unsigned char*)var5)[Enum_ov003_021728fc_969] = (((unsigned char*)var5)[Enum_ov003_021728fc_969] & ~1) | 1;
    func_020939dc(var5);

    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x1000);

    arg0->unknown_ec_ = 1;
    arg0->unknown_ee_ = 0;
}
