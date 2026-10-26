#include <globaldefs.h>

struct Struct_02057f8c {
    int id;
    char unk[0x1e8];
    struct Struct_02057f8c* next;
};

// USA: func_02057f8c
extern "C" ARM struct Struct_02057f8c* func_02057f8c(void* list, int id) {
    struct Struct_02057f8c* node = *(struct Struct_02057f8c**)list;
    while (node != 0) {
        if (id == node->id) {
            return node;
        }
        node = node->next;
    }
    return 0;
}
