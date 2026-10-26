#include <globaldefs.h>

struct Struct_ov025_021e267c_3 {
    char pad0[1];
    unsigned char field1;
    char pad1[6];
    struct Struct_ov025_021e267c_3* next;
};
struct Struct_ov025_021e267c_2 {
    char pad0[0x30];
    unsigned char unknown_30_;
    char pad1[0x1a7];
    struct Struct_ov025_021e267c_3* head;
};

// USA: func_ov025_021e8bac
extern "C" ARM void func_ov025_021e8bac(struct Struct_ov025_021e267c_2* obj, struct Struct_ov025_021e267c_3* node) {
    node->field1 = obj->unknown_30_;
    node->next = obj->head;
    obj->head = node;
}
