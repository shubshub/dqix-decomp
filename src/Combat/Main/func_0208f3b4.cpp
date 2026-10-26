#include <globaldefs.h>

struct Struct_0208f3b4_2 {
    int key;
    char unknown_4_[0x10];
    struct Struct_0208f3b4_2* next;
};

struct Struct_0208f3b4 {
    char unknown_0_[0xc];
    struct Struct_0208f3b4_2* head;
};

// USA: func_0208f3b4
extern "C" ARM void func_0208f3b4(struct Struct_0208f3b4 *c, int key) {
    struct Struct_0208f3b4_2 *cur = c->head;
    struct Struct_0208f3b4_2 *prev = NULL;
    while (cur != NULL) {
        if (cur->key == key) {
            if (cur == c->head) {
                c->head = cur->next;
            } else if (cur->next == NULL) {
                prev->next = NULL;
            } else {
                prev->next = cur->next;
            }
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
