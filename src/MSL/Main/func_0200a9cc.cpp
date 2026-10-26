#include <globaldefs.h>

// USA: func_0200a9cc
extern "C" ARM unsigned char func_0200a9cc(unsigned long long v) {
    v = v - ((v >> 1) & 0x5555555555555555ULL);
    v = (v & 0x3333333333333333ULL) + ((v >> 2) & 0x3333333333333333ULL);
    v = (v + (v >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
    v = v + (v >> 8);
    v = v + (v >> 16);
    v = v + (v >> 32);
    return (unsigned char)v;
}
