#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FormationPosition.h"

struct Struct_ov000_021676a8 {
    char unknown_0_[0x8e20];
    int unknown_8e20_;
};

struct Struct_ov000_021676a8_2 {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x29c];
#endif
    Struct_ov000_021676a8* unknown_29c_;
};

extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int start);
int ClassifyField0x81fe_ov000_0215fc60(char* self);
int GetSubstructByte0x1c_020493a4(unsigned char* obj);
void SetSubstructByte0x1c_02049390(unsigned char* obj, unsigned char value);
void SetSubstructFields0x10And0x18ClearFlag0x1_02049bd4(unsigned char* obj, int* src);
void SetSubstructField0x14ClearFlag0x1_02049c60(unsigned char* obj, int* src);

struct Struct_ov000_021830c0 { unsigned int unknown_0_[3]; };
extern unsigned char data_ov000_02183108[][4];
extern struct Struct_ov000_021830c0 data_ov000_021830fc;
extern struct Struct_ov000_021830c0 data_ov000_021830c0;

static inline Struct_02048cf0 inline_02048e2c_2(const int& arg0) {
    return func_ov000_0216f74c(const_cast<int*>(&arg0));
}

// USA: func_ov000_021676a8
extern "C" ARM void func_ov000_021676a8(Owner_021676a8* obj) {
    GameState* battle = GameState::GetInstance();
    battle->GetResources();
    BattleCore_021676a8* core = obj->core;
    short ids[4];
    int count = func_ov000_0215e9fc(core, ids, 4, 0);
    if (ClassifyField0x81fe_ov000_0215fc60((char*)core) != 0) {
        count = 1;
    }
    int var4;
    for (var4 = 0; var4 < var3; var4++) {
        GameObject* var5 = var0->GetCombatantByIndex(var2[var4]);
        if (var5 != 0) {
            int var6 = data_ov000_02183108[var3 - 1][var4];
            if (func_020493a4((unsigned char*)var5) != 0xff && arg0->unknown_29c_->unknown_8e20_ != 0) {
                var6 = func_020493a4((unsigned char*)var5);
            }
            Struct_02048cf0 var7 = inline_02048e2c_2(var6);
            struct Struct_ov000_021830c0 var8 = data_ov000_021830fc;
            struct Struct_ov000_021830c0 var9 = data_ov000_021830c0;
            var8.unknown_0_[0] = var7.unknown_0_;
            var8.unknown_0_[2] = var7.unknown_4_;
            func_02049390((unsigned char*)var5, (unsigned char)(var6 & 0xff));
            func_02049bd4((unsigned char*)var5, (int*)&var8);
            func_02049c60((unsigned char*)var5, (int*)&var9);
        }
    }
}
