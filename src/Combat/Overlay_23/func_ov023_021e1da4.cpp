#include <globaldefs.h>

struct Struct_ov004_021549e4 {
    void* first;
};

struct Struct_ov023_021e1da4 {
    struct Struct_ov023_021e1da4* next;
    char pad[4];
    short f8;
};

// USA: func_ov023_021e1da4
extern "C" ARM short func_ov023_021e1da4(struct Struct_ov004_021549e4* head, int val) {
    struct Struct_ov023_021e1da4* n = (struct Struct_ov023_021e1da4*)head->first;
    short i;
    if (n == NULL) {
        return -1;
    }
    i = 0;
    while (n != NULL) {
        if (n->f8 == val) {
            return i;
        }
        i = i + 1;
        n = n->next;
    }
    return -1;
}
