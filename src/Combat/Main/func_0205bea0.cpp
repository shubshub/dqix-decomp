#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int func_0205bd78(void* p, int b, int c);

// USA: func_0205bea0
extern "C" ARM int func_0205bea0(void* p) {
    if (g_touchInput.pressed_ != 0) {
        int v1;
        int v2;
        g_touchInput.GetTouchPoint(&v1, &v2);
        return (func_0205bd78(p, v1, v2) >= 0) ? 1 : 0;
    }
    return 0;
}
