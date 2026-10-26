#include <globaldefs.h>

struct Struct_0208e7a4_2 {
    unsigned int packed;              // 0x0
    char pad[0x6c - 4];               // 0x4..0x6b
    struct Struct_0208e7a4_2* next;        // 0x6c
};

struct Head0208e7a4 {
    char pad[4];                      // 0x0..0x3
    struct Struct_0208e7a4_2* head;        // 0x4
};

// USA: func_0208e7a4
extern "C" ARM struct Struct_0208e7a4_2* func_0208e7a4(struct Head0208e7a4* owner, unsigned int key) {
    struct Struct_0208e7a4_2* node = owner->head;
    while (node != NULL) {
        if (key == ((node->packed << 9) >> 25)) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}
