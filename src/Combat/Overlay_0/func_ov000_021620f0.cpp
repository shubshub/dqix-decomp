#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

#if defined(jpn)
#define data_ov000_02182ff8 data_ov000_021840b0
#define data_ov000_02182fd4 data_ov000_0218408c
#endif

struct Struct_02070b6c_3;
struct Struct_0206f01c_2;
struct Struct_02048934 {
    unsigned char unknown_0_[0x2c];
    unsigned char unknown_2c_[1];
};
struct Struct_02048850;
struct Struct_02048850_2;

struct Struct_ov000_021620f0_7 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned char unknown_8_[0x1d];
    unsigned char unknown_25_;
    unsigned char unknown_26_[0xa4 - 0x26];

    unsigned char inline_ov000_021620f0_2() { return unknown_25_; }
};

struct Struct_ov000_021620f0_8 {
    Object3D unknown_0_;
    unsigned char unknown_ac_[0x134 - 0xac];
    unsigned char* unknown_134_;
    Struct_ov000_021620f0_7* unknown_138_;
    unsigned char unknown_13c_[0xc];
    Struct_02048934* unknown_148_;
    unsigned char unknown_14c_[0x30];
    unsigned char unknown_17c_;
    unsigned char unknown_17d_[7];
    unsigned char unknown_184_;
    unsigned char unknown_185_;
    unsigned short unknown_186_;
    unsigned short unknown_188_;
    unsigned short unknown_18a_;
    unsigned char unknown_18c_;
    unsigned char unknown_18d_;
    unsigned char unknown_18e_[2];
};

struct Struct_01ff91ac_8 { unsigned char unknown_0_[0x70]; };

struct Struct_ov000_021620f0 {
    unsigned char unknown_0_[0x158];
    Struct_ov000_021620f0_7 unknown_158_[8];
    unsigned char unknown_678_[0xc];
    unsigned char unknown_684_[0xc];
};

struct Struct_ov000_021620f0_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[8];
    unsigned char unknown_a_0_ : 4;
    unsigned char unknown_a_4_ : 4;
    unsigned char unknown_b_[2];
    unsigned char unknown_d_[8];
    unsigned char unknown_15_;
    unsigned char unknown_16_[2];
};

struct Struct_ov000_021620f0_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned int unknown_4_;
};

struct Struct_ov000_021620f0_4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    unsigned short unknown_2_;
    Struct_ov000_021620f0_2 unknown_4_[3];
    Struct_ov000_021620f0_3 unknown_4c_[4];
};

struct Struct_ov000_021620f0_5 {
    Random unknown_0_;
    unsigned char unknown_20_[0x81b0 - sizeof(Random)];
    Struct_ov000_021620f0_4 unknown_81b0_;

    Random* inline_ov000_021620f0() { return &unknown_0_; }
};

struct Struct_ov000_021620f0_6 {
#if defined(jpn)
    unsigned char unknown_0_[0x218];
    Struct_ov000_021620f0_5* unknown_29c_;
    Struct_ov000_021620f0* unknown_2a0_;
    unsigned char unknown_220_[0xe44 - 0x220];
    unsigned short unknown_ec8_;
    unsigned char unknown_e46_[0x6014 - 0xe46];
#else
    unsigned char unknown1_0_[0x29c];
    Struct_ov000_021620f0_5* unknown_29c_;
    Struct_ov000_021620f0* unknown_2a0_;
    unsigned char unknown_2a4_[0xec8 - 0x2a4];
    unsigned short unknown_ec8_;
    unsigned char unknown_eca_[0x5e24 - 0xeca];
#endif
    Struct_ov000_021620f0_8 unknown_5e24_[8];
    Struct_01ff91ac_8 unknown_6aa4_[8];
};

extern "C" void* LinkSession_GetInstance(void);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* gameState, int combatantId);
struct ZeroableStruct021620d8;
void ZeroStruct021620d8(ZeroableStruct021620d8*);
FieldStruct02048934* SearchWithLow15Comparator02070fd0(Container02070e60* table, int key);
Param02048850* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct* table, int key);
void FindOrAssignSlot02167c28(unsigned char* obj, int id);
extern "C" int func_ov000_02161bb8(unsigned char* obj);
extern "C" void func_020891cc(void* obj);
extern "C" void func_02089630(void* dst, void* src, int useExactValue);
extern "C" void func_02049c88(void* obj, void* model);
void RegisterCombatantSlot_0200fd38(GameState* gameState, int id, GameObject* combatant);
void SyncNameFlag_02161274(GameObject* obj);
void SetRandomizedShort0x18802048934(void* p, FieldStruct02048934* f, Random* r);
void IncrementByteCounterWrapAt0x12_ov000_02161bec(unsigned char* p);
void ResetNameState02048614(unsigned char* obj);
void SetupFieldsFromParam02048850(Obj02048850* obj, Param02048850* param);
void BuildName020488ec(char* obj);
void ClearSubstructByte0x56_02049f3c(unsigned char* obj);

