#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"
#include "Resource/GameResources.h"

struct Struct_02045cac;
struct Struct_ov023_021e49a4_2 {
    unsigned char unknown_0_[0xc00];
    Struct_0201099c_3 unknown_c00_;
};
struct Struct_ov023_021e49a4_3 {
    unsigned char unknown_0_[0x1f8];
    Struct_ov023_021e49a4_2 unknown_1f8_;
};
struct Struct_ov023_021e49a4_4 {
    Struct_ov023_021e49a4_3* unknown_0_;
    unsigned char unknown_4_[0x500 - 4];
    unsigned short unknown_500_[4][16];
    int unknown_580_[4];
    unsigned short unknown_590_[4][10];
    unsigned short unknown_5e0_[8];
    unsigned short unknown_5f0_[4][8];
    unsigned char unknown_630_[0x10];
    char* unknown_640_[2];
};
struct Struct_02000c9c_70 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
};
static inline int inline_ov023_021e49a4(Struct_02000c9c_70* arg0) { return arg0->unknown_4_; }
struct Struct_ov023_021e49a4_5 {
    unsigned char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
    unsigned char unknown_49c_1_ : 7;
    unsigned char unknown_49d_[0x950 - 0x49d];
    int unknown_950_;
};
struct Struct_ov023_021e49a4 {
    unsigned char unknown_0_[0x130];
    Struct_02000c9c_70* unknown_130_;
    char* unknown_134_;
    unsigned char unknown_138_[0x18];
    Struct_ov023_021e49a4_5* unknown_150_;
};
CombatSlots02045cac* MessageSystem_GetInstance();
void MessageSystem_ResetGlyphs(CombatSlots02045cac*);
char* StandardStrings_Get(int);
int KeyTable_Get(Container020e0310*, int);
int GetByteViaFieldIndirectOffset_021e4250_021e4250(char*);
extern const char data_ov023_021fdcd8[];
extern "C" {
void func_02045d14(CombatSlots02045cac*, const char*, unsigned short*, int);
int Font_GetTextWidth(const char*, int);
int func_ov017_021bdbcc(GameResources*);
void __clear(void*, unsigned int);
int sprintf(char*, const char*, ...);
void func_020439b0(Struct_02045cac*, int);
}

// USA: func_ov023_021e49a4
extern "C" ARM void func_ov023_021e49a4(BattleSetup021e49a4* self) {
    BattleTexts021e49a4* texts;
    GameState* game = GameState::GetInstance();
    unsigned short (*suffixes)[8];
    unsigned short (*labels)[10];
    unsigned short (*names)[16];
    CombatSlots02045cac* messages = MessageSystem_GetInstance();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) self->names[i][j] = 0xffff;
        for (int j = 0; j < 10; j++) self->labels[i][j] = 0xffff;
        for (int j = 0; j < 8; j++) self->suffixes[i][j] = 0xffff;
        self->positions[i] = 0;
    }
    for (int i = 0; i < 8; i++) self->default_label[i] = 0xffff;
    MessageSystem_ResetGlyphs(messages);
    texts = &self->battle->texts;
    func_02045d14(messages, StandardStrings_Get(0x3f3), self->default_label, 0);
    for (int i = 0; i < 4; i++) {
        names = self->names;
        labels = self->labels;
        suffixes = self->suffixes;
        Combatant021e49a4* combatant = (Combatant021e49a4*)GetCombatantWithFlag0x100_0200ff1c(game, i);
        if (combatant != 0) {
            char* name = combatant->name;
            func_02045d14(messages, name, names[i], 0);
            self->positions[i] = 35 - Font_GetTextWidth(name, 0) / 2;
            short label = combatant->data->label_id + 500;
            if (func_ov017_021bdbcc(GetGameResources())) label = 500;
            if (ConditionValue021e49a4(combatant->condition) <= 0) {
                func_02045d14(messages, self->buffers[combatant->data->selector], labels[i], 0);
            } else {
                func_02045d14(messages, (const char*)KeyTable_Get(&texts->dictionary, label), labels[i], 0);
            }
            unsigned char var15 = func_ov023_021e4250((char*)var12);
            char var16[16];
            __clear(var16, 16);
            if (var15 != 0) {
                sprintf(var16, data_ov023_021fdcd8, func_ov023_021e4250((char*)var12));
            }
            func_02045d14(var5, var16, var2[var11], 0);
            func_020439b0(var5, 0);
        }
    }
}
