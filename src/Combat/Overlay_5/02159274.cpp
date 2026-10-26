#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov005_02159274_3684 = 0xe60, Enum_ov005_02159274_2400 = 0x800, Enum_ov005_02159274_3812 = 0xee0 };
#else
enum { Enum_ov005_02159274_3684 = 0xe64, Enum_ov005_02159274_2400 = 0x960, Enum_ov005_02159274_3812 = 0xee4 };
#endif

#include <std_library_functions.h>
#include <GameState/GameState.h>

struct Struct_020e28dc;
struct Struct_020e263c_2;
struct SePlayer;
struct StructA0205d5d0;
struct ItemTable;
struct Struct_020dd768;

struct Struct_ov005_02159274 {
    unsigned int amount : 4;
    unsigned int pad0 : 14;
    unsigned int unknown_2_2_ : 1;
    unsigned int pad1 : 13;
};

struct Struct_ov005_02159274_2 {
    short id;
    signed char count;
    unsigned char equipped;
    void* vramState;
    void* model;
    int x;
    int y;
    int offset;
    short unknown_18_;
};

struct Struct_ov005_02159274_3 {
    char unknown0[0xdf4];
    ItemTable* items_;
    char unknown_df8_[0xe10 - 0xdf8];
    char* text_;
    char unknown_e14_[Enum_ov005_02159274_3684 - 0xe14];
    void* unknown_e64_;
#if defined(jpn)
    char unknown1_e64_[0x2d08 - Enum_ov005_02159274_3684 - 4];
#else
    char unknown_e68_[0x2d90 - Enum_ov005_02159274_3684 - 4];
#endif
    Struct_ov005_02159274_2 slots[24];
    char unknown_3030_[0x3daa - 0x3030];
    unsigned char unknown_3daa_;
    char unknown_3dab_[0x3dbb - 0x3dab];
    signed char selectedSlot;
    char unknown_3dbc_[0x3dcc - 0x3dbc];
    unsigned int unknown_3dcc_;
    unsigned char unknown_3dd0_;
    unsigned char message_;
    char unknown_3dd2_[0x3ddc - 0x3dd2];
    unsigned char step_;
    unsigned char unknown_3ddd_;
    unsigned char unknown_3dde_;
    unsigned char unknown_3ddf_;
};

extern "C" char g_sePlayer[];

extern "C" int func_020e28dc(Struct_020e28dc* o);
extern "C" void func_020e263c(Struct_020e263c_2* w, int value);
extern "C" void func_ov005_021589f4(void* self);
extern "C" void func_ov005_02159b74(void* self);
extern "C" int func_ov005_02158b3c(void* object, void* buffer);
extern "C" int func_020e2918(signed char*);
extern "C" void SePlayer_Play(SePlayer* obj, int a, int b);
struct Struct_020e25e8;
extern "C" void func_020e25e8(Struct_020e25e8*);
extern "C" int func_020e2984(struct Struct_020e28dc* window);
extern "C" void* ItemTable_Find(ItemTable* c, int key);
extern "C" int func_020dd768(Struct_020dd768* s);
extern "C" void EquipMenu_EquipItem(void* self, int key, int keep);
struct Struct_0207c484;
extern "C" void func_0207c484(Struct_0207c484*, int, int, int);
extern "C" void func_ov005_021555c0(void* self);

