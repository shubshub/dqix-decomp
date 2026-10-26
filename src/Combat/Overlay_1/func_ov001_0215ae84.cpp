#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void func_ov017_021d6134(void* obj, unsigned int val);

// USA: func_ov001_0215ae84
extern "C" ARM int func_ov001_0215ae84(void* obj) {
    int v = func_ov017_021d60f4(obj);
    unsigned short var1 = (unsigned short)v;
    int result = g_keyManager.TestKeysPressed(var1);
    func_ov017_021d6134((char*)obj + 8, result);
    return 1;
}
