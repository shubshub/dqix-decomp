#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define func_ov013_02186160 func_ov013_02187178
#endif

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
#if defined(jpn)
    enum Enum_ov013_02186160 { Enum_ov013_02186160_m1 = -1, Enum_ov013_02186160_2 = 2, Enum_ov013_02186160_3 = 3, Enum_ov013_02186160_4 = 4 };
    void inline_ov013_02186160();
#endif
};

extern "C" void* __clear(void* dst, int count);
struct Struct_0205dee8;
extern "C" void func_0205dee8(struct Struct_0205dee8* obj, int val);
struct Struct_0205c570;
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);
extern "C" void func_0205d7a0(unsigned char* obj, int val);
struct Struct_0205d81c;
extern "C" int func_0205d97c(Struct_0205d81c* window);
extern "C" int func_ov013_021842a0(void* obj, int index);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern int g_sePlayer;
extern "C" void func_ov013_02185774(void* obj);
extern "C" void func_ov013_02185828(unsigned char* obj);
struct Entry_0205d6a0;
extern "C" void Window_ClosePane(struct Entry_0205d6a0* a, int flag);
extern "C" void func_ov013_02186c64(void* obj, int a, int b);
extern "C" void func_ov013_02186bd4(void* obj);

#if defined(jpn)
inline void Struct_ov013_021846a0_2::inline_ov013_02186160() {
    func_0205dee8((Struct_0205dee8*)window, 4);
    Window_ClosePane((Entry_0205d6a0*)window, 0);
}
#endif

