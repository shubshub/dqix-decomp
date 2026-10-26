#include <globaldefs.h>

struct Struct_020a15bc_2 {
    unsigned int field : 9;
    unsigned int pad : 23;
    unsigned int w1;
    unsigned int w2;
};

struct Struct_020a15bc {
    struct Struct_020a15bc_2* base;
    unsigned short pad4;
    unsigned short count;
};

// USA: func_020a15bc
extern "C" ARM struct Struct_020a15bc_2* func_020a15bc(struct Struct_020a15bc* arr, int id) {
    unsigned short key;
    int i;
    if (id <= 0) {
        return NULL;
    }
    key = (unsigned short)id;
    for (i = 0; i < arr->count; i++) {
        if (key == arr->base[i].field) {
            return &arr->base[i];
        }
    }
    return NULL;
}
