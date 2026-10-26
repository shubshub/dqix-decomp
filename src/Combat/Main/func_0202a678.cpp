#include <globaldefs.h>

struct Struct_02029988 {
    char unk[0x40];
    int value;
    int lower;
    int upper;
    unsigned short flags;
};

// USA: func_0202a678
extern "C" ARM void func_0202a678(struct Struct_02029988* obj, int delta) {
    int above;
    int below;
    obj->value += delta;
    below = obj->lower;
    above = obj->upper;
    if (obj->flags & 0x100) {
        below = obj->upper;
        above = obj->lower;
    }
    if (obj->value < obj->lower) {
        obj->value = below;
        return;
    }
    if (obj->upper < obj->value) {
        obj->value = above;
    }
}
