#include <globaldefs.h>
#if defined(jpn)
#define data_ov004_0216fffa data_ov004_02170752
#define data_ov004_0216fff8 data_ov004_02170750
struct Struct_ov004_021680cc;
struct Struct_ov004_021680cc_2 { char unknown_0_[0xe0]; void (*unknown_e0_)(Struct_ov004_021680cc*, int); };
struct Struct_ov004_021680cc { Struct_ov004_021680cc_2* unknown_0_; };
#endif
#include "GameState/GameState.h"

struct Obj02086aec;
short Party_CountItem(struct Obj02086aec* obj, int key);
extern "C" void func_ov023_021f64a8(void* obj, int id, int argE0, int argD8);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* arg0);
#define func_ov024_021f6f10 func_ov023_021f6f10
#else
extern "C" int func_ov024_021f6f10(void* arg0);
#endif
extern "C" int func_ov004_02167908(void* a, int key);
struct ItemTable;
struct Element020de650 { char pad[4]; int field4; };
struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern "C" void func_ov023_021f809c(void* obj, void* param2);

extern short data_ov004_0216fffa;
extern short data_ov004_0216fff8;

// USA: func_ov004_021680cc
extern "C" ARM int func_ov004_021680cc(void* a) {
    short matches = Party_CountItem((struct Obj02086aec*)GameState_GetParty(GameState::GetInstance()), 0x5617);
#if defined(jpn)
    {
        Struct_ov004_021680cc* var1 = (Struct_ov004_021680cc*)func_ov023_021f6880(func_ov011_021849c8(arg0), 0x2b);
        if (var1) var1->unknown_0_->unknown_e0_(var1, var0);
    }
#else
    func_ov023_021f64a8(arg0, 0x2b, var0, 0xf);
#endif

    unsigned char* var2;
    void* var3;
    unsigned char* var4;
    var3 = func_ov011_021849c8(arg0);
    var2 = (unsigned char*)func_ov023_021f6880(var3, 0xc);
    if (!var2) return 0;
    if (func_ov024_021f6f10(var2) != 6) return 0;

    var4 = (unsigned char*)func_ov023_021f6880(var3, 0xd);
    if (!var4) return 0;
    if (func_ov024_021f6f10(var4) != 6) return 0;

    for (int var5 = 0; var5 < 6; var5++) {
        unsigned char* var6 = (unsigned char*)func_ov023_021f6880(var3, var5 + 0x15);
        if (!var6) continue;
        if (func_ov024_021f6f10(var6) != 8) continue;

        short var7 = *(short*)((char*)&data_ov004_0216fffa + var5 * 4);
        short var8 = *(short*)((char*)&data_ov004_0216fff8 + var5 * 4);

        void* var9 = (void*)func_ov004_02167908(arg0, 5);
        if (!var9) continue;

        *(int*)(var6 + 0x20) = 0;
        var6[0xc] |= 8;

        struct Element020de650* elem = ItemTable_Find((struct ItemTable*)container, valA);
        if (!elem) continue;

        *(int*)(var6 + 0x20) = var10->unknown_4_;
        var6[0xc] &= ~8;
#if defined(jpn)
        {
            Struct_ov004_021680cc* var11 = (Struct_ov004_021680cc*)func_ov023_021f6880(func_ov011_021849c8(arg0), var5 + 0x21);
            if (var11) var11->unknown_0_->unknown_e0_(var11, var8);
        }
#else
        func_ov023_021f64a8(arg0, var5 + 0x21, var8, 0xf);
#endif
    }

    *(short*)(var2 + 0x104) = 0;
    *(short*)(var2 + 0x106) = 0;
    func_ov023_021f809c(var2, arg0);

    *(short*)(var4 + 0x104) = 0;
    *(short*)(var4 + 0x106) = 0;
    func_ov023_021f809c(var4, arg0);

    return 0;
}
