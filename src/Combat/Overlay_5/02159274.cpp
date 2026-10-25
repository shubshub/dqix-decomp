#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>

#if defined(jpn)
enum { kYesNo = 0xe60, kTextBytes = 0x800, kPanel = 0xee0 };
#else
enum { Enum_ov005_02159274_3684 = 0xe64, Enum_ov005_02159274_2400 = 0x960, Enum_ov005_02159274_3812 = 0xee4 };
#endif

#include <std_library_functions.h>
#include <GameState/GameState.h>

struct Outer020e28dc;
struct Ctx020e263c;
struct SePlayer;
struct StructA0205d5d0;
struct ItemTable;
struct Struct020dd768;

struct Struct_ov005_02159274 {
    unsigned int unknown_0_0_ : 4;
    unsigned int unknown_0_4_ : 14;
    unsigned int unknown_2_2_ : 1;
    unsigned int unknown_2_3_ : 13;
};

struct Struct_ov005_02159274_2 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    void* unknown_4_;
    void* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
};

struct Menu02159274 {
    char unknown0[0xdf4];
    ItemTable* items_;
    char unknownDf8[0xe10 - 0xdf8];
    char* text_;
    char unknownE14[kYesNo - 0xe14];
    void* yesNo_;
#if defined(jpn)
    char unknown1_e64_[0x2d08 - Enum_ov005_02159274_3684 - 4];
#else
    char unknown_e68_[0x2d90 - Enum_ov005_02159274_3684 - 4];
#endif
    Struct_ov005_02159274_2 unknown_2d90_[24];
    char unknown_3030_[0x3daa - 0x3030];
    unsigned char unknown_3daa_;
    char unknown_3dab_[0x3dbb - 0x3dab];
    signed char unknown_3dbb_;
    char unknown_3dbc_[0x3dcc - 0x3dbc];
    unsigned int unknown_3dcc_;
    unsigned char unknown_3dd0_;
    unsigned char unknown_3dd1_;
    char unknown_3dd2_[0x3ddc - 0x3dd2];
    unsigned char unknown_3ddc_;
    unsigned char unknown_3ddd_;
    unsigned char unknown_3dde_;
    unsigned char unknown_3ddf_;
};

extern "C" char g_sePlayer[];

int GetInnerFlagBit0020e28dc(Outer020e28dc* o);
void UpdateEntryStateAndPosition(Ctx020e263c* w, int value);
extern "C" void func_ov005_021589f4(void* self);
extern "C" void func_ov005_02159b74(void* self);
extern "C" int func_ov005_02158b3c(void* object, void* buffer);
int GetField0x15UnlessInactive_020e2918(signed char*);
void SePlayer_Play(SePlayer* obj, int a, int b);
struct Obj020e25e8;
void ResetSelectionState020e25e8(Obj020e25e8*);
int IsFlag0x2Active020e2984(struct Outer020e28dc* window);
void* ItemTable_Find(ItemTable* c, int key);
int GetFlagFromField0x8Bits(Struct020dd768* s);
extern "C" void EquipMenu_EquipItem(void* self, int key, int keep);
struct KeyedList0207c484;
void DecrementKeyedStackAmount0207c484(KeyedList0207c484*, int, int, int);
extern "C" void func_ov005_021555c0(void* self);

