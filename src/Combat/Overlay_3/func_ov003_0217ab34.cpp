#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Obj2081;
struct Cont0207fdf0;
struct SePlayer;
struct Obj0208203c;
struct Container020dedd0;
struct Obj021dcae0;
struct Obj02179e18;

struct Struct_ov003_02179e18 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 12;
    unsigned int unknown_9_4_ : 2;
};

struct Struct_ov003_0217ab34 {
    char unknown_0_[0xc];
    short unknown_c_[1];
};

struct Struct_ov003_0217ab34_2 {
    char unknown_0_[8];
    struct Struct_ov003_02179e18* unknown_8_;
    char unknown_c_[0x30];
#if defined(jpn)
    char unknown_3c_[0x7f0 - 0x3c];
#else
    char unknown_3c_[0x874 - 0x3c];
#endif
    char unknown_874_[0x88c - 0x874];
    char unknown_88c_[0x89c - 0x88c];
    struct Struct_0207fdcc_2* unknown_89c_;
    char unknown_8a0_[0xff8 - 0x8a0];
    short* unknown_ff8_;
    short unknown_ffc_;
    short unknown_ffe_;
    char unknown_1000_[0xe];
    short unknown_100e_;
    char unknown_1010_[4];
    short unknown_1014_;
    char unknown_1016_[0x1036 - 0x1016];
    short unknown_1036_;
    char unknown_1038_[2];
    short unknown_103a_;
    unsigned char unknown_103c_;
    char unknown_103d_;
    unsigned char unknown_103e_;
    unsigned char unknown_103f_;
    char unknown_1040_[6];
    unsigned short unknown_1046_;
    char unknown_1048_[2];
    unsigned char unknown_104a_;
    unsigned char unknown_104b_;
    unsigned char unknown_104c_;
};

void* GetPtrField0x2a04_02010828(GameState* gs);
short FindMappedMemberId02080468(void* obj, int id);
void SetElementFlag0x40_02081ea4(struct Obj2081* obj, int id, int value);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
void ResetWithSub0208203c(struct Obj0208203c* obj);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
struct Obj02179e18* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
void CallFunc0204c804OnNonMatchingKey(struct Cont0207fdf0* obj, int key);
void CallFunc0204c804OnMatchingKey_0207fdcc(struct Obj2081* obj, int key);
unsigned short GetInnerShort_0217b200(void** obj);
int SumKeyedLookups02086bf4(char* table, int key);
int ComputeTimeRemaining_02179e18(struct Obj02179e18* elem);
void RefillAndResetEntry_02175d78(char* obj);

extern "C" int func_ov003_02179f34(void* arg0);
extern "C" void func_ov003_02177dd4(void* arg0);
extern "C" void func_ov003_021748c4(void* arg0);
extern "C" void func_ov003_0217a14c(void* arg0);
extern "C" void func_ov023_021dcae0(struct Struct_ov003_02178910* arg0, int arg1);
extern "C" int func_ov003_021765b4(void* arg0);
extern "C" int func_ov003_02179da8(void* arg0, int arg1);
extern "C" int func_ov003_021766e8(void* arg0);
extern "C" void func_ov003_02177208(void* arg0);
extern "C" void func_ov003_0217726c(void* arg0);
extern "C" int func_ov003_02178218(void* arg0);
extern "C" int func_02081f20(void* arg0, unsigned int arg1);
extern "C" int func_ov003_021782a0(void* arg0);
extern "C" void func_ov003_02176468(void* arg0);
extern "C" int func_ov003_021764f4(void* arg0);
extern "C" void func_ov003_02175df4(void* arg0);

extern struct SePlayer g_sePlayer;

