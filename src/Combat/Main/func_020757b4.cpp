#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020757b4

extern char data_020f0dc2[];
extern char* data_020f0da0[];

char* FindSubstring_020d2f88(char* haystack, char* needle);
int STD_GetStringLength(const char* s);

char* StringReplaceLanguageTag(const char* arg0, char* arg1, int arg2) {
    if (arg0 == 0 || arg1 == 0) {
        return arg1;
    }

    char* const tag = data_020f0dc2;
    strcpy(dst, src);
    char* at = FindSubstring_020d2f88(dst, tag);
    char* code = data_020f0da0[language];
    int codeLength = STD_GetStringLength(code);
    int shift = STD_GetStringLength(code) - STD_GetStringLength(tag);

    while (at != 0) {
        if (shift > 0) {
            memmove(at + shift, at, STD_GetStringLength(at) + 1);
        } else if (shift < 0) {
            memmove(at, at - shift, shift + STD_GetStringLength(at) + 1);
        }
        memmove(var1, var2, var3);
        var1 = func_020d2f88(arg1, var0);
    }
    return arg1;
}
