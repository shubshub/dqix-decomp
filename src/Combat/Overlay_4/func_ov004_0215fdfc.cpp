#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

extern "C" unsigned char GameState_GetPartyOrder(char* obj, void* dst);
extern "C" int func_02061bd8(struct Struct_0205faf4_11* obj);
extern "C" unsigned short func_ov004_0215eb20(void* obj, int bit);
struct SePlayer;
extern struct SePlayer g_sePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void* func_ov004_0215e4c0(void* a, int key);
struct Struct_ov004_0215fdfc;
extern "C" void func_ov023_021f809c(struct Struct_ov004_0215fdfc*, void*);
extern "C" void func_ov023_021fc71c(void*, int, int);
extern "C" void func_020dc7e8(int, int);
extern "C" void func_ov004_0215ee90(void*);
extern "C" void func_ov004_0215f0c0(void*);
extern "C" void func_ov004_0215e5fc(void*, int);
extern "C" void func_ov004_0215eb40(void*);
extern "C" void func_ov004_0215ef14();
extern "C" void func_ov004_0216033c(void*);
extern "C" void func_ov004_02161514(void*);
extern "C" void func_ov004_02161c18(void*);
extern "C" void func_ov004_02162108(void*);
extern "C" void func_ov004_0216276c(void*);
extern "C" void func_ov023_021f66bc(void* a, int b, void* c);

struct Struct_ov004_0215fdfc_2 {
#if defined(jpn)
    char pad[0x8b8];
#else
    char pad[0x950];
#endif
    int field950;
};

struct Struct_ov004_0215fdfc_3 {
#if defined(jpn)
    char pad[0x144];
#else
    char pad[0x150];
#endif
    Struct_ov004_0215fdfc_2* sub;
};

class Struct_ov004_0215fdfc_4 {
public:
    char pad4[0xc];
    unsigned char flags;
};

struct Struct_ov004_0215fdfc_5 {
    char pad[0x104];
    short unknown_104_;
    short unknown_106_;
};

extern "C" Struct_ov004_0215fdfc_4* func_ov004_0215e47c(void* a, int key);

struct Struct_ov004_021707e8_2 {
#if defined(jpn)
    signed char unknown_5_;
    unsigned char index;
    unsigned char f2;
    unsigned char f1;
    signed char unknown_6_;
    signed char unknown_9_;
    unsigned char type;
    unsigned char entry;
    signed char fb;
    unsigned char f3;
    unsigned char padA;
    unsigned char busy;
#else
    unsigned char busy;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    signed char unknown_5_;
    signed char unknown_6_;
    unsigned char type;
    unsigned char entry;
    signed char unknown_9_;
    unsigned char index;
    signed char fb;
#endif
    char pad[0x10];
    int combatant;
#if defined(jpn)
    char pad2[0x40];
#else
    char pad2[0x4c];
#endif
    int f6c;
    int unknown_70_;
};

extern Struct_ov004_021707e8_2 data_ov004_021707e8;
#if defined(jpn)
extern int data_ov004_021705c4[];
extern unsigned char data_ov004_021710d5[];
extern "C" void func_ov004_0215fa1c();
#else
extern int data_ov004_0216fe5c[];
#endif
extern int data_ov004_02170854[];
extern unsigned char data_ov004_02170838[];
extern unsigned char data_ov004_02170845[];
extern unsigned char data_ov004_02170b90[];