// USA: func_ov003_0217ab34
extern "C" ARM void func_ov003_0217ab34(struct Struct_ov003_0217ab34_2* arg0) {
    char* var0 = (char*)func_02010828(GameState::GetInstance());
    struct Struct_0207fdcc_2* var1 = arg0->unknown_89c_;

    if (arg0->unknown_103f_ == 0) {
        int var2 = func_ov003_02179f34(arg0);
        arg0->unknown_1046_ &= ~0x400;
        if (var2 > 8) {
            arg0->unknown_1046_ |= 0x400;
        }
        arg0->unknown_ffe_ = 0x16;
        if (arg0->unknown_100e_ < 0) {
            arg0->unknown_100e_ = func_02080468(var1, arg0->unknown_ffe_);
        }
        short var3 = func_02080468(var1, arg0->unknown_ffe_);
        short var4 = (short)(arg0->unknown_100e_ - var3);
        struct Struct_ov003_0217ab34* var5 = (struct Struct_ov003_0217ab34*)var0;
        arg0->unknown_103a_ = var5->unknown_c_[(short)(arg0->unknown_1014_ * 8 + var4)];
        arg0->unknown_103c_ = 1;
        func_ov003_02177dd4(arg0);
        func_02081ea4(var1, arg0->unknown_ffe_, 0);
        func_02080c68(var1, arg0->unknown_ffe_, 0);
        func_0208203c((struct Struct_02081f20_2*)arg0->unknown_88c_);
        arg0->unknown_ff8_ = 0;
        arg0->unknown_103f_ = 1;
        func_ov003_021748c4(arg0);
        return;
    }

    if (self->step == 1) {
        short prevSel = self->sel;
        self->cursor = &self->member100e;
        func_ov003_0217a14c(self);
        func_ov023_021dcae0((struct Obj021dcae0*)self->sub3c, self->sel);
        if (func_ov003_021765b4(self) && prevSel == self->sel) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            ResetWithSub0208203c((struct Obj0208203c*)self->repeat);
            self->cursor = 0;
            self->elem = FindElementByKey020dedd0((struct Container020dedd0*)self->container, self->sel);
            if (self->elem == 0) {
                return;
            }
            arg0->unknown_ffc_ = arg0->unknown_ffe_;
            func_02080c68(var1, arg0->unknown_ffe_, 1);
            arg0->unknown_103f_ = 2;
            if (arg0->unknown_8_->unknown_9_4_ == 0) {
                func_0207fdf0((struct Struct_0207fdf0_2*)var1, 0);
                arg0->unknown_1036_ = 0x12;
                arg0->unknown_103f_ = 0;
                arg0->unknown_1046_ |= 0x20;
#if !defined(jpn)
                arg0->unknown_1046_ &= ~0x2000;
#endif
                return;
            }
            switch (func_ov003_02179da8(arg0->unknown_8_, 1)) {
            case 1:
                func_0207fdf0((struct Struct_0207fdf0_2*)var1, 0);
                arg0->unknown_1036_ = 0xd;
                arg0->unknown_103f_ = 6;
                arg0->unknown_1046_ |= 0x2000;
                if (arg0->unknown_8_->unknown_9_4_ == 2) {
                    arg0->unknown_1036_ = 0x11;
                    arg0->unknown_103f_ = 4;
                }
                break;
            case 2:
                func_0207fdf0((struct Struct_0207fdf0_2*)var1, 0);
                arg0->unknown_1036_ = 0x1c;
                arg0->unknown_103e_ = 1;
                arg0->unknown_103f_ = 0;
                arg0->unknown_1046_ |= 0x2000;
                break;
            }
            return;
        }
        if (func_ov003_021766e8(arg0) == 0) {
            return;
        }
        func_0208203c((struct Struct_02081f20_2*)arg0->unknown_88c_);
        arg0->unknown_ff8_ = 0;
        func_0207fdf0((struct Struct_0207fdf0_2*)var1, 0);
        arg0->unknown_103e_ = 4;
        arg0->unknown_103f_ = 1;
        arg0->unknown_1046_ |= 0x2000;
        return;
    }

    if (arg0->unknown_103f_ == 2) {
        func_ov003_02177208(arg0);
        func_ov003_0217726c(arg0);
        func_0208203c((struct Struct_02081f20_2*)arg0->unknown_88c_);
        arg0->unknown_103f_ = 3;
        arg0->unknown_104a_ = 0;
        return;
    }

    if (arg0->unknown_103f_ == 3) {
        int var7 = 0;
        if (arg0->unknown_104a_ < 5) {
            arg0->unknown_104a_++;
        } else {
            var7 = func_ov003_02178218(arg0);
            if (var7 != 0) {
                arg0->unknown_104a_ = 0;
            }
        }
        int var8 = func_02081f20(arg0->unknown_88c_, GameState::GetInstance()->GetTickCount());
        if ((unsigned short)(var8 + 0xffff) <= 1) {
            unsigned short var9 = func_ov003_0217b200((void**)arg0->unknown_88c_);
            if (var9 == 0x40) {
                var7 = 1;
            } else if (var9 == 0x80) {
                var7 = -1;
            } else if (var9 == 0x20) {
                var7 = 0x83;
            } else if (var9 == 0x10) {
                var7 = -0x83;
            }
        }
        if (var7 != 0) {
            int var10 = arg0->unknown_103c_ + var7;
            int var11 = func_02086bf4(var0, arg0->unknown_103a_);
            int var12 = func_ov003_02179e18(arg0->unknown_8_);
            if (var12 < var11) {
                var11 = var12;
            }
            if (var11 < var10) {
                var10 = var11;
            }
            if (var10 <= 1) {
                var10 = 1;
            }
            arg0->unknown_104b_ = arg0->unknown_103c_ < var10;
            arg0->unknown_104c_ = var10 < arg0->unknown_103c_;
            arg0->unknown_103c_ = var10;
            func_ov003_02177208(arg0);
            func_ov003_0217726c(arg0);
        }
        int pressed = func_ov003_021782a0(self);
        if (g_keyManager.TestKeysPressed(0x401) != 0 || pressed == 1) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)menu, 0);
            self->nextState = 0xd;
            if (self->count > 1) {
                self->nextState = 0x20;
            }
            arg0->unknown_103f_ = 6;
            arg0->unknown_1046_ |= 0x2000;
            func_0208203c((struct Struct_02081f20_2*)arg0->unknown_88c_);
            if (arg0->unknown_8_->unknown_9_4_ == 2) {
                arg0->unknown_1036_ = 0x11;
                arg0->unknown_103f_ = 4;
            }
        } else if (g_keyManager.TestKeysPressed(2) != 0 || var13 == -1) {
            func_0207fdcc(var1, 9);
            func_0207fdcc(var1, 10);
            func_0208203c((struct Struct_02081f20_2*)arg0->unknown_88c_);
            arg0->unknown_103f_ = 0;
        }
        return;
    }

    if (arg0->unknown_103f_ == 4) {
        func_ov003_02176468(arg0);
        arg0->unknown_103f_ = 5;
        return;
    }

    if (arg0->unknown_103f_ == 5) {
        int var14 = func_ov003_021764f4(arg0);
        if (var14 != -1) {
            if (var14 != 1) {
                return;
            }
            arg0->unknown_1036_ = 0x10;
            arg0->unknown_103f_ = 6;
        } else {
            arg0->unknown_1036_ = 0x30;
            arg0->unknown_103f_ = 0;
            arg0->unknown_1046_ |= 0x20;
        }
        return;
    }

    if (arg0->unknown_103f_ == 6) {
        func_ov003_02176468(arg0);
        arg0->unknown_103f_ = 7;
        return;
    }

    if (arg0->unknown_103f_ == 7) {
        int var15 = func_ov003_021764f4(arg0);
        if (var15 != -1) {
            if (var15 != 1) {
                return;
            }
            func_ov003_02175d78((char*)arg0);
            func_ov003_02175df4(arg0);
            arg0->unknown_1036_ = 0xe;
            arg0->unknown_103e_ = 4;
            arg0->unknown_103f_ = 1;
            arg0->unknown_1046_ |= 0x20;
        } else {
            arg0->unknown_1036_ = 0x30;
            arg0->unknown_103e_ = 6;
            arg0->unknown_103f_ = 0;
            arg0->unknown_1046_ |= 0x20;
        }
    }
}
