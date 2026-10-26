#include <globaldefs.h>
#if defined(jpn)
#define data_ov004_0216fffa data_ov004_02170752
#define data_ov004_0216fff8 data_ov004_02170750
struct Struct_ov004_021680cc;
struct Struct_ov004_021680cc_2 { char pad[0xe0]; void (*unknown_e0_)(Struct_ov004_021680cc*, int); };
struct Struct_ov004_021680cc { Struct_ov004_021680cc_2* unknown_0_; };
#endif
#include "GameState/GameState.h"

struct Obj02086aec;
extern "C" short Party_CountItem(struct Obj02086aec* obj, int key);
extern "C" void func_ov023_021f64a8(void* obj, int id, int arg2, int arg3);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#define func_ov024_021f6f10 func_ov023_021f6f10
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
extern "C" int func_ov004_02167908(void* a, int key);
struct ItemTable;
struct Element020de650 { char pad[4]; int field4; };
extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern "C" void func_ov023_021f809c(void* obj, void* param2);

extern short data_ov004_0216fffa;
extern short data_ov004_0216fff8;

// USA: func_ov004_021680cc
extern "C" ARM int func_ov004_021680cc(void* a) {
    short matches = Party_CountItem((struct Obj02086aec*)GameState_GetParty(GameState::GetInstance()), 0x5617);
#if defined(jpn)
    {
        Struct_ov004_021680cc* entry = (Struct_ov004_021680cc*)func_ov023_021f6880(func_ov011_021849c8(a), 0x2b);
        if (entry) entry->unknown_0_->unknown_e0_(entry, matches);
    }
#else
    func_ov023_021f64a8(a, 0x2b, matches, 0xf);
#endif

    unsigned char* var2;
    void* sub;
    unsigned char* var4;
    sub = func_ov011_021849c8(a);
    var2 = (unsigned char*)func_ov023_021f6880(sub, 0xc);
    if (!var2) return 0;
    if (func_ov024_021f6f10(var2) != 6) return 0;

    var4 = (unsigned char*)func_ov023_021f6880(sub, 0xd);
    if (!var4) return 0;
    if (func_ov024_021f6f10(var4) != 6) return 0;

    for (int i = 0; i < 6; i++) {
        unsigned char* node4 = (unsigned char*)func_ov023_021f6880(sub, i + 0x15);
        if (!node4) continue;
        if (func_ov024_021f6f10(node4) != 8) continue;

        short valA = *(short*)((char*)&data_ov004_0216fffa + i * 4);
        short valB = *(short*)((char*)&data_ov004_0216fff8 + i * 4);

        void* container = (void*)func_ov004_02167908(a, 5);
        if (!container) continue;

        *(int*)(node4 + 0x20) = 0;
        node4[0xc] |= 8;

        struct Element020de650* elem = ItemTable_Find((struct ItemTable*)container, valA);
        if (!elem) continue;

        *(int*)(node4 + 0x20) = elem->field4;
        node4[0xc] &= ~8;
#if defined(jpn)
        {
            Struct_ov004_021680cc* entry = (Struct_ov004_021680cc*)func_ov023_021f6880(func_ov011_021849c8(a), i + 0x21);
            if (entry) entry->unknown_0_->unknown_e0_(entry, valB);
        }
#else
        func_ov023_021f64a8(a, i + 0x21, valB, 0xf);
#endif
    }

    *(short*)(var2 + 0x104) = 0;
    *(short*)(var2 + 0x106) = 0;
    func_ov023_021f809c(var2, a);

    *(short*)(var4 + 0x104) = 0;
    *(short*)(var4 + 0x106) = 0;
    func_ov023_021f809c(var4, a);

    return 0;
}
