#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"

struct Struct_ov017_021aa1ac {
    char unknown_0_[0xf78];
    signed char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_ov017_021aa1ac_2 {
#if defined(jpn)
    char unknown_0_[0x868];
#else
    char unknown1_0_[0x998];
#endif
    int unknown_998_;
#if defined(jpn)
    char unknown_86c_[0x17e2 - 0x86c];
#else
    char unknown_99c_[0x19b2 - 0x99c];
#endif
    unsigned char unknown_19b2_;
};

struct Struct_ov017_021aa1ac_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    short unknown_8_[4];
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    unsigned short unknown_12_;
};

Controller021aa1ac* MessageSystem_GetInstance(void);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void __clear(void* dst, unsigned int size);
#if defined(jpn)
extern "C" void func_0204500c(Struct_ov017_021aa1ac_2* arg0, const char* arg1, int arg2);
#else
extern "C" void func_0204500c(Struct_ov017_021aa1ac_2* arg0, const char* arg1, int arg2, int arg3);
#endif
extern "C" int func_ov017_021aa080(void);

extern char data_ov017_021d783c[];
extern char data_ov017_021d7868[];

// Overlay 17, originally func_ov017_021aa1ac (USA/EUR 0x021aa1ac, JPN 0x021aaa1c)
extern "C" ARM void FieldTask_SetPartyHpToOne(Self021aa1ac* self) {
    GameState* gs = GameState::GetInstance();
    Party021aa1ac* party = (Party021aa1ac*)GameState_GetParty(gs);
    Controller021aa1ac* controller = MessageSystem_GetInstance();
    int memberCount = party->memberCount;
    if (self->step == 0) {
        memset(self->ids, -1, sizeof(self->ids));
        self->shown = 0;
        self->count = 0;
        for (int i = 0; i < memberCount; i++) {
            int id = party->memberIds[i];
            GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(gs, id);
            if (combatant == NULL) {
                continue;
            }
            Struct_020200c0* var7 = var6->unknown_ac_.unknown_84_;
            if (var7->unknown_0_ & 1) {
                continue;
            }
            var7->unknown_4_ = 1;
            func_ov017_021c9e00(var5, 1, 0, 1);
            arg0->unknown_8_[arg0->unknown_10_++] = var5;
        }
        if (arg0->unknown_10_ != 0) {
            char var8[0x100];
            __clear(var8, sizeof(var8));
            sprintf(var8, data_ov017_021d783c, func_0200ff1c(var0, arg0->unknown_8_[0])->baseStats_);
            if (++arg0->unknown_11_ >= arg0->unknown_10_) {
                arg0->unknown_12_++;
            } else {
                strcat(var8, data_ov017_021d7868);
            }
#if defined(jpn)
            func_0204500c(var2, var8, 0);
#else
            func_0204500c(var2, var8, 0, 0xe3);
#endif
            var2->unknown_19b2_ = 0;
            var2->unknown_998_ = 1;
        }
        arg0->unknown_12_++;
    } else if (arg0->unknown_12_ == 1) {
        if (func_ov017_021aa080() == 0) {
            return;
        }
        if (arg0->unknown_11_ >= arg0->unknown_10_) {
            return;
        }
        char var9[0x100];
        __clear(var9, sizeof(var9));
        sprintf(var9, data_ov017_021d783c, func_0200ff1c(var0, arg0->unknown_8_[arg0->unknown_11_])->baseStats_);
        if (++arg0->unknown_11_ >= arg0->unknown_10_) {
            arg0->unknown_12_++;
        } else {
            strcat(var9, data_ov017_021d7868);
        }
#if defined(jpn)
        func_0204500c(var2, var9, 0);
#else
        func_0204500c(var2, var9, 0, 0xe3);
#endif
        var2->unknown_19b2_ = 0;
        var2->unknown_998_ = 1;
    } else if (arg0->unknown_12_ == 2) {
        if (func_ov017_021aa080() != 0) {
            arg0->unknown_1_ = 1;
        }
    }
}
