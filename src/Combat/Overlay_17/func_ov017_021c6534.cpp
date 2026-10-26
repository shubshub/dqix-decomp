#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021c6534 {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct Struct_ov017_021c6534_2 {
    unsigned short key;
    unsigned short ids[3];
    unsigned char unknown_8_[3];
    Struct_ov017_021c6534 nibbles[3];
    unsigned char mode;
};

struct Struct_ov017_021c6534_3 {
    unsigned char pad0[4];
    Struct_ov017_021c6534_2 data;
};

struct Struct_ov017_021c6534_4 {
    unsigned char pad0[8];
    unsigned short key;
    unsigned char unknown_a_[0x2a - 0x0a];
    signed char field_0x2a;
};

struct Struct_ov017_021c6534_5 {
    unsigned short id;
    unsigned char pad2[0xa - 0x2];
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char val;
    unsigned char unknown_c_[0x18 - 0x0c];
};

struct Struct_ov017_021c6534_6 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char count : 2;
    unsigned char mode : 2;
    unsigned char pad2[2];
    Struct_ov017_021c6534_5 slots[3];
};

// USA: func_ov017_021c6534
extern "C" ARM void func_ov017_021c6534(int unused0, Struct_ov017_021c6534_3* evt, GameState* battleStruct, char* base) {
#if defined(jpn)
 enum { regionalOffset = 0x508 };
#else
 enum { regionalOffset = 0x718 };
#endif
    void* table = *(void**)(base + 0x3000 + regionalOffset);

    Struct_ov017_021c6534_4* fieldObj = (Struct_ov017_021c6534_4*)func_ov017_021b8478(table);
    if (!fieldObj) return;

    void* state = func_ov017_021b8470(table);
    if (!state) return;

    if (fieldObj->field_0x2a == GameState_GetProtagonistIndex(battleStruct)) return;
    Struct_ov017_021c6534_2* data = &evt->data;
    if (fieldObj->key != data->key) return;

    Struct_ov017_021c6534_6* party = (Struct_ov017_021c6534_6*)((char*)state + 0x1b0 + 0x8000);
    unsigned char lo[3];
    unsigned char hi[3];
    lo[0] = data->nibbles[0].lo;
    lo[1] = data->nibbles[1].lo;
    lo[2] = data->nibbles[2].lo;
    hi[0] = data->nibbles[0].hi;
    hi[1] = data->nibbles[1].hi;
    hi[2] = data->nibbles[2].hi;

    int count = 0;
    int var8 = 0;
    int var9 = 0;
    for (int i = 0; i < 3; i++) {
        Struct_ov017_021c6534_5* slot = &party->slots[i];
        slot->id = data->ids[i];
        slot->val = data->unknown_8_[i];
        slot->lo = lo[i];
        slot->hi = hi[i];
        if (slot->id != 0) {
            count++;
            var8 += slot->lo;
            var9 += slot->hi;
        }
    }
    party->count = count;
    party->mode = data->mode;
    party->unknown_0_ = var8;
    party->unknown_1_0_ = var9;
}
