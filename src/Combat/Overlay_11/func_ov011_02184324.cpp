#include <globaldefs.h>

struct Struct_ov011_02184324 { char pad[0x18]; Struct_ov011_02184324* next; };

// USA: func_ov011_02184324
extern "C" ARM void func_ov011_02184324(Struct_ov011_02184324* head, Struct_ov011_02184324* node) {
    if (head->next != 0) {
        Struct_ov011_02184324* p = head->next;
        while (p->next != 0) {
            p = p->next;
        }
        p->next = node;
    } else {
        head->next = node;
    }
}
