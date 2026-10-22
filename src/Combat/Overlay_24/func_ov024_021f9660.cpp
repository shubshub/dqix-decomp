#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

struct Struct_ov024_021f9660 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 28;
    unsigned int unknown_b_4_ : 1;
    unsigned int unknown_b_5_ : 3;
    char unknown_c_[0xc];
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
    unsigned int unknown_19_4_ : 20;
    char unknown_1c_[0x10];
    unsigned int unknown_2c_0_ : 14;
    unsigned int unknown_2d_6_ : 6;
    unsigned int unknown_2e_4_ : 12;
};
struct Struct_ov024_021f9660_2 { short unknown_0_; short unknown_2_; };
struct Struct_ov024_021f9660_3 {
    char unknown_0_[6];
    unsigned char unknown_6_;
    char unknown_7_;
    GameObject* unknown_8_;
    char unknown_c_[0x20];
    unsigned char unknown_2c_;
    char unknown_2d_[7];
    unsigned char unknown_34_;
    char unknown_35_[3];
    int unknown_38_;
    int unknown_3c_;
    char unknown_40_[0x134];
    int unknown_174_;
    Struct_ov024_021f9660_2 unknown_178_[0x134];
    Struct_ov024_021f9660_2* unknown_648_;
    Struct_ov024_021f9660* unknown_64c_;
    int unknown_650_;
    unsigned char unknown_654_;
    unsigned char unknown_655_;
};
typedef void (Struct_ov024_021f9660_3::*Type_ov024_021f9660)();
struct Struct_ov024_021ffeac { Type_ov024_021f9660 unknown_0_[79]; };
extern Struct_ov024_021ffeac data_ov024_021ffeac;
extern unsigned int data_ov024_02200150;
extern SkillHandler021f9660 __ptmf_null;
void* GetFieldAt0x150_02053c6c(unsigned char*);
Skill021f9660* SearchBothTables02079e2c(char*, int);
extern "C" int func_ov024_021f8874(Planner021f9660*, Skill021f9660*, GameObject*, int*);

// USA: func_ov024_021f9660
extern "C" ARM void func_ov024_021f9660(Struct_ov024_021f9660_3* arg0) {
    GameObject* var0 = arg0->unknown_8_;
    func_02053c6c((unsigned char*)var0);
    Struct_02108e10* var1 = func_020797dc();
    if (!(data_ov024_02200150 & 1)) {
        SkillHandler021f9660 empty = __ptmf_null;
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
    for (int index = 0; index < planner->count; ++index) {
        Skill021f9660* skill = SearchBothTables02079e2c((char*)database, planner->skills[index].id);
        if (skill->excluded) continue;
        if (skill->restriction) continue;
        int cost;
        if (!func_ov024_021f8874(planner, skill, combatant, &cost)) continue;
        if (planner->mode == 4 && cost != 0) continue;
        planner->selected = &planner->skills[index];
        planner->selectedSkill = skill;
        planner->cost = cost;
        planner->field_34 = 0;
        planner->field_2c = 0;
        planner->active = 1;
        planner->field_38 = 0;
        planner->field_3c = 0;
        SkillHandler021f9660 handler = __ptmf_null;
        if (skill->handler <= 78) handler = data_ov024_021ffeac.handlers[skill->handler];
        if (handler != 0) (planner->*handler)();
    }
}
