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
extern "C" void func_02069ecc(MessageSystem0219050c*, const char*, char*);
extern "C" void func_0206c570(void*, const char*);
extern "C" unsigned char* func_020e1b24(void*);
extern "C" void func_020e1b2c(void*, int);
extern "C" int func_020e1f1c(void*);
extern "C" void func_020e2110(void*);
extern "C" void func_020e23f4(void*);
extern "C" void func_020e2478(int*);
extern "C" void func_020e2cc4(Struct_020439b0*, int);
extern "C" void VramState_Rewind(Foo0207df50*);
extern int g_sePlayer;

#else

extern "C" void __clear(void* dst, int size);
extern "C" void* memcpy(void* dst, const void* src, unsigned int size);
extern "C" void* memset(void* dst, int value, unsigned int size);
extern "C" void* NameText_Clear(void*);
extern "C" void func_020dcf7c(int, void*);
extern "C" int STD_GetStringLength(const char*);
extern "C" void func_02044f3c(struct MessageSystem* window, const char* text, int mode);
extern "C" void func_0206b198(struct Struct_0204500c_4*, unsigned short);
extern "C" void func_0205e944(void* target, int level);
extern "C" void func_020416c0(struct Struct_0204166c*);
extern "C" void func_02042b98(struct MessageSystem* window, int a, int b, int c, int d);
extern "C" void func_02042fcc(struct Struct_02042c68*);
extern "C" void func_02045824(struct Struct_02042c68_2*, int, int);
extern "C" void func_02044d0c(void);
extern "C" void func_0204394c(struct Struct_0204394c*);
extern "C" void func_0206831c(struct MessageSystem* window, const char* text, char* destination);
extern "C" void func_02068418(struct MessageSystem* window, const char* source, char* destination, int fontIndex);
extern "C" void func_02068f40(struct MessageSystem* window, const char* source, char* destination, int fontIndex);
extern "C" void func_02069234(struct MessageSystem* window, const char* source, char* destination, int fontIndex);
extern "C" void func_020695f4(struct MessageSystem* window, const char* source, char* destination, int fontIndex);
extern "C" void func_02069fec(struct MessageSystem* window, const char* source, char* destination);
extern "C" void func_0206a974(struct Struct_0204500c_3*, const char*, int);
extern "C" unsigned char* func_020e1b24(void*);
extern "C" void func_020e1b2c(void*, int);
extern "C" int func_020e1f1c(void*);
extern "C" void func_020e2110(void*);
extern "C" void func_020e23f4(void*);
extern "C" void func_020e2478(int*);
extern "C" void func_020e2cc4(struct Struct_020439b0*, int);
extern "C" void VramState_Rewind(struct Foo0207df50*);

extern int g_sePlayer;

#endif

