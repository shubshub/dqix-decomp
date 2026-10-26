#include <globaldefs.h>

struct Struct_ov001_02159f54 { char pad[0x3c]; void* next; };

extern "C" void* func_ov001_02159eb0(void* obj);

// USA: func_ov001_02159f54
extern "C" ARM void* func_ov001_02159f54(char* obj) {
    Struct_ov001_02159f54* node = (Struct_ov001_02159f54*)func_ov001_02159eb0(obj);
    if (node == NULL) return NULL;
    Struct_ov001_02159f54** tail = (Struct_ov001_02159f54**)(obj + 0x14);
    if (*tail != NULL) (*tail)->next = node;
    *tail = node;
    node->next = NULL;
    Struct_ov001_02159f54** head = (Struct_ov001_02159f54**)(obj + 0x10);
    if (*head == NULL) *head = node;
    return node;
}
