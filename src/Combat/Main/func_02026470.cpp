#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int StandardStrings_Get(int value);
extern "C" int Font_GetTextWidth(char*, int);

#if defined(jpn)
#define data_020ef6c5 data_020ef5b0
#endif
extern char data_020ef6b5;
extern char data_020ef6c5;

// USA: func_02026470
extern "C" ARM void func_02026470(void* obj, int number) {
    if (number == 0) {
        strcpy((char*)obj + 0x5f4, &data_020ef6b5);
    } else {
#if defined(jpn)
        sprintf((char*)obj + 0x5f4, &data_020ef6c5, number);
#else
        const char* prefix = (const char*)StandardStrings_Get(0x3f3);
        sprintf((char*)obj + 0x5f4, &data_020ef6c5, prefix, number);
#endif
    }
#if !defined(jpn)
    int len = Font_GetTextWidth((char*)obj + 0x5f4, 0);
    *(int*)((char*)obj + 0xbe4) += len + 4;
#endif
}
