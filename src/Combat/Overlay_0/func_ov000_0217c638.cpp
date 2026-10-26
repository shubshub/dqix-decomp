#include <globaldefs.h>
#include "GameState/GameState.h"

struct GridCursor;
struct Struct_0205bcdc;
struct Struct_0205cf1c;

void* GameState_GetParty(GameState*);
void CopyStaticData02174da4(int, void*);
extern "C" void* LinkSession_GetInstance();
int LinkSession_IsActive(int*);
int GameState_GetProtagonistIndex(GameState*);
int CountSetBitsLow12_0x68_ov000_0218155c(void*);
extern "C" void* func_ov000_02161318(void*, int);
void* GetFieldAt0x150_02053c6c(unsigned char*);
void ClearChannelAFlag0205cf10(void*);
void ClearFlagByte0205cf1c(Struct0205cf1c*);
void SetChannelAFlag0205cef8(void*);
void SetChannelBFlag0205cf04(void*);
void GridCursor_SetDimensions(GridCursor*, int, int, int);
void GridCursor_SetCount(GridCursor*, int);
void GridCursor_SelectIfValid(Struct_0205bcdc*, int);
extern "C" void GridCursor_SetSelectedIndex(void*, int);

#if defined(jpn)
extern int data_ov000_02184294[3];
#else
extern int data_ov000_02184294[2];
#endif

struct Struct_ov000_02182a74 {
    char unknown_0_[0xf7c];
    unsigned char unknown_f7c_;
};

struct Struct_ov000_0217c638 {
#if defined(jpn)
    char unknown_0_[0x8b4];
#else
    char unknown1_0_[0x94c];
#endif
    int unknown_94c_;
};

struct Struct_ov000_0217c638_2 {
    int unknown_0_;
    int unknown_4_;
    char unknown_8_[0x48];
};

struct Struct_ov000_0217c638_3 {
    char unknown_0_[0x1a];
    signed char unknown_1a_;
    char unknown_1b_;
    signed char unknown_1c_;
    char unknown_1d_[0x66 - 0x1d];
    short unknown_66_;
    char unknown_68_[0x79 - 0x68];
    unsigned char unknown_79_;
    char unknown_7a_[0x188 - 0x7a];
    char unknown_188_[4];
    Struct_ov000_0217c638_2 unknown_18c_;
    Struct_ov000_0217c638_2 unknown_1dc_;
#if defined(jpn)
    char unknown_22c_[0x1f98 - 0x22c];
#else
    char unknown1_22c_[0x1d60 - 0x22c];
#endif
    signed char unknown_1d60_[8];
    signed char unknown_1d68_;
    signed char unknown_1d69_[7];
    char unknown_1d70_[4];
    signed char unknown_1d74_[8];
};

// USA: func_ov000_0217c638
extern "C" ARM void func_ov000_0217c638(Struct_ov000_0217c638_3* arg0, int arg1, int arg2) {
    int var0 = 1;
    int var1 = arg2;
    int var2;
    int var3 = var0;
    signed char var4;
#if defined(jpn)
    data_ov000_02184294[2] = arg1;
    data_ov000_02184294[1] = arg2;
#else
    data_ov000_02184294[1] = arg1;
    data_ov000_02184294[0] = arg2;
#endif
    GameState* gs = GameState::GetInstance();
    Party* party = (Party*)GameState_GetParty(gs);
    switch (battle->commands[battle->index]) {
    case 1: {
        int var7[4];
        var1 = 0;
        func_ov000_02174da4((int)arg0, var7);
        for (int var8 = 0; var8 < 4; var8++) {
            if (var7[var8] >= 0) var1++;
        }
        var2 = var1;
        var4 = arg0->unknown_1d69_[0];
        break;
    }
    case 2: {
        void* state = LinkSession_GetInstance();
        rows = 3;
        if (LinkSession_IsActive((int*)state)) {
            if (GameState_GetProtagonistIndex(gs) == 0) rows = 4;
        }
        var1 = var2;
        var4 = arg0->unknown_1d69_[1];
        break;
    }
    case 3:
        var1 = var6->unknown_f7c_;
        var4 = arg0->unknown_1d69_[2];
        var2 = var1;
        break;
    case 5:
        var1 = var6->unknown_f7c_;
        var4 = arg0->unknown_1d69_[2];
        var2 = var1;
        break;
    case 6: {
        var2 = 4;
        int var10 = func_ov000_0218155c(arg0);
        var1 = var10;
        var4 = arg0->unknown_1d69_[5];
        if (var10 < 4) var2 = var10;
        var3 = (var10 + 3) / 4;
        break;
    }
    case 7: {
        var1 = arg0->unknown_66_;
        var4 = arg0->unknown_1d69_[6];
        var2 = 4;
        if (var1 < 4) var2 = var1;
        var3 = (var1 + 3) / 4;
        break;
    }
    case 4: {
        var0 = 2;
        var2 = 3;
        int var11 = arg0->unknown_1d74_[arg0->unknown_1d69_[2]];
        var1 = 6;
        signed char var12 = 0;
        int var13 = var11 >= 0 && var11 <= 3;
        if (var13 && func_ov000_02161318(arg0, var11)) {
            GameObject* var14 = var5->GetPartyMemberByIndex(var11);
            if (var14) {
                var12 = (signed char)((Struct_ov000_0217c638*)func_02053c6c((unsigned char*)var14))->unknown_94c_;
            }
        }
        arg0->unknown_1d69_[3] = var12;
        var4 = arg0->unknown_1d69_[3];
        break;
    }
    case 8:
        var1 = arg0->unknown_79_;
        var4 = arg0->unknown_1d69_[2];
        var2 = var1;
        break;
    case 23:
        var2 = arg0->unknown_1a_;
        var4 = arg0->unknown_1d69_[4];
        var1 = var2;
        break;
    case 25:
        var2 = 1;
        var0 = var1;
        var3 = var2;
        var4 = arg0->unknown_1c_;
        break;
    default:
        func_0205cf10(arg0->unknown_188_);
        func_0205cf1c((Struct_0205cf1c*)arg0->unknown_188_);
        return;
    }
    SetChannelAFlag0205cef8(battle->flags);
    SetChannelBFlag0205cf04(battle->flags);
    GridCursor_SetDimensions((GridCursor*)&battle->first, columns, rows, 0);
    GridCursor_SetDimensions((GridCursor*)&battle->second, columns, rows, 0);
    GridCursor_SetCount((GridCursor*)&battle->first, total);
    GridCursor_SetCount((GridCursor*)&battle->second, total);
    battle->first.level = pages;
    battle->second.level = pages;
    GridCursor_SelectIfValid((Struct_0205bcdc*)&battle->first, selected);
    GridCursor_SetSelectedIndex(&battle->second, selected);
}
