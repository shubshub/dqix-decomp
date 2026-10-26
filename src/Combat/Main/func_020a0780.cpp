#include <globaldefs.h>

struct Struct_020a0780 {
    char pad[0x34];
    unsigned int value : 24;
    unsigned int upper : 8;
};

// USA: func_020a0780
extern "C" ARM void func_020a0780(struct Struct_020a0780* obj, unsigned int amount) {
    unsigned int v = obj->value + amount;
    if (v > 0xffffff) {
        v = 0xffffff;
    }
    obj->value = v;
}
