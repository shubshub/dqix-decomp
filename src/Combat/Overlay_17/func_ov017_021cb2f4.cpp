#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8470(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021cb2f4_2 {
    unsigned int f0 : 3;
    unsigned int f1 : 3;
    unsigned int f2 : 3;
    unsigned int f3 : 3;
    unsigned int f4 : 3;
    unsigned int unknown_1_7_ : 3;
    unsigned int unknown_2_2_ : 3;
    unsigned int unknown_2_5_ : 3;
    unsigned int f8 : 3;
    unsigned int unknown_3_3_ : 3;
    unsigned int pad : 2;
};

struct Struct_ov017_021cb2f4_3 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    Struct_ov017_021cb2f4_2 unknown_8_;
    Struct_ov017_021cb2f4_2 unknown_c_;
    unsigned short field10;
    unsigned char field12;
};

struct Struct_ov017_021cb2f4_4 {
    unsigned char pad0[0x36];
    unsigned short unknown_36_;
    unsigned char pad1[0x5c - 0x38];
    unsigned char unknown_5c_[0x14];
    unsigned char pad2[0x7f - 0x70];
    unsigned char unknown_7f_[0x14];
    unsigned char pad3[0xa4 - 0x93];
};

struct Struct_ov017_021cb2f4 {
    unsigned char pad0[8];
    unsigned short field8;
    unsigned char pad1[0x2a - 0xa];
    signed char field2a;
    unsigned char pad2[0x158 - 0x2b];
    Struct_ov017_021cb2f4_4 entries[8];
};

// USA: func_ov017_021cb2f4
extern "C" ARM void func_ov017_021cb2f4(int unused0, Struct_ov017_021cb2f4_3* src, GameState* battleStruct, unsigned char* self) {
#if defined(jpn)
    void* h = *(void**)(self + 0x3000 + 0x508);
#else
    void* h = *(void**)(self + 0x3000 + 0x718);
#endif
    void* work = func_ov017_021b8470(h);
    if (!work) return;
    Struct_ov017_021cb2f4* r = *(Struct_ov017_021cb2f4**)((unsigned char*)work + 0x8000 + 0xe18);
    if (!r) return;
    int val = GameState_GetProtagonistIndex(battleStruct);
    if (r->field2a == val) return;
    if (r->field8 != src->field4) return;
    int idx = (int)src->field6 - 0xc0;
    if (idx < 0) return;
    if (idx >= 8) return;
    Struct_ov017_021cb2f4_4* entry = &r->entries[idx];
    if (src->field12 == 1) {
        entry->unknown_5c_[0] = (unsigned char)src->unknown_8_.f0;
        entry->unknown_5c_[1] = (unsigned char)src->unknown_8_.f1;
        entry->unknown_5c_[2] = (unsigned char)src->unknown_8_.f2;
        entry->unknown_5c_[3] = (unsigned char)src->unknown_8_.f3;
        entry->unknown_5c_[4] = (unsigned char)src->unknown_8_.f4;
        entry->unknown_5c_[5] = (unsigned char)src->unknown_8_.unknown_1_7_;
        entry->unknown_5c_[6] = (unsigned char)src->unknown_8_.unknown_2_2_;
        entry->unknown_5c_[7] = (unsigned char)src->unknown_8_.unknown_2_5_;
        entry->unknown_5c_[8] = (unsigned char)src->unknown_8_.f8;
        entry->unknown_5c_[9] = (unsigned char)src->unknown_8_.unknown_3_3_;
        entry->unknown_5c_[10] = (unsigned char)src->unknown_c_.f0;
        entry->unknown_5c_[11] = (unsigned char)src->unknown_c_.f1;
        entry->unknown_5c_[12] = (unsigned char)src->unknown_c_.f2;
        entry->unknown_5c_[13] = (unsigned char)src->unknown_c_.f3;
        entry->unknown_5c_[14] = (unsigned char)src->unknown_c_.f4;
        entry->unknown_5c_[15] = (unsigned char)src->unknown_c_.unknown_1_7_;
        entry->unknown_5c_[16] = (unsigned char)src->unknown_c_.unknown_2_2_;
        entry->unknown_5c_[17] = (unsigned char)src->unknown_c_.unknown_2_5_;
        entry->unknown_5c_[18] = (unsigned char)src->unknown_c_.f8;
        entry->unknown_5c_[19] = (unsigned char)src->unknown_c_.unknown_3_3_;
        entry->unknown_36_ = src->field10;
    } else {
        entry->unknown_7f_[0] = (unsigned char)src->unknown_8_.f0;
        entry->unknown_7f_[1] = (unsigned char)src->unknown_8_.f1;
        entry->unknown_7f_[2] = (unsigned char)src->unknown_8_.f2;
        entry->unknown_7f_[3] = (unsigned char)src->unknown_8_.f3;
        entry->unknown_7f_[4] = (unsigned char)src->unknown_8_.f4;
        entry->unknown_7f_[5] = (unsigned char)src->unknown_8_.unknown_1_7_;
        entry->unknown_7f_[6] = (unsigned char)src->unknown_8_.unknown_2_2_;
        entry->unknown_7f_[7] = (unsigned char)src->unknown_8_.unknown_2_5_;
        entry->unknown_7f_[8] = (unsigned char)src->unknown_8_.f8;
        entry->unknown_7f_[9] = (unsigned char)src->unknown_8_.unknown_3_3_;
        entry->unknown_7f_[10] = (unsigned char)src->unknown_c_.f0;
        entry->unknown_7f_[11] = (unsigned char)src->unknown_c_.f1;
        entry->unknown_7f_[12] = (unsigned char)src->unknown_c_.f2;
        entry->unknown_7f_[13] = (unsigned char)src->unknown_c_.f3;
        entry->unknown_7f_[14] = (unsigned char)src->unknown_c_.f4;
        entry->unknown_7f_[15] = (unsigned char)src->unknown_c_.unknown_1_7_;
        entry->unknown_7f_[16] = (unsigned char)src->unknown_c_.unknown_2_2_;
        entry->unknown_7f_[17] = (unsigned char)src->unknown_c_.unknown_2_5_;
        entry->unknown_7f_[18] = (unsigned char)src->unknown_c_.f8;
        entry->unknown_7f_[19] = (unsigned char)src->unknown_c_.unknown_3_3_;
    }
}
