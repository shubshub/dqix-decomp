#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8470(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021cac7c {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char nibble : 4;
};

struct Struct_ov017_021cac7c_2 {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 1;
};

struct Struct_ov017_021cac7c_3 {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    short field8;
    short fielda;
    unsigned short fieldc;
    unsigned short unknown_e_;
    unsigned char field10;
    struct Struct_ov017_021cac7c unknown_11_;
    unsigned char field12;
    struct Struct_ov017_021cac7c_2 unknown_13_;
};

// USA: func_ov017_021cac7c
extern "C" ARM void func_ov017_021cac7c(int unused0, struct Struct_ov017_021cac7c_3* src, GameState* battleStruct, unsigned char* base) {
#if defined(jpn)
    void* table = *(void**)(base + 0x3000 + 0x508);
#else
    void* table = *(void**)(base + 0x3000 + 0x718);
#endif
    void* obj = func_ov017_021b8470(table);
    if (obj == NULL) {
        return;
    }
    unsigned char* header = *(unsigned char**)((char*)obj + 0x8000 + 0xe18);
    if (header == NULL) {
        return;
    }
    if (*(signed char*)(header + 0x2a) == GameState_GetProtagonistIndex(battleStruct)) {
        return;
    }
    if (*(unsigned short*)(header + 8) != src->field4) {
        return;
    }
    int idx = src->field6 - 0xc0;
    if (idx < 0) {
        return;
    }
    if (idx >= 8) {
        return;
    }
    unsigned char* dest = header + 0x158 + idx * 0xa4;
    *(short*)(dest + 0x32) = src->field8;
    *(short*)(dest + 0x34) = src->fielda;
    *(unsigned short*)(dest + 0x30) = src->unknown_e_;
    *(dest + 0x38) = src->field10;
    ((struct Struct_ov017_021cac7c*)(dest + 0x3b))->bit0 = src->unknown_11_.bit0;
    ((struct Struct_ov017_021cac7c*)(dest + 0x3b))->unknown_0_1_ = src->unknown_11_.unknown_0_1_;
    ((struct Struct_ov017_021cac7c*)(dest + 0x3b))->bit2 = src->unknown_11_.bit2;
    ((struct Struct_ov017_021cac7c*)(dest + 0x3b))->unknown_0_3_ = src->unknown_11_.unknown_0_3_;
    ((struct Struct_ov017_021cac7c*)(dest + 0x3b))->nibble = src->unknown_11_.nibble;
    *(dest + 0x39) = 0;
    ((struct Struct_ov017_021cac7c_2*)(dest + 0x3c))->bit0 = src->unknown_13_.bit0;
    ((struct Struct_ov017_021cac7c_2*)(dest + 0x3c))->unknown_0_1_ = src->unknown_13_.unknown_0_1_;
    ((struct Struct_ov017_021cac7c_2*)(dest + 0x3c))->bit2 = src->unknown_13_.bit2;
    ((struct Struct_ov017_021cac7c_2*)(dest + 0x3c))->unknown_0_3_ = src->unknown_13_.unknown_0_3_;
    ((struct Struct_ov017_021cac7c_2*)(dest + 0x3c))->unknown_0_4_ = src->unknown_13_.unknown_0_4_;
    ((struct Struct_ov017_021cac7c_2*)(dest + 0x3c))->unknown_0_5_ = src->unknown_13_.unknown_0_5_;
    ((struct Struct_ov017_021cac7c_2*)(dest + 0x3c))->unknown_0_6_ = src->unknown_13_.unknown_0_6_;
    *(dest + 0x3d) = src->field12;
    *(unsigned short*)(dest + 0xc) = src->fieldc;
}
