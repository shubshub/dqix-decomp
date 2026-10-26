#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Input/Input.h"

struct Struct_0205c570;
struct Struct_0205def8;
struct SePlayer;

struct Struct_ov000_0217b518 {
    unsigned char unknown_0_[0x188];
#if defined(jpn)
    unsigned char elements[0x1faa - 0x188];
#else
    unsigned char elements[0x1bea];
#endif
    unsigned short flags;
};

struct Struct_ov000_02184294_4 {
#if defined(jpn)
    Struct_ov000_0217b518* window;
    int arg0;
    int arg1;
    Struct_ov000_0217b518* const& GetWindow() const {
        return window;
    }
#else
    int arg0;
    int arg1;
    Struct_ov000_0217b518* window;
#endif
};

struct Struct_ov000_0217b518_2 {
    unsigned char unknown_0_[0xb8];
    unsigned char state;
};

struct Struct_ov000_0217b518_3 {
    unsigned char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char depth;
    unsigned char unknown_19_[7];
    signed char selection;
    unsigned char unknown_21_[5];
    unsigned short itemId;
    unsigned char unknown_28_[0x10];
    Struct_ov000_0217b518_2* list;
    unsigned char unk3c[0x10];
    int partyIndex;
#if defined(jpn)
    unsigned char unk50[0x434];
#else
    unsigned char unk50[0x3f4];
#endif
    unsigned char unknown_444_;
#if defined(jpn)
    const signed char& inline_ov000_0217b518() const {
        return selection;
    }
#endif
};

extern Struct_ov000_02184294_4 data_ov000_02184294;
extern SePlayer g_sePlayer;

extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);
extern "C" void func_0205def8(struct Struct_0205def8* s, int set, int key);
struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" unsigned char* func_02053c6c(unsigned char* member);
extern "C" int func_ov000_0217ab48(void* menu);
extern "C" void func_ov000_02171458(Struct_ov000_0217b518_3* menu);
extern "C" void func_ov000_0217629c(Struct_ov000_0217b518_3* menu);
extern "C" void func_ov000_0217ab8c(Struct_ov000_0217b518_3* menu, int a, int b);
extern "C" void func_ov000_02176e3c(Struct_ov000_0217b518* window, Struct_ov000_0217b518_3* menu, int c, int d, int e, int f);

#if defined(jpn)
// USA: func_ov000_0217b518
extern "C" ARM int func_ov000_0217b518(Struct_ov000_0217b518_3* menu, int arg1, int arg2)
{
    Struct_ov000_0217b518* window;
    enum Selection { Enum_ov000_0217b518_m128 = -128, Enum_ov000_0217b518_127 = 127 };
    Selection current;
    data_ov000_02184294.window->flags |= 0x100;
    const signed char previous = menu->inline_ov000_0217b518();
    current = (Selection)(signed char)Window_GetSelectedIndex((struct Struct_0205c570*)menu->list);
    menu->selection = current;
    {
    window = data_ov000_02184294.GetWindow();
    func_0205def8((struct Struct_0205def8*)window->elements, 1, 0x22);
    if (previous != current) {
        return -1;
    }
    int pressed = g_keyManager.TestKeysPressed(0x601);
    bool cancel = (pressed | Window_IsSelectionTouched((struct Obj_0205da38*)menu->list, 0x14)) ? 1 : 0;
    if (cancel || menu->unknown_444_) {
        func_0205def8((struct Struct_0205def8*)window->elements, 0, 0x22);
        SePlayer_Play(&g_sePlayer, 1, 0);
        func_ov000_02171458(menu);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(menu->partyIndex);
        if (member != NULL) {
            unsigned char* data = func_02053c6c((unsigned char*)member);
            if (data != NULL) {
                *(unsigned short*)(data + 0x8c8) = menu->itemId;
            }
        }
        if (menu->unknown_10_[menu->depth] != 100) {
            menu->list->state = 15;
        }
        return menu->unknown_10_[menu->depth];
    }
    if (func_ov000_0217ab48(menu)) {
        func_ov000_0217629c(menu);
        menu->unknown_10_[menu->depth] = 0;
        menu->depth = menu->depth - 1;
        menu->selection = -1;
        menu->itemId = 0;
        func_ov000_0217ab8c(menu, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.window, menu, menu->unknown_10_[menu->depth],
                            data_ov000_02184294.arg1, data_ov000_02184294.arg0, 0);
    }
    return -1;
    }
}
#else
// USA: func_ov000_0217b518
extern "C" ARM int func_ov000_0217b518(Struct_ov000_0217b518_3* menu, int arg1, int arg2)
{
    signed char current;
    Struct_ov000_0217b518* window;
    signed char previous;
    data_ov000_02184294.window->flags |= 0x100;
    previous = menu->selection;
    current = Window_GetSelectedIndex((struct Struct_0205c570*)menu->list);
    menu->selection = current;
    window = data_ov000_02184294.window;
    func_0205def8((struct Struct_0205def8*)window->elements, 1, 0x22);
    if (previous != current) {
        return -1;
    }
    int pressed = g_keyManager.TestKeysPressed(0x601);
    int cancel = (pressed | Window_IsSelectionTouched((struct Obj_0205da38*)menu->list, 0x14)) ? 1 : 0;
    if (cancel || menu->unknown_444_) {
        func_0205def8((struct Struct_0205def8*)window->elements, 0, 0x22);
        SePlayer_Play(&g_sePlayer, 1, 0);
        func_ov000_02171458(menu);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(menu->partyIndex);
        if (member != NULL) {
            unsigned char* data = func_02053c6c((unsigned char*)member);
            if (data != NULL) {
                *(unsigned short*)(data + 0x960) = menu->itemId;
            }
        }
        if (menu->unknown_10_[menu->depth] != 100) {
            menu->list->state = 15;
        }
        return menu->unknown_10_[menu->depth];
    }
    if (func_ov000_0217ab48(menu)) {
        func_ov000_0217629c(menu);
        menu->unknown_10_[menu->depth] = 0;
        menu->depth = menu->depth - 1;
        menu->selection = -1;
        menu->itemId = 0;
        func_ov000_0217ab8c(menu, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.window, menu, menu->unknown_10_[menu->depth],
                            data_ov000_02184294.arg1, data_ov000_02184294.arg0, 0);
    }
    return -1;
}
#endif
