#include <globaldefs.h>

struct Struct_ov003_0215570c {
    char pad0[0x20];
    int* f20;
};

// USA: func_ov003_0215570c
extern "C" ARM int func_ov003_0215570c(struct Struct_ov003_0215570c* obj) {
    int count = 0;
    for (unsigned char i = 0; i < 0xc; i++) {
        if (obj->f20[i] != 0) count++;
    }
    return count;
}