#if defined(jpn)
// USA: func_0204500c
extern "C" ARM void func_0204500c(MessageSystem* window, const char* text, int mode) {
    if (text == 0) return;
    for (int i = 0; i < 4; i++) {
        window->unknown_177c_[i] = -1;
        window->unknown_1952_[i] = 0;
    }
    window->unknown_1784_ = 0;
    window->unknown_1957_ = 0;
    window->flags17ff.flag4 = 1;
    window->flags17ff.unknown_0_3_ = 0;
    window->unknown_1958_ = 0;
    window->unknown_195b_ = 0;
    window->unknown_880_ = 0;
    window->unknown_1788_ = 12;
    if (window->mode == 3) {
        func_02044f3c(window, text, mode);
    } else {
        unsigned short var1 = window->unknown_1772_;
        unsigned short* var2 = window->unknown_1752_;
        for (unsigned short i = 0; i < var1; i++) {
            func_0206cb14(window, 10, var2[i]);
        }
        memset(window->unknown_1752_, 0xff01, sizeof(window->unknown_1752_));
        window->unknown_19c4_ = 0;
        window->unknown_19c3_ = 0;
        window->unknown_1772_ = 0;
        window->unknown_1774_ = 0;
        window->unknown_17f3_ = 1;
        window->flags17ff.flag5 = 0;
        window->unknown_17e0_ = 0;
        window->unknown_19bf_ = 1;
        window->flags17ff.flag1 = 1;
        window->levels[0] = window->levels[1] = window->levels[2] = window->levels[3] = 0x7f;
        func_0205e944(&g_sePlayer, 0x7f);
        memset(window->unknown_2cc_, 0, sizeof(window->unknown_2cc_));
        memset(window->textBuffer, 0, 0x800);
        memset(window->unknown_4c_, 0, 0x140);
        memset(window->unknown_1c_, 0, 0x140);
        window->unknown_19bd_ = 1;
        window->unknown_9b4_ = 14;
        for (int slot = 14; slot < 0x80; ++slot) {
            func_02041bbc(&window->glyphs[slot]);
            window->unknown_17b8_[slot] = 0;
        }
        window->unknown_17eb_ = 1;
        window->unknown_1730_ = 0xc;
        window->unknown_1864_ = 0x10;
        window->unknown_174c_ = 0x7fff;
        window->unknown_9a4_ = 3;
        func_02043270(window, 2, 0x80, 0xfc, 0x3e);
        window->unknown_19b8_ = 0;
        window->unknown_19b1_ = 1;
        window->unknown_860_ = 0x80;
        window->unknown_1868_ = 0;
        window->unknown_912_ = 0;
        window->unknown_994_ = -1;
        window->unknown_94c_[0] = 0;
        window->unknown_94c_[1] = 0;
        window->unknown_94c_[2] = 0;
        window->unknown_94c_[3] = 0;
        window->unknown_19ac_ = 0;
        window->unknown_17dd_ = 0;
        window->unknown_1960_ = 0;

        for (int i = 0; i < 4; i++) window->unknown_1868_ = 0;
        window->unknown_17f2_ = 0;
        window->unknown_19c0_ = 0;
        window->unknown_195d_ = 0x1e;
        window->b19c1 = 0;
        window->unknown_19c6_ = 0;
        window->unknown_19c7_ = 0;
        window->unknown_19c8_ = 0;
        window->unknown_19c9_ = 0;
        window->unknown_174e_ = 0;
        window->unknown_19cc_ = 0;
        window->flags17ff.unknown_0_0_ = 0;
        window->unknown_19cd_ = 0;
        if (mode == 1) {
            window->unknown_19cc_ = 1;
        } else if (mode == 1) {

            window->flags17ff.unknown_0_0_ = 1;
        }
        if (window->unknown_19cc_ != 0) {
            window->unknown_19cd_ = 1;
            window->unknown_40_ = 0;
            func_02044d0c();
        }
        if (window->flags17ff.unknown_0_0_ != 0) {
            window->unknown_44_ = 0;
            func_02044104((Struct_0204394c*)window->encoder);
        }
        func_020698d8(window, window->unknown_1788_, text, window->unknown_2c_);
        func_02069ecc((MessageSystem0219050c*)window, window->unknown_2c_, window->unknown_30_);
        func_0206c570(window, window->unknown_30_);
        func_02043270(window, 2, 0x74, 0xfc, 0x4a);
        window->unknown_1728_ = 2;
        window->unknown_172c_ = 0x7e;
        window->unknown_1730_ = 0xc;
        window->unknown_1864_ = 0x14;
        if (window->frame != 0) {
            unsigned char* frame = func_020e1b24(window->frame);
            if (frame != 0) {
                frame[0x38] = 2;
                frame[0x39] = 0x74;
                frame[0x3a] = 0xfc;
                frame[0x3b] = 0x4a;
                func_020e1b2c(window->frame, -1);
                if (func_020e1f1c(window->frame) != 0) {
                    func_020e2110(window->frame);
                    func_020e23f4(window->frame);
                    func_020e2478((int*)window->frame);
                }
            }
        }
        memset(window->unknown_82c_, 0, sizeof(window->unknown_82c_));
        memset(window->unknown_84c_, 0, sizeof(window->unknown_84c_));
        window->unknown_994_ = -1;
        window->unknown_19bc_ = 0;
        window->mode = 5;
        window->unknown_19b2_ = 1;
        window->state = 0;
        window->unknown_19ae_ = 0;
        window->unknown_19af_ = 0;
        window->unknown_19b5_ = 0;
        window->unknown_19c5_ = 0;
        window->b19ca = 1;
        window->unknown_19b4_ = 0;
        for (int i = 0; i < 2; i++) {
            func_020e2cc4(&window->entries[i].prefix, 0);
        }
        if (window->encoder != 0) VramState_Rewind(window->encoder);
    }
}
#else
// USA: func_0204500c
extern "C" ARM void func_0204500c(struct MessageSystem* window, const char* text, int mode, int arg3) {
    GameState* gs = GameState::GetInstance();

    short itemId = gs->unknown_7f58_;
    Struct_0204500c_2 itemName;
    NameText_Clear(&itemName);
    if (itemId > 0) {
        char first[0x80] = {};
        char second[0x80] = {};
        itemName.first = first;
        itemName.second = second;
        func_020dcf7c(itemId, &itemName);
        window->itemName = &itemName;
    }
    window->unknown_19dc_ = 1;
    if (text == 0) {
        return;
    }

    int len = STD_GetStringLength(text);
    for (int pos = 0; pos < len;) {
        int n = 0x40;
        char var16[0x43] = {};
        if (len < pos + 0x40) {
            n = len - pos;
        }
        memcpy(var16, text + pos, n);
        pos += n;
    }

    for (int i = 0; i < 4; i++) {
        window->unknown_194e_[i] = -1;
        window->unknown_1952_[i] = 0;
    }
    window->unknown_1956_ = 0;
    window->unknown_1957_ = 0;
    window->unknown_19d2_ = 1;
    window->unknown_19d1_ = 0;
    window->unknown_1958_ = 0;
    window->unknown_195b_ = 0;
    window->unknown_9b0_ = 0;
    window->unknown_195a_ = 8;

    if (window->mode == 3) {
        func_02044f3c(window, text, mode);
    } else {
        unsigned short var18 = window->unknown_1942_;
        for (unsigned short i = 0; i < var18; i++) {
            func_0206b198((struct Struct_0204500c_4*)window, window->unknown_1882_[i]);
        }
        memset(window->unknown_1882_, 0xff01, sizeof(window->unknown_1882_));
        memset(window->slotData, 0, sizeof(window->slotData));
        window->unknown_19c4_ = 0;
        window->unknown_19c3_ = 0;
        window->unknown_1942_ = 0;
        window->unknown_1944_ = 0;
        window->unknown_1946_ = 0;
        window->unknown_19c2_ = 1;
        window->b19d3 = 0;
        window->unknown_19b0_ = 0;
        window->unknown_19bf_ = 1;
        window->unknown_19cf_ = 1;
        window->levels[0] = window->levels[1] = window->levels[2] = window->levels[3] = 0x7f;
        func_0205e944(&g_sePlayer, 0x7f);
        memset(window->unknown_2cc_, 0, sizeof(window->unknown_2cc_));
        memset(window->textBuffer, 0, 0x960);
        memset(window->unknown_4c_, 0, 0x280);
        memset(window->unknown_50_, 0, 0x280);
        window->unknown_19bd_ = 1;
        window->unknown_9b4_ = 0;
        for (int slot = 0; slot < 0x80; ++slot) {
            func_020416c0(&window->glyphs[slot]);
            window->unknown_17b8_[slot] = 0;
        }
        window->unknown_19bb_ = 1;
        window->unknown_1860_ = 0xc;
        window->unknown_1864_ = 0x10;
        window->unknown_187c_ = 0x7fff;
        window->unknown_9a4_ = 3;
        func_02042b98(window, 2, 0x80, 0xfc, 0x3e);
        func_02042fcc(&window->unknown_930_);
        window->unknown_19b8_ = 0;
        window->unknown_19b1_ = 1;
        window->unknown_990_ = 0x80;
        window->unknown_1868_ = 0;
        window->unknown_912_ = 0;
        window->unknown_994_ = -1;
        window->unknown_94c_[0] = 0;
        window->unknown_94c_[1] = 0;
        window->unknown_94c_[2] = 0;
        window->unknown_94c_[3] = 0;
        window->unknown_19ac_ = 0;
        window->unknown_19ad_ = 0;
        window->unknown_1960_ = 0;
        func_02045824((struct Struct_02042c68_2*)window, 0, -1);
        window->unknown_19c0_ = 0;
        window->unknown_195d_ = 0x1e;
        window->b19c1 = 0;
        window->unknown_19c6_ = 0;
        window->unknown_19c7_ = 0;
        window->unknown_19c8_ = 0;
        window->unknown_19c9_ = 0;
        window->unknown_187e_ = 0;
        window->unknown_19cc_ = 0;
        window->unknown_19ce_ = 0;
        window->unknown_19cd_ = 0;
        if (mode == 1) {
            window->unknown_19cc_ = 1;
        } else if (mode == 1) {

            window->unknown_19ce_ = 1;
        }
        if (window->unknown_19cc_ != 0) {
            window->unknown_19cd_ = 1;
            window->unknown_40_ = 0;
            func_02044d0c();
        }
        if (window->unknown_19ce_ != 0) {
            window->unknown_44_ = 0;
            func_0204394c((struct Struct_0204394c*)window->encoder);
        }
        char* var21 = window->unknown_60_;
        char* var22 = window->unknown_64_;
        func_0206831c(window, text, var21);
        func_02068418(window, var21, var22, window->unknown_19dc_);
        func_02068f40(window, var22, var21, window->unknown_19dc_);
        func_02069234(window, var21, var22, window->unknown_19dc_);
        func_020695f4(window, var22, var21, window->unknown_19dc_);
        func_02069fec(window, var21, var22);
        func_0206a974((struct Struct_0204500c_3*)window, var22, arg3);
        func_02042b98(window, 2, 0x74, 0xfc, 0x4a);
        window->unknown_1858_ = 2;
        window->unknown_185c_ = 0x7e;
        window->unknown_1860_ = 0xc;
        window->unknown_1864_ = 0x14;
        if (window->frame != 0) {
            unsigned char* frame = func_020e1b24(window->frame);
            if (frame != 0) {
                frame[0x38] = 2;
                frame[0x39] = 0x74;
                frame[0x3a] = 0xfc;
                frame[0x3b] = 0x4a;
                func_020e1b2c(window->frame, -1);
                if (func_020e1f1c(window->frame) != 0) {
                    func_020e2110(window->frame);
                    func_020e23f4(window->frame);
                    func_020e2478((int*)window->frame);
                }
            }
        }
        memset(window->unknown_95c_, 0, sizeof(window->unknown_95c_));
        memset(window->unknown_97c_, 0, sizeof(window->unknown_97c_));
        window->unknown_994_ = -1;
        window->unknown_19bc_ = 0;
        window->mode = 5;
        window->unknown_19b2_ = 1;
        window->state = 0;
        window->unknown_19ae_ = 0;
        window->unknown_19af_ = 0;
        window->unknown_19b5_ = 0;
        window->unknown_19c5_ = 0;
        window->b19ca = 1;
        window->unknown_19b4_ = 0;
        for (int i = 0; i < 2; i++) {
            func_020e2cc4(&window->entries[i], 0);
        }
        if (window->encoder != 0) {
            VramState_Rewind(window->encoder);
        }
    }
    window->unknown_30_ = -1;
    window->unknown_31_ = -1;
    if (itemId > 0) {
        gs->unknown_7f58_ = 0;
    }
}

#endif
