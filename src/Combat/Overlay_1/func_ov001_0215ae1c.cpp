#include <globaldefs.h>
#include "Input/Input.h"

extern "C" void func_ov017_021d6134(void* obj, int sum);

// USA: func_ov001_0215ae1c
extern "C" ARM int func_ov001_0215ae1c(void* obj, int count) {
    if (count < 1) return 0;
    g_keyManager.RefreshKeys();
    int var0 = g_keyManager.IsYHeld();
    int var1 = g_keyManager.IsXHeld();
    int f1 = g_keyManager.IsAHeld();
    int f2 = g_keyManager.IsBHeld();
    func_ov017_021d6134(obj, f1 + f2 + var1 + var0);
    return 1;
}
