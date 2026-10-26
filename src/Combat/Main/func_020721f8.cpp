#include <globaldefs.h>
extern "C" struct Struct_020721f8* func_02072238(struct Struct_020721f8_2*, int);

struct Struct_020721f8 {
    unsigned char pad0[0x1a];
    short unknown_1a_;
    struct Struct_020721f8* next;
};

struct Struct_02071ffc_3 {
    struct Struct_020721f8* head;
};


// USA: func_020721f8
extern "C" ARM void func_020721f8(struct Struct_02071ffc_3* list) {
    struct Struct_020721f8* node;
    list->head = func_02072238((struct Struct_020721f8_2*)(list), (int)(-1));
    if (list->head == NULL) return;
    node = list->head;
    while (node != NULL) {
        struct Struct_020721f8* next = func_02072238((struct Struct_020721f8_2*)(list), (int)(node->unknown_1a_));
        node->next = next;
        node = next;
    }
}
