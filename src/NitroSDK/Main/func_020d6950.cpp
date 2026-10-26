#include <globaldefs.h>

#include "NitroSDK/Cache.h"

extern "C" int func_020d4204(void);
extern "C" void func_020d404c(int index, int value);
extern "C" int func_020d40bc(int, int, int, int, int);


// USA: func_020d6950
extern "C" ARM int func_020d6950(int a0, int a1, int a2, int a3) {
    int r = func_020d4204();
    if (r != 0) {
        return r;
    }
    if ((unsigned int)a1 > 3) {
        return 6;
    }
    if (a1 != 0) {
        if (a3 == 0) {
            return 6;
        }
        CleanCacheRange((const void*)a3, 0x50);
    }
    func_020d404c(0x27, a0);
    r = func_020d40bc(0x27, 3, a1, a3, a2);
    if (r == 0) {
        r = 2;
    }
    return r;
}
