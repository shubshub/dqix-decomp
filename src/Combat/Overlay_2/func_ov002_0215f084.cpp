#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_020dd290(void *arg0, unsigned int arg1);
extern "C" void *MessageSystem_GetInstance();
extern "C" void func_02046380();
struct StoreStruct;
extern "C" void func_020465c0(StoreStruct*, int, int);
struct Container020e0310;
extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" void MessageSystem_FormatText(void *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6);

#if defined(jpn)
#define RG(u, j) (j)
extern "C" void func_020465f0(StoreStruct*, int, unsigned char);
extern "C" void func_020465d8(StoreStruct*, int, unsigned char);
extern "C" void func_020474a8(void *arg0, int arg1, int arg2, int arg3);
#else
#define RG(u, j) (u)
#endif

struct Struct_020fdcb0 { int unknown_0_; int unknown_4_; char unknown_8_[0x18]; };
extern Struct_020fdcb0 data_020fdcb0[];

// USA: func_ov002_0215f084
extern "C" ARM void func_ov002_0215f084(void *arg0, int arg1) {
    if (arg1 == 0) {
        return;
    }
    char *var0 = (char*)arg0;
    void *var1 = GameState::GetInstance();
    signed char var2 = *(signed char*)(var0 + RG(0x1c20, 0x1ae8));
    void *var3 = ((GameState*)var1)->GetPartyMemberByIndex(var2);
    if (var3 == 0) {
        return;
    }
    short var4 = *(short*)(var0 + RG(0x1bfa, 0x1ac2));
    void *var5 = 0;
    if (var4 >= 0) {
        if (var4 < 0x20) {
            var5 = *(void**)(var0 + 0x2000 + var4 * 4 + RG(0x4a0, 0x2d0));
        }
    }
    if (var5 == 0) {
        return;
    }
    struct Struct_ov002_0215f084 { unsigned int unknown_0_0_ : 8; unsigned int unknown_1_0_ : 24; };
    unsigned int var6 = ((Struct_ov002_0215f084*)((char*)var5 + 8))->unknown_0_0_;
    int var7 = func_020dd290(var3, var6);
    short var8 = *(short*)((char*)var3 + 4);
    Struct_020fdcb0 *var9 = &data_020fdcb0[var8];
    void *var10 = MessageSystem_GetInstance();
    func_02046380();
    func_020465c0((StoreStruct*)var10, 0, var7);
#if defined(jpn)
    func_020465f0((StoreStruct*)var10, 0, 3);
    func_020465d8((StoreStruct*)var10, 0, 1);
#endif
    func_020465c0((StoreStruct*)var10, 1, var9->unknown_4_);
#if defined(jpn)
    func_020465f0((StoreStruct*)var10, 1, 3);
    func_020465d8((StoreStruct*)var10, 1, 0);
#endif
    int var11 = KeyTable_Get((Container020e0310*)(var0 + RG(0x20, 0x8)), 0xbb8);
#if defined(jpn)
    func_020474a8(var10, 0xa, var11, arg1);
#else
    MessageSystem_FormatText(var10, 0xa, var11, arg1, 0x100, 0, 0);
#endif
}
