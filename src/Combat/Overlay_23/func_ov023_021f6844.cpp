#include <globaldefs.h>

struct Struct_ov023_021f6844_2 {
    char pad0[0x8];
    unsigned short field8;
    char pad1[0x18 - 0x8 - 0x2];
    struct Struct_ov023_021f6844_2* next;
};

struct Struct_ov023_021f6844 {
    struct Struct_ov023_021f6844_2* first;
};

extern "C" void func_ov023_021f67ec(struct Struct_ov023_021f6844* head, struct Struct_ov023_021f6844_2* node);

// USA: func_ov023_021f6844
extern "C" ARM void func_ov023_021f6844(struct Struct_ov023_021f6844* head, unsigned short value) {
    struct Struct_ov023_021f6844_2* node = head->first;
    while (node != 0) {
        struct Struct_ov023_021f6844_2* next = node->next;
        if (node->field8 == value) {
            func_ov023_021f67ec(head, node);
        }
        node = next;
    }
}
