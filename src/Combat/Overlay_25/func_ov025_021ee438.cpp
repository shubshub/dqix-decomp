#include <globaldefs.h>

struct Struct_ov025_021ee438 {
    char pad0[0xb0];
    int arr[(0x150 - 0xb0) / 4];
    unsigned char count;
    char pad1[7];
    int unknown_158_;
};

// USA: func_ov025_021ee438
extern "C" ARM int func_ov025_021ee438(struct Struct_ov025_021ee438* obj, int id) {
    if (id == 0) {
        return 1;
    }
    if (id == obj->unknown_158_) {
        return 0;
    }
    int i;
    for (i = 0; i < obj->count; i++) {
        int v = obj->arr[i];
        if (v == id) {
            return 0;
        }
    }
    return 1;
}
