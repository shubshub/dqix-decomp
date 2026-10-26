#include <globaldefs.h>

struct Struct_ov023_021f66bc_2 {
    char pad[0xf0];
    void (*fn)(void*, void*);
};
struct Struct_ov023_021f66bc {
    struct Struct_ov023_021f66bc_2* unknown_0_;
};

extern "C" void* func_ov011_021849c8(void*);
extern "C" struct Struct_ov023_021f66bc* func_ov023_021f6880(void*, int);

// USA: func_ov023_021f66bc
extern "C" ARM void func_ov023_021f66bc(void* a, int key, void* arg2) {
    void* base = func_ov011_021849c8(a);
    struct Struct_ov023_021f66bc* node = func_ov023_021f6880(base, key);
    if (node) node->unknown_0_->fn(node, arg2);
}