// USA: func_ov005_02159274
extern "C" ARM void func_ov005_02159274(Struct_ov005_02159274_3* self) {
    int sel = GameState::GetInstance()->GetTickCount();
    if (sel == 0)
        sel = 1;

    if (self->unknown_e64_ != 0 && func_020e28dc((Struct_020e28dc*)self->unknown_e64_))
        func_020e263c((Struct_020e263c_2*)self->unknown_e64_, sel);

    if (self->step_ == 0) {
        self->message_ = 8;
        func_ov005_021589f4(self);
        func_ov005_02159b74(self);
        self->step_++;
        return;
    }
    if (self->step_ == 1) {
        sel = func_020e2918((signed char*)self->unknown_e64_);
        if (sel >= 0) {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            func_020e25e8((Struct_020e25e8*)self->unknown_e64_);
        } else if (func_020e2984((struct Struct_020e28dc*)self->unknown_e64_)) {
            func_020e25e8((Struct_020e25e8*)self->unknown_e64_);
            sel = -2;
        }
        if (sel == 0) {
            void* item;
            int var2;
            int flag;
            item = ItemTable_Find(
                self->items_,
                self->slots[self->selectedSlot].id);
            flag = func_020dd768((Struct_020dd768*)item);
            if (flag == 1) {
                self->message_ = 0xa;
                memset(self->text_, 0, Enum_ov005_02159274_2400);
                func_ov005_02158b3c(self, self->text_);
                if (self->selectedSlot >= 0 && self->selectedSlot < 8) {
                    if (((Struct_ov005_02159274*)((char*)item + 8))->unknown_2_2_) {
                        self->message_ = 0xc;
                        memset(self->text_, 0, Enum_ov005_02159274_2400);
                        func_ov005_02158b3c(self, self->text_);
                        Window_SetPaneText(
                            (StructA0205d5d0*)((char*)self + Enum_ov005_02159274_3812), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
                        self->unknown_3ddf_ = 4;
                        self->step_ = 0;
                        return;
                    }
                    EquipMenu_EquipItem(self, 0xffff, 1);
                } else if (self->selectedSlot >= 8 &&
                       self->selectedSlot < 0x18) {
                    char* list = (char*)GameState_GetParty(GameState::GetInstance());
                    int amount = ((Struct_ov005_02159274*)((char*)item + 8))->amount;
                    sel = *(short*)((char*)item + 0x18);
                    func_0207c484((Struct_0207c484*)(list + 0x1d4), sel, 1, amount);
                    var2 = 1;
                    func_ov005_021555c0(self);
                    for (int i = 8; i < 0x18; i++) {
                        if (self->slots[i].id == sel) {
                            var2 = 0;
                            break;
                        }
                    }
                    if (var2) {
                        self->unknown_3dcc_ |= 0x40;
                        self->unknown_3daa_ = 0;
                    }
                }
                Window_SetPaneText(
                    (StructA0205d5d0*)((char*)self + Enum_ov005_02159274_3812), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
            } else if (flag == 2) {
                self->message_ = 9;
                memset(self->text_, 0, Enum_ov005_02159274_2400);
                func_ov005_02158b3c(self, self->text_);
                Window_SetPaneText(
                    (StructA0205d5d0*)((char*)self + Enum_ov005_02159274_3812), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
                self->step_++;
                return;
            } else if (flag == 4) {
                self->message_ = 0xb;
                memset(self->text_, 0, Enum_ov005_02159274_2400);
                func_ov005_02158b3c(self, self->text_);
                Window_SetPaneText(
                    (StructA0205d5d0*)((char*)self + Enum_ov005_02159274_3812), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
            }
            self->unknown_3ddf_ = 4;
            self->step_ = 0;
            return;
        }
        if (sel == -2 || sel == 1) {
            self->unknown_3ddf_ = 4;
            self->step_ = 0;
            return;
        }
        return;
    }
    if (self->step_ == 2) {
        func_ov005_02159b74(self);
        self->step_++;
        return;
    }
    if (self->step_ == 3) {
        sel = func_020e2918((signed char*)self->unknown_e64_);
        if (sel >= 0) {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            func_020e25e8((Struct_020e25e8*)self->unknown_e64_);
        } else if (func_020e2984((struct Struct_020e28dc*)self->unknown_e64_)) {
            func_020e25e8((Struct_020e25e8*)self->unknown_e64_);
            sel = -2;
        }
        if (sel == 0) {
            void* item;
            int var8;
            self->message_ = 0xa;
            memset(self->text_, 0, Enum_ov005_02159274_2400);
            func_ov005_02158b3c(self, self->text_);
            if (self->selectedSlot >= 0 && self->selectedSlot < 8) {
                item = ItemTable_Find(
                    self->items_,
                    self->slots[self->selectedSlot].id);
                if (((Struct_ov005_02159274*)((char*)item + 8))->unknown_2_2_) {
                    self->message_ = 0xc;
                    memset(self->text_, 0, Enum_ov005_02159274_2400);
                    func_ov005_02158b3c(self, self->text_);
                    Window_SetPaneText(
                        (StructA0205d5d0*)((char*)self + Enum_ov005_02159274_3812), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
                    self->unknown_3ddf_ = 4;
                    self->step_ = 0;
                    return;
                }
                EquipMenu_EquipItem(self, 0xffff, 1);
            } else if (self->selectedSlot >= 8 && self->selectedSlot < 0x18) {
                char* list = (char*)GameState_GetParty(GameState::GetInstance());
                item = ItemTable_Find(
                    self->items_,
                    self->slots[self->selectedSlot].id);
                sel = *(short*)((char*)item + 0x18);
                func_0207c484((Struct_0207c484*)(list + 0x1d4), sel, 1, ((Struct_ov005_02159274*)((char*)item + 8))->amount);
                var8 = 1;
                func_ov005_021555c0(self);
                for (int i = 8; i < 0x18; i++) {
                    if (self->slots[i].id == sel) {
                        var8 = 0;
                        break;
                    }
                }
                if (var8) {
                    self->unknown_3dcc_ |= 0x40;
                    self->unknown_3daa_ = 0;
                }
            }
            Window_SetPaneText(
                (StructA0205d5d0*)((char*)self + Enum_ov005_02159274_3812), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
            self->unknown_3ddf_ = 4;
            self->step_ = 0;
            return;
        }
        if (sel == -2 || sel == 1) {
            self->unknown_3ddf_ = 4;
            self->step_ = 0;
            return;
        }
        return;
    }
}
