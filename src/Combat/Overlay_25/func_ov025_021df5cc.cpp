#include <globaldefs.h>

struct Struct_ov025_021def64 {
    char pad0[8];
    struct Struct_ov025_021def64* next;
};

// USA: func_ov025_021df5cc
extern "C" ARM struct Struct_ov025_021def64* func_ov025_021df5cc(struct Struct_ov025_021def64* node) {
    struct Struct_ov025_021def64* n;
    while ((n = node->next) != NULL) {
        node = n;
    }
    return node;
}
