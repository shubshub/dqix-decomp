#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

typedef unsigned char Type_020b1300;
typedef signed char Type_ov002_0215ab60;
typedef short Type_ov003_021666c4;
typedef unsigned int Type_020b11c8;

struct Struct_02080cc0 {
    Type_020b1300 unknown_0_[0x36];
    Type_ov003_021666c4 unknown_36_;
};
struct Struct_02080f8c;
struct Struct_02080fa8;
struct Struct_02081198;
struct Struct_02081164;
struct Struct_ov003_021666c4 {
    Type_020b1300 unknown_0_0_ : 1;
    Type_020b1300 unknown_0_1_ : 6;
    Type_020b1300 unknown_0_7_ : 1;
    char unknown_1_[0x36];
};
struct Struct_ov003_021666c4_2 {
    Struct_ov003_021666c4 unknown_0_[10];
    Type_ov003_021666c4 unknown_226_;
    Type_020b1300 unknown_228_[0xb4];
    Struct_0201099c_3 unknown_2dc_;
    Type_020b1300 unknown_2e4_[0x40];
    Struct_02080cc0* unknown_324_;
    Type_020b1300 unknown_328_[0x13c];
    Type_020b11c8 unknown_464_;
    Type_020b1300 unknown_468_[0x38];
    Type_ov002_0215ab60 unknown_4a0_;
    Type_020b1300 unknown_4a1_[0x1c];
    Type_020b1300 unknown_4bd_;
};

void SetSublistEntriesFlag1_02080b54(void*, int);
extern "C" void LinkSession_GetInstance();
void SetEntryHighNibble0x13(Container02080cc0*, int, int);
void SetEntryFlagById02080b40(void*, int);
void SetEntryFirstField02080f8c(Container02080f8c*, int, int);
void SetEntryFirstField02080fa8(Container02080fa8*, int, int);
int KeyTable_Get(Container020e0310*, int);
void SetEntryNibbleByShortId(StatusOwner02081198*, int, int);
void SetEntryFlag0x2ByShortId(StatusOwner02081164*, int, int);
extern "C" void func_020813ec(void*, int);
extern "C" void func_ov003_02160794(Struct_ov003_021666c4_2*);

// USA: func_ov003_021666c4
extern "C" ARM void func_ov003_021666c4(CombatMenu021666c4* self) {
    Container02080cc0* menu = self->menu;
    SetSublistEntriesFlag1_02080b54(menu, 16);
    int id = 69;
    LinkSession_GetInstance();
    self->selection = id;
    int index = self->page * 4;
    int end = index + 4;
    for (; index < end; id = (s16)(id + 1), index++) {
        int color = 15;
        if (id == menu->selected) color = 10;
        SetEntryHighNibble0x13(menu, id, color);
        CombatMenuEntry021666c4* entry = &self->entries[index];
        if (entry->active && index < self->entry_count) {
            char* text;
            int count;
            if (entry->enabled) {
                text = entry->text;
                count = 4 - entry->count;
            } else {
                if (var1 == var0->unknown_36_) func_02080cc0(var0, var1, 8);
                else func_02080cc0(var0, var1, 4);
                var6 = var5->unknown_1_;
                var7 = 0;
            }
            for (int var8 = 1; var8 < 3; var8 = (Type_ov003_021666c4)(var8 + 1)) {
                int var9 = var1 + var8 * 4;
                func_02080cc0(var0, (Type_ov003_021666c4)var9, var4);
                func_02080b40(var0, (Type_ov003_021666c4)(unsigned int)var9);
            }
            func_02080f8c((Struct_02080f8c*)var0, var1, (int)var6);
            func_02080fa8((Struct_02080fa8*)var0, (Type_ov003_021666c4)(var1 + 4), var7);
        } else {
            int text = KeyTable_Get(&self->messages, 30000);
            SetEntryFirstField02080f8c((Container02080f8c*)menu, (s16)id, text);
        }
        func_02080b40(var0, var1);
    }
    func_02080fa8((Struct_02080fa8*)var0, 201, arg0->unknown_4a0_ + 1);
    func_02080fa8((Struct_02080fa8*)var0, 202, 2);
    func_02080b40(var0, 200);
    func_02080b40(var0, 201);
    func_02080b40(var0, 202);
    func_02081198((Struct_02081198*)var0, 16, 1);
    func_02081164((Struct_02081164*)var0, 16, 1);
    func_020813ec(var0, 16);
    arg0->unknown_464_ |= 0xd00000;
    func_ov003_02160794(arg0);
}
