#include <globaldefs.h>

struct Struct_0206528c_2 {
    unsigned short id;
#if defined(jpn)
    char unk[0x1a];
#else
    char unk[0xe];
#endif
    struct Struct_0206528c_2* next;
};

struct Struct_0206528c {
    struct Struct_0206528c_2* head;
};

// USA: func_0206528c
extern "C" ARM struct Struct_0206528c_2* func_0206528c(struct Struct_0206528c* list, int key) {
    struct Struct_0206528c_2* node = list->head;
    while (node != 0) {
        if (node->id == key) {
            return node;
        }
        node = node->next;
    }
    return 0;
}
