#include <globaldefs.h>

extern "C" int func_020d6884(void*, int, int, int);

// USA: func_020d6830
extern "C" ARM int func_020d6830(int a, unsigned short* b, int c) {
    unsigned short var0 = b[0];
    unsigned short m2 = b[1];
    int mask = 1 << c;
    if (a == 0) return 0;
    if (b == NULL) return 0;
    if ((var0 & mask) == 0) return 0;
    if ((m2 & mask) == 0) return 0;
    return func_020d6884((void*)a, var0, (int)((char*)b + 4), c);
}
