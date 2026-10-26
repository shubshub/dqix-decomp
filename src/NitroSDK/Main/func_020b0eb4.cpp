#include <globaldefs.h>

struct Struct_020b0eb4_2 {
    unsigned short lo;
    unsigned short hi;
    struct Struct_020b0eb4_2* next;
    unsigned char data[4];
};

struct Struct_020b0eb4 {
    unsigned char pad0[0xc];
    struct Struct_020b0eb4_2* head;
};

// USA: func_020b0eb4
extern "C" ARM void* func_020b0eb4(struct Struct_020b0eb4** slot, unsigned int key) {
    struct Struct_020b0eb4_2* node = (*slot)->head;
    if (node != NULL) {
        do {
            if (node->lo <= key && key <= node->hi) {
                return (char*)node + 8 + (key - node->lo) * 3;
            }
            node = node->next;
        } while (node != NULL);
    }
    return (char*)*slot + 4;
}
