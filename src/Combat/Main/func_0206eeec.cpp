#include <globaldefs.h>

struct Struct_0206ed44_2 {
    char unk[0x10];
    struct Struct_0206ed44_2* next;
};

struct Struct_0206ed44 {
    struct Struct_0206ed44_2* head;
    unsigned char count;
};

// USA: func_0206eeec
extern "C" ARM void func_0206eeec(struct Struct_0206ed44* list, struct Struct_0206ed44_2* node) {
    struct Struct_0206ed44_2* head = list->head;
    if (head != 0) {
        node->next = head;
        list->head = node;
    } else {
        list->head = node;
        node->next = 0;
    }
    list->count++;
}
