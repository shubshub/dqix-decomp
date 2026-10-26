#include <globaldefs.h>

struct Struct_ov023_021f6bc0_2 {
    char pad0[0x18];
    Struct_ov023_021f6bc0_2* next;
    int state;
};

struct Struct_ov023_021f6bc0 {
    Struct_ov023_021f6bc0_2* head;
};

// USA: func_ov023_021f6bc0
extern "C" ARM int func_ov023_021f6bc0(Struct_ov023_021f6bc0* obj) {
    for (Struct_ov023_021f6bc0_2* n = obj->head; n != 0; n = n->next) {
        if (n->state != 2) return 1;
    }
    return 0;
}
