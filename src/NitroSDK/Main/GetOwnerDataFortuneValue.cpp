#include <globaldefs.h>

extern "C" ARM void OS_GetMacAddress(void* dst);

// USA: func_020d4b58
ARM unsigned short GetOwnerDataFortuneValue_020d4b58() {
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
    unsigned short combined = (unsigned short)(sum + *(int*)0x27ffc3c);
    unsigned short mul7 = (unsigned short)(combined * 7);
    return (mul7 % 20) + 200;
}
