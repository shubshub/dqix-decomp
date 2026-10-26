#include <globaldefs.h>

struct Struct_ov025_021e27c8 {
    char pad[0x582];
    unsigned char count;
    char pad2;
    unsigned short arr[1];
};

// USA: func_ov025_021eb084
extern "C" ARM void func_ov025_021eb084(struct Struct_ov025_021e27c8* obj, int val) {
    if (val < 0) {
        return;
    }
    if (obj->count == 0) {
        return;
    }
    int removed = 0;
    int w = 0;
    for (int i = 0; i < obj->count; i++) {
        unsigned short v = obj->arr[i];
        if (val == v) {
            removed = 1;
        } else {
            obj->arr[w] = v;
            w++;
        }
    }
    if (removed) {
        obj->count = obj->count - 1;
    }
}