extern const short data_ov000_02182ff8[][3];
extern const signed char data_ov000_02182fd4[][3];

// USA: func_ov000_021620f0
extern "C" ARM void func_ov000_021620f0(Scene021620f0* scene, int formation) {
    unsigned short kind;
    int id;
    Combatant021620f0* c;
    Formation021620f0* f = &scene->data->formation;
    GameState* game = GameState::GetInstance();
    LinkSession_GetInstance();
    Container02070e60* names = (Container02070e60*)scene->roster->names;
    BinarySearchByComparatorStruct* infos = (BinarySearchByComparatorStruct*)scene->roster->infos;
    f->total = 0;
    f->alive = 0;
    f->groupCount = 0;
    f->pairCount = 0;
    f->field_2 = 0;
    for (int i = 0; i < 3; i++) {
        memset(&f->groups[i], 0, sizeof(Group021620f0));
    }
    for (int var8 = 0; var8 < 4; var8++) {
        func_ov000_021620d8((Struct_ov000_02161e30_3*)&var3->unknown_4c_[var8]);
    }
    const short* var9 = data_ov000_02182ff8[arg1];
    const signed char* var10 = data_ov000_02182fd4[arg1];
    int var11;
    for (var11 = 0, var1 = 0; var9[var11] != -1; var11++) {
        Struct_02048934* var12 = func_02070fd0(var5, var9[var11]);
        Struct_02048850_2* var13 = func_0206f4f0(var6, var9[var11]);
        if (!var12 || !var13) return;
        int var14 = var9[var11];
        var0 = var14;
        var3->unknown_4_[var11].unknown_0_ = var0;
        var3->unknown_4c_[var11].unknown_2_ = var0;
        var3->unknown_4c_[var11].unknown_0_ = 1;
        var3->unknown_1_4_++;
        var3->unknown_1_6_++;
        for (int var15 = 0; var15 < var10[var11]; var15++, var1++) {
            var2 = (Struct_ov000_021620f0_8*)func_0200fea4(var4, var1 + 0xc0);
            Struct_ov000_021620f0_7* var16 = &arg0->unknown_2a0_->unknown_158_[var1];
            func_020891cc(var16);
            if (!var2) {
                func_ov000_02167c28((unsigned char*)arg0, var1 + 0xc0);
                var2 = &arg0->unknown_5e24_[var1];
                func_02048614((unsigned char*)var2);
                func_02049c88(var2, &arg0->unknown_6aa4_[var1]);
                func_02089630(var16, var12->unknown_2c_, 0);
                var2->unknown_0_.SetField06(arg0->unknown_ec8_);
                var2->unknown_138_ = var16;
                var2->unknown_134_ = var12->unknown_2c_;
                var2->unknown_148_ = var12;
                func_02048850((Struct_02048850*)var2, var13);
                var2->unknown_0_.MakeHidden();
                func_02049f3c((unsigned char*)var2);
                func_0200fd38(var4, var1 + 0xc0, (GameObject*)var2);
            }
            func_02048934(var2, var12, arg0->unknown_29c_->inline_ov000_021620f0());
            unsigned short var17 = var2->unknown_188_;
            unsigned short var18 = var2->unknown_18a_;
            var2->unknown_138_->unknown_0_ = var17;
            var2->unknown_138_->unknown_4_ = var17;
            var2->unknown_138_->unknown_2_ = var18;
            var2->unknown_138_->unknown_6_ = var18;
            unsigned char var19 = func_ov000_02161bb8((unsigned char*)&var3->unknown_4c_[var11]);
            if (var19 == 1) {
                var19 = 0;
            } else if (var19 == 2) {
                func_ov000_02161274((GameObject*)var2);
            }
            var2->unknown_0_.unknown_2_ = var14;
            var2->unknown_17c_ = var11;
            var2->unknown_138_->unknown_25_ = var19;
            func_020488ec((char*)var2);
            var2->unknown_186_ = var0;
            var2->unknown_18c_ = var11;
            var2->unknown_18d_ = var19;
            var2->unknown_184_ = 1;
            int var20 = var2->unknown_138_->inline_ov000_021620f0_2();
            var3->unknown_4c_[var11].unknown_4_ |= 1 << var20;
            func_ov000_02161bec((unsigned char*)&var3->unknown_4c_[var11]);
            var3->unknown_4_[var11].unknown_2_[var15] = var1;
            var3->unknown_4_[var11].unknown_a_0_++;
            var3->unknown_4_[var11].unknown_a_4_++;
            var3->unknown_0_++;
            var3->unknown_1_0_++;
        }
    }
}
