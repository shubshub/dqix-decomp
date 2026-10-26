#include <globaldefs.h>

struct Struct_02046968_2 {
    char unk0;
    unsigned char flag1;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    struct Struct_02046968_2* next;
};

struct Struct_02046968 {
    struct Struct_02046968_2* head;
};

// USA: func_02046968
extern "C" ARM void func_02046968(struct Struct_02046968* list) {
    struct Struct_02046968_2* node;
    while ((node = list->head) != NULL) {
        if (node->flag1 != 0) {
            node->unknown_2_ = 0;
            list->head->unknown_3_ = 0;
            list->head = list->head->next;
        } else {
            node->unknown_3_ = 1;
            return;
        }
    }
}
