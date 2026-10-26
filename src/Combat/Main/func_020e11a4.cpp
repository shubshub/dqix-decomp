#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_02153628_3 { unsigned int field0; unsigned int field4; unsigned int field8; };
extern struct Struct_02153628_3 data_02153628;

// USA: func_020e11a4
extern "C" ARM void func_020e11a4(void) {
    data_02153628.field4 = 0;
    data_02153628.field8 = 0;
    data_02153628.field0 = 0;
    g_keyManager.SetInputEnabled(true);
    g_touchInput.SetInputEnabled(true);
}
