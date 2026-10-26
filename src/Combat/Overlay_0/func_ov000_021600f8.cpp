#include <globaldefs.h>

struct Struct_ov000_021600f8 {
    char pad[0x20];
    struct Struct_ov000_021600f8* next;
};

struct Struct_ov000_0215440c {
    char pad0[9];
    unsigned char count;
    char pad1[10];
    struct Struct_ov000_021600f8* head;
};

// USA: func_ov000_021600f8
extern "C" ARM struct Struct_ov000_021600f8* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index) {
    struct Struct_ov000_021600f8* node;
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
