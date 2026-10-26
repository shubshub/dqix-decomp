#include <globaldefs.h>

struct Struct_02061c04_27 {
    char unk[0x2c];
    struct Struct_02061c04_27* next;
};

struct Struct_02061c04_28 {
    char unk[0x494];
    struct Struct_02061c04_27* head;
};

// USA: func_02064af8
extern "C" ARM void func_02064af8(struct Struct_02061c04_28* obj, struct Struct_02061c04_27* node) {
    struct Struct_02061c04_27* cur = obj->head;
    if (cur == 0) {
        obj->head = node;
        return;
    }
    while (cur->next != 0) {
        cur = cur->next;
    }
    cur->next = node;
}
