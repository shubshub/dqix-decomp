#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Struct_0205c570;
struct SePlayer;
struct S_10088;

int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
int CheckFlagsOrField_0217ab48_0217ab48(void* obj);
int IsFlag10088Set_02010088(struct S_10088* obj);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int combatantId);

struct Struct_ov000_0217bb2c_3 {
    char unknown_0_[4];
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 20;
    char unknown_8_[0x10];
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
    unsigned int unknown_19_4_ : 20;
};

extern "C" int func_ov000_0217b518(void* arg0, int arg1, int arg2);
extern "C" int func_ov000_0217b6d0(void* arg0, int arg1, int arg2);
extern "C" int func_ov000_0217b8a4(void* arg0, int arg1, int arg2);
extern "C" void func_ov000_0217629c(void* arg0);
extern "C" void func_ov000_0217ab8c(void* arg0, int arg1, int arg2);
extern "C" Struct_ov000_0217bb2c_3* func_ov000_02170cf8(void* arg0, int arg1);
extern "C" void func_ov000_02176e3c(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5);

struct Struct_ov000_0217bb2c {
    char unknown_0_[0x188];
#if defined(jpn)
    char unknown_188_[0x1faa - 0x188];
#else
    char unknown1_188_[0x1d72 - 0x188];
#endif
    unsigned short unknown_1d72_;
};

struct Struct_ov000_02184294_7 {
#if defined(jpn)
    Struct_ov000_0217bb2c* unknown_8_;
    int unknown_0_;
    int unknown_4_;
#else
    int unknown_0_;
    int unknown_4_;
    Struct_ov000_0217bb2c* unknown_8_;
#endif
};

struct Struct_ov000_0217bb2c_2 {
    char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[0x21 - 0x19];
    signed char unknown_21_;
    char unknown_22_[0x26 - 0x22];
    unsigned short unknown_26_;
    char unknown_28_[0x2e - 0x28];
    signed char unknown_2e_;
    char unknown_2f_[0x30 - 0x2f];
    signed char* unknown_30_;
    char unknown_34_[0x38 - 0x34];
    void* unknown_38_;
#if defined(jpn)
    char unknown_3c_[0x47d - 0x3c];
#else
    char unknown1_3c_[0x43d - 0x3c];
#endif
    signed char unknown_43d_;
    char unknown_43e_[0x441 - 0x43e];
    signed char unknown_441_;
    signed char unknown_442_;
    char unknown_443_;
    unsigned char unknown_444_;
};

extern MenuGlobals_0217bb2c data_ov000_02184294;
extern char g_sePlayer;

// USA: func_ov000_0217bb2c
extern "C" ARM int func_ov000_0217bb2c(Struct_ov000_0217bb2c_2* arg0, int arg1, int arg2) {
    data_ov000_02184294.unknown_8_->unknown_1d72_ |= 0x100;
    arg0->unknown_21_ = func_0205d794((struct Struct_0205c570*)arg0->unknown_38_);
    arg0->unknown_2e_ = -1;
    if (arg0->unknown_441_ != arg1) {
        arg0->unknown_441_ = arg1;
        arg0->unknown_442_ = arg0->unknown_30_[arg0->unknown_21_];
        arg0->unknown_444_ = 1;
        func_ov000_0217629c(arg0);
        arg0->unknown_10_[arg0->unknown_18_] = 0;
        arg0->unknown_18_--;
        arg0->unknown_21_ = -1;
        arg0->unknown_2e_ = -1;
        func_ov000_0217ab8c(arg0, arg1, arg2);
        int var0 = -1;
        switch (arg0->unknown_10_[arg0->unknown_18_]) {
        case 0xf:
            var0 = func_ov000_0217b518(arg0, data_ov000_02184294.unknown_4_, data_ov000_02184294.unknown_0_);
            break;
        case 0x10:
            var0 = func_ov000_0217b6d0(arg0, data_ov000_02184294.unknown_4_, data_ov000_02184294.unknown_0_);
            break;
        case 0x11:
            var0 = func_ov000_0217b8a4(arg0, data_ov000_02184294.unknown_4_, data_ov000_02184294.unknown_0_);
            break;
        }
        return var0;
    }
    int var1 = g_keyManager.TestKeysPressed(0x601);
    int var2 = (var1 | func_0205da38((struct Struct_0205da38*)arg0->unknown_38_, 0x14)) != 0;
    if (var2) {
        GameObject* var3 = func_0200ff1c(GameState::GetInstance(), arg0->unknown_30_[arg0->unknown_21_]);
        if (var3 == NULL) {
            return -1;
        }
        int var4 = !func_02010088((struct Struct_02010088*)var3);
        Struct_ov000_0217bb2c_3* var5 = func_ov000_02170cf8(arg0, arg0->unknown_26_);
        if (var5 != NULL) {
            if (var5->unknown_18_5_ == 0x12) {
                var4 = func_02010088((struct Struct_02010088*)var3);
            }
            if (var5->unknown_4_0_ == 0x26 || var5->unknown_4_0_ == 0x27 || var5->unknown_4_0_ == 0x54) {
                var4 = 1;
            }
        } else {
            var4 = 1;
        }
        if (ok) {
            obj->field43d = obj->selections[obj->depth];
            obj->field2e = obj->order[obj->cursor];
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
            obj->depth++;
            obj->selections[obj->depth] = 100;
        }
    } else if (func_ov000_0217ab48(arg0)) {
        func_ov000_0217629c(arg0);
        arg0->unknown_10_[arg0->unknown_18_] = 0;
        arg0->unknown_18_--;
        arg0->unknown_21_ = -1;
        arg0->unknown_2e_ = -1;
        func_ov000_0217ab8c(arg0, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.unknown_8_, arg0, arg0->unknown_10_[arg0->unknown_18_], data_ov000_02184294.unknown_4_, data_ov000_02184294.unknown_0_, 0);
    }
    return -1;
}
