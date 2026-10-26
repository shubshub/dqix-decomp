#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int func_0205d97c(void*);

// USA: func_ov000_0217c5f4
extern "C" ARM int func_ov000_0217c5f4(void* objRaw) {
    char* obj = (char*)objRaw;
    int a = g_keyManager.TestKeysPressed(0x802);
    int b = func_0205d97c(obj + 0x188);
    if ((a | (b == 2)) != 0) {
        return 1;
    }
    return 0;
}
