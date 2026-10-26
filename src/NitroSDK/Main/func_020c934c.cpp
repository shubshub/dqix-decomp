#include <globaldefs.h>

struct Struct_020c92d0_2 {
    unsigned char unknown_0_[0x14];
    Struct_020c92d0_2* prev; // +0x14
    Struct_020c92d0_2* next; // +0x18
};

struct Struct_02111654_3 {
    unsigned char unknown_0_[0xc];
    Struct_020c92d0_2* head; // +0xc
    Struct_020c92d0_2* tail; // +0x10
};

extern Struct_02111654_3 data_02111654;
extern "C" void func_020c945c(void);

// USA: func_020c934c
extern "C" ARM void func_020c934c(Struct_020c92d0_2* node) {
    Struct_020c92d0_2* var0 = data_02111654.tail;
    node->prev = var0;
    node->next = NULL;
    data_02111654.tail = node;
    if (var0 != NULL) {
        var0->next = node;
        return;
    }
    data_02111654.head = node;
    func_020c945c();
}
