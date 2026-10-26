#if defined(jpn)
enum { Enum_ov017_021cbcc0_1816 = 0x508 };
#else
enum { Enum_ov017_021cbcc0_1816 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" void func_ov000_02160fa8(void* work, int mask);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_ov000_0216872c(void* obj, int a, int b);
extern "C" void __clear(void* buf, int len);
extern "C" void func_ov017_021b848c(void* h, void* buf, int a, int b, int c, int d, int e, int f);

struct Struct_ov017_021cbcc0 {
    unsigned char pad0[8];
    unsigned short field8;
};

struct Struct_ov017_021cbcc0_2 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned int field8;
    unsigned char unknown_c_;
    signed char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    signed char unknown_10_;
    unsigned char pad1;
    signed short unknown_12_;
};

// USA: func_ov017_021cbcc0
extern "C" ARM void func_ov017_021cbcc0(int unused0, Struct_ov017_021cbcc0_2* evt, GameState* battleStruct, unsigned char* base) {
    unsigned short f4;
    unsigned short var1;
    unsigned int var2;
    unsigned char var3;
    unsigned char var4;
    Struct_ov017_021cbcc0* a;
    void* var6;
    void* var7;
    void* table = *(void**)(base + 0x3000 + Enum_ov017_021cbcc0_1816);
    a = (Struct_ov017_021cbcc0*)func_ov017_021b8478(table);
    if (!a) return;
    var6 = func_ov017_021b8470(table);
    if (!var6) return;
    var7 = func_ov017_021b8468(table);
    if (!var7) return;

    f4 = evt->field4;
    var1 = a->field8;
    var2 = evt->field8;
    var3 = evt->unknown_e_;
    var4 = evt->unknown_f_;
    if (f4 != var1) return;

    func_ov000_02160fa8(var7, 0x80000000);
    int idx = GameState_GetProtagonistIndex(battleStruct);
    if (!(evt->unknown_c_ & (1 << idx))) return;

    *(unsigned char*)((char*)var6 + 0x8e48) = (unsigned char)var2;
    func_ov000_0216872c(var7, var3, var4);

    unsigned char buf[4];
    __clear(buf, 4);
    for (int i = 0; i < 4; i++) {
        if (evt->unknown_c_ & (1 << i)) buf[i] = 1;
        else buf[i] = 0;
    }
    func_ov017_021b848c(table, buf, evt->unknown_d_, 1, evt->field6, evt->unknown_10_, 1, evt->unknown_12_);
}
