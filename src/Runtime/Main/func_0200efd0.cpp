#include <globaldefs.h>

struct Struct_02104b60 {
    struct Struct_02104b60* next;
    int b;
    int c;
};

extern struct Struct_02104b60* data_020f33b0;

// USA: func_0200efd0
extern "C" ARM void __register_global_object(int c, int b, struct Struct_02104b60* node) {
    node->next = data_020f33b0;
    node->b = b;
    node->c = c;
    data_020f33b0 = node;
}
