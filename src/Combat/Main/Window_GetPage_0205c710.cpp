#include <globaldefs.h>

// Main, originally SelectField0x18Or0x68ByFlags_0205c710 (USA 0x0205c710, EUR 0x0205c720, JPN 0x0205da70)
extern "C" ARM unsigned int Window_GetPage(unsigned char* obj) {
    unsigned int result = 0;
    if (obj[0x94] && obj[0x50]) result = *(unsigned int*)(obj + 0x18);
    if (obj[0x95]) result = *(unsigned int*)(obj + 0x68);
    return result;
}
