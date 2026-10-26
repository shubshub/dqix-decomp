#include <globaldefs.h>

struct Struct_ov000_02160094 {
    char pad[0x30];
    struct Struct_ov000_02160094* next;
};

struct Struct_ov000_0215440c_2 {
    char pad0[8];
    unsigned char count;
    char pad1[7];
    struct Struct_ov000_02160094* head;
};

// USA: func_ov000_02160094
extern "C" ARM struct Struct_ov000_02160094* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int index) {
    struct Struct_ov000_02160094* node;
    int i;
    if (list->count <= index) return 0;
    node = list->head;
    i = 0;
    while (i < index && node != 0) {
        node = node->next;
        i++;
    }
    return node;
}
