#include <globaldefs.h>

struct Struct_ov001_02159fd4 { char pad[0x3c]; void* next; };

extern "C" void* func_ov001_02159eb0(void* obj);

// USA: func_ov001_02159fd4
extern "C" ARM void* func_ov001_02159fd4(char* obj) {
    Struct_ov001_02159fd4* node = (Struct_ov001_02159fd4*)func_ov001_02159eb0(obj);
    if (node == NULL) return NULL;
    Struct_ov001_02159fd4** tail = (Struct_ov001_02159fd4**)(obj + 0x34);
    if (*tail != NULL) (*tail)->next = node;
    *tail = node;
    node->next = NULL;
    Struct_ov001_02159fd4** head = (Struct_ov001_02159fd4**)(obj + 0x30);
    if (*head == NULL) *head = node;
    return node;
}
