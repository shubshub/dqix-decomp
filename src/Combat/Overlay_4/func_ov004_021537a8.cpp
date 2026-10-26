#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);

struct Struct_ov004_021537a8 {
    char pad[0x3c];
    int (*fn)(void*, int);
};
struct Struct_ov004_021537a8_2 {
    struct Struct_ov004_021537a8* unknown_0_;
};

// USA: func_ov004_021537a8
extern "C" ARM int func_ov004_021537a8(void* self, int key, int arg) {
    struct Struct_ov004_021537a8_2* node = (struct Struct_ov004_021537a8_2*)func_ov023_021f6880(func_ov011_021849c8(self), key);
    if (!node) return (int)node;
    return node->unknown_0_->fn(node, arg);
}
