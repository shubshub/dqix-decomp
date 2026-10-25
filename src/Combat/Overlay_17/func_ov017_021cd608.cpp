#if defined(jpn)
enum { Enum_ov017_021cd608_1816 = 0x508 };
#else
enum { Enum_ov017_021cd608_1816 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021cd608_3 {
    char unknown_0_[8];
    unsigned short unknown_8_;
};

extern "C" struct Owner021cd608* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
int GameState_GetProtagonistIndex(GameState* battleStruct);
int LoadBattleBlock020ac4c0(void* dst);
int CopyInBattleField0x7540_020ac494(void* src);
void CopyFourAndSetFlag02163378(void* dst, int* src, unsigned char val);

struct Struct_020a0858 {
    char unknown_0_[0x48];
    unsigned int unknown_48_;
};

struct Struct_020a0300 {
    char unknown_0_[0x24];
    unsigned int unknown_24_0_ : 24;
    unsigned int unknown_27_0_ : 8;
};

extern "C" void func_020a0858(struct Struct_020a0858* arg0, unsigned int arg1);
extern "C" void func_020a0300(struct Struct_020a0300* arg0, unsigned int arg1);

struct Struct_ov017_021cd608_4 {
    struct Struct_020a0858 unknown_0_;
    char unknown_4c_[0x68 - sizeof(struct Struct_020a0858)];
    struct Struct_020a0300 unknown_68_;
    char unknown_90_[0xb0 - 0x68 - sizeof(struct Struct_020a0300)];
};

struct Struct_ov017_021cd608 {
    unsigned short unknown_0_;
    unsigned short unknown_2_[4];
    unsigned char unknown_a_[4];
    unsigned char unknown_e_;
    unsigned char unknown_f_;
};

struct Struct_ov017_021cd608_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    struct Struct_ov017_021cd608 unknown_4_;
};

// USA: func_ov017_021cd608
extern "C" ARM void func_ov017_021cd608(int arg0, struct Struct_ov017_021cd608_2* arg1, int arg2, unsigned char* arg3) {
    int var0;
    void* var1 = *(void**)(arg3 + 0x3000 + Enum_ov017_021cd608_1816);
    struct Struct_ov017_021cd608* var2 = &arg1->unknown_4_;
    int var3[4];
    struct Struct_ov017_021cd608_4 var4;

    struct Struct_ov017_021cd608_3* var5 = func_ov017_021b8478(var1);
    if (var5->unknown_8_ != var2->unknown_0_) {
        return;
    }
    void* var6 = func_ov017_021b8468(var1);
    if (var6 == 0) {
        return;
    }
    for (var0 = 0; var0 < 4; var0++) {
        var3[var0] = var2->unknown_2_[var0] + (var2->unknown_a_[var0] << 16);
    }
    if (p->apply) {
        int idx = GameState_GetProtagonistIndex(GameState::GetInstance());
        LoadBattleBlock020ac4c0(&block);
        AddSaturateField0x48_020a0858(&block.head, amounts[idx]);
        AddClamped24BitFieldAt0x24_020a0300(&block.tail, amounts[idx]);
        CopyInBattleField0x7540_020ac494(&block);
    } else {
        func_ov000_02163378(var6, var3, var2->unknown_e_);
    }
}
