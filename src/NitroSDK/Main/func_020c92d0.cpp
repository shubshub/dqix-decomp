#include <globaldefs.h>

struct Struct_020c92d0 {
    char unknown_0_[0xc];
    unsigned int key;
    short priority;
    short unknown_12_;
    struct Struct_020c92d0* prev;
    struct Struct_020c92d0* next;
};

struct Struct_02111654_2 {
    char unknown_0_[0xc];
    struct Struct_020c92d0* head;
    struct Struct_020c92d0* tail;
};

extern struct Struct_02111654_2 data_02111654;

struct Struct_020c92d0_2;
extern "C" ARM void func_020c934c(struct Struct_020c92d0_2* node);
extern "C" void func_020c945c(void);

// USA: func_020c92d0
extern "C" ARM void func_020c92d0(struct Struct_020c92d0* node) {
    struct Struct_020c92d0* cur = data_02111654.head;
    unsigned int key;
    struct Struct_020c92d0* prev;
    if (cur == NULL) goto append;
    key = node->key;
loop:
    if (cur->key < key) goto advance;
    if (cur->key != key) goto insert;
    if (cur->priority <= node->priority) goto advance;
insert:
    prev = cur->prev;
    node->prev = prev;
    node->next = cur;
    cur->prev = node;
    if (prev != NULL) {
        prev->next = node;
        return;
    }
    data_02111654.head = node;
    func_020c945c();
    return;
advance:
    cur = cur->next;
    if (cur != NULL) goto loop;
append:
    func_020c934c((struct Struct_020c92d0_2*)node);
}
