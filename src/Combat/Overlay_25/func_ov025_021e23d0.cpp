#include <globaldefs.h>

struct Struct_ov000_02171720_2 {
    char pad0[8];
    struct Struct_ov000_02171720_2* next;
};
struct Struct_ov000_02171720 {
    struct Struct_ov000_02171720_2* head;
};

// USA: func_ov025_021e23d0
#if defined(jpn)
extern "C" ARM void func_ov000_02171720(struct Struct_ov000_02171720* list, struct Struct_ov000_02171720_2* node)
#else
extern "C" ARM void func_ov025_021e23d0(struct Struct_ov000_02171720* list, struct Struct_ov000_02171720_2* node)
#endif
{
    node->next = list->head ? list->head : NULL;
    list->head = node;
}
