#include <globaldefs.h>

struct Struct_ov023_021f6600 { char pad[0xc]; unsigned char unknown_c_; };

extern "C" void* func_ov011_021849c8(void*);
extern "C" Struct_ov023_021f6600* func_ov023_021f6880(void*, int);

// USA: func_ov023_021f6600
extern "C" ARM void func_ov023_021f6600(void* obj, int id, int mask) {
    void* sub = func_ov011_021849c8(obj);
    Struct_ov023_021f6600* node = func_ov023_021f6880(sub, id);
    if (node != NULL) {
        node->unknown_c_ &= ~mask;
    }
}
