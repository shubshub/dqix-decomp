#if defined(jpn)
#define func_0204f7e8 func_02050cc0
#endif
#include <globaldefs.h>

#pragma opt_common_subs off

extern "C" void* __clear(void* dst, int count);
extern "C" int sprintf(char* dst, const char* fmt, ...);
int IsValueEqual12_02042190(int x);
extern "C" int Font_GetTextWidth(char* str, int id);
extern "C" void func_0204f41c(int a, short b, short c, char* buf, int d, int e, void* f, void* g, int h);
extern char data_020f02f5;
extern char data_020f02fc;
extern char data_020f0300;
#if defined(jpn)
extern char data_020f0315;
extern char data_020f031c;
extern char data_020f0327;
extern "C" void func_02050678(int arg0, short arg1, short arg2, char* arg3, int arg4, int arg5, void* arg6, void* arg7);
#endif

// USA: func_0204f7e8
extern "C" ARM void func_0204f7e8(int arg0, short arg1, short arg2, int arg3,
                                  unsigned char arg4, unsigned char arg5, void* arg6, void* arg7,
                                  unsigned char arg8, unsigned char arg9,
                                  unsigned char arg10, unsigned char arg11) {
#if defined(jpn)
    unsigned char var0 = 0;
    int var1 = arg3;
    do {
        var0++;
        var1 = var1 / 10;
    } while (var1 != 0);

    int var2 = 0;
    if (arg8) {
        if (var0 <= arg9) {
            var2 = arg4 * (arg9 - var0);
        } else {
            var2 = -(arg4 * (var0 - arg9));
        }
    }

    char var3[0x40];
    __clear(var3, 0x40);
    if (arg11) {
        char var4[8];
        __clear(var4, 8);
        sprintf(var4, &data_020f0315, arg9);
        sprintf(var3, var4, arg3);
    } else if (arg10 && arg3 > 0) {
        sprintf(var3, &data_020f031c, var2, arg3);
    } else {
        sprintf(var3, &data_020f0327, var2, arg3);
    }
    func_02050678(arg0, arg1, arg2, var3, arg4, arg5, arg6, arg7);
#else
    int var5 = arg3;
    do {
        var5 = var5 / 10;
    } while (var5 != 0);

    char var6[0x40];
    __clear(var6, 0x40);
    if (arg11) {
        char var7[8];
        __clear(var7, 8);
        sprintf(var7, &data_020f02f5, arg9);
        sprintf(var6, var7, arg3);
    } else if (arg10 && arg3 > 0) {
        sprintf(var6, &data_020f02fc, arg3);
    } else {
        sprintf(var6, &data_020f0300, arg3);
    }

    int index = IsValueEqual12_02042190(style);
    if (measure) {
        width = width - Font_GetTextWidth(buf, index);
    }
    func_0204f41c(arg0, arg1, arg2, var6, arg4, arg5, arg6, arg7, var8);
#endif
}
