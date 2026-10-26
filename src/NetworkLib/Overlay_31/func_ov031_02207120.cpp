#include <globaldefs.h>

struct Struct_ov031_02207120_2 { unsigned char pad[0x7c]; Struct_ov031_02207120_2* next; };
struct Struct_ov031_02207120 { Struct_ov031_02207120_2* head; };

extern "C" Struct_ov031_02207120_2** func_ov031_0220713c(Struct_ov031_02207120* list, Struct_ov031_02207120_2* target);

// USA: func_ov031_02207120
extern "C" ARM Struct_ov031_02207120_2** func_ov031_02207120(Struct_ov031_02207120* list, Struct_ov031_02207120_2* target) {
    Struct_ov031_02207120_2** link = func_ov031_0220713c(list, target);
    if (link != NULL) {
        *link = target->next;
    }
    return link;
}
