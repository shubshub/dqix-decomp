#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cbd4 data_ov005_0215dfb4
#define data_ov005_0215cd60 data_ov005_0215e140
#define data_ov014_02189480 data_ov014_0218a2c0
#define data_ov014_02189498 data_ov014_0218a2d8
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194564 data_ov015_02195184
#define data_ov015_02194570 data_ov015_02195190
#define data_ov015_021945a0 data_ov015_021951c0
#define data_ov015_021945d0 data_ov015_021951f0
#define data_ov024_021ff17c data_ov023_021ff17c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <GameState/GameState.h>

void* GameState_GetParty(GameState* gameState);
short* GetPointerFromArray0xbd0_0207c5f8(unsigned char* p, unsigned int list);
signed char* GetPointerAt0xbf0_0207c60c(void* p, unsigned int list);

extern "C" unsigned char data_ov005_0215cd60[8];

struct Struct_ov005_02153ba4 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    void* unknown_4_;
    void* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
};

struct Struct_ov005_02153954 {
    char unknown_0_[R(0x2d08, 0x2d90)];
    Struct_ov005_02153ba4 unknown_2d90_[24];
    char unknown_3030_[0x3dbc - 0x3030];
    unsigned char unknown_3dbc_;
    signed char unknown_3dbd_;
};

// USA: func_ov005_021555c0
extern "C" ARM void func_ov005_021555c0(EquipmentMenu* self) {
    char* party = (char*)GameState_GetParty(GameState::GetInstance());
    short* items = GetPointerFromArray0xbd0_0207c5f8((unsigned char*)(party + 0x1d4), data_ov005_0215cd60[self->kind_]);
    signed char* counts = GetPointerAt0xbf0_0207c60c(party + 0x1d4, data_ov005_0215cd60[self->kind_]);
    signed char page = self->page_;
    for (int i = 0; i < 16; i++) {
        EquipmentSlot* slot = &self->slots_[i + 8];
        int index = i + page * 16;
        short item = items[index];
        signed char count = counts[index];
        if (item == slot->loadedItem_)
            slot->equipped_ = 1;
        else
            var5->unknown_3_ = 0;
        var5->unknown_0_ = var7;
        var5->unknown_2_ = var8;
    }
}
