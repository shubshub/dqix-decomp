#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct ArrayContainsByteStruct;

struct Struct_ov002_0216c42c_2 {
    short lo : 11;
    short hi : 5;
};

struct Struct_ov002_0216c42c_3 {
    unsigned char kind;
    unsigned char type;
    unsigned char sub;
    signed char f3;
    signed char ids[3];
    signed char count;
    Struct_ov002_0216c42c_2 unknown_8_[3];
    signed char fe;
};

struct Struct_ov002_0216c42c_4 {
    unsigned char kind;
    short lo;
    short hi;
};

struct Struct_ov002_0216c42c_5 {
    char pad0[3];
    unsigned char count;
    signed char ids[4];
    Struct_ov002_0216c42c_4 lo[4];
    Struct_ov002_0216c42c_4 hi[4];
};

struct Struct_ov002_0216c42c_6 {
    char pad0[0x18];
    unsigned int kind : 5;
    unsigned int id : 7;
};

extern "C" void* GameState_GetParty(GameState* gs);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" int func_02086ef0(ArrayContainsByteStruct* s, int val);

extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void func_ov017_021d2cc0(void* src);

// USA: func_ov002_0216c42c
extern "C" ARM void func_ov002_0216c42c(char* base, Struct_ov002_0216c42c_5* src, Struct_ov002_0216c42c_6* action) {
    if (src == NULL || action == NULL) return;
    GameState* gs = GameState::GetInstance();
    ArrayContainsByteStruct* party = (ArrayContainsByteStruct*)GameState_GetParty(gs);
    Struct_ov002_0216c42c_3 ev;
    memset(&ev, 0, 0x10);
    ev.kind = 1;
    switch (action->id) {
    case 7:
        ev.type = 3;
        break;
    case 0x1a:
        ev.type = 2;
        break;
    case 0x4f:
    case 0x50:
        ev.sub = 3;
    case 2:
        ev.type = 1;
        break;
    case 0x12:
        ev.type = 4;
        break;
    }
    if (action->kind == 5) ev.sub = 3;
    ev.f3 = *(signed char*)(base + RG(0x1c20, 0x1ae8));
    signed char n = 0;
    for (int i = 0; i < src->count; i++) {
        int id = src->ids[i];
        if (func_02086ef0(party, id) == 0) {
            ev.ids[n] = id;
            Struct_ov002_0216c42c_2* d = &ev.unknown_8_[n];
            Struct_ov002_0216c42c_4* v = &src->lo[i];
            d->lo = v->lo;
            d->hi = src->hi[i].lo;
            if (ev.type == 4 && v->kind == 3) {
                char* c = (char*)func_0200ff1c(gs, id);
                if (c != NULL) {
                    *(unsigned char*)(base + RG(0x2522, 0x2352)) = 1;
                    *(unsigned char*)(base + RG(0x2523, 0x2353)) = 0;
                    *(Vector3i*)(base + RG(0x2524, 0x2354)) = *(Vector3i*)(c + 0x44);
                }
            }
            n++;
        }
    }
    ev.count = n;
    ev.fe = GameState_GetProtagonistIndex(gs);
    func_ov017_021d2cc0(&ev);
}