// USA: func_ov005_02159274
extern "C" ARM void func_ov005_02159274(Struct_ov005_02159274_3* arg0) {
    int var0 = GameState::GetInstance()->GetTickCount();
    if (var0 == 0)
        var0 = 1;

    if (arg0->unknown_e64_ != 0 && func_020e28dc((Struct_020e28dc*)arg0->unknown_e64_))
        func_020e263c((Struct_020e263c_2*)arg0->unknown_e64_, var0);

    if (arg0->unknown_3ddc_ == 0) {
        arg0->unknown_3dd1_ = 8;
        func_ov005_021589f4(arg0);
        func_ov005_02159b74(arg0);
        arg0->unknown_3ddc_++;
        return;
    }
    if (self->step_ == 1) {
        sel = GetField0x15UnlessInactive_020e2918((signed char*)self->yesNo_);
        if (sel >= 0) {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            ResetSelectionState020e25e8((Obj020e25e8*)self->yesNo_);
        } else if (IsFlag0x2Active020e2984((struct Outer020e28dc*)self->yesNo_)) {
            ResetSelectionState020e25e8((Obj020e25e8*)self->yesNo_);
            sel = -2;
        }
        if (sel == 0) {
            void* item;
            int notfound;
            int flag;
            item = ItemTable_Find(
                self->items_,
                self->slots[self->selectedSlot].id);
            flag = GetFlagFromField0x8Bits((Struct020dd768*)item);
            if (flag == 1) {
                self->message_ = 0xa;
                memset(self->text_, 0, kTextBytes);
                func_ov005_02158b3c(self, self->text_);
                if (self->selectedSlot >= 0 && self->selectedSlot < 8) {
                    if (((ItemBits02159274*)((char*)item + 8))->flag18) {
                        self->message_ = 0xc;
                        memset(self->text_, 0, kTextBytes);
                        func_ov005_02158b3c(self, self->text_);
                        Window_SetPaneText(
                            (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
                        arg0->unknown_3ddf_ = 4;
                        arg0->unknown_3ddc_ = 0;
                        return;
                    }
                    EquipMenu_EquipItem(self, 0xffff, 1);
                } else if (self->selectedSlot >= 8 &&
                       self->selectedSlot < 0x18) {
                    char* list = (char*)GameState_GetParty(GameState::GetInstance());
                    int amount = ((ItemBits02159274*)((char*)item + 8))->amount;
                    sel = *(short*)((char*)item + 0x18);
                    DecrementKeyedStackAmount0207c484((KeyedList0207c484*)(list + 0x1d4), sel, 1, amount);
                    notfound = 1;
                    func_ov005_021555c0(self);
                    for (int i = 8; i < 0x18; i++) {
                        if (self->slots[i].id == sel) {
                            notfound = 0;
                            break;
                        }
                    }
                    if (var2) {
                        arg0->unknown_3dcc_ |= 0x40;
                        arg0->unknown_3daa_ = 0;
                    }
                }
                Window_SetPaneText(
                    (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
            } else if (flag == 2) {
                self->message_ = 9;
                memset(self->text_, 0, kTextBytes);
                func_ov005_02158b3c(self, self->text_);
                Window_SetPaneText(
                    (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
                arg0->unknown_3ddc_++;
                return;
            } else if (flag == 4) {
                self->message_ = 0xb;
                memset(self->text_, 0, kTextBytes);
                func_ov005_02158b3c(self, self->text_);
                Window_SetPaneText(
                    (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
            }
            arg0->unknown_3ddf_ = 4;
            arg0->unknown_3ddc_ = 0;
            return;
        }
        if (var0 == -2 || var0 == 1) {
            arg0->unknown_3ddf_ = 4;
            arg0->unknown_3ddc_ = 0;
            return;
        }
        return;
    }
    if (arg0->unknown_3ddc_ == 2) {
        func_ov005_02159b74(arg0);
        arg0->unknown_3ddc_++;
        return;
    }
    if (self->step_ == 3) {
        sel = GetField0x15UnlessInactive_020e2918((signed char*)self->yesNo_);
        if (sel >= 0) {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            ResetSelectionState020e25e8((Obj020e25e8*)self->yesNo_);
        } else if (IsFlag0x2Active020e2984((struct Outer020e28dc*)self->yesNo_)) {
            ResetSelectionState020e25e8((Obj020e25e8*)self->yesNo_);
            sel = -2;
        }
        if (sel == 0) {
            void* item;
            int notfound;
            self->message_ = 0xa;
            memset(self->text_, 0, kTextBytes);
            func_ov005_02158b3c(self, self->text_);
            if (self->selectedSlot >= 0 && self->selectedSlot < 8) {
                item = ItemTable_Find(
                    self->items_,
                    self->slots[self->selectedSlot].id);
                if (((ItemBits02159274*)((char*)item + 8))->flag18) {
                    self->message_ = 0xc;
                    memset(self->text_, 0, kTextBytes);
                    func_ov005_02158b3c(self, self->text_);
                    Window_SetPaneText(
                        (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
                    arg0->unknown_3ddf_ = 4;
                    arg0->unknown_3ddc_ = 0;
                    return;
                }
                EquipMenu_EquipItem(self, 0xffff, 1);
            } else if (self->selectedSlot >= 8 && self->selectedSlot < 0x18) {
                char* list = (char*)GameState_GetParty(GameState::GetInstance());
                item = ItemTable_Find(
                    self->items_,
                    self->slots[self->selectedSlot].id);
                sel = *(short*)((char*)item + 0x18);
                DecrementKeyedStackAmount0207c484((KeyedList0207c484*)(list + 0x1d4), sel, 1, ((ItemBits02159274*)((char*)item + 8))->amount);
                notfound = 1;
                func_ov005_021555c0(self);
                for (int i = 8; i < 0x18; i++) {
                    if (self->slots[i].id == sel) {
                        notfound = 0;
                        break;
                    }
                }
                if (var8) {
                    arg0->unknown_3dcc_ |= 0x40;
                    arg0->unknown_3daa_ = 0;
                }
            }
            Window_SetPaneText(
                (StructA0205d5d0*)((char*)self + kPanel), 0, (int)self->text_, 1
#if !defined(jpn)
                            , 0
#endif
                        );
            arg0->unknown_3ddf_ = 4;
            arg0->unknown_3ddc_ = 0;
            return;
        }
        if (var0 == -2 || var0 == 1) {
            arg0->unknown_3ddf_ = 4;
            arg0->unknown_3ddc_ = 0;
            return;
        }
        return;
    }
}
