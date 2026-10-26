#include <globaldefs.h>

struct Struct_0203fc5c {
    char pad[0x40];
    float field40;
};

// USA: func_0203fc5c
extern "C" ARM int func_0203fc5c(struct Struct_0203fc5c* obj, float value) {
    if (value <= 0.0f) {
        return 0;
    }
    obj->field40 = value;
    return 1;
}
