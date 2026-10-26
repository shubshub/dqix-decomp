#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

typedef int (*Type_020bbc38)(int, int, int);
extern Type_020bbc38 data_020e92a8[];

struct Struct_020bbc38 {
    int idx;    // +0x0
    int addr;   // +0x4
    int unknown_8_;    // +0x8
    int size;   // +0xc
};

// USA: func_020bbc38
extern "C" ARM int func_020bbc38(Struct_020bbc38* arg0) {
    Type_020bbc38 fn = data_020e92a8[arg0->idx];
    CleanInvalidateCacheRange((const void*)(arg0->addr), arg0->size);
    return fn(arg0->addr, arg0->unknown_8_, arg0->size);
}
