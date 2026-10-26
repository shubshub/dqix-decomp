#include <globaldefs.h>

extern "C" int func_ov023_021f6f10(void*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);

// USA: func_ov023_021f9cb8
extern "C" ARM void* func_ov023_021f9cb8(void* unused, void* other, void* node) {
    void* obj;
    void* node2;
    unsigned short var2;
    if (!node) {
        return 0;
    }
    if (func_ov023_021f6f10(node) != 8) {
        return 0;
    }
    var2 = *(unsigned short*)((char*)node + 0x34);
    obj = func_ov011_021849c8(other);
    node2 = func_ov023_021f6880(obj, var2);
    if (!node2) {
        return 0;
    }
    if (func_ov023_021f6f10(node2) != 6) {
        return 0;
    }
    return node2;
}
