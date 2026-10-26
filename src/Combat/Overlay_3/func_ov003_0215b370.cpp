#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int func_0205d97c(void* p);

// USA: func_ov003_0215b370
extern "C" ARM int func_ov003_0215b370(void* obj, int flag) {
    if (g_keyManager.TestKeysPressed(2) != 0) return 1;
    if (flag == 0) goto ret0;
    if (func_0205d97c((char*)obj + 0xf4) == 2) return 1;
ret0:
    return 0;
}
