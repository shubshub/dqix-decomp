#include <globaldefs.h>

struct Struct_0209c0c0 {
    unsigned short arr[12];
    unsigned short count;
};

// USA: func_0209c0c0
extern "C" ARM unsigned short func_0209c0c0(struct Struct_0209c0c0* src, struct Struct_0209c0c0* dst) {
    int i;
    for (i = 0; i < src->count; i++) {
        dst->arr[i] = src->arr[i];
    }
    return src->count;
}
