#include <globaldefs.h>
#include "Input/Input.h"
#if defined(jpn)
enum { kRegion98 = 0xb0 };
#else
enum { kRegion98 = 0x98 };
#endif

extern "C" int func_0205d97c(void* obj);

// USA: func_ov003_0215dd00
extern "C" ARM int func_ov003_0215dd00(char* self) {
    if (g_keyManager.TestKeysPressed(2)) {
        return 1;
    }
    return func_0205d97c(self + kRegion98) == 2;
}
