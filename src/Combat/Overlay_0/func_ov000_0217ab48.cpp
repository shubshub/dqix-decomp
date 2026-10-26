#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int func_0205d97c(int);

// USA: func_ov000_0217ab48
extern "C" ARM int func_ov000_0217ab48(void* objRaw) {
    char* obj = (char*)objRaw;
    int a = g_keyManager.TestKeysPressed(0x802);
    int b = func_0205d97c(*(int*)(obj + 0x38));
    if ((a | (b == 2)) != 0) {
        return 1;
    }
    return 0;
}
