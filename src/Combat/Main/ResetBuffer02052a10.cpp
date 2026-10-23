#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void Font_EncodeText(void*, void*, int);

// USA: func_02052a10
ARM void* ResetBuffer02052a10(char* obj) {
    memset(obj + 0x141, 0, 0xc);
    Font_EncodeText(*(void**)(obj + 0x134), obj + 0x141, 1);
    return obj + 0x141;
}
