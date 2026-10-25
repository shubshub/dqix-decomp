#include <globaldefs.h>
#include "std_library_functions.h"
extern "C" void __clear(void*, int);
extern "C" int Font_GetTextWidth(char*, int);
struct TextSurface0208d42c;
extern "C" void func_0204f41c(TextSurface0208d42c*, short, short, char*, int, unsigned char, short*, short*, int);
extern char data_020f120d, data_020f1212, data_020f1217;
#if defined(jpn)
extern char data_020f12e0[], data_020f12e5[], data_020f129b[];
int STD_GetStringLength(const char*);
extern "C" void func_02050678(TextSurface0208d42c*, short, short, const char*, int, unsigned char, short*, short*);
#endif

// USA: func_0208d42c
extern "C" ARM void func_0208d42c(void*, Struct_0208d42c* arg1, short arg2, short arg3, int arg4, unsigned char arg5, unsigned char arg6, unsigned char arg7, unsigned char arg8) {
    if (arg1) {
        char var0[8];
        short var1, var2;
        short var3 = 0;
        __clear(var0, 8);
#if defined(jpn)
        if (special) {
            if (mode == 2) sprintf(text, data_020f12e0, value);
            else sprintf(text, data_020f12e5, value);
        } else sprintf(text, data_020f129b, value);
        int length = STD_GetStringLength(text);
        if (rightAlign) offset = (mode - length) * 8;
        func_02050678(surface, x + offset, y, text, 8, style, &width, &height);
#else
        if (special) {
            if (mode == 2) sprintf(text, &data_020f120d, value);
            else sprintf(text, &data_020f1212, value);
        } else sprintf(text, &data_020f1217, value);
        if (rightAlign) offset = -Font_GetTextWidth(text, 0);
        func_0204f41c(surface, x + offset, y, text, 8, style, &width, &height, 0);
#endif
    }
}
