#include <globaldefs.h>

struct Struct_ov000_02169aa4 {
    unsigned short* arr;
    unsigned short count;
    char pad[6];
    struct Struct_ov000_02169aa4* next;
};

// USA: func_ov000_02169aa4
extern "C" ARM int func_ov000_02169aa4(struct Struct_ov000_02169aa4* node, unsigned short target, void** out, int max) {
    int found = 0;
    while (node != 0) {
        int i;
        for (i = 0; i < node->count; i++) {
            if (node->arr[i] == target) {
                out[found++] = node;
                if (found == max) break;
            }
        }
        node = node->next;
    }
    return found;
}
