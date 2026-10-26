#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void Font_DecodeText(const char*, char*, int);
extern char data_020ef6ca;

// USA: func_02026528
extern "C" ARM void func_02026528(char* obj, char* name) {
#if defined(jpn)
    if (name != NULL && *name != 0) {
        strcpy(obj + 0x698, name);
    } else {
        strcpy(obj + 0x698, &data_020ef6ca);
    }
#else
    if (name != NULL && *name != 0) {
        Font_DecodeText(name, obj + 0x724, 1);
    } else {
        strcpy(obj + 0x724, &data_020ef6ca);
    }
#endif
}
