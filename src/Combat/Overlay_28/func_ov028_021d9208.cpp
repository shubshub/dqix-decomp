#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define func_0204f41c func_02050678
#endif

struct Struct_ov028_021d8a74;
extern "C" void func_ov028_021d8a74(Struct_ov028_021d8a74*, float);
extern "C" void func_ov028_021d8ad4(void* obj, char* buf);

struct Struct_ov028_021d9208 {
    unsigned int unknown_0_0_ : 4;
#if defined(jpn)
    unsigned int unknown_0_4_ : 1;
#else
    unsigned int unknown1_0_4_ : 2;
#endif
    unsigned int unknown_0_6_ : 1;
    unsigned int unknown_0_7_ : 4;
#if defined(jpn)
    unsigned int rest : 22;
#else
    unsigned int rest : 21;
#endif
};

struct Struct_ov028_021d9208_2 {
    short a;
    short b;
    Struct_ov028_021d9208 c;
    unsigned int d;
};

struct Struct_ov028_021d9208_3;
extern "C" struct Struct_ov028_021d9208_2* func_ov028_021d99f8(Struct_ov028_021d9208_3*, unsigned int);
extern "C" void func_ov028_021d8a40(void* buf, unsigned int val);
extern "C" int Font_GetTextWidth(void* d, int flag);
#if defined(jpn)
extern "C" void func_0204f41c(void* buf, int arg1, int byteField, void* d, unsigned char arg4, unsigned char arg5, short* p1, short* p2);
extern "C" void WindowPane_Init(char* obj);
extern "C" int func_0204fc40(void* unused0, char** cursor, char* tag, short* out, int max);
extern char data_ov028_021da41d[];
#else
extern "C" void func_0204f41c(void* buf, int arg1, int byteField, void* d, unsigned char arg4, unsigned char arg5, short* p1, short* p2, int flagC);
#endif

// USA: func_ov028_021d9208
extern "C" ARM void func_ov028_021d9208(char* self, int arg1) {
    float scale = *(float*)self;
    float angle = 0.5f * ((float)arg1 * scale);
    func_ov028_021d8a74((Struct_ov028_021d8a74*)(self + 0x60), angle);
    func_ov028_021d8ad4(self + 0x60, *(char**)(self + 0x40));

    char* buf40 = *(char**)(self + 0x40);
    short var3 = -1;
#if defined(jpn)
    unsigned char advance;
    int var5;
#else
    int var6;
#endif
    int flagC;
#if defined(jpn)
    short byteField;
#else
    int byteField;
#endif
#if defined(jpn)
    char measure[0xe0];
    short amount;
    short var11;
    short local1;
    unsigned int localBuf[0x38];
#else
    short var13;
    short local1;
    unsigned int localBuf[0x38];
#endif
    int found;

    for (;;) {
        unsigned short idx = *(unsigned short*)(self + 0x6c);
        struct Struct_ov028_021d9208_2* elem = func_ov028_021d99f8((Struct_ov028_021d9208_3*)self, idx);
        if (elem == 0) {
            found = 1;
            goto exitLoop;
        }

#if defined(jpn)
        unsigned int lhs = (*(int*)(self + 0x60) >> 12) + 0xc0;
        short var20 = elem->b;
        unsigned int rhs = var20 + ((int)*(int*)(self + 0x64) >> 12);
        if (lhs < rhs) {
            goto fail;
        }
        *(int*)(self + 0x64) += (var20 << 12);
#else
        short var22 = elem->a;
        if (var3 != var22) {
            unsigned int lhs = (*(int*)(self + 0x60) >> 12) + 0xc0;
            short var24 = elem->b;
            unsigned int rhs = var24 + (*(int*)(self + 0x64) >> 12);
            if (lhs < rhs) {
                goto fail;
            }
            *(unsigned int*)(self + 0x64) += (var24 << 12);
        }
#endif

        byteField = (*(int*)(self + 0x64) >> 12) & 0xff;
#if defined(jpn)
        var5 = 0;
        if (elem->c.unknown_0_4_ != 0) {
            advance = (unsigned char)elem->c.unknown_0_0_;
            char* text = (char*)elem->d;
            if (text != NULL) {
                WindowPane_Init(measure);
                char* cursor = text;
                while (*cursor != 0) {
                    amount = 0;
                    if (func_0204fc40(measure, &cursor, data_ov028_021da41d, &amount, 1)) {
                        var5 += amount;
                    } else if (*cursor >= '0' && *cursor <= '9') {
                        ++cursor;
                        var5 += advance;
                    } else if (*cursor >= 'a' && *cursor <= 'z') {
                        var5 += advance;
                        ++cursor;
                    } else if (*cursor >= 'A' && *cursor <= 'Z') {
                        var5 += advance;
                        ++cursor;
                    } else {
                        unsigned char ch = *(unsigned char*)cursor;
                        if ((ch >= 0x81 && ch <= 0x9f) || (ch >= 0xe0 && ch <= 0xea)) {
                            ++cursor;
                        }
                        var5 += advance;
                        ++cursor;
                    }
                }
            }
            var5 = (0x100 - var5) << 0xf >> 0x10;
        }
#else
        flagC = 0;
        if (elem->c.unknown_0_0_ == 0xc) {
            flagC = 1;
        }
        var6 = 0;
        if (elem->c.unknown1_0_4_ != 0) {
            int base = Font_GetTextWidth((void*)elem->d, flagC);
            var6 = 0x88;
            switch (elem->c.unknown1_0_4_) {
                case 1:
                    var6 = (0x100 - base) << 0xf >> 0x10;
                    break;
                case 2:
                    var6 = (short)(0x78 - base);
                    break;
            }
        }
#endif

        func_ov028_021d8a40(localBuf, (unsigned int)buf40);

        short var30 = elem->c.unknown_0_0_;
        *(short*)((char*)localBuf + 0xb4) = var30;
        *(short*)((char*)localBuf + 0xb6) = var30 + 1;

#if defined(jpn)
        func_0204f41c(localBuf, var5, byteField, (void*)elem->d, elem->c.unknown_0_0_, elem->c.unknown_0_7_, &local1, &var11);
#else
        func_0204f41c(localBuf, var6, byteField, (void*)elem->d, elem->c.unknown_0_0_, elem->c.unknown_0_7_, &local1, &var13, flagC);
#endif

        if ((unsigned int)byteField + elem->c.unknown_0_0_ > 0x100) {
#if defined(jpn)
            func_0204f41c(localBuf, var5, (short)(byteField - 0x100), (void*)elem->d, elem->c.unknown_0_0_, elem->c.unknown_0_7_, &local1, &var11);
#else
            func_0204f41c(localBuf, var6, (short)(byteField - 0x100), (void*)elem->d, elem->c.unknown_0_0_, elem->c.unknown_0_7_, &local1, &var13, flagC);
#endif
        }

        *(unsigned short*)(self + 0x6c) = *(unsigned short*)(self + 0x6c) + 1;
        *(unsigned char*)(self + 0x6e) = 1;
#if defined(jpn)

#else
        var3 = elem->a;
#endif
    }
fail:
    found = 0;
exitLoop:
    g_keyManager.TestKeysHeld(0x2000);
    if (found != 0) {
        *(unsigned char*)(self + 0x80) = 2;
        *(unsigned char*)(self + 0x81) = 0;
    }
}
