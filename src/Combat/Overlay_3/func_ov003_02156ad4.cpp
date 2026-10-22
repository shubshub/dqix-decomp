#include <globaldefs.h>

extern "C" {
void* _ZN9GameState11GetInstanceEv(void);
int func_02080468(void*, int);
void func_020813ec(void*, int);
void func_0208203c(void*);
int func_ov003_021550dc(void*);
void _Z13SePlayer_PlayP8SePlayerii(void*, int, int);
int _Z27GetField0x3acValue_020100a8P9GameState(void*);
int _Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(void*, int);
void _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(void*);
void* _Z26GetPtrField0x2a04_02010828P9GameState(void*);
void* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
int func_0202053c(void*);
int func_ov003_02155208(void*);
}

extern char g_sePlayer[];

struct Struct_ov003_02156ad4_3 {
    short unknown_0_;
    short unknown_2_;
};

struct Struct_ov003_02156ad4_4 {
    char unknown_0_[8];
    void* unknown_8_;
    char unknown_c_[0xc];
    void* unknown_18_;
    char unknown_1c_[0x80 - 0x1c];
    char unknown_80_[0x80];
#if defined(jpn)
    char unknown_100_[0x1dc - 0x100];
#else
    char unknown1_100_[0x1e0 - 0x100];
#endif
    short unknown_1e0_;
    char unknown_1e2_[4];
    short unknown_1e6_;
    char unknown_1e8_[0x1ec - 0x1e8];
    struct Struct_ov003_02156ad4_3 unknown_1ec_;
    char unknown_1f0_[2];
    unsigned char unknown_1f2_;
    char unknown_1f3_[4];
    char unknown_1f7_;
    unsigned char unknown_1f8_;
    unsigned char unknown_1f9_;
    char unknown_1fa_;
    unsigned char unknown_1fb_;
    unsigned int unknown_1fc_;
};

struct Struct_ov003_02156ad4 {
#if defined(jpn)
    char unknown_0_[0x2a];
#else
    char unknown1_0_[0x36];
#endif
    short unknown_36_;
};

struct Struct_ov003_02156ad4_2 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

// USA: func_ov003_02156ad4
extern "C" ARM void func_ov003_02156ad4(struct Struct_ov003_02156ad4_4* arg0) {
    struct Struct_ov003_02156ad4* var0 = (struct Struct_ov003_02156ad4*)arg0->unknown_18_;
    struct Struct_ov003_02156ad4_3* var1 = &arg0->unknown_1ec_;
    int var2;
    if (arg0->unknown_1f9_ == 0) {
        arg0->unknown_1e6_ = 2;
        if (arg0->unknown_1e0_ < 0) {
            arg0->unknown_1e0_ = func_02080468(var0, arg0->unknown_1e6_);
        }
        var0->unknown_36_ = arg0->unknown_1e0_;
        func_020813ec(var0, arg0->unknown_1e6_);
        func_0208203c(arg0->unknown_80_);
        arg0->unknown_8_ = 0;
        arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
        return;
    }
    if (arg0->unknown_1f9_ != 1) {
        return;
    }
    self->f08 = &self->f1e0;
    if (func_ov003_021550dc(self) != 0) {
        _Z13SePlayer_PlayP8SePlayerii(g_sePlayer, 1, 0);
        _Z20ResetWithSub0208203cP11Obj0208203c(self->sub80);
        self->f08 = 0;
        void* gs = _ZN9GameState11GetInstanceEv();
        switch (self->f1e0) {
        case 8:
            if (arg0->unknown_1fb_ == 0) {
                arg0->unknown_1f7_ = func_020100a8(var3);
                arg0->unknown_1f9_ = 0;
                if (func_ov003_02155f88(arg0, arg0->unknown_1f7_)) {
                    var1->unknown_0_ = 8;
                    arg0->unknown_1f8_ = 7;
                    func_0207fe44(var0);
                    return;
                }
                arg0->unknown_1fc_ = arg0->unknown_1fc_ | 2;
                var1->unknown_0_ = 9;
                arg0->unknown_1f8_ = 3;
                arg0->unknown_1f9_ = 0;
            } else {
                arg0->unknown_1f7_ = arg0->unknown_1f2_;
                var1->unknown_0_ = 6;
                arg0->unknown_1f8_ = 2;
                arg0->unknown_1f9_ = 2;
            }
            break;
        case 9: {
            unsigned char var4;
            if (arg0->unknown_1fb_ == 0) {
                arg0->unknown_1f7_ = func_020100a8(var3);
                var1->unknown_0_ = 0xe;
                arg0->unknown_1f8_ = 4;
                var4 = 2;
            } else {
                var1->unknown_0_ = 0xe;
                var1->unknown_2_ = 0xf;
                arg0->unknown_1f8_ = 4;
                var4 = 0;
            }
            arg0->unknown_1f9_ = var4;
            unsigned char var5;
            struct Struct_ov003_02156ad4_2* var6;
            void* var7 = _ZN9GameState11GetInstanceEv();
            var6 = (struct Struct_ov003_02156ad4_2*)func_02010828(var7);
            var5 = var6->unknown_f7c_;
            int var8;
            for (var2 = 0; var2 < var5; var2++) {
                void* var9 = _ZN9GameState21GetPartyMemberByIndexEi(var7, var6->unknown_f78_[var2]);
                if (var9 != 0 && func_0202053c(var9) == 0x63) {
                    var8 = 1;
                    goto found_done;
                }
            }
            var8 = 0;
        found_done:
            if (var8 == 0) {
                var1->unknown_2_ = 0x42;
                arg0->unknown_1f8_ = 7;
            }
            break;
        }
        default:
            break;
        }
        func_0207fe44(var0);
    } else {
        if (func_ov003_02155208(arg0) != 0) {
            arg0->unknown_8_ = 0;
            func_0207fe44(var0);
            var1->unknown_0_ = 5;
            arg0->unknown_1f8_ = 7;
        }
    }
}
