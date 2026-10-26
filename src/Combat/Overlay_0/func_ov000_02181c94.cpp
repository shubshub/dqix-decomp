#include <globaldefs.h>

struct Struct_ov000_02181c94_2 {
    char pad0[0xe];
    short val;
    char pad1[0x10];
    struct Struct_ov000_02181c94_2* next;
};
struct Struct_ov000_02181c94 {
    char pad0[0x14];
    struct Struct_ov000_02181c94_2* head;
};

// USA: func_ov000_02181c94
extern "C" ARM int func_ov000_02181c94(void* unused, struct Struct_ov000_02181c94* obj, int* arg2) {
    struct Struct_ov000_02181c94_2* node = obj->head;
    int count = 0;
    while (node) {
        arg2[count] = node->val;
        node = node->next;
        count++;
    }
    return count;
}
