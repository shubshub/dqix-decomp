#include <globaldefs.h>

struct Struct_ov025_021eee48 { unsigned int v[4]; };

struct Struct_ov025_021dcf14_8 {
    unsigned int f0;
    unsigned int f4;
    struct Struct_ov025_021eee48 unknown_8_;
    struct Struct_ov025_021dcf14_8* next;
};

struct Struct_ov025_021dcf14_7 {
    char pad0[0xe0];
    struct Struct_ov025_021dcf14_8* unknown_e0_;
    struct Struct_ov025_021dcf14_8* unknown_e4_;
};

// USA: func_ov025_021eee48
extern "C" ARM void func_ov025_021eee48(struct Struct_ov025_021dcf14_7* obj, struct Struct_ov025_021dcf14_8* src) {
    struct Struct_ov025_021dcf14_8* node = obj->unknown_e4_;
    if (node == NULL) {
        return;
    }
    struct Struct_ov025_021dcf14_8* var1 = node->next;
    node->f0 = src->f0;
    node->f4 = src->f4;
    node->unknown_8_ = src->unknown_8_;
    node->next = src->next;
    obj->unknown_e4_ = var1;
    node->next = obj->unknown_e0_;
    obj->unknown_e0_ = node;
}
