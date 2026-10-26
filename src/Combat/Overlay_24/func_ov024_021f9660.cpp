#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

struct Struct_ov024_021f9660 {
    char field_0[8];
    unsigned int field_8 : 28;
    unsigned int excluded : 1;
    unsigned int unknown_b_5_ : 3;
    char unknown_c_[0xc];
    unsigned int field_18 : 5;
    unsigned int handler : 7;
    unsigned int unknown_19_4_ : 20;
    char field_1c[0x10];
    unsigned int unknown_2c_0_ : 14;
    unsigned int unknown_2d_6_ : 6;
    unsigned int unknown_2e_4_ : 12;
};
struct Struct_ov024_021f9660_2 { short id; short flags; };
struct Struct_ov024_021f9660_3 {
    char field_0[6];
    unsigned char mode;
    char unknown_7_;
    GameObject* combatant;
    char unknown_c_[0x20];
    unsigned char unknown_2c_;
    char unknown_2d_[7];
    unsigned char unknown_34_;
    char unknown_35_[3];
    int unknown_38_;
    int unknown_3c_;
    char unknown_40_[0x134];
    int count;
    Struct_ov024_021f9660_2 unknown_178_[0x134];
    Struct_ov024_021f9660_2* selected;
    Struct_ov024_021f9660* selectedSkill;
    int unknown_650_;
    unsigned char unknown_654_;
    unsigned char active;
};
typedef void (Struct_ov024_021f9660_3::*Type_ov024_021f9660)();
struct Struct_ov024_021ffeac { Type_ov024_021f9660 handlers[79]; };
extern Struct_ov024_021ffeac data_ov024_021ffeac;
extern unsigned int data_ov024_02200150;
extern Type_ov024_021f9660 __ptmf_null;
extern "C" void* func_02053c6c(unsigned char*);
extern "C" Struct_ov024_021f9660* func_02079e2c(char*, int);
extern "C" int func_ov024_021f8874(Struct_ov024_021f9660_3*, Struct_ov024_021f9660*, GameObject*, int*);

// USA: func_ov024_021f9660
extern "C" ARM void func_ov024_021f9660(Struct_ov024_021f9660_3* arg0) {
    GameObject* combatant = arg0->combatant;
    func_02053c6c((unsigned char*)combatant);
    ActionDataTables* var1 = func_020797dc();
    if (!(data_ov024_02200150 & 1)) {
        Type_ov024_021f9660 empty = __ptmf_null;
        data_ov024_021ffeac.handlers[0] = empty;
        data_ov024_021ffeac.handlers[11] = empty;
        data_ov024_021ffeac.handlers[12] = empty;
        data_ov024_021ffeac.handlers[29] = empty;
        data_ov024_021ffeac.handlers[30] = empty;
        data_ov024_021ffeac.handlers[31] = empty;
        data_ov024_021ffeac.handlers[34] = empty;
        data_ov024_021ffeac.handlers[35] = empty;
        data_ov024_021ffeac.handlers[44] = empty;
        data_ov024_021ffeac.handlers[45] = empty;
        data_ov024_021ffeac.handlers[52] = empty;
        data_ov024_021ffeac.handlers[57] = empty;
        data_ov024_021ffeac.handlers[58] = empty;
        data_ov024_021ffeac.handlers[59] = empty;
        data_ov024_021ffeac.handlers[60] = empty;
        data_ov024_021ffeac.handlers[65] = empty;
        data_ov024_021ffeac.handlers[66] = empty;
        data_ov024_02200150 |= 1;
    }
    for (int index = 0; index < arg0->count; ++index) {
        Struct_ov024_021f9660* skill = func_02079e2c((char*)var1, arg0->unknown_178_[index].id);
        if (skill->excluded) continue;
        if (skill->unknown_2d_6_) continue;
        int var5;
        if (!func_ov024_021f8874(arg0, skill, combatant, &var5)) continue;
        if (arg0->mode == 4 && var5 != 0) continue;
        arg0->selected = &arg0->unknown_178_[index];
        arg0->selectedSkill = skill;
        arg0->unknown_650_ = var5;
        arg0->unknown_34_ = 0;
        arg0->unknown_2c_ = 0;
        arg0->active = 1;
        arg0->unknown_38_ = 0;
        arg0->unknown_3c_ = 0;
        Type_ov024_021f9660 handler = __ptmf_null;
        if (skill->handler <= 78) handler = data_ov024_021ffeac.handlers[skill->handler];
        if (handler != 0) (arg0->*handler)();
    }
}
