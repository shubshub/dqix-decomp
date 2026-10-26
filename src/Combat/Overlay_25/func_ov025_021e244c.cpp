#include <globaldefs.h>

struct Struct_ov000_0217179c_2 {
    char pad0[8];
    struct Struct_ov000_0217179c_2* next;
};
struct Struct_ov000_0217179c {
    struct Struct_ov000_0217179c_2* head;
};

// USA: func_ov025_021e244c
#if defined(jpn)
extern "C" ARM void func_ov000_0217179c(struct Struct_ov000_0217179c* list, struct Struct_ov000_0217179c_2* target)
#else
extern "C" ARM void func_ov025_021e244c(struct Struct_ov000_0217179c* list, struct Struct_ov000_0217179c_2* target)
#endif
{
    struct Struct_ov000_0217179c_2* node = list->head;
    struct Struct_ov000_0217179c_2* prev = NULL;
    while (node != NULL) {
        if (node == target) {
            if (prev != NULL) {
                prev->next = node->next;
            } else {
                list->head = node->next;
            }
            target->next = NULL;
            return;
        }
        prev = node;
        node = node->next;
    }
}
