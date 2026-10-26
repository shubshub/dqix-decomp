#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215ffb4 data_ov006_02161318
#define data_ov006_0215ffc0 data_ov006_0216131b
#define data_ov006_0215ffc4 data_ov006_02161328
#define data_ov006_0215ffca data_ov006_02161336
#define data_ov006_0215ffe2 data_ov006_0216132e
#define data_ov006_0215fff4 data_ov006_02161346
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov006_021537d0 {
    short id_;
    short item_;
    short ingredients_[3];
    unsigned short unknown_a_0_ : 4;
    unsigned short unknown_a_4_ : 4;
    unsigned short unknown_b_0_ : 4;
    unsigned short unknown_b_4_ : 4;
    unsigned int unknown_c_0_ : 10;
    unsigned int unknown_d_2_ : 10;
    unsigned int kind_ : 8;
    unsigned int unknown_f_4_ : 4;
    unsigned int unknown_10_0_ : 10;
    unsigned int unknown_11_2_ : 10;
    unsigned int unknown_12_4_ : 2;
    unsigned int unknown_12_6_ : 1;
    unsigned int unknown_12_7_ : 9;
};

struct Struct_02071d60;

extern "C" Struct_ov006_021537d0* func_02071d60(Struct_02071d60* list, int key);

struct PartyMemberData {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
    unsigned int unknown_4_0_ : 10;
    unsigned int unknown_5_2_ : 10;
    unsigned int unknown_6_4_ : 10;
    unsigned int unknown_7_6_ : 2;
    unsigned int unknown_8_0_ : 10;
    unsigned int unknown_9_2_ : 22;
};

struct PrimaryCombatStats {
    unsigned short currHP;
    unsigned short currMP;
    unsigned short maxHP;
    unsigned short maxMP;
};

struct BaseCombatStats {
    char name[0x2C];
    PrimaryCombatStats primaryStats;
};

class GameObject {
public:
    char unk_0[0x134];
    BaseCombatStats* baseStats_;
    void* currentStats_;
    char unknown_13c_[R(8, 0x14)];
    PartyMemberData* unknown_150_;
};

class GameState {
public:
    static GameState* GetInstance();
    GameObject* GetProtagonist();
};

struct Struct_ov006_021537c8 {
    Struct_02071d60* table_;
};

// USA: func_ov006_02153f24
extern "C" ARM short func_ov006_02153f24(Struct_ov006_021537c8* self, short id) {
    Struct_ov006_021537d0* var0 = func_02071d60(self->table_, id);
    if (var0 == 0)
        return 0;
    short rate = 100;
    if (var0->unknown_b_4_ != 0) {
        GameObject* protagonist = GameState::GetInstance()->GetProtagonist();
        if (protagonist != 0) {
            unsigned short value = 0;
            switch (var0->unknown_b_4_) {
            case 1:
                value = protagonist->unknown_150_->unknown_0_0_;
                break;
            case 2:
                value = protagonist->unknown_150_->unknown_1_2_;
                break;
            case 3:
                value = protagonist->unknown_150_->unknown_2_4_;
                break;
            case 4:
                value = protagonist->unknown_150_->unknown_4_0_;
                break;
            case 5:
                value = protagonist->unknown_150_->unknown_5_2_;
                break;
            case 6:
                value = protagonist->unknown_150_->unknown_6_4_;
                break;
            case 7:
                value = protagonist->unknown_150_->unknown_8_0_;
                break;
            case 8:
                value = protagonist->baseStats_->primaryStats.maxHP;
                break;
            case 9:
                value = protagonist->baseStats_->primaryStats.maxMP;
                break;
            }
            unsigned int var4 = var0->unknown_c_0_;
            unsigned int var5 = var0->unknown_d_2_;
            float var6 = var5 - var4;
            unsigned int var7 = var0->unknown_10_0_;
            float var8 = var0->unknown_11_2_ - var7;
            rate = (int)(((float)value - var7) * (var6 / var8)) + var4;
            if (rate > 100)
                rate = 100;
            else if (rate < 0)
                rate = 0;
            if (rate <= var4)
                rate = var4;
            if (var5 <= rate)
                rate = var5;
        }
    }
    return rate;
}
