#include <globaldefs.h>

struct Struct_ov001_0215a054 { char pad[0x3c]; void* next; };

extern "C" void* func_ov001_02159eb0(void* obj);

// USA: func_ov001_0215a054
extern "C" ARM void* func_ov001_0215a054(char* obj) {
    Struct_ov001_0215a054* node = (Struct_ov001_0215a054*)func_ov001_02159eb0(obj);
    if (node == NULL) return NULL;
    Struct_ov001_0215a054** tail = (Struct_ov001_0215a054**)(obj + 0x44);
    if (*tail != NULL) (*tail)->next = node;
    *tail = node;
    node->next = NULL;
    Struct_ov001_0215a054** head = (Struct_ov001_0215a054**)(obj + 0x40);
    if (*head == NULL) *head = node;
    return node;
}
