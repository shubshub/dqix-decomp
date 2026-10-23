#include <globaldefs.h>
#include "Input/Input.h"
#if defined(jpn)
enum { kRegione4 = 0xe0 };
#else
enum { kRegione4 = 0xe4 };
#endif

struct Obj_0205da38;
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);

// USA: func_ov003_0216950c  (semantic: CheckFlagsAndActiveElement_0216950c)
extern "C" ARM int func_ov003_0216950c(void* objRaw) {
    char* obj = (char*)objRaw;
    int a = Window_IsSelectionTouched((struct Obj_0205da38*)(obj + kRegione4), 0x14);
    int b = g_keyManager.TestKeysPressed(0x1);
    int c = g_keyManager.TestKeysPressed(0x400);
    if ((b | c | a) != 0) {
        return 1;
    }
    return 0;
}
