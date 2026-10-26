#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0x3508 };
#else
enum { kRegionalFieldOffset = 0x3718 };
#endif
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021ca6dc {
    unsigned short field0 : 2;
    unsigned short field2 : 4;
    unsigned short field6 : 3;
    unsigned short field9 : 3;
    unsigned short field12 : 2;
    unsigned short field14 : 2;
};

struct Struct_ov017_021ca6dc_2 {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned short unknown_a_;
    char pad1[0x22 - 0xc];
    struct Struct_ov017_021ca6dc bits;
    unsigned char unknown_24_;
    unsigned char unknown_25_;
};

struct Struct_020886dc_2;
extern "C" void func_02088818(struct Struct_020886dc_2* obj, unsigned short mode);

struct Struct_ov017_021ca6dc_3 {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    struct Struct_ov017_021ca6dc unknown_8_;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
};

// USA: func_ov017_021ca6dc
extern "C" ARM void func_ov017_021ca6dc(void* unused0, struct Struct_ov017_021ca6dc_3* src, GameState* battleStruct, char* data) {
    void* var0 = func_ov017_021b8478(*(void**)(data + kRegionalFieldOffset));
    if (!var0) {
        return;
    }
    int val = GameState_GetProtagonistIndex(battleStruct);
    if (*(signed char*)((char*)var0 + 0x2a) == val) {
        return;
    }
    if (*(unsigned short*)((char*)var0 + 0x8) != src->field4) {
        return;
    }
    int idx = src->field6 - 0xc0;
    if (idx < 0) {
        return;
    }
    if (idx >= 8) {
        return;
    }
    struct Struct_ov017_021ca6dc_2* slot = (struct Struct_ov017_021ca6dc_2*)((char*)var0 + 0x158 + idx * 0xa4);
    unsigned char f0 = src->unknown_8_.field0;
    slot->bits.field0 = f0;
    unsigned char f2 = src->unknown_8_.field2;
    slot->bits.field2 = f2;
    unsigned char var6 = src->unknown_8_.field6;
    slot->bits.field6 = var6;
    unsigned char var7 = src->unknown_8_.field9;
    func_02088818((struct Struct_020886dc_2*)slot, var7);
    unsigned char f12 = src->unknown_8_.field12;
    slot->bits.field12 = f12;
    slot->unknown_24_ = src->unknown_a_;
    slot->unknown_25_ = src->unknown_b_;
    slot->field4 = src->unknown_c_;
    slot->field6 = src->unknown_e_;
    slot->field8 = src->unknown_10_;
    slot->unknown_a_ = src->unknown_12_;
}
