#include <globaldefs.h>

struct Struct_02089fb0 {
    signed char id;
    unsigned char pad[0x3f];
};

struct Struct_02086f24_5 {
    struct Struct_02089fb0* base;
    short count;
};

// USA: func_02089fb0
extern "C" ARM struct Struct_02089fb0* func_02089fb0(struct Struct_02086f24_5* arr, int id) {
    short i;
    if (id < 0) {
        return 0;
    }
    if (arr->base == 0) {
        return 0;
    }
    if (arr->count == 0) {
        return 0;
    }
    for (i = 0; i < arr->count; i++) {
        signed char entryId = arr->base[i].id;
        if (entryId == id) {
            return &arr->base[i];
        }
    }
    return 0;
}
