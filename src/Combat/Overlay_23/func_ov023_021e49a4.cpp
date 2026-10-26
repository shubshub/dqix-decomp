#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"
#include "Resource/GameResources.h"

struct CombatSlots02045cac;
struct Struct_ov023_021e49a4_2 {
    unsigned char unknown_0_[0xc00];
    Container020e0310 dictionary;
};
struct Struct_ov023_021e49a4_3 {
    unsigned char unknown_0_[0x1f8];
    Struct_ov023_021e49a4_2 texts;
};
struct Struct_ov023_021e49a4_4 {
    Struct_ov023_021e49a4_3* battle;
    unsigned char unknown_4_[0x500 - 4];
    unsigned short names[4][16];
    int positions[4];
    unsigned short labels[4][10];
    unsigned short default_label[8];
    unsigned short unknown_5f0_[4][8];
    unsigned char unknown_630_[0x10];
    char* buffers[2];
};
struct Struct_02000c9c_70 {
    unsigned int field_0;
    unsigned short value;
};
static inline int inline_ov023_021e49a4(Struct_02000c9c_70* arg0) { return arg0->value; }
struct Struct_ov023_021e49a4_5 {
    unsigned char unknown_0_[0x49c];
    unsigned char selector : 1;
    unsigned char flags : 7;
    unsigned char unknown_49d_[0x950 - 0x49d];
    int unknown_950_;
};
struct Struct_ov023_021e49a4 {
    unsigned char unknown_0_[0x130];
    Struct_02000c9c_70* unknown_130_;
    char* name;
    unsigned char unknown_138_[0x18];
    Struct_ov023_021e49a4_5* data;
};
extern "C" CombatSlots02045cac* MessageSystem_GetInstance();
extern "C" void MessageSystem_ResetGlyphs(CombatSlots02045cac*);
extern "C" char* StandardStrings_Get(int);
extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" int func_ov023_021e4250(char*);
extern const char data_ov023_021fdcd8[];
extern "C" {
void func_02045d14(CombatSlots02045cac*, const char*, unsigned short*, int);
int Font_GetTextWidth(const char*, int);
int func_ov017_021bdbcc(GameResources*);
void __clear(void*, unsigned int);
int sprintf(char*, const char*, ...);
void func_020439b0(CombatSlots02045cac*, int);
}

// USA: func_ov023_021e49a4
extern "C" ARM void func_ov023_021e49a4(Struct_ov023_021e49a4_4* self) {
    Struct_ov023_021e49a4_2* texts;
    GameState* game = GameState::GetInstance();
    unsigned short (*var2)[8];
    unsigned short (*labels)[10];
    unsigned short (*names)[16];
    CombatSlots02045cac* messages = MessageSystem_GetInstance();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) self->names[i][j] = 0xffff;
        for (int j = 0; j < 10; j++) self->labels[i][j] = 0xffff;
        for (int j = 0; j < 8; j++) self->unknown_5f0_[i][j] = 0xffff;
        self->positions[i] = 0;
    }
    for (int i = 0; i < 8; i++) self->default_label[i] = 0xffff;
    MessageSystem_ResetGlyphs(messages);
    texts = &self->battle->texts;
    func_02045d14(messages, StandardStrings_Get(0x3f3), self->default_label, 0);
    for (int i = 0; i < 4; i++) {
        names = self->names;
        labels = self->labels;
        var2 = self->unknown_5f0_;
        Struct_ov023_021e49a4* combatant = (Struct_ov023_021e49a4*)func_0200ff1c(game, i);
        if (combatant != 0) {
            char* name = combatant->name;
            func_02045d14(messages, name, names[i], 0);
            self->positions[i] = 35 - Font_GetTextWidth(name, 0) / 2;
            short label = combatant->data->unknown_950_ + 500;
            if (func_ov017_021bdbcc(GetGameResources())) label = 500;
            if (inline_ov023_021e49a4(combatant->unknown_130_) <= 0) {
                func_02045d14(messages, self->buffers[combatant->data->selector], labels[i], 0);
            } else {
                func_02045d14(messages, (const char*)KeyTable_Get(&texts->dictionary, label), labels[i], 0);
            }
            unsigned char suffix = func_ov023_021e4250((char*)combatant);
            char buffer[16];
            __clear(buffer, 16);
            if (suffix != 0) {
                sprintf(buffer, data_ov023_021fdcd8, func_ov023_021e4250((char*)combatant));
            }
            func_02045d14(messages, buffer, var2[i], 0);
            func_020439b0(messages, 0);
        }
    }
}
