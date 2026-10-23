#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Input/Input.h"

#if defined(jpn)
#define MENU_SHIFT 4
#define TEXT_BYTES 0x800
extern "C" void func_02042428(char*, int);
#else
#define MENU_SHIFT 0
#define TEXT_BYTES 0x960
#endif
struct Struct_ov003_0216aa28 {
    char unknown_0_[0x30];
    int unknown_30_;
    char unknown_34_[0x50 - 0x34];
};

struct Struct_02000c9c_86 {
    int unknown_0_;
    struct Struct_ov003_0216aa28 unknown_4_[2];
};

struct Struct_0201099c_3;
struct Struct_0205d5d0;

struct Struct_ov003_0216aa28_2 {
    char unknown_0_[0x64];
    char unknown_64_[0x7c - 0x64];
    char* unknown_7c_;
    char unknown_80_[0xe4 - MENU_SHIFT - 0x80];
    struct Struct_02000c9c_86 unknown_e4_;
    char unknown_188_[0x194 - 0x188];
    unsigned char unknown_194_;
    char unknown_195_[0x4ea - 0x195];
    unsigned char unknown_4ea_;
    unsigned char unknown_4eb_;
    char unknown_4ec_[0x56c - 0x4ec];
    int unknown_56c_;
};

struct Struct_ov003_0216aa28_3 {
    char unknown_0_[0xf6c];
    int unknown_f6c_;
};

struct Struct_020465c0;

const char* KeyTable_Get(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);
#if defined(jpn)
#define APPLY_MENU(a,b,c,d,e) func_0205d5d0(a,b,c,d)
#else
#define APPLY_MENU(a,b,c,d,e) func_0205d5d0(a,b,c,d,e)
#endif
extern "C" void func_ov003_02169a84(struct Struct_ov003_0216aa28_2* arg0, char* arg1, int arg2);
extern "C" void func_ov003_02169d10(struct Struct_ov003_0216aa28_2* arg0, char* arg1, int arg2);
extern "C" struct Struct_020465c0* func_020421a0();
extern "C" void func_02046380(struct Struct_020465c0* arg0);
extern "C" void func_020465c0(struct Struct_020465c0* arg0, int arg1, int arg2);
extern "C" void func_020465f0(unsigned char* arg0, int arg1, unsigned char arg2);
extern "C" void func_020465d8(unsigned char* arg0, int arg1, unsigned char arg2);

static inline struct Struct_ov003_0216aa28* inline_ov003_02169594(void* arg0) { SDK_NULL_ASSERT(arg0); return ((struct Struct_02000c9c_86*)arg0)->unknown_4_; }

// USA: func_ov003_0216aa28
extern "C" ARM void func_ov003_0216aa28(struct Struct_ov003_0216aa28_2* arg0) {
    unsigned char var0 = arg0->unknown_4ea_;
    if (var0 != 0) {
        int var1 = 0;
        if (var0 == 2) {
            if (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) {
                if (inline_ov003_02169594(&arg0->unknown_e4_)->unknown_30_ >= 0) {
                    var1 = 1;
                } else if (arg0->unknown_56c_ >= 0) {
                    var1 = 1;
                } else {
                    return;
                }
            }
        } else if (var0 == 4) {
            var1 = 1;
        }
        memset(arg0->unknown_7c_, 0, TEXT_BYTES);
        unsigned char var2 = arg0->unknown_194_;
        switch (var2) {
        case 1:
            func_ov003_02169a84(arg0, arg0->unknown_7c_, var1);
            break;
        case 2:
            func_ov003_02169d10(arg0, arg0->unknown_7c_, var1);
            break;
        }
#if defined(jpn)
        APPLY_MENU((struct Struct_0205d5d0*)&arg0->unknown_e4_, var2, (int)arg0->unknown_7c_, 1, 0);
#else
        if (var2 == 2) {
            APPLY_MENU((struct Struct_0205d5d0*)&arg0->unknown_e4_, var2, (int)arg0->unknown_7c_, 0, 1);
        } else {
            APPLY_MENU((struct Struct_0205d5d0*)&arg0->unknown_e4_, var2, (int)arg0->unknown_7c_, 1, 0);
        }
#endif
    }
    if (arg0->unknown_4eb_ == 0) {
        return;
    }
    GameState* var3 = GameState::GetInstance();
    struct Struct_020465c0* var4 = func_020421a0();
    struct Struct_ov003_0216aa28_3* var5 = (struct Struct_ov003_0216aa28_3*)func_02010828(var3);
    memset(arg0->unknown_7c_, 0, TEXT_BYTES);
#if defined(jpn)
    func_02042428(arg0->unknown_7c_, 8);
#endif
    AppendString02042058(menu->textBuf, KeyTable_Get((struct Container020e0310*)menu->names, 0x65));
    func_02046380(g);
    StoreInArray0x8b0_020465c0(g, 0, p->value);
    SetByteInRange_020465f0((unsigned char*)g, 0, 7);
    SetByteAtIndex_020465d8((unsigned char*)g, 0, 1);
    APPLY_MENU((struct StructA0205d5d0*)&menu->list, 0, (int)menu->textBuf, 1, 0);
    menu->pendingReset = 0;
}
