#include <globaldefs.h>

// Main, originally SelectField0x8Or0x58ByFlags_0205c6e4 (USA 0x0205c6e4, EUR 0x0205c6f4, JPN 0x0205da44)
ARM unsigned int Window_GetPageCount(unsigned char* obj) {
    unsigned int result = 0;
    if (obj[0x94] && obj[0x50]) result = *(unsigned int*)(obj + 0x8);
    if (obj[0x95]) result = *(unsigned int*)(obj + 0x58);
    return result;
}
