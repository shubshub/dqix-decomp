#include <globaldefs.h>
extern "C" struct Struct_0207214c* func_0207218c(struct Struct_0207214c_2*, int);

struct Struct_0207214c {
    unsigned char pad0[0x18];
    short unknown_18_;
    unsigned char pad1a[2];
    struct Struct_0207214c* next;
};

struct Struct_02071ffc_2 {
    struct Struct_0207214c* head;
};


// USA: func_0207214c
extern "C" ARM void func_0207214c(struct Struct_02071ffc_2* list) {
    struct Struct_0207214c* node;
    list->head = func_0207218c((struct Struct_0207214c_2*)(list), (int)(-1));
    if (list->head == NULL) return;
    node = list->head;
    while (node != NULL) {
        struct Struct_0207214c* next = func_0207218c((struct Struct_0207214c_2*)(list), (int)(node->unknown_18_));
        node->next = next;
        node = next;
    }
}
