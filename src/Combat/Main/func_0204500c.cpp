#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"

#if defined(jpn)

extern "C" void func_02044f3c(void*, const char*, int);
extern "C" void func_0206cb14(void*, int, unsigned short);
extern "C" void func_0205e944(void*, int);
extern "C" void func_02041bbc(Struct_0204166c*);
extern "C" void func_02043270(void*, int, int, int, int);
extern "C" void func_02044d0c(void);
extern "C" void func_02044104(Struct_0204394c*);
extern "C" void func_020698d8(void*, int, const char*, char*);
extern "C" void func_02069ecc(Struct_0204500c_5*, const char*, char*);
extern "C" void func_0206c570(void*, const char*);
extern "C" unsigned char* func_020e1b24(void*);
extern "C" void func_020e1b2c(void*, int);
extern "C" int func_020e1f1c(void*);
extern "C" void func_020e2110(void*);
extern "C" void func_020e23f4(void*);
void InvokeSubHandlerIfPresent_020e2478(int*);
void SetEntryEnabled020e2cc4(Entry020e2cc4*, int);
void CopyInternalFields0207df50(Foo0207df50*);
extern int g_sePlayer;

#else

extern "C" void __clear(void* arg0, int arg1);
extern "C" void* memcpy(void* arg0, const void* arg1, unsigned int arg2);
extern "C" void* memset(void* arg0, int arg1, unsigned int arg2);
extern "C" void* func_020e46c4(void*);
extern "C" void func_020dcf7c(int, void*);
extern "C" int func_020d2ff0(const char*);
extern "C" void func_02044f3c(struct Struct_02021b84* arg0, const char* arg1, int arg2);
extern "C" void func_0206b198(struct Struct_0204500c_4*, unsigned short);
extern "C" void func_0205e944(void* arg0, int arg1);
extern "C" void func_020416c0(struct Struct_0204166c*);
extern "C" void func_02042b98(struct Struct_02021b84* arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_02042fcc(struct Struct_02042c68*);
extern "C" void func_02045824(struct Struct_02042c68_2*, int, int);
extern "C" void func_02044d0c(void);
extern "C" void func_0204394c(struct Struct_0204394c*);
extern "C" void func_0206831c(struct Struct_02021b84* arg0, const char* arg1, char* arg2);
extern "C" void func_02068418(struct Struct_02021b84* arg0, const char* arg1, char* arg2, int arg3);
extern "C" void func_02068f40(struct Struct_02021b84* arg0, const char* arg1, char* arg2, int arg3);
extern "C" void func_02069234(struct Struct_02021b84* arg0, const char* arg1, char* arg2, int arg3);
extern "C" void func_020695f4(struct Struct_02021b84* arg0, const char* arg1, char* arg2, int arg3);
extern "C" void func_02069fec(struct Struct_02021b84* arg0, const char* arg1, char* arg2);
extern "C" void func_0206a974(struct Struct_0204500c_3*, const char*, int);
extern "C" unsigned char* func_020e1b24(void*);
extern "C" void func_020e1b2c(void*, int);
extern "C" int func_020e1f1c(void*);
extern "C" void func_020e2110(void*);
extern "C" void func_020e23f4(void*);
extern "C" void func_020e2478(int*);
extern "C" void func_020e2cc4(struct Struct_020439b0*, int);
extern "C" void func_0207df50(struct Struct_0203d028*);

extern int g_sePlayer;

#endif

#if defined(jpn)
// USA: func_0204500c
extern "C" ARM void func_0204500c(Struct_02021b84* arg0, const char* arg1, int arg2) {
    if (arg1 == 0) return;
    for (int var0 = 0; var0 < 4; var0++) {
        arg0->unknown_177c_[var0] = -1;
        arg0->unknown_1952_[var0] = 0;
    }
    arg0->unknown_1784_ = 0;
    arg0->unknown_1957_ = 0;
    arg0->unknown_17ff_.unknown_0_4_ = 1;
    arg0->unknown_17ff_.unknown_0_3_ = 0;
    arg0->unknown_1958_ = 0;
    arg0->unknown_195b_ = 0;
    arg0->unknown_880_ = 0;
    arg0->unknown_1788_ = 12;
    if (arg0->unknown_9a0_ == 3) {
        func_02044f3c(arg0, arg1, arg2);
    } else {
        unsigned short var1 = arg0->unknown_1772_;
        unsigned short* var2 = arg0->unknown_1752_;
        for (unsigned short var3 = 0; var3 < var1; var3++) {
            func_0206cb14(arg0, 10, var2[var3]);
        }
        memset(window->lineGlyphSlots, 0xff01, sizeof(window->lineGlyphSlots));
        window->b19c4 = 0;
        window->b19c3 = 0;
        window->lineGlyphCount = 0;
        window->h1944 = 0;
        window->b19c2 = 1;
        window->flags17ff.flag5 = 0;
        window->b19b0 = 0;
        window->b19bf = 1;
        window->flags17ff.flag1 = 1;
        window->levels[0] = window->levels[1] = window->levels[2] = window->levels[3] = 0x7f;
        func_0205e944(&g_sePlayer, 0x7f);
        memset(window->bitmapAllocationBits, 0, sizeof(window->bitmapAllocationBits));
        memset(window->textBuffer, 0, 0x800);
        memset(window->firstLineBuffer, 0, 0x140);
        memset(window->secondLineBuffer, 0, 0x140);
        window->b19bd = 1;
        window->allocatedGlyphCount = 14;
        for (int slot = 14; slot < 0x80; ++slot) {
            func_02041bbc(&window->glyphs[slot]);
            window->glyphReferences[slot] = 0;
        }
        arg0->unknown_17eb_ = 1;
        arg0->unknown_1730_ = 0xc;
        arg0->unknown_1864_ = 0x10;
        arg0->unknown_174c_ = 0x7fff;
        arg0->unknown_9a4_ = 3;
        func_02043270(arg0, 2, 0x80, 0xfc, 0x3e);
        arg0->unknown_19b8_ = 0;
        arg0->unknown_19b1_ = 1;
        arg0->unknown_860_ = 0x80;
        arg0->unknown_1868_ = 0;
        arg0->unknown_912_ = 0;
        arg0->unknown_994_ = -1;
        arg0->unknown_94c_[0] = 0;
        arg0->unknown_94c_[1] = 0;
        arg0->unknown_94c_[2] = 0;
        arg0->unknown_94c_[3] = 0;
        arg0->unknown_19ac_ = 0;
        arg0->unknown_17dd_ = 0;
        arg0->unknown_1960_ = 0;

        for (int var5 = 0; var5 < 4; var5++) arg0->unknown_1868_ = 0;
        arg0->unknown_17f2_ = 0;
        arg0->unknown_19c0_ = 0;
        arg0->unknown_195d_ = 0x1e;
        arg0->unknown_19c1_ = 0;
        arg0->unknown_19c6_ = 0;
        arg0->unknown_19c7_ = 0;
        arg0->unknown_19c8_ = 0;
        arg0->unknown_19c9_ = 0;
        arg0->unknown_174e_ = 0;
        arg0->unknown_19cc_ = 0;
        arg0->unknown_17ff_.unknown_0_0_ = 0;
        arg0->unknown_19cd_ = 0;
        if (arg2 == 1) {
            arg0->unknown_19cc_ = 1;
        } else if (arg2 == 1) {

            arg0->unknown_17ff_.unknown_0_0_ = 1;
        }
        if (arg0->unknown_19cc_ != 0) {
            arg0->unknown_19cd_ = 1;
            arg0->unknown_40_ = 0;
            func_02044d0c();
        }
        if (arg0->unknown_17ff_.unknown_0_0_ != 0) {
            arg0->unknown_44_ = 0;
            func_02044104((Struct_0204394c*)arg0->unknown_1e28_);
        }
        func_020698d8(arg0, arg0->unknown_1788_, arg1, arg0->unknown_2c_);
        func_02069ecc((Struct_0204500c_5*)arg0, arg0->unknown_2c_, arg0->unknown_30_);
        func_0206c570(arg0, arg0->unknown_30_);
        func_02043270(arg0, 2, 0x74, 0xfc, 0x4a);
        arg0->unknown_1728_ = 2;
        arg0->unknown_172c_ = 0x7e;
        arg0->unknown_1730_ = 0xc;
        arg0->unknown_1864_ = 0x14;
        if (arg0->unknown_4_ != 0) {
            unsigned char* var6 = func_020e1b24(arg0->unknown_4_);
            if (var6 != 0) {
                var6[0x38] = 2;
                var6[0x39] = 0x74;
                var6[0x3a] = 0xfc;
                var6[0x3b] = 0x4a;
                func_020e1b2c(arg0->unknown_4_, -1);
                if (func_020e1f1c(arg0->unknown_4_) != 0) {
                    func_020e2110(arg0->unknown_4_);
                    func_020e23f4(arg0->unknown_4_);
                    func_020e2478((int*)arg0->unknown_4_);
                }
            }
        }
        memset(arg0->unknown_82c_, 0, sizeof(arg0->unknown_82c_));
        memset(arg0->unknown_84c_, 0, sizeof(arg0->unknown_84c_));
        arg0->unknown_994_ = -1;
        arg0->unknown_19bc_ = 0;
        arg0->unknown_9a0_ = 5;
        arg0->unknown_19b2_ = 1;
        arg0->unknown_99c_ = 0;
        arg0->unknown_19ae_ = 0;
        arg0->unknown_19af_ = 0;
        arg0->unknown_19b5_ = 0;
        arg0->unknown_19c5_ = 0;
        arg0->unknown_19ca_ = 1;
        arg0->unknown_19b4_ = 0;
        for (int var7 = 0; var7 < 2; var7++) {
            func_020e2cc4(&arg0->unknown_1964_[var7].unknown_0_, 0);
        }
        if (arg0->unknown_1e28_ != 0) func_0207df50(arg0->unknown_1e28_);
    }
}
#else
// USA: func_0204500c
extern "C" ARM void func_0204500c(struct Struct_02021b84* arg0, const char* arg1, int arg2, int arg3) {
    GameState* var8 = GameState::GetInstance();

    short var9 = var8->unknown_7f58_;
    Struct_0204500c_2 var10;
    func_020e46c4(&var10);
    if (var9 > 0) {
        char var11[0x80] = {};
        char var12[0x80] = {};
        var10.unknown_0_ = var11;
        var10.unknown_4_ = var12;
        func_020dcf7c(var9, &var10);
        arg0->unknown_18_ = &var10;
    }
    arg0->unknown_19dc_ = 1;
    if (arg1 == 0) {
        return;
    }

    int var13 = func_020d2ff0(arg1);
    for (int var14 = 0; var14 < var13;) {
        int var15 = 0x40;
        char var16[0x43] = {};
        if (var13 < var14 + 0x40) {
            var15 = var13 - var14;
        }
        memcpy(var16, arg1 + var14, var15);
        var14 += var15;
    }

    for (int var17 = 0; var17 < 4; var17++) {
        arg0->unknown_194e_[var17] = -1;
        arg0->unknown_1952_[var17] = 0;
    }
    arg0->unknown_1956_ = 0;
    arg0->unknown_1957_ = 0;
    arg0->unknown_19d2_ = 1;
    arg0->unknown_19d1_ = 0;
    arg0->unknown_1958_ = 0;
    arg0->unknown_195b_ = 0;
    arg0->unknown_9b0_ = 0;
    arg0->unknown_195a_ = 8;

    if (arg0->unknown_9a0_ == 3) {
        func_02044f3c(arg0, arg1, arg2);
    } else {
        unsigned short var18 = arg0->unknown_1942_;
        for (unsigned short var19 = 0; var19 < var18; var19++) {
            func_0206b198((struct Struct_0204500c_4*)arg0, arg0->unknown_1882_[var19]);
        }
        memset(window->lineGlyphSlots, 0xff01, sizeof(window->lineGlyphSlots));
        memset(window->slotData, 0, sizeof(window->slotData));
        window->b19c4 = 0;
        window->b19c3 = 0;
        window->lineGlyphCount = 0;
        window->h1944 = 0;
        window->h1946 = 0;
        window->b19c2 = 1;
        window->b19d3 = 0;
        window->b19b0 = 0;
        window->b19bf = 1;
        window->b19cf = 1;
        window->levels[0] = window->levels[1] = window->levels[2] = window->levels[3] = 0x7f;
        func_0205e944(&g_sePlayer, 0x7f);
        memset(window->bitmapAllocationBits, 0, sizeof(window->bitmapAllocationBits));
        memset(window->textBuffer, 0, 0x960);
        memset(window->firstLineBuffer, 0, 0x280);
        memset(window->secondLineBuffer, 0, 0x280);
        window->b19bd = 1;
        window->allocatedGlyphCount = 0;
        for (int slot = 0; slot < 0x80; ++slot) {
            Forward020416c0(&window->glyphs[slot]);
            window->glyphReferences[slot] = 0;
        }
        arg0->unknown_19bb_ = 1;
        arg0->unknown_1860_ = 0xc;
        arg0->unknown_1864_ = 0x10;
        arg0->unknown_187c_ = 0x7fff;
        arg0->unknown_9a4_ = 3;
        func_02042b98(arg0, 2, 0x80, 0xfc, 0x3e);
        func_02042fcc(&arg0->unknown_930_);
        arg0->unknown_19b8_ = 0;
        arg0->unknown_19b1_ = 1;
        arg0->unknown_990_ = 0x80;
        arg0->unknown_1868_ = 0;
        arg0->unknown_912_ = 0;
        arg0->unknown_994_ = -1;
        arg0->unknown_94c_[0] = 0;
        arg0->unknown_94c_[1] = 0;
        arg0->unknown_94c_[2] = 0;
        arg0->unknown_94c_[3] = 0;
        arg0->unknown_19ac_ = 0;
        arg0->unknown_19ad_ = 0;
        arg0->unknown_1960_ = 0;
        func_02045824((struct Struct_02042c68_2*)arg0, 0, -1);
        arg0->unknown_19c0_ = 0;
        arg0->unknown_195d_ = 0x1e;
        arg0->unknown_19c1_ = 0;
        arg0->unknown_19c6_ = 0;
        arg0->unknown_19c7_ = 0;
        arg0->unknown_19c8_ = 0;
        arg0->unknown_19c9_ = 0;
        arg0->unknown_187e_ = 0;
        arg0->unknown_19cc_ = 0;
        arg0->unknown_19ce_ = 0;
        arg0->unknown_19cd_ = 0;
        if (arg2 == 1) {
            arg0->unknown_19cc_ = 1;
        } else if (arg2 == 1) {

            arg0->unknown_19ce_ = 1;
        }
        if (arg0->unknown_19cc_ != 0) {
            arg0->unknown_19cd_ = 1;
            arg0->unknown_40_ = 0;
            func_02044d0c();
        }
        if (arg0->unknown_19ce_ != 0) {
            arg0->unknown_44_ = 0;
            func_0204394c((struct Struct_0204394c*)arg0->unknown_1e28_);
        }
        char* var21 = arg0->unknown_60_;
        char* var22 = arg0->unknown_64_;
        func_0206831c(arg0, arg1, var21);
        func_02068418(arg0, var21, var22, arg0->unknown_19dc_);
        func_02068f40(arg0, var22, var21, arg0->unknown_19dc_);
        func_02069234(arg0, var21, var22, arg0->unknown_19dc_);
        func_020695f4(arg0, var22, var21, arg0->unknown_19dc_);
        func_02069fec(arg0, var21, var22);
        func_0206a974((struct Struct_0204500c_3*)arg0, var22, arg3);
        func_02042b98(arg0, 2, 0x74, 0xfc, 0x4a);
        arg0->unknown_1858_ = 2;
        arg0->unknown_185c_ = 0x7e;
        arg0->unknown_1860_ = 0xc;
        arg0->unknown_1864_ = 0x14;
        if (arg0->unknown_38_ != 0) {
            unsigned char* var23 = func_020e1b24(arg0->unknown_38_);
            if (var23 != 0) {
                var23[0x38] = 2;
                var23[0x39] = 0x74;
                var23[0x3a] = 0xfc;
                var23[0x3b] = 0x4a;
                func_020e1b2c(arg0->unknown_38_, -1);
                if (func_020e1f1c(arg0->unknown_38_) != 0) {
                    func_020e2110(arg0->unknown_38_);
                    func_020e23f4(arg0->unknown_38_);
                    func_020e2478((int*)arg0->unknown_38_);
                }
            }
        }
        memset(arg0->unknown_95c_, 0, sizeof(arg0->unknown_95c_));
        memset(arg0->unknown_97c_, 0, sizeof(arg0->unknown_97c_));
        arg0->unknown_994_ = -1;
        arg0->unknown_19bc_ = 0;
        arg0->unknown_9a0_ = 5;
        arg0->unknown_19b2_ = 1;
        arg0->unknown_99c_ = 0;
        arg0->unknown_19ae_ = 0;
        arg0->unknown_19af_ = 0;
        arg0->unknown_19b5_ = 0;
        arg0->unknown_19c5_ = 0;
        arg0->unknown_19ca_ = 1;
        arg0->unknown_19b4_ = 0;
        for (int var24 = 0; var24 < 2; var24++) {
            func_020e2cc4(&arg0->unknown_1964_[var24], 0);
        }
        if (arg0->unknown_1e28_ != 0) {
            func_0207df50(arg0->unknown_1e28_);
        }
    }
    arg0->unknown_30_ = -1;
    arg0->unknown_31_ = -1;
    if (var9 > 0) {
        var8->unknown_7f58_ = 0;
    }
}

#endif
