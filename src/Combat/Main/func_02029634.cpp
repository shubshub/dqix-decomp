#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_02029634_3 {
    char unknown_0_[0x4c];
    int unknown_4c_;
    char unknown_50_[0xc];
    short unknown_5c_, unknown_5e_, unknown_60_;
    char unknown_62_[6];
    short unknown_68_, unknown_6a_;
    unsigned char unknown_6c_, unknown_6d_, unknown_6e_, unknown_6f_, unknown_70_;
};
struct IndexList_0202a9ac;
struct IndexNode_0202a9ac { int kind; char padding4[0x34]; int busy; };
extern "C" int func_0202a9f4(Callback_0202a91c*);
extern "C" int func_0202aa94(Callback_0202a91c*);
IndexNode_0202a9ac* DebugMenu_GetItem(IndexList_0202a9ac*, int);
void SetState0x6cAndInvoke(Callback_0202a91c*);
void DebugMenu_Open(char*, int);

// USA: func_02029634
extern "C" ARM void func_02029634(Struct_02029634_3* arg0, int arg1) {
    if (arg0->unknown_6c_ != 0) return;
    if (!(arg0->unknown_6d_ & 1) && arg0->unknown_5c_ >= 0 && arg0->unknown_5c_ <= arg0->unknown_5e_) {
        if (g_keyManager.TestKeysReleased(0x40)) {
            arg0->unknown_6f_ = 0;
            arg0->unknown_68_ = 0;
            arg0->unknown_6a_ = 0;
        }
        if (g_keyManager.TestKeysReleased(0x80)) {
            arg0->unknown_6f_ = 0;
            arg0->unknown_68_ = 0;
            arg0->unknown_6a_ = 0;
        }
        if (arg0->unknown_6f_) arg0->unknown_6a_ += arg1;
        if (func_0202a9f4(arg0)) {
            if (arg0->unknown_6a_ >= arg0->unknown_68_) {
                arg0->unknown_6a_ = 0;
                arg0->unknown_68_ -= 5;
                if (arg0->unknown_68_ < 0) arg0->unknown_68_ = 0;
                if (arg0->unknown_60_ != arg0->unknown_5c_ || !arg0->unknown_6f_) {
                    --arg0->unknown_60_;
                    if (arg0->unknown_60_ < arg0->unknown_5c_) arg0->unknown_60_ = arg0->unknown_5e_;
                }
            }
            if (!arg0->unknown_6f_) {
                arg0->unknown_68_ = 15;
                arg0->unknown_6a_ = 0;
            }
            arg0->unknown_6f_ = 1;
        } else if (func_0202aa94(arg0)) {
            if (arg0->unknown_6a_ >= arg0->unknown_68_) {
                arg0->unknown_6a_ = 0;
                arg0->unknown_68_ -= 5;
                if (arg0->unknown_68_ < 0) arg0->unknown_68_ = 0;
                if (arg0->unknown_60_ != arg0->unknown_5e_ || !arg0->unknown_6f_) {
                    ++arg0->unknown_60_;
                    if (arg0->unknown_5e_ < arg0->unknown_60_) arg0->unknown_60_ = arg0->unknown_5c_;
                }
            }
            if (!arg0->unknown_6f_) {
                arg0->unknown_68_ = 15;
                arg0->unknown_6a_ = 0;
            }
            arg0->unknown_6f_ = 1;
        }
        if (arg0->unknown_70_) {
            if (g_keyManager.TestKeyRepeat(0x20)) {
                arg0->unknown_60_ -= arg0->unknown_4c_;
                if (arg0->unknown_60_ < arg0->unknown_5c_) arg0->unknown_60_ = arg0->unknown_5c_;
            } else if (g_keyManager.TestKeyRepeat(0x10)) {
                arg0->unknown_60_ += arg0->unknown_4c_;
                if (arg0->unknown_5e_ < arg0->unknown_60_) arg0->unknown_60_ = arg0->unknown_5e_;
            }
        }
    }
    IndexNode_0202a9ac* node = DebugMenu_GetItem(reinterpret_cast<IndexList_0202a9ac*>(menu), menu->selected);
    if (menu->flags & 1) return;
    if (g_keyManager.TestKeysPressed(1)) {
        int var1 = arg0->unknown_6d_ & 2;
        if (!var1 && !var0) {
            func_0202a91c(arg0);
            arg0->unknown_6e_ = 1;
            return;
        }
        if (!var0) return;
        if (arg0->unknown_60_ < 0 || var0->unknown_0_ != 1) {
            if (var1) return;
            func_0202a91c(arg0);
            arg0->unknown_6e_ = 1;
            return;
        }
        if (node->kind != 1 || node->busy != 0) return;
        DebugMenu_Open(reinterpret_cast<char*>(node), 1);
        menu->state = 4;
        return;
    }
    if (!(arg0->unknown_6d_ & 4) && g_keyManager.TestKeysPressed(2)) {
        arg0->unknown_6e_ = 0;
        func_0202a91c(arg0);
        return;
    }
    if (g_keyManager.TestKeysPressed(4)) {
        arg0->unknown_6e_ = 0;
        func_0202a91c(arg0);
    }
}
