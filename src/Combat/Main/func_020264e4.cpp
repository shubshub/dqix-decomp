#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void Font_DecodeText(const char*, char*, int);
extern char data_020ef6ca;

// USA: func_020264e4
extern "C" ARM void func_020264e4(char* obj, char* name) {
#if defined(jpn)
    if (name != NULL && *name != 0) {
        strcpy(obj + 0x688, name);
    } else {
        strcpy(obj + 0x688, &data_020ef6ca);
    }
#else
    if (name != NULL && *name != 0) {
        Font_DecodeText(name, obj + 0x6f4, 1);
    } else {
        strcpy(obj + 0x6f4, &data_020ef6ca);
    }
#endif
}
