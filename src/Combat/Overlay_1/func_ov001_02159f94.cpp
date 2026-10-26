#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov001_02159f94 { char pad[0x3c]; void* next; };

extern "C" void* func_ov001_02159eb0(void* obj);

// USA: func_ov001_02159f94
extern "C" ARM void* func_ov001_02159f94(char* obj) {
    Struct_ov001_02159f94* node = (Struct_ov001_02159f94*)func_ov001_02159eb0(obj);
    if (node == NULL) return NULL;
    Struct_ov001_02159f94** tail = (Struct_ov001_02159f94**)(obj + 0x1c);
    if (*tail != NULL) (*tail)->next = node;
    *tail = node;
    node->next = NULL;
    Struct_ov001_02159f94** head = (Struct_ov001_02159f94**)(obj + 0x18);
    if (*head == NULL) *head = node;
    return node;
}
