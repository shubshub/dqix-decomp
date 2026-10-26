#include <globaldefs.h>

struct Struct_ov000_02171738_2 {
    char pad0[1];
    unsigned char val;
    char pad2[6];
    struct Struct_ov000_02171738_2* next;
};
struct Struct_ov000_02171738 {
    struct Struct_ov000_02171738_2* head;
};

// USA: func_ov025_021e23e8
#if defined(jpn)
extern "C" ARM struct Struct_ov000_02171738_2* func_ov000_02171738(struct Struct_ov000_02171738* list)
#else
extern "C" ARM struct Struct_ov000_02171738_2* func_ov025_021e23e8(struct Struct_ov000_02171738* list)
#endif
{
    struct Struct_ov000_02171738_2* cur = list->head;
    struct Struct_ov000_02171738_2* prev = NULL;
    unsigned int var2 = 0xff;
    struct Struct_ov000_02171738_2* best = NULL;
    struct Struct_ov000_02171738_2* var4 = NULL;
    while (cur != NULL) {
        unsigned char v = cur->val;
        if (v < var2) {
            var4 = prev;
            best = cur;
            var2 = v;
        }
        prev = cur;
        cur = cur->next;
    }
    if (best != NULL) {
        if (var4 != NULL) {
            var4->next = best->next;
        } else {
            list->head = best->next;
        }
    }
    return best;
}
