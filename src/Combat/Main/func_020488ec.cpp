#include <globaldefs.h>
#include "std_library_functions.h"

extern char* data_020f015c[];

// USA: func_020488ec
extern "C" ARM void func_020488ec(char* obj) {
    memset(obj + 0x14c, 0, 0x30);
    strcpy(obj + 0x14c, *(char**)(obj + 0x148) + 0x2c);
    strcat(obj + 0x14c, data_020f015c[*(unsigned char*)(*(char**)(obj + 0x138) + 0x25)]);
}
