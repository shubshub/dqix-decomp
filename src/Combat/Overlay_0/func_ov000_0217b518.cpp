#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Input/Input.h"

struct Struct_0205c570;
struct Struct_0205def8;
struct SePlayer;

struct Struct_ov000_0217b518 {
    unsigned char unknown_0_[0x188];
#if defined(jpn)
    unsigned char unknown_188_[0x1faa - 0x188];
#else
    unsigned char unknown1_188_[0x1bea];
#endif
    unsigned short unknown_1d72_;
};

struct Struct_ov000_02184294_4 {
#if defined(jpn)
    Struct_ov000_0217b518* unknown_0_;
    int arg0;
    int arg1;
    Struct_ov000_0217b518* const& inline_ov000_0217b518_2() const {
        return unknown_0_;
    }
#else
    int arg0;
    int arg1;
    Struct_ov000_0217b518* unknown_8_;
#endif
};

struct Struct_ov000_0217b518_2 {
    unsigned char unknown_0_[0xb8];
    unsigned char unknown_b8_;
};

struct Struct_ov000_0217b518_3 {
    unsigned char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    unsigned char unknown_19_[7];
    signed char unknown_20_;
    unsigned char unknown_21_[5];
    unsigned short unknown_26_;
    unsigned char unknown_28_[0x10];
    Struct_ov000_0217b518_2* unknown_38_;
    unsigned char unknown_3c_[0x10];
    int unknown_4c_;
#if defined(jpn)
    unsigned char unknown_50_[0x434];
#else
    unsigned char unknown1_50_[0x3f4];
#endif
    unsigned char unknown_444_;
#if defined(jpn)
    const signed char& inline_ov000_0217b518() const {
        return unknown_20_;
    }
#endif
};

extern BattleWindowContext data_ov000_02184294;
extern SePlayer g_sePlayer;

int Window_GetSelectedIndex(struct Struct_0205c570* s);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8* s, int set, int key);
struct Obj_0205da38;
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
unsigned char* GetFieldAt0x150_02053c6c(unsigned char* member);
int CheckFlagsOrField_0217ab48_0217ab48(void* menu);
extern "C" void func_ov000_02171458(BattleSubMenu* menu);
extern "C" void func_ov000_0217629c(BattleSubMenu* menu);
extern "C" void func_ov000_0217ab8c(BattleSubMenu* menu, int a, int b);
extern "C" void func_ov000_02176e3c(BattleWindow* window, BattleSubMenu* menu, int c, int d, int e, int f);

#if defined(jpn)
// USA: func_ov000_0217b518
extern "C" ARM int func_ov000_0217b518(Struct_ov000_0217b518_3* arg0, int arg1, int arg2)
{
    BattleWindow* window;
    enum Selection { kSelectionMin = -128, kSelectionMax = 127 };
    Selection current;
    data_ov000_02184294.window->flags |= 0x100;
    const signed char previous = menu->GetSelection();
    current = (Selection)(signed char)Window_GetSelectedIndex((struct Struct_0205c570*)menu->list);
    menu->selection = current;
    {
    var0 = data_ov000_02184294.inline_ov000_0217b518_2();
    func_0205def8((struct Struct_0205def8*)var0->unknown_188_, 1, 0x22);
    if (var2 != var1) {
        return -1;
    }
    int pressed = g_keyManager.TestKeysPressed(0x601);
    bool cancel = (pressed | Window_IsSelectionTouched((struct Obj_0205da38*)menu->list, 0x14)) ? 1 : 0;
    if (cancel || menu->forceClose) {
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)window->elements, 0, 0x22);
        SePlayer_Play(&g_sePlayer, 1, 0);
        func_ov000_02171458(menu);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(menu->partyIndex);
        if (member != NULL) {
            unsigned char* data = GetFieldAt0x150_02053c6c((unsigned char*)member);
            if (data != NULL) {
                *(unsigned short*)(data + 0x8c8) = menu->itemId;
            }
        }
        if (arg0->unknown_10_[arg0->unknown_18_] != 100) {
            arg0->unknown_38_->unknown_b8_ = 15;
        }
        return arg0->unknown_10_[arg0->unknown_18_];
    }
    if (func_ov000_0217ab48(arg0)) {
        func_ov000_0217629c(arg0);
        arg0->unknown_10_[arg0->unknown_18_] = 0;
        arg0->unknown_18_ = arg0->unknown_18_ - 1;
        arg0->unknown_20_ = -1;
        arg0->unknown_26_ = 0;
        func_ov000_0217ab8c(arg0, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.unknown_0_, arg0, arg0->unknown_10_[arg0->unknown_18_],
                            data_ov000_02184294.arg1, data_ov000_02184294.arg0, 0);
    }
    return -1;
    }
}
#else
// USA: func_ov000_0217b518
extern "C" ARM int func_ov000_0217b518(Struct_ov000_0217b518_3* arg0, int arg1, int arg2)
{
    signed char current;
    BattleWindow* window;
    signed char previous;
    data_ov000_02184294.window->flags |= 0x100;
    previous = menu->selection;
    current = Window_GetSelectedIndex((struct Struct_0205c570*)menu->list);
    menu->selection = current;
    window = data_ov000_02184294.window;
    SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)window->elements, 1, 0x22);
    if (previous != current) {
        return -1;
    }
    int pressed = g_keyManager.TestKeysPressed(0x601);
    int cancel = (pressed | Window_IsSelectionTouched((struct Obj_0205da38*)menu->list, 0x14)) ? 1 : 0;
    if (cancel || menu->forceClose) {
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)window->elements, 0, 0x22);
        SePlayer_Play(&g_sePlayer, 1, 0);
        func_ov000_02171458(menu);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(menu->partyIndex);
        if (member != NULL) {
            unsigned char* data = GetFieldAt0x150_02053c6c((unsigned char*)member);
            if (data != NULL) {
                *(unsigned short*)(data + 0x960) = menu->itemId;
            }
        }
        if (arg0->unknown_10_[arg0->unknown_18_] != 100) {
            arg0->unknown_38_->unknown_b8_ = 15;
        }
        return arg0->unknown_10_[arg0->unknown_18_];
    }
    if (func_ov000_0217ab48(arg0)) {
        func_ov000_0217629c(arg0);
        arg0->unknown_10_[arg0->unknown_18_] = 0;
        arg0->unknown_18_ = arg0->unknown_18_ - 1;
        arg0->unknown_20_ = -1;
        arg0->unknown_26_ = 0;
        func_ov000_0217ab8c(arg0, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.unknown_8_, arg0, arg0->unknown_10_[arg0->unknown_18_],
                            data_ov000_02184294.arg1, data_ov000_02184294.arg0, 0);
    }
    return -1;
}
#endif
