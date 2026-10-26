#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);

// USA: func_ov004_0215e47c
extern "C" ARM void* func_ov004_0215e47c(void* a, int id) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), id);
    return node ? node : 0;
}
