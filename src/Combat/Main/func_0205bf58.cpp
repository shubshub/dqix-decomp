#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205bb84 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
    int* unknown_24_;
    int* unknown_28_;
    int* unknown_2c_;
};
struct Struct_0205c4a8 : Struct_0205bb84 {};
struct Struct_0205bf3c : Struct_0205c4a8 {
    int unknown_30_;
    unsigned short unknown_34_;
    unsigned char unknown_36_;
    unsigned char unknown_37_;
    unsigned char unknown_38_;
    unsigned char unknown_39_;
    unsigned char unknown_3a_;
    unsigned char unknown_3b_;
    unsigned char unknown_3c_;
    unsigned char unknown_3d_;
};
struct NavigationSteps { int values[4]; };
struct NavigationKeys { unsigned short values[5]; };
struct NavigationRepeatDirections { unsigned char values[4]; };
void ResetState0205bf3c(Struct_0205bf3c*);
int GridCursor_GetSelectedIndex(Struct_0205bb84*);
void AdvanceWrappedAccumulator0205c4a8(Struct_0205c4a8*, int);
extern "C" void GridCursor_SetSelectedIndex(Struct_0205bf3c*, int);
extern const NavigationKeys data_020e7db8;
extern const NavigationSteps data_020e7dc4;
extern const NavigationRepeatDirections data_020e7db0, data_020e7db4;

// USA: func_0205bf58
extern "C" ARM int func_0205bf58(Struct_0205bf3c* arg0, unsigned int arg1) {
    if (arg0->unknown_0_ == 0) return 0;
    if (arg0->unknown_8_ <= 0) return 0;
    if (arg0->unknown_c_ <= 0) return 0;
    unsigned char var0 = arg0->unknown_39_;
    unsigned char var1 = arg0->unknown_3a_;
    Struct_020e7db8 var2 = data_020e7db8;
    int var3 = 0;
    while (var2.unknown_0_[var3] != 0xffff && arg0->unknown_34_ == 0) {
        unsigned short var4 = var2.unknown_0_[var3];
        if (g_keyManager.TestKeysPressed(var4)) {
            if (arg0->unknown_36_ | arg0->unknown_37_) {
                func_0205bf3c(arg0);
                break;
            }
            NavigationSteps steps = data_020e7dc4;
            NavigationRepeatDirections rowRepeats = data_020e7db0;
            NavigationRepeatDirections columnRepeats = data_020e7db4;
            navigation->key = key;
            navigation->countdown = initialDelay;
            navigation->step = steps.values[index];
            navigation->rowRepeat = rowRepeats.values[index];
            navigation->columnRepeat = columnRepeats.values[index];
            if (navigation->key == 0x40 || navigation->key == 0x80) {
                int previous = navigation->row;
                navigation->row += navigation->step;
                if (navigation->wrapRows) {
                    if (navigation->rows <= navigation->row) navigation->row = 0;
                    else if (navigation->row < 0) navigation->row = navigation->rows - 1;
                    if (navigation->key == 0x40) {
                        int total = navigation->count;
                        if (total <= GridCursor_GetSelectedIndex(navigation))
                            GridCursor_SetSelectedIndex(navigation, total - 1);
                    } else if (navigation->key == 0x80) {
                        if (navigation->count <= GridCursor_GetSelectedIndex(navigation))
                            navigation->row = 0;
                    }
                } else {
                    if (navigation->rows <= navigation->row) navigation->row = previous;
                    else if (navigation->row < 0) navigation->row = previous;
                    if (GridCursor_GetSelectedIndex(navigation) >= navigation->count)
                        navigation->row = previous;
                }
            } else if (arg0->unknown_34_ == 0x20 || arg0->unknown_34_ == 0x10) {
                int var10 = arg0->unknown_18_;
                arg0->unknown_18_ += arg0->unknown_30_;
                if (arg0->unknown_8_ <= arg0->unknown_18_) {
                    if (arg0->unknown_3c_) {
                        arg0->unknown_18_ = 0;
                        if (arg0->unknown_4_ > 1) func_0205c4a8(arg0, 1);
                    } else {
                        if (arg0->unknown_4_ == 1) arg0->unknown_18_ = var10;
                        else {
                            arg0->unknown_18_ = 0;
                            func_0205c4a8(arg0, 1);
                        }
                    }
                } else if (arg0->unknown_18_ < 0) {
                    if (arg0->unknown_3c_) {
                        arg0->unknown_18_ = arg0->unknown_8_ - 1;
                        if (arg0->unknown_4_ > 1) func_0205c4a8(arg0, -1);
                    } else {
                        if (arg0->unknown_4_ == 1) arg0->unknown_18_ = var10;
                        else {
                            arg0->unknown_18_ = arg0->unknown_8_ - 1;
                            func_0205c4a8(arg0, -1);
                        }
                    }
                }
                if (GridCursor_GetSelectedIndex(navigation) >= navigation->count) {
                    if (navigation->pages == 1) navigation->column = previous;
                    else {
                        arg0->unknown_18_ = 0;
                        func_0205c4a8(arg0, 1);
                    }
                }
            }
            return 1;
        }
        ++var3;
    }
    if (arg0->unknown_36_) {
        if (g_keyManager.TestKeysHeld(0xf0)) {
            unsigned char var11 = arg1;
            if (var11 < arg0->unknown_38_) arg0->unknown_38_ -= var11;
            else {
                navigation->countdown = repeatDelay;
                navigation->rowRepeat = 1;
                navigation->columnRepeat = 0;
                navigation->row += navigation->step;
                if (navigation->rows <= navigation->row) navigation->row = navigation->rows - 1;
                else if (navigation->row < 0) navigation->row = 0;
                int total = navigation->count;
                if (total <= GridCursor_GetSelectedIndex(navigation))
                    GridCursor_SetSelectedIndex(navigation, total - 1);
                if (navigation->key == 0x40 || navigation->key == 0x20) {
                    int total = navigation->count;
                    if (total <= GridCursor_GetSelectedIndex(navigation))
                        GridCursor_SetSelectedIndex(navigation, total - 1);
                } else if (navigation->key == 0x80 || navigation->key == 0x10) {
                    if (navigation->count <= GridCursor_GetSelectedIndex(navigation))
                        navigation->row = 0;
                }
            }
        }
        if (g_keyManager.TestKeysReleased(0xf0)) func_0205bf3c(arg0);
        return 1;
    } else if (arg0->unknown_37_) {
        if (g_keyManager.TestKeysHeld(0xf0)) {
            unsigned char var14 = arg1;
            if (var14 < arg0->unknown_38_) arg0->unknown_38_ -= var14;
            else {
                arg0->unknown_38_ = var1;
                arg0->unknown_36_ = 0;
                arg0->unknown_37_ = 1;
                arg0->unknown_18_ += arg0->unknown_30_;
                if (arg0->unknown_8_ <= arg0->unknown_18_) {
                    arg0->unknown_18_ = arg0->unknown_8_ - 1;
                    func_0205c4a8(arg0, 1);
                } else if (arg0->unknown_18_ < 0) {
                    arg0->unknown_18_ = 0;
                    func_0205c4a8(arg0, -1);
                }
                if (GridCursor_GetSelectedIndex(navigation) >= navigation->count) {
                    if (navigation->pages == 1) navigation->column = 0;
                    else {
                        arg0->unknown_18_ = 0;
                        func_0205c4a8(arg0, 1);
                    }
                }
            }
        }
        if (g_keyManager.TestKeysReleased(0xf0)) func_0205bf3c(arg0);
        return 1;
    }
    return 0;
}
