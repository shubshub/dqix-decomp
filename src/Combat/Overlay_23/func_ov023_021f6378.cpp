#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned short func_ov023_021f6f10(void*);

// USA: func_ov023_021f6378
extern "C" ARM int func_ov023_021f6378(void* a, int key) {
    void* base = func_ov011_021849c8(a);
    char* node = (char*)func_ov023_021f6880(base, key);
    if (!node) return 0;
    int kind = func_ov023_021f6f10(node);
    int result;
    if (kind != 8) result = 0;
    else result = *(unsigned short*)(node + 0x38);
    return result;
}
