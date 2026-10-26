#include <globaldefs.h>

struct Struct_ov031_0220eea0_3 {
    unsigned char unknown_0_[4];
    unsigned int id;
    Struct_ov031_0220eea0_3* previous;
    Struct_ov031_0220eea0_3* next;
};
struct Struct_ov031_0220eea0 {
    unsigned int count;
    Struct_ov031_0220eea0_3* first;
    Struct_ov031_0220eea0_3* last;
};
struct Struct_ov031_0220eea0_2 {
    char padding[0x2270];
    Struct_ov031_0220eea0* list;
    unsigned int capacity;
};
extern "C" Struct_ov031_0220eea0_2* func_ov031_0220d60c();

// USA: func_ov031_0220eea0
extern "C" ARM void func_ov031_0220eea0(Struct_ov031_0220eea0_3* node) {
    Struct_ov031_0220eea0_2* context = func_ov031_0220d60c();
    Struct_ov031_0220eea0* list = context->list;
    if (!node || !list) return;
    if (context->capacity <= 12) return;
    Struct_ov031_0220eea0_3* current = list->first;
    if (current) do {
        if (current == node) {
            if (current->previous) current->previous->next = current->next;
            else list->first = current->next;
            if (current->next) current->next->previous = current->previous;
            else list->last = current->previous;
            break;
        }
        current = current->next;
    } while (current);
    node->next = NULL;
    node->previous = list->last;
    list->last = node;
    if (node->previous) node->previous->next = node;
    else list->first = node;
    if (current == NULL) {
        node->id = list->count;
        list->count++;
    } else return;
}
