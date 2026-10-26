#include <globaldefs.h>

struct Struct_ov004_0215c30c {
    void* first;
};

struct Struct_ov004_0215c30c_2 {
    char pad0[0x6];
    unsigned short flag;
    char pad1[0xc];
    struct Struct_ov004_0215c30c_2* prev;
    struct Struct_ov004_0215c30c_2* next;
};

// USA: func_ov023_021f67ac
extern "C" ARM void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node) {
    struct Struct_ov004_0215c30c_2* cur;
    if (node->flag == 0) {
        return;
    }
    cur = (struct Struct_ov004_0215c30c_2*)head->first;
    if (cur != NULL) {
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
        node->prev = cur;
        return;
    }
    head->first = node;
}
