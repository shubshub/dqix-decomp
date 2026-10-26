#include <globaldefs.h>
#include "Input/Input.h"

unsigned long long GetCurrentTimestamp(void);

struct Struct_02153628_2 { void* field0; unsigned int field4; unsigned int field8; };
extern Struct_02153628_2 data_02153628;

// USA: func_020e1154
extern "C" ARM void func_020e1154(void* obj) {
    unsigned long long result = GetCurrentTimestamp();
    data_02153628.field4 = (unsigned int)result;
    data_02153628.field8 = (unsigned int)(result >> 32);
    data_02153628.field0 = obj;
    g_keyManager.SetInputEnabled(false);
    g_keyManager.Clear();
    g_touchInput.SetInputEnabled(false);
    g_touchInput.ClearCurrentInput();
}
