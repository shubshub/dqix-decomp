#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int func_0205d97c(void* p);

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

// USA: func_ov002_02161b48
extern "C" ARM int func_ov002_02161b48(char* base, int flag) {
    if (g_keyManager.TestKeysPressed(2)) {
        return 1;
    }
    if (flag) {
        if (func_0205d97c(base + RG(0xec8, 0xe20)) == 2) {
            return 1;
        }
    }
    return 0;
}
