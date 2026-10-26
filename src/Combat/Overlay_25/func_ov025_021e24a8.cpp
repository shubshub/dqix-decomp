#include <globaldefs.h>

struct Struct_ov025_021e24a8_2 { int unk0; int unknown_4_; struct Struct_ov025_021e24a8_2* next; };
struct Struct_ov025_021e24a8 { struct Struct_ov025_021e24a8_2* head; };

// USA: func_ov025_021e24a8
extern "C" ARM int func_ov025_021e24a8(struct Struct_ov025_021e24a8* container, struct Struct_ov025_021e24a8_2* target) {
    struct Struct_ov025_021e24a8_2* node = container->head;
    while (node != 0) {
        if (node == target) return 1;
        node = node->next;
    }
    return 0;
}
