#include <globaldefs.h>

struct Struct_ov000_02169b2c {
    char pad[4];
    struct Struct_ov000_02169b2c* next;
};

// USA: func_ov000_02169b2c
extern "C" ARM void func_ov000_02169b2c(struct Struct_ov000_02169b2c* node, struct Struct_ov000_02169b2c* arg1) {
    if (node->next == NULL) {
        node->next = arg1;
        arg1->next = NULL;
        return;
    }
    func_ov000_02169b2c(node->next, arg1);
}
