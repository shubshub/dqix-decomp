#include <globaldefs.h>
#include "std_library_functions.h"
extern "C" void __clear(void*, int);
extern "C" int Font_GetTextWidth(char*, int);
struct Struct_0208d42c;
extern "C" void func_0204f41c(Struct_0208d42c*, short, short, char*, int, unsigned char, short*, short*, int);
extern char data_020f120d, data_020f1212, data_020f1217;
#if defined(jpn)
extern char data_020f12e0[], data_020f12e5[], data_020f129b[];
extern "C" int STD_GetStringLength(const char*);
extern "C" void func_02050678(Struct_0208d42c*, short, short, const char*, int, unsigned char, short*, short*);
#endif

// USA: func_0208d42c
extern "C" ARM void func_0208d42c(void*, Struct_0208d42c* arg1, short x, short y, int value, unsigned char style, unsigned char mode, unsigned char rightAlign, unsigned char special) {
    if (arg1) {
        char text[8];
        short width, height;
        short offset = 0;
        __clear(text, 8);
#if defined(jpn)
        if (special) {
            if (mode == 2) sprintf(text, data_020f12e0, value);
            else sprintf(text, data_020f12e5, value);
        } else sprintf(text, data_020f129b, value);
        int length = STD_GetStringLength(text);
        if (rightAlign) offset = (mode - length) * 8;
        func_02050678(arg1, x + offset, y, text, 8, style, &width, &height);
#else
        if (special) {
            if (mode == 2) sprintf(text, &data_020f120d, value);
            else sprintf(text, &data_020f1212, value);
        } else sprintf(text, &data_020f1217, value);
        if (rightAlign) offset = -Font_GetTextWidth(text, 0);
        func_0204f41c(arg1, x + offset, y, text, 8, style, &width, &height, 0);
#endif
    }
}
