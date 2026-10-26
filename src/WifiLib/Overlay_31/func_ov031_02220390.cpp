#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov031_02220390
extern "C" THUMB unsigned char* func_ov031_02220390(unsigned char* buffer, int type, const void* data, int length) {
    buffer[0] = 0;
    buffer[1] = 0;
    buffer[2] = 0;
    buffer[3] = 0;
    unsigned short tag = type;
    ((unsigned short*)buffer)[0] = (unsigned char)(tag >> 8) | ((tag << 8) & 0xff00);
    int var1 = ((length + 4 + 7) & ~7) - 4;
    unsigned short size = length;
    ((unsigned short*)buffer)[1] = (unsigned char)(size >> 8) | ((size << 8) & 0xff00);
    buffer += 4;
    memset(buffer, 0, var1);
    memcpy(buffer, data, length);
    buffer += var1;
    return buffer;
}
