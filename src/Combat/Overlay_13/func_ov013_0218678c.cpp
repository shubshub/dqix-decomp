#if defined(jpn)
#define func_ov013_0218678c func_ov013_02187ab8
#endif

#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

struct Struct_0205dee8;
extern "C" void func_0205dee8(struct Struct_0205dee8* obj, int val);

struct Entry_0205d6a0;
extern "C" void Window_ClosePane(struct Entry_0205d6a0* a, int flag);

extern "C" void func_ov013_02186c64(void* obj, int a, int b);
extern "C" void func_ov013_02185cc0(void* obj);

struct Struct_ov013_021846a0_2 {
#if defined(jpn)
    char unknown0[0x34];
    unsigned char window[0xbc];
    char unknown_f0_[0x5ac - 0xf0];
#else
    char unknown0[0x38];
    unsigned char window[0xbc];
    char unknown_f4_[0x620 - 0xf4];
#endif
    char texts[0x18];
    unsigned char unknown_638_[4];
    unsigned char state;
    unsigned char unknown_63d_;
    unsigned char step;
    bool stateChanged;
    bool subScreen;
    unsigned int ticks;
    int windowInput;
#if !defined(jpn)
    int unknown_64c_;
#endif
    int task;
    void* unknown_654_;
    char* text;
    int selectedSkill;
    int confirmationChoice;
    unsigned char unknown_664_;
    unsigned char unknown_665_;
    char unknown_666_[2];
    int unknown_668_;
    int unknown_66c_;
    int unknown_670_;
    int skillPoints[5];
    int unknown_688_[5];
    unsigned char unknown_69c_[5];
    char unknown_6a1_[8];
    unsigned char unknown_6a9_[5];
    char unknown_6ae_[0xe];
    unsigned char flags;
};

// USA: func_ov013_0218678c
extern "C" ARM void func_ov013_0218678c(Struct_ov013_021846a0_2* menu) {
    menu->flags &= ~1;
    menu->unknown_638_[2] = 0;

    if (menu->unknown_63d_ != menu->state) return;

    if (!g_keyManager.TestKeysPressed(0x613) && !g_touchInput.IsPressed()) {
        return;
    }

    menu->state = 1;
    g_keyManager.CancelCurrentKeyRepeat();
    func_0205dee8((struct Struct_0205dee8*)menu->window, 2);
    Window_ClosePane((struct Entry_0205d6a0*)menu->window, 0);
    menu->unknown_638_[1] = 0;
    menu->flags &= ~1;
    func_ov013_02186c64(menu, 0, 0);
    func_ov013_02185cc0(menu);
}
