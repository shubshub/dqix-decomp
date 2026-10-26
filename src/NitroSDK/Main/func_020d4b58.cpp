#include <globaldefs.h>

extern "C" ARM void OS_GetMacAddress(void* dst);

// USA: func_020d4b58
extern "C" ARM unsigned short func_020d4b58() {
    unsigned char buf[8];
    OS_GetMacAddress(buf);
    unsigned char* p = buf;
    unsigned short sum;
    int i;
    i = 0, sum = 0;
    do {
        unsigned char b = *p++;
        i++;
        sum = (unsigned short)(sum + b);
    } while (i < 6);
    unsigned short var5 = (unsigned short)(sum + *(int*)0x27ffc3c);
    unsigned short var6 = (unsigned short)(var5 * 7);
    return (var6 % 20) + 200;
}
