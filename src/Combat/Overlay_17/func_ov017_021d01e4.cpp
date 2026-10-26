#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_ov017_021a7c94(unsigned char* obj, int id, int arg2);
struct Struct_ov017_021a85d4;
extern "C" void func_ov017_021a85d4(struct Struct_ov017_021a85d4* obj, int val);
extern "C" void func_ov017_021a5a28(void* obj, int mode);
extern "C" int func_ov017_021a5a48(void* obj);

struct Struct_ov017_021d01e4 {
    unsigned char pad0[4];
    unsigned char kind;
    signed char idA;
    signed char unknown_6_;
    unsigned char unknown_7_;
    short arg;
};

struct Struct_ov017_021d01e4_2 {
#if defined(jpn)
    unsigned char pad0[0x350c];
#else
    unsigned char pad0[0x371c];
#endif
    void* unknown_371c_;
#if defined(jpn)
    unsigned char unknown_3510_[0x397c - 0x3510];
#else
    unsigned char unknown_3720_[0x3b9c - 0x3720];
#endif
    struct Struct_ov017_021a85d4* unknown_3b9c_;
};

// USA: func_ov017_021d01e4
extern "C" ARM void func_ov017_021d01e4(int unused0, struct Struct_ov017_021d01e4* evt, GameState* bs, struct Struct_ov017_021d01e4_2* work) {
    GameState_GetProtagonistIndex(bs);
    unsigned char* list = (unsigned char*)GameState_GetParty(bs);
    unsigned char* ids = list + 0xf78;
    unsigned char count = list[0xf7c];
    int idA = evt->idA;
    int var4 = evt->unknown_6_;
    int arg = evt->arg;
    int var6 = 0;
    int var7 = 0;
    for (int i = 0; i < count; i++) {
        unsigned char id = ids[i];
        if (id == idA) {
            var6 = 1;
        }
        if (id == var4) {
            var7 = 1;
        }
    }

    struct Struct_ov017_021a85d4* field = work->unknown_3b9c_;
    void* p = work->unknown_371c_;
    switch (evt->kind) {
    case 0:
        break;
    case 1:
        if (var7) {
            func_ov017_021a7c94((unsigned char*)work, idA, arg);
        }
        break;
    case 2:
        if (var7) {
            func_ov017_021a85d4(field, 6);
        }
        break;
    case 3:
        if (var7) {
            func_ov017_021a85d4(field, 5);
        }
        break;
    case 4:
        if (var6) {
            func_ov017_021a5a28(p, 2);
        }
        break;
    case 5:
        if (var6) {
            func_ov017_021a5a28(p, 6);
        }
        break;
    case 6:
        if (var6) {
            if (func_ov017_021a5a48(p) != 4) {
                func_ov017_021a5a28(p, 8);
            }
        }
        break;
    case 7:
        if (var6) {
            func_ov017_021a5a28(p, 5);
        }
        break;
    case 8:
        if (var6) {
            func_ov017_021a5a28(p, 7);
        }
        break;
    }
}
