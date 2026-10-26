#include <globaldefs.h>

extern "C" int func_ov023_021f6f10(void*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);

// USA: func_ov004_02156f04
extern "C" ARM void* func_ov004_02156f04(void* a, int key) {
    void* base = func_ov011_021849c8(a);
    void* node = func_ov023_021f6880(base, key);
    if (node) {
        if (func_ov023_021f6f10(node) == 8) {
            return node;
        }
    }
    return 0;
}
