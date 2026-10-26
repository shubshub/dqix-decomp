#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

typedef unsigned char Type_020b1300;
typedef signed char Type_ov002_0215ab60;
typedef short Type_ov003_021666c4;
typedef unsigned int u32;

struct Struct_02080cc0 {
    Type_020b1300 unknown_0_[0x36];
    Type_ov003_021666c4 selected;
};
struct Container02080f8c;
struct Struct_02080fa8;
struct Struct_02081198;
struct Struct_02081164;
struct Struct_ov003_021666c4 {
    Type_020b1300 enabled : 1;
    Type_020b1300 count : 6;
    Type_020b1300 active : 1;
    char text[0x36];
};
struct Struct_ov003_021666c4_2 {
    Struct_ov003_021666c4 entries[10];
    Type_ov003_021666c4 unknown_226_;
    Type_020b1300 unknown_228_[0xb4];
    Container020e0310 messages;
    Type_020b1300 unknown_2e4_[0x40];
    Struct_02080cc0* menu;
    Type_020b1300 unknown_328_[0x13c];
    u32 flags;
    Type_020b1300 unknown_468_[0x38];
    Type_ov002_0215ab60 page;
    Type_020b1300 unknown_4a1_[0x1c];
    Type_020b1300 selection;
};

extern "C" void func_02080b54(void*, int);
extern "C" void LinkSession_GetInstance();
extern "C" void func_02080cc0(Struct_02080cc0*, int, int);
extern "C" void func_02080b40(void*, int);
extern "C" void func_02080f8c(Container02080f8c*, int, int);
extern "C" void func_02080fa8(Struct_02080fa8*, int, int);
extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" void func_02081198(Struct_02081198*, int, int);
extern "C" void func_02081164(Struct_02081164*, int, int);
extern "C" void func_020813ec(void*, int);
extern "C" void func_ov003_02160794(Struct_ov003_021666c4_2*);

// USA: func_ov003_021666c4
extern "C" ARM void func_ov003_021666c4(Struct_ov003_021666c4_2* self) {
    Struct_02080cc0* menu = self->menu;
    func_02080b54(menu, 16);
    int id = 69;
    LinkSession_GetInstance();
    self->selection = id;
    int index = self->page * 4;
    int end = index + 4;
    for (; index < end; id = (Type_ov003_021666c4)(id + 1), index++) {
        int color = 15;
        if (id == menu->selected) color = 10;
        func_02080cc0(menu, id, color);
        Struct_ov003_021666c4* entry = &self->entries[index];
        if (entry->active && index < self->unknown_226_) {
            char* text;
            int count;
            if (entry->enabled) {
                text = entry->text;
                count = 4 - entry->count;
            } else {
                if (id == menu->selected) func_02080cc0(menu, id, 8);
                else func_02080cc0(menu, id, 4);
                text = entry->text;
                count = 0;
            }
            for (int row = 1; row < 3; row = (Type_ov003_021666c4)(row + 1)) {
                int var9 = id + row * 4;
                func_02080cc0(menu, (Type_ov003_021666c4)var9, color);
                func_02080b40(menu, (Type_ov003_021666c4)(unsigned int)var9);
            }
            func_02080f8c((Container02080f8c*)menu, id, (int)text);
            func_02080fa8((Struct_02080fa8*)menu, (Type_ov003_021666c4)(id + 4), count);
        } else {
            int text = KeyTable_Get(&self->messages, 30000);
            func_02080f8c((Container02080f8c*)menu, (Type_ov003_021666c4)id, text);
        }
        func_02080b40(menu, id);
    }
    func_02080fa8((Struct_02080fa8*)menu, 201, self->page + 1);
    func_02080fa8((Struct_02080fa8*)menu, 202, 2);
    func_02080b40(menu, 200);
    func_02080b40(menu, 201);
    func_02080b40(menu, 202);
    func_02081198((Struct_02081198*)menu, 16, 1);
    func_02081164((Struct_02081164*)menu, 16, 1);
    func_020813ec(menu, 16);
    self->flags |= 0xd00000;
    func_ov003_02160794(self);
}
