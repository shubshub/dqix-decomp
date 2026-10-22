#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int func_ov017_02195658(void);
extern "C" void* func_0207d78c(void);
extern "C" void func_ov000_02174a50(void* arg0, int arg1);
extern "C" void func_020a367c(unsigned char* arg0, int arg1);

struct Struct_0207da94;
extern "C" void func_0207da94(struct Struct_0207da94* arg0, int arg1);

extern "C" int func_020a35e0(unsigned char* arg0, unsigned char arg1);

extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov000_02160fa8(void* arg0, int arg1);

extern "C" void func_ov023_021f52c8(void* arg0);
extern "C" void func_ov023_021d8b6c(void* arg0);
extern "C" void func_ov023_021d8af8(void* arg0);
extern "C" void func_ov023_021d8bb4(void* arg0);

struct Pair021ed9f8 { unsigned int a; unsigned int b; };
extern struct Pair021ed9f8 __ptmf_null;

struct Struct_ov023_021fe148 { unsigned int unknown_0_; unsigned int unknown_4_; };
extern struct Struct_ov023_021fe148 data_ov023_021fe148[];

struct Struct_ov023_021ed9f8 {
    void* unknown_0_;
    char unknown_4_[4];
    unsigned int unknown_8_;
};
extern "C" struct Struct_ov023_021ed9f8 _ZZ21inline_ov023_021f4c04vE1s;

struct Struct_ov023_021ed9f8_2 {
    char unknown_0_[4];
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
};

// USA: func_ov023_021ed9f8
extern "C" ARM void func_ov023_021ed9f8(char* arg0) {
#if defined(jpn)
 enum {Enum_ov023_021ed9f8_672=0x21c, Enum_ov023_021ed9f8_14176=0x371c, Enum_ov023_021ed9f8_3756=0xe28, Enum_ov023_021ed9f8_30673=0x79c1, Enum_ov023_021ed9f8_21896=0x5778};
#else
 enum {Enum_ov023_021ed9f8_672=0x2a0, Enum_ov023_021ed9f8_14176=0x3760, Enum_ov023_021ed9f8_3756=0xeac, Enum_ov023_021ed9f8_30673=0x77d1, Enum_ov023_021ed9f8_21896=0x5588};
#endif
    GameState::GetInstance();
    int var0 = (int)BackgroundLoader::GetInstance();
    ((int)GetGameResources());
    unsigned char* var1 = *(unsigned char**)(arg0 + Enum_ov023_021ed9f8_672);
    int var2 = func_ov017_02195658();
    if (var2 > 0) {
        void* var3 = func_0207d78c();
        func_ov000_02174a50(arg0 + Enum_ov023_021ed9f8_14176, var2);
        func_020a367c(var1, var2 & 0xff);
        func_0207da94((struct Struct_0207da94*)var3, (int)(unsigned char)var2);
        if (var2 == (signed char)var1[0x2a]) {
            for (int var4 = 0; var4 < 4; var4++) {
                if (func_020a35e0(var1, var4 & 0xff)) {
                    var1[0x2a] = var4;
                    break;
                }
            }
        }
    }

    unsigned int flags = _ZZ17GetGlobal021ffefcvE1s.flags;
    if (!(flags & 1)) {
        unsigned int va = *(volatile unsigned int*)&__ptmf_null.a;
        unsigned int vb = *(volatile unsigned int*)&__ptmf_null.b;
        *(unsigned int*)((char*)data_ov023_021fe148 + 0x88) = va;
        *(unsigned int*)((char*)data_ov023_021fe148 + 0x8c) = vb;
        _ZZ17GetGlobal021ffefcvE1s.flags = flags | 1;
    }

    int var8 = *(int*)(arg0 + Enum_ov023_021ed9f8_3756);
    struct Struct_ov023_021fe148* var9 = &data_ov023_021fe148[var8];
    void* var10 = arg0 + ((int)var9->unknown_4_ >> 1);
    void* var11;
    if (var9->unknown_4_ & 1) {
        var11 = *(void**)((char*)*(void**)var10 + var9->unknown_0_);
    } else {
        var11 = (void*)var9->unknown_0_;
    }
    int var12 = ((int(*)(void*))var11)(var10);
    *(int*)(arg0 + Enum_ov023_021ed9f8_3756) = var12;

    int var13 = 0;
    if (func_ov017_021959b4()) {
        if (*(unsigned char*)(arg0 + Enum_ov023_021ed9f8_30673) == 0) {
            func_ov000_02160fa8(arg0, 0x2000000);
            var13 = 1;
        }
    }

    if (var13) {
        func_ov023_021f52c8((char*)_ZZ21inline_ov023_021f4c04vE1s.unknown_0_ + 0xf4);
        if (*(void**)(arg0 + Enum_ov023_021ed9f8_21896) != NULL) {
            func_ov023_021d8b6c(*(void**)(arg0 + Enum_ov023_021ed9f8_21896));
            func_ov023_021d8af8(*(void**)(arg0 + Enum_ov023_021ed9f8_21896));
            *(void**)(arg0 + Enum_ov023_021ed9f8_21896) = NULL;
        }

        if (((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.unknown_0_)->unknown_4_ > -1) {
            ((BackgroundLoader*)(var0))->RemoveTask((int)(((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.unknown_0_)->unknown_4_));
        }
        if (((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.unknown_0_)->unknown_8_ > -1) {
            ((BackgroundLoader*)(var0))->RemoveTask((int)(((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.unknown_0_)->unknown_8_));
        }
        if (((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.unknown_0_)->unknown_c_ > -1) {
            ((BackgroundLoader*)(var0))->RemoveTask((int)(((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.unknown_0_)->unknown_c_));
        }

        ((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.unknown_0_)->unknown_4_ = -1;
        ((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.unknown_0_)->unknown_8_ = -1;
        ((Struct_ov023_021ed9f8_2*)_ZZ21inline_ov023_021f4c04vE1s.unknown_0_)->unknown_c_ = -1;
        return;
    }

    void* var14 = *(void**)(arg0 + Enum_ov023_021ed9f8_21896);
    if (var14 == NULL) return;
    func_ov023_021d8bb4(var14);
}