// USA: func_ov013_02186160
extern "C" ARM void func_ov013_02186160(Struct_ov013_021846a0_2* menu) {
#if defined(jpn)
    menu->flags |= 1;
    menu->unknown_638_[0] = 0;
    menu->unknown_638_[1] = 0;
    func_0205dee8((Struct_0205dee8*)menu->window, 0);

    int var0[5];
    for (int j = 0; j < 5; j++)
        var0[j] = menu->unknown_688_[j];
    bool var2 = false;
    bool transitioned = false;
    if (g_keyManager.TestKeyRepeat(0x80)) {
        ++menu->selectedSkill;
        var2 = true;
    }
    if (g_keyManager.TestKeyRepeat(0x40)) {
        --menu->selectedSkill;
        var2 = true;
    }
    if (menu->selectedSkill < 0) menu->selectedSkill = 5;
    if (menu->selectedSkill >= 6) menu->selectedSkill = 0;
    int var4 = g_touchInput.TestPressInRectangle(0x1e, 0x5a, 0x2a, 0xa);
    if (menu->windowInput == 2) {
        menu->selectedSkill = (signed char)Window_GetSelectedIndex((Struct_0205c570*)menu->window);
        var2 = true;
    }
    if (menu->unknown_66c_ >= 0 && menu->selectedSkill < 5) {
        if (g_keyManager.TestKeyRepeat(0x20) ||
            g_keyManager.TestKeyRepeat(2) ||
            (g_touchInput.repeatFired_ && g_touchInput.TestHoldInRectangle(0x52, menu->selectedSkill * 0xd + 0x12, 0xe, 0xb))) {
            if (menu->unknown_69c_[menu->selectedSkill] == 0) {
                menu->unknown_688_[menu->selectedSkill]--;
                var2 = true;
                if (menu->unknown_688_[menu->selectedSkill] < 0)
                    menu->unknown_688_[menu->selectedSkill] = 0;
                else
                    SePlayer_Play((SePlayer*)&g_sePlayer, 0x5d, 0);
            }
        } else if (menu->unknown_66c_ > 0 && menu->skillPoints[menu->selectedSkill] != 0x64) {
            if (menu->skillPoints[menu->selectedSkill] > menu->unknown_670_) {
                if (g_keyManager.TestKeyRepeat(0x611) ||
                    (g_touchInput.repeatFired_ && g_touchInput.TestHoldInRectangle(0x8c, menu->selectedSkill * 0xd + 0x14, 0xe, 0xb))) {
                    menu->flags &= ~1;
                    menu->state = Struct_ov013_021846a0_2::Enum_ov013_02186160_2;
                    transitioned = true;
                    var2 = true;
                    if (menu->subScreen) func_ov013_02185828((unsigned char*)menu);
                    else func_ov013_02185774(menu);
                    if (!menu->subScreen) {
                        menu->inline_ov013_02186160();
                    }
                }
            } else {
                bool var5 = false;
                if (g_keyManager.TestKeyRepeat(0x611) ||
                    (g_touchInput.repeatFired_ && g_touchInput.TestHoldInRectangle(0x84, menu->selectedSkill * 0xd + 0x14, 0xe, 0xb))) {
                    if (menu->unknown_69c_[menu->selectedSkill] == 0) {
                        menu->unknown_688_[menu->selectedSkill]++;
                        var5 = true;
                        var2 = true;
                    }
                }
                if (menu->unknown_688_[menu->selectedSkill] + menu->skillPoints[menu->selectedSkill] > menu->unknown_670_) {
                    menu->unknown_688_[menu->selectedSkill]--;
                    var5 = false;
                    if (menu->unknown_670_ != 0x64) {
                        menu->flags &= ~1;
                        menu->state = Struct_ov013_021846a0_2::Enum_ov013_02186160_2;
                        transitioned = true;
                        var2 = true;
                        if (menu->subScreen) func_ov013_02185828((unsigned char*)menu);
                        else func_ov013_02185774(menu);
                        if (!menu->subScreen) {
                            menu->inline_ov013_02186160();
                        }
                    }
                }
                if (var5)
                    SePlayer_Play((SePlayer*)&g_sePlayer, 0x5d, 0);
            }
        }
    }
    Struct_ov013_021846a0_2::Enum_ov013_02186160 var6 = Struct_ov013_021846a0_2::Enum_ov013_02186160_m1;
    if (g_keyManager.TestKeysPressed(0x601) && menu->state != Struct_ov013_021846a0_2::Enum_ov013_02186160_2) {
        if (menu->selectedSkill != 5 && menu->unknown_66c_ == 0) {
            menu->selectedSkill = 5;
            var2 = true;
        } else if (menu->selectedSkill == 5) {
            var6 = Struct_ov013_021846a0_2::Enum_ov013_02186160_3;
        } else if (func_0205d97c((Struct_0205d81c*)menu->window) == 2) {
            var6 = Struct_ov013_021846a0_2::Enum_ov013_02186160_4;
        }
    } else {
        if ((g_keyManager.TestKeyRepeat(0x611) ||
             (g_touchInput.repeatFired_ && g_touchInput.TestHoldInRectangle(0x84, menu->selectedSkill * 0xd + 0x14, 0xe, 0xb))) &&
            menu->selectedSkill != 5 && menu->unknown_66c_ == 0) {
            menu->selectedSkill = 5;
            var2 = true;
        } else if (g_keyManager.TestKeysPressed(2) && menu->state != Struct_ov013_021846a0_2::Enum_ov013_02186160_2) {
            if (var0[menu->selectedSkill] == 0 || menu->selectedSkill == 5 || menu->selectedSkill == 6)
                var6 = Struct_ov013_021846a0_2::Enum_ov013_02186160_4;
        } else if (menu->selectedSkill == 5 && menu->state != Struct_ov013_021846a0_2::Enum_ov013_02186160_2 && g_touchInput.released_ &&
                   (unsigned int)g_touchInput.prevTimeHeld_ < 0x14 && menu->unknown_665_ == 1) {
            if (var4) {
                menu->unknown_665_ = 0;
                var6 = Struct_ov013_021846a0_2::Enum_ov013_02186160_3;
            }
        } else if (func_0205d97c((Struct_0205d81c*)menu->window) == 2 && menu->state != Struct_ov013_021846a0_2::Enum_ov013_02186160_2) {
            var6 = Struct_ov013_021846a0_2::Enum_ov013_02186160_4;
        }
    }
    if (var6 == Struct_ov013_021846a0_2::Enum_ov013_02186160_3 || var6 == Struct_ov013_021846a0_2::Enum_ov013_02186160_4) {
        if (var6 == Struct_ov013_021846a0_2::Enum_ov013_02186160_3) menu->state = Struct_ov013_021846a0_2::Enum_ov013_02186160_3;
        else menu->state = Struct_ov013_021846a0_2::Enum_ov013_02186160_4;
        menu->flags &= ~1;
        transitioned = true;
        var2 = true;
        if (menu->subScreen == 0) {
            SePlayer_Play((SePlayer*)&g_sePlayer, transitioned, 0);
            menu->inline_ov013_02186160();
        } else {
            SePlayer_Play((SePlayer*)&g_sePlayer, 5, 0);
        }
        if (menu->subScreen) func_ov013_02185828((unsigned char*)menu);
                        else func_ov013_02185774(menu);
    } else {
        if (menu->selectedSkill == 5 && g_touchInput.released_ && var4)
            menu->unknown_665_ = 1;
        else if (g_touchInput.pressed_ && !var4)
            menu->unknown_665_ = 0;
    }
    int sum = 0;
    for (int k = 0; k < 5; k++)
        sum += menu->unknown_688_[k];
    menu->unknown_66c_ = menu->unknown_668_ - sum;
    if (transitioned)
        func_ov013_02186c64(menu, 0, 1);
    else if (var2)
        func_ov013_02186bd4(menu);
#else

    menu->flags |= 1;
    menu->unknown_638_[0] = 0;
    menu->unknown_638_[1] = 0;
    func_0205dee8((struct Struct_0205dee8*)menu->window, 0);

    int var9[6];
    __clear(var9, 0x18);
    for (int j = 0; j < 5; j++) {
        var9[j] = menu->unknown_688_[j];
    }

    int var11, transitioned, nextState, var14;
    var14 = menu->selectedSkill;
    var11 = 0;
    transitioned = var11;
    nextState = var11 - 1;
    menu->selectedSkill = Window_GetSelectedIndex((struct Struct_0205c570*)menu->window);

    if (g_keyManager.TestKeysPressed(0x601) != 0) {
        if (menu->selectedSkill != 5) {
            if (menu->unknown_66c_ == 0) {
                menu->selectedSkill = 5;
                func_0205d7a0(menu->window, 5);
                menu->unknown_64c_ = var11;
                var11 = 1;
            }
        } else {
            nextState = 3;
        }
    } else {
        int b = func_0205d97c((Struct_0205d81c*)menu->window);
        if (b == 2) {
            nextState = 4;
        } else if (g_keyManager.TestKeysPressed(2) != 0) {
            if (var9[menu->selectedSkill] == 0) {
                nextState = 4;
            }
        }
    }

    int windowInput = menu->windowInput;
    if (windowInput == 0) {
        if (menu->unknown_66c_ >= 0 && menu->selectedSkill < 5) {
            if (g_keyManager.TestKeyRepeat(0x20) != 0 ||
                g_keyManager.TestKeyRepeat(2) != 0 ||
                func_ov013_021842a0((void*)menu->window, 0xa) != 0) {
                menu->unknown_64c_ = 0;
                if (menu->unknown_69c_[menu->selectedSkill] == 0) {
                    menu->unknown_688_[menu->selectedSkill]--;
                    var11 = 1;
                    if (menu->unknown_688_[menu->selectedSkill] >= 0) {
                        SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x5d, 0);
                    } else {
                        menu->unknown_688_[menu->selectedSkill] = 0;
                    }
                }
            } else if (menu->unknown_66c_ > 0) {
                int var17 = 0;
                menu->unknown_64c_ = 0;
                int skillPoints = menu->skillPoints[menu->selectedSkill];
                if (skillPoints != 0x64) {
                    int var19 = menu->unknown_688_[menu->selectedSkill];
                    if (skillPoints + var19 < 0x64) {
                        if (g_keyManager.TestKeyRepeat(0x611) != 0 ||
                            func_ov013_021842a0((void*)menu->window, 0xb) != 0) {
                            if (menu->unknown_69c_[menu->selectedSkill] == 0) {
                                menu->unknown_688_[menu->selectedSkill]++;
                                var17 = 1;
                                var11 = var17;
                            }
                        }
                        if (var17 != 0) {
                            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x5d, 0);
                        }
                    }
                }
            }
        }
    } else {
        var11 = 1;
        if (windowInput == 2 && menu->unknown_64c_ == windowInput && var14 == 5 && menu->selectedSkill == 5) {
            nextState = 3;
        }
        menu->unknown_64c_ = windowInput;
    }

    if (nextState >= 0) {
        menu->unknown_64c_ = 0;
        menu->state = (unsigned char)nextState;
        menu->unknown_665_ = 0;
        menu->flags &= ~1;
        transitioned = 1;
        var11 = 1;
        if (menu->subScreen == 0) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, transitioned, 0);
            func_0205dee8((struct Struct_0205dee8*)menu->window, 4);
            Window_ClosePane((struct Entry_0205d6a0*)menu->window, 0);
        } else {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 5, 0);
        }
        if (menu->subScreen != 0) {
            func_ov013_02185828((unsigned char*)menu);
        } else {
            func_ov013_02185774(menu);
        }
    }

    int sum = 0;
    for (int k = 0; k < 5; k++) {
        sum += menu->unknown_688_[k];
    }
    menu->unknown_66c_ = menu->unknown_668_ - sum;

    if (transitioned != 0) {
        func_ov013_02186c64(menu, 0, 1);
    } else if (var11 != 0) {
        func_ov013_02186bd4(menu);
    }
#endif
}
