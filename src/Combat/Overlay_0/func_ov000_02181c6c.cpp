#include <globaldefs.h>

struct Struct_ov000_02181c6c_2 {
    char pad0[0x20];
    unsigned short val;
    char pad1[0xe];
    struct Struct_ov000_02181c6c_2* next;
};
struct Struct_ov000_02181c6c {
    char pad0[0x10];
    struct Struct_ov000_02181c6c_2* head;
};

// USA: func_ov000_02181c6c
extern "C" ARM int func_ov000_02181c6c(void* unused, struct Struct_ov000_02181c6c* obj, int* arg2) {
    struct Struct_ov000_02181c6c_2* node = obj->head;
    int count = 0;
    while (node) {
        arg2[count] = node->val;
        node = node->next;
        count++;
    }
    return count;
}
