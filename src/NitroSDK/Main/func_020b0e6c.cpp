#include <globaldefs.h>

struct Struct_020b0e6c_3 {
    unsigned short lo;                  // 0x0
    unsigned short hi;                  // 0x2
    int field4;                         // 0x4
    struct Struct_020b0e6c_3* next;     // 0x8
};

struct Struct_020b0e6c_2 {
    char pad[0x10];
    struct Struct_020b0e6c_3* head;     // 0x10
};

struct Struct_020b0e6c {
    struct Struct_020b0e6c_2* inner;   // 0x0
};

extern "C" int func_020b0d80(struct Struct_020b0e6c_3*, unsigned int);

// USA: func_020b0e6c
extern "C" ARM int func_020b0e6c(struct Struct_020b0e6c* obj, unsigned int key) {
    struct Struct_020b0e6c_3* node = obj->inner->head;
    if (node != NULL) {
        do {
            if (node->lo <= key && key <= node->hi) {
                return func_020b0d80(node, key);
            }
            node = node->next;
        } while (node != NULL);
    }
    return 0xffff;
}
