#include <globaldefs.h>

struct Struct_ov023_021f67ec_2 {
    virtual void inline_ov023_021f67ec_6();
    virtual void inline_ov023_021f67ec_7();
    virtual void inline_ov023_021f67ec();
    virtual void inline_ov023_021f67ec_2();
    virtual void inline_ov023_021f67ec_3();
    virtual void inline_ov023_021f67ec_4();
    virtual void inline_ov023_021f67ec_5(void* head);
    char pad4[0x14 - 4];
    struct Struct_ov023_021f67ec_2* prev;
    struct Struct_ov023_021f67ec_2* next;
};

struct Struct_ov023_021f67ec {
    struct Struct_ov023_021f67ec_2* first;
};

// USA: func_ov023_021f67ec
extern "C" ARM void func_ov023_021f67ec(struct Struct_ov023_021f67ec* head, struct Struct_ov023_021f67ec_2* node) {
    if (!node) return;
    struct Struct_ov023_021f67ec_2* prev = node->prev;
    struct Struct_ov023_021f67ec_2* next = node->next;
    if (prev) prev->next = next;
    if (next) next->prev = prev;
    if (head->first == node) head->first = next;
    node->prev = 0;
    node->next = 0;
    node->inline_ov023_021f67ec_5(head);
}
