#include <globaldefs.h>

#include "NitroSDK/Cache.h"

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

extern "C" int func_020d424c(int, int, int);
extern "C" int func_020ca3b8(int, void*, int);
extern "C" void func_020d404c(int index, int value);
extern "C" int func_020d40bc(int, int, void*, int, int, int, int);

extern char data_02114d80;


// USA: func_020d69cc
extern "C" ARM int func_020d69cc(int a0, int a1, int a2, int a3, unsigned short a4, unsigned char a5) {
    int r = func_020d424c(2, 7, 9);
    if (r != 0) {
        return r;
    }
    if (a1 == 0) {
        return 6;
    }
    if ((unsigned int)a2 > 0x70) {
        return 6;
    }
    func_020ca3b8(a1, &data_02114d80, a2);
    CleanCacheRange(&data_02114d80, a2);
    func_020d404c(0x18, a0);
    r = func_020d40bc(0x18, 5, &data_02114d80, a2, a3, a4, a5);
    if (r == 0) {
        r = 2;
    }
    return r;
}
