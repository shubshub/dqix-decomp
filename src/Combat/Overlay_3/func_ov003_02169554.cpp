#include <globaldefs.h>
#include "Input/Input.h"
#if defined(jpn)
enum { kRegione4 = 0xe0 };
#else
enum { kRegione4 = 0xe4 };
#endif

extern "C" int func_0205d97c(void*);

// USA: func_ov003_02169554
extern "C" ARM int func_ov003_02169554(void* obj) {
    int a = g_keyManager.TestKeysPressed(2);
    int b = func_0205d97c((char*)obj + kRegione4) == 2;
    return (a | b) != 0;
}