// JPN: func_ov004_0215fdfc (02160780)
// USA: func_ov004_0215fdfc
extern "C" ARM int func_ov004_0215fdfc(void* a) {
    if (data_ov004_021707e8.busy == 1) return 0;
    data_ov004_021707e8.busy = 1;
    GameState* gs;
    GameObject* c;
    unsigned char saved;
    int none;
    int target;
    int n;
    unsigned char order[4];
    gs = GameState::GetInstance();
    n = GameState_GetPartyOrder((char*)gs, order);
    target = data_ov004_021707e8.combatant;
    none = 0;
    saved = data_ov004_021707e8.index;
    if (func_0200ff1c(gs, target) == NULL) none = 1;
    if (!none) {
        data_ov004_021707e8.index = data_ov004_021707e8.index + 1;
        data_ov004_021707e8.index = (unsigned)data_ov004_021707e8.index % n;
    }
    data_ov004_021707e8.combatant = order[data_ov004_021707e8.index];
    c = func_0200ff1c(gs, data_ov004_021707e8.combatant);
    if (data_ov004_021707e8.combatant == target && !none) {
        c = NULL;
        while (c == NULL) {
            data_ov004_021707e8.index = data_ov004_021707e8.index + 1;
            data_ov004_021707e8.index = (unsigned)data_ov004_021707e8.index % n;
            data_ov004_021707e8.combatant = order[data_ov004_021707e8.index];
            if (data_ov004_021707e8.combatant == target) {
                data_ov004_021707e8.index = saved;
                data_ov004_021707e8.combatant = target;
                data_ov004_021707e8.busy = 0;
                Struct_ov004_0215fdfc_4* var7 = func_ov004_0215e47c(a, 0x85);
                if (var7) var7->flags |= 0x78;
                return 0;
            }
            c = func_0200ff1c(gs, data_ov004_021707e8.combatant);
            if (c != NULL) break;
        }
    }
    if (c == NULL) {
        while (c == NULL) {
            data_ov004_021707e8.index = data_ov004_021707e8.index + 1;
            data_ov004_021707e8.index = (unsigned)data_ov004_021707e8.index % n;
            data_ov004_021707e8.combatant = order[data_ov004_021707e8.index];
            if (data_ov004_021707e8.combatant == target) {
                data_ov004_021707e8.index = saved;
                data_ov004_021707e8.combatant = target;
                data_ov004_021707e8.busy = 0;
                Struct_ov004_0215fdfc_4* var8 = func_ov004_0215e47c(a, 0x85);
                if (var8) var8->flags |= 0x78;
                return 0;
            }
            c = func_0200ff1c(gs, data_ov004_021707e8.combatant);
            if (c != NULL) break;
        }
    }
    if (func_02061bd8((struct Struct_0205faf4_11*)c)) {
        int ok = 0;
        while (!ok) {
            data_ov004_021707e8.index = data_ov004_021707e8.index + 1;
            data_ov004_021707e8.index = (unsigned)data_ov004_021707e8.index % n;
            data_ov004_021707e8.combatant = order[data_ov004_021707e8.index];
            if (data_ov004_021707e8.combatant == target) {
                data_ov004_021707e8.index = saved;
                data_ov004_021707e8.combatant = target;
                data_ov004_021707e8.busy = 0;
                return 0;
            }
            c = func_0200ff1c(gs, data_ov004_021707e8.combatant);
            if (c == NULL) {
                data_ov004_021707e8.index = saved;
                data_ov004_021707e8.combatant = target;
                break;
            }
            if (func_02061bd8((struct Struct_0205faf4_11*)c) == 0) ok = 1;
        }
    }
    int v = ((Struct_ov004_0215fdfc_3*)c)->sub->field950;
    data_ov004_021707e8.f2 = v;
    data_ov004_021707e8.entry = 0;
    data_ov004_021707e8.f6c = 0;
    int key = v & 0xff;
    data_ov004_021707e8.unknown_70_ = key;
    unsigned char i = 1;
    unsigned char j = 2;
    while (j < 0xd) {
#if defined(jpn)
        int t = data_ov004_021705c4[i];
#else
        int t = data_ov004_0216fe5c[i];
#endif
        data_ov004_02170854[j] = t;
        if (key != t) {
            j++;
            i++;
        } else {
            i++;
        }
    }
    int e = data_ov004_021707e8.entry;
    while (key != data_ov004_02170854[(unsigned char)e]) {
        data_ov004_021707e8.entry = (unsigned char)e + 1;
        e = data_ov004_021707e8.entry % 13;
        data_ov004_021707e8.entry = e;
        if (key == data_ov004_02170854[data_ov004_021707e8.entry]) break;
    }
    for (int k = 0; k < 13; k++) {
        if (func_ov004_0215eb20(c, data_ov004_02170854[k]) != 0) data_ov004_02170838[k] = 1;
        else data_ov004_02170838[k] = 0;
#if defined(jpn)
        if (func_ov004_0215eb20(c, data_ov004_021705c4[k]) != 0) data_ov004_021710d5[k] = 1;
        else data_ov004_021710d5[k] = 0;
#else
        if (func_ov004_0215eb20(c, data_ov004_0216fe5c[k]) != 0) data_ov004_02170845[k] = 1;
        else data_ov004_02170845[k] = 0;
#endif
    }
    data_ov004_021707e8.f3 = data_ov004_021707e8.entry;
    func_ov004_0215ee90(data_ov004_02170b90);
    data_ov004_021707e8.unknown_9_ = 0;
    data_ov004_021707e8.unknown_5_ = 0;
#if defined(jpn)
    func_ov004_0215e5fc(a, data_ov004_021707e8.combatant);
    func_ov004_0215f0c0(a);
#else
    func_ov004_0215f0c0(a);
    func_ov004_0215e5fc(a, data_ov004_021707e8.combatant);
#endif
    func_ov004_0215eb40(a);
#if defined(jpn)
    func_ov004_0215fa1c();
#else
    func_ov004_0215ef14();
#endif
    data_ov004_021707e8.f1 = 1;
    SePlayer_Play(&g_sePlayer, 1, 0);
    Struct_ov004_0215fdfc_4* var17 = func_ov004_0215e47c(a, 0x82);
    func_ov023_021fc71c(var17, data_ov004_021707e8.combatant, 1);
    data_ov004_021707e8.fb = 0;
    data_ov004_021707e8.unknown_6_ = 0;
    switch (data_ov004_021707e8.type - 0x64) {
    case 0:
        data_ov004_021707e8.unknown_6_ = data_ov004_021707e8.unknown_9_;
        func_ov004_0216033c(a);
        break;
    case 1:
        data_ov004_021707e8.unknown_6_ = data_ov004_021707e8.unknown_5_;
        func_ov004_02161514(a);
        break;
    case 2:
        data_ov004_021707e8.unknown_6_ = data_ov004_02170b90[0x23f];
        func_ov004_02161c18(a);
        break;
    case 3:
        data_ov004_021707e8.unknown_6_ = data_ov004_02170b90[0x47f];
        func_ov004_02162108(a);
        break;
    case 4:
        data_ov004_021707e8.unknown_6_ = 1;
        func_ov004_0216276c(a);
        break;
    }
    func_020dc7e8(2, (signed char)data_ov004_021707e8.combatant);
    func_020dc7e8(5, (signed char)data_ov004_021707e8.combatant);
    Struct_ov004_0215fdfc_5* node = (Struct_ov004_0215fdfc_5*)func_ov004_0215e4c0(a, 3);
    node->unknown_104_ = data_ov004_021707e8.fb;
    node->unknown_106_ = data_ov004_021707e8.unknown_6_;
    func_ov023_021f809c((struct Struct_ov004_0215fdfc*)node, a);
    data_ov004_021707e8.busy = 0;
    func_ov023_021f66bc(a, 0x85, (void*)1);
    return 0;
}
