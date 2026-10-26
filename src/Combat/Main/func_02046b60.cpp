#include <globaldefs.h>

struct Struct_02046b60 {
    signed char id;
    char pad[3];
    struct Struct_02046b60* next;
};

struct ListHead02046b60 {
    struct Struct_02046b60* head;
};

// USA: func_02046b60
extern "C" ARM int func_02046b60(struct ListHead02046b60* list, int id) {
    struct Struct_02046b60* node = list->head;
    while (node != 0) {
        if (node->id == id) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}
