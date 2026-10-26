#include <globaldefs.h>

extern "C" ARM void OS_GetMacAddress(void* dst);

// USA: func_020d4be8
ARM unsigned short GetOwnerDataFortuneValue020d4be8() {
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
    sum = (unsigned short)(sum + *(int*)0x27ffc3c);
    return ((unsigned short)(sum * 13) % 10) + 30;
}
