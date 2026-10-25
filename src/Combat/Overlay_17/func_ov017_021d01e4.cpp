#include <globaldefs.h>
#include "GameState/GameState.h"

int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_ov017_021a7c94(unsigned char* obj, int id, int arg2);
struct FieldStruct021a85d4;
void SetFieldndMaybe_021a85d4_021a85d4(struct FieldStruct021a85d4* obj, int val);
void CallIfGlobalPtrSet_021a5a28(void* obj, int mode);
int GetByteAtOffset7289OrFF_021a5a48(void* obj);

struct Struct_ov017_021d01e4 {
    unsigned char unknown_0_[4];
    unsigned char unknown_4_;
    signed char unknown_5_;
    signed char unknown_6_;
    unsigned char unknown_7_;
    short unknown_8_;
};

struct Struct_ov017_021d01e4_2 {
#if defined(jpn)
    unsigned char unknown_0_[0x350c];
#else
    unsigned char unknown1_0_[0x371c];
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
extern "C" ARM void func_ov017_021d01e4(int unused0, struct Evt021d01e4* evt, GameState* bs, struct Work021d01e4* work) {
    GameState_GetProtagonistIndex(bs);
    unsigned char* list = (unsigned char*)GameState_GetParty(bs);
    unsigned char* ids = list + 0xf78;
    unsigned char count = list[0xf7c];
    int idA = evt->idA;
    int idB = evt->idB;
    int arg = evt->arg;
    int foundA = 0;
    int foundB = 0;
    for (int i = 0; i < count; i++) {
        unsigned char id = ids[i];
        if (id == idA) {
            foundA = 1;
        }
        if (var9 == var4) {
            var7 = 1;
        }
    }

    struct Struct_ov017_021a85d4* var10 = arg3->unknown_3b9c_;
    void* var11 = arg3->unknown_371c_;
    switch (arg1->unknown_4_) {
    case 0:
        break;
    case 1:
        if (var7) {
            func_ov017_021a7c94((unsigned char*)arg3, var3, var5);
        }
        break;
    case 2:
        if (var7) {
            func_ov017_021a85d4(var10, 6);
        }
        break;
    case 3:
        if (var7) {
            func_ov017_021a85d4(var10, 5);
        }
        break;
    case 4:
        if (var6) {
            func_ov017_021a5a28(var11, 2);
        }
        break;
    case 5:
        if (var6) {
            func_ov017_021a5a28(var11, 6);
        }
        break;
    case 6:
        if (var6) {
            if (func_ov017_021a5a48(var11) != 4) {
                func_ov017_021a5a28(var11, 8);
            }
        }
        break;
    case 7:
        if (var6) {
            func_ov017_021a5a28(var11, 5);
        }
        break;
    case 8:
        if (var6) {
            func_ov017_021a5a28(var11, 7);
        }
        break;
    }
}
