#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned short func_ov023_021f6f10(void*);

// USA: func_ov004_02153944
extern "C" ARM void* func_ov004_02153944(void* a, int key) {
    void* base = func_ov011_021849c8(a);
    void* node = func_ov023_021f6880(base, key);
    if (!node) return NULL;
    int kind = func_ov023_021f6f10(node);
    void* result;
    if (kind != 6) result = NULL;
    else result = node;
    return result;
}
