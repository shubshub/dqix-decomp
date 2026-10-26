#include <globaldefs.h>

struct Struct_0208e024_2 {
    unsigned short field0;
    unsigned short low : 9;
#if defined(jpn)
    unsigned short kind : 7;
    int field4;
    int field8;
#else
    unsigned short kind : 6;
    unsigned short high : 1;
    int field4;
#endif
    struct Struct_0208e024_2* next;
};

struct Struct_0208e024 {
    struct Struct_0208e024_2* head;
};

// USA: func_0208e024
extern "C" ARM struct Struct_0208e024_2* func_0208e024(struct Struct_0208e024* list, int kind, int index) {
    struct Struct_0208e024_2* n;
    unsigned char count;
    n = list->head;
    if (n == NULL) {
        return NULL;
    }
    count = 0;
    while (n != NULL) {
        if (kind == n->kind) {
            if (count == index) {
                return n;
            }
            count++;
        }
        n = n->next;
    }
    return n;
}
