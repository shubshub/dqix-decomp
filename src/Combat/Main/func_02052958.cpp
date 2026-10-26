#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int size);
extern "C" void Font_DecodeText(char* name, void* buf, int flag);
extern "C" int Font_EncodeText(void* a, void* b, int flag);
extern char g_stringFormat;

// USA: func_02052958
extern "C" ARM void func_02052958(char* obj, char* name, int arg2) {
    char buf1[0x30];
    char buf2[0x30];
    int len;

    __clear(buf1, 0x30);
    __clear(buf2, 0x30);
    Font_DecodeText(name, buf1, 1);
    len = Font_EncodeText(buf1, buf2, 1);
    memset(obj + 0x141, 0, 0xc);
    memcpy(obj + 0x141, name, len);
    if (arg2) {
        char buf3[0x30];
        __clear(buf3, 0x30);
        Font_DecodeText(name, buf3, 1);
        sprintf(*(char**)(obj + 0x134), &g_stringFormat, buf3);
    }
}
