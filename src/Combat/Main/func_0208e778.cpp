#include <globaldefs.h>

struct Struct_0208e0c4_2 {
    char unknown_0_[0x6c];
    struct Struct_0208e0c4_2* next;
};

struct Struct_0208e0c4 {
    char unknown_0_[4];
    struct Struct_0208e0c4_2* head;
    unsigned short count;
};

// USA: func_0208e778
extern "C" ARM void func_0208e778(struct Struct_0208e0c4* c, struct Struct_0208e0c4_2* node) {
    struct Struct_0208e0c4_2** slot = &c->head;
    while (*slot != 0) {
        slot = &(*slot)->next;
    }
    *slot = node;
    c->count++;
}
