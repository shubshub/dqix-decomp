#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int func_0205bd78(void* p, int b, int c);

struct Struct_0205bc2c {
    int field0;
    char pad0[0x30 - 0x4];
    int unknown_30_;
    char pad1[0x4c - 0x34];
    unsigned char field4c;
    unsigned char unknown_4d_;
    unsigned char unknown_4e_;
};

// USA: func_0205bc2c
extern "C" ARM int func_0205bc2c(Struct_0205bc2c* obj, int) {
    int v1, v2;

    if (obj->field0 == 0) return 0;

    g_touchInput.GetTouchPoint(&v1, &v2);

    if (g_touchInput.pressed_ != 0 && obj->unknown_4e_ == 0) {
        int var2;

        obj->unknown_4e_ = 1;
        var2 = obj->unknown_30_;
        obj->unknown_30_ = func_0205bd78(obj, v1, v2);
        if (obj->unknown_30_ < 0) {
            obj->unknown_4e_ = 0;
            return 0;
        }
        obj->field4c = 1;
        if (var2 != obj->unknown_30_) obj->field4c = 0;
        return 1;
    }

    obj->field4c = 0;
    obj->unknown_4e_ = 0;
    return 0;
}
