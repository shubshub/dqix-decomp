#include <globaldefs.h>

struct Struct_ov001_02159f14 { char pad[0x3c]; void* next; };

extern "C" void* func_ov001_02159eb0(void* obj);

// USA: func_ov001_02159f14
extern "C" ARM void* func_ov001_02159f14(char* obj) {
    Struct_ov001_02159f14* node = (Struct_ov001_02159f14*)func_ov001_02159eb0(obj);
    if (node == NULL) return NULL;
    Struct_ov001_02159f14** tail = (Struct_ov001_02159f14**)(obj + 0xc);
    if (*tail != NULL) (*tail)->next = node;
    *tail = node;
    node->next = NULL;
    Struct_ov001_02159f14** head = (Struct_ov001_02159f14**)(obj + 0x8);
    if (*head == NULL) *head = node;
    return node;
}
