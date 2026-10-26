#include <globaldefs.h>

struct Struct_0208e06c_2 {
    short id;
    short field2;
    int field4;
#if defined(jpn)
    int field8;
#endif
    struct Struct_0208e06c_2* next;
};

struct Struct_0208e06c {
    struct Struct_0208e06c_2* head;
};

// USA: func_0208e06c
extern "C" ARM struct Struct_0208e06c_2* func_0208e06c(struct Struct_0208e06c* list, int id) {
    struct Struct_0208e06c_2* n;
    if (id < 0) {
        return NULL;
    }
    n = list->head;
    if (n == NULL) {
        return NULL;
    }
    while (n != NULL) {
        if (n->id == id) {
            return n;
        }
        n = n->next;
    }
    return n;
}
