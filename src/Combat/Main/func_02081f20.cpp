#include <globaldefs.h>
#include "Input/Input.h"

extern unsigned short __attribute__((aligned(4))) data_020e8a84[];

struct Struct_02081f20 {
    unsigned short field_0;
    unsigned char unknown_2_;
};

struct Struct_02081f20_2 {
    struct Struct_02081f20 *field_0;
    unsigned short unknown_4_;
    signed char unknown_6_;
    signed char unknown_7_;
    signed char field_8;
};

extern "C" void func_0208203c(struct Struct_02081f20_2* obj);

// USA: func_02081f20
extern "C" ARM unsigned short func_02081f20(struct Struct_02081f20_2* obj, int ticks) {
    if (obj->field_0 == NULL) return 0;
    obj->field_0->unknown_2_ = 0;
    if (obj->field_0->field_0 == 0) {
        unsigned short ids[4];
        {
            const unsigned short* src = data_020e8a84;
            unsigned short* dst = ids;
            int n = 4;
            do {
                *dst++ = *src++;
            } while (--n);
        }
        int i;
        for (i = 0; i < 4; i++) {
            unsigned short id = ids[i];
            if (g_keyManager.TestKeysPressed(id)) {
                obj->field_0->field_0 = id;
                obj->field_8 = obj->unknown_6_;
                obj->field_0->unknown_2_ = 1;
                goto end;
            }
        }
        goto end;
    }
    if (obj->field_0->field_0 != 0) {
        if (g_keyManager.TestKeysHeld(obj->field_0->field_0)) {
            obj->field_8 -= (signed char)ticks;
            if (obj->field_8 < 0) {
                obj->field_8 += obj->unknown_7_;
                obj->field_0->unknown_2_ = 2;
            }
            goto end;
        }
        func_0208203c(obj);
    }
end:
    return obj->field_0->unknown_2_;
}
