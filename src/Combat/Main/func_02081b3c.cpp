#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02081b3c_2 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
};
struct Struct_02081b3c {
    unsigned char unknown_0_0_ : 2;
    unsigned char unknown_0_2_ : 6;
};

extern "C" ARM int func_02042190(int arg0);
extern "C" ARM int MessageSystem_GetInstance(void);
extern "C" ARM void func_0206819c(const char* arg0, char* arg1, int arg2);

extern "C" void __clear(void* arg0, int arg1);
extern "C" int Font_GetTextWidth(void* arg0, int arg1);
extern "C" void func_02046380(void* arg0);
extern "C" int MessageSystem_FormatText(int arg0, int arg1, void* arg2, void* arg3, int arg4, int arg5, int arg6);
extern "C" int func_0204f41c(void* arg0, int arg1, int arg2, void* arg3, int arg4, int arg5, void* arg6, void* arg7, int arg8);

#if defined(jpn)
extern "C" int STD_GetStringLength(const char* arg0);
extern "C" void func_020474a8(void* arg0, int arg1, void* arg2, void* arg3);
extern "C" void func_02050678(void* arg0, int arg1, int arg2, void* arg3, int arg4, int arg5, void* arg6, void* arg7);
#endif

#define F13(e) ((struct Struct_02081b3c_2*)((e) + 0x13))
#define F14(e) ((struct Struct_02081b3c*)((e) + 0x14))

// USA: func_02081b3c
#if defined(jpn)
extern "C" ARM void func_02081b3c(void* arg0, void* arg1, void* arg2) {
    char* var0 = (char*)arg0;
    char* var1 = (char*)arg1;
    char* var2 = (char*)arg2;

    int var3 = F13(var2)->unknown_0_4_;
    if (*(unsigned char*)(var2 + 0x2a) & 0x4) {
        var3 = 5;
    }

    if ((*(unsigned char*)(var2 + 0x2a) & 0x8) && *(char**)(var2 + 0x0) != NULL) {
        short var7 = *(short*)(var1 + 0xa8) * 8;
        int var8 = STD_GetStringLength(*(char**)(var2 + 0x0)) >> 1;
        *(short*)(var2 + 0x6) = (short)(var7 - var8 * F13(var2)->unknown_0_0_) >> 1;
    }

    int var10 = MessageSystem_GetInstance();
    memset(*(void**)(var0 + 0x18), 0, 0x800);
    func_02046380((void*)var10);
    func_020474a8((void*)var10, F13(var2)->unknown_0_0_, *(void**)(var2 + 0x0), *(void**)(var0 + 0x18));

    int var11 = F13(var2)->unknown_0_0_;
    *(short*)(var1 + 0xb4) = (short)var11;
    *(short*)(var1 + 0xb6) = (short)(var11 + 1);

    if (*(unsigned char*)(var2 + 0x2a) & 0x10) {
        int var12 = F13(var2)->unknown_0_0_;
        if (var12 == 0xc) {
            *(short*)(var1 + 0xb4) = (short)var12;
            *(short*)(var1 + 0xb6) = 0x14;
        }
    }

    short var14 = *(short*)(var2 + 0x6);
    short var15 = *(short*)(var2 + 0x28);
    short var16 = *(short*)(var2 + 0x8);
    int var17 = (short)(var14 + var15);
    func_02050678(var1, var17, var16, *(void**)(var0 + 0x18), F13(var2)->unknown_0_0_, var3, var2 + 0xa, var2 + 0xc);
}
#else
extern "C" ARM void func_02081b3c(void* arg0, void* arg1, void* arg2) {
    char* var0 = (char*)arg0;
    char* var1 = (char*)arg1;
    char* var2 = (char*)arg2;

    int var3 = F13(var2)->unknown_0_4_;
    if (*(unsigned char*)(var2 + 0x2a) & 0x4) {
        var3 = 5;
    }

    int var4 = func_02042190(F13(var2)->unknown_0_0_);

    char var5[0x100];
    char* var6 = *(char**)(var2 + 0x0);
    __clear(var5, 0x100);

    if (*(unsigned char*)(var2 + 0x2a) & 0x40) {
        func_0206819c(var6, var5, var4);
        var6 = var5;
    }

    if ((*(unsigned char*)(var2 + 0x2a) & 0x8) && var6 != NULL) {
        int var7 = *(short*)(var1 + 0xa8) << 0x13;
        int var8 = Font_GetTextWidth(var6, var4);
        int var9 = (int)((unsigned int)((var7 >> 0x10) - var8) << 0x10) >> 0x11;
        *(short*)(var2 + 0x6) = (short)var9;
    }

    int var10 = MessageSystem_GetInstance();
    memset(*(void**)(var0 + 0x18), 0, 0x960);
    func_02046380((void*)var10);
    MessageSystem_FormatText(var10, F13(var2)->unknown_0_0_, var6, *(void**)(var0 + 0x18), 0x100, 0, 0);

    int var11 = F13(var2)->unknown_0_0_;
    *(short*)(var1 + 0xb4) = (short)var11;
    *(short*)(var1 + 0xb6) = (short)(var11 + 1);

    if (*(unsigned char*)(var2 + 0x2a) & 0x10) {
        int var12 = F13(var2)->unknown_0_0_;
        if (var12 == 0xc) {
            *(short*)(var1 + 0xb4) = (short)var12;
            *(short*)(var1 + 0xb6) = 0x14;
        }
    }

    int var13 = 0;
    if (F14(var2)->unknown_0_0_) {
        var13 = Font_GetTextWidth(*(void**)(var0 + 0x18), 0);
    }

    short var14 = *(short*)(var2 + 0x6);
    short var15 = *(short*)(var2 + 0x28);
    short var16 = *(short*)(var2 + 0x8);
    int var17 = (short)(var14 + var15 - var13);
    func_0204f41c(var1, var17, var16, *(void**)(var0 + 0x18), F13(var2)->unknown_0_0_, var3, var2 + 0xa, var2 + 0xc, 0);
}
#endif
