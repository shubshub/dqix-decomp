#include <globaldefs.h>

struct Struct_0206ef18 {
    short id;
    char unk[0xe];
    struct Struct_0206ef18* next;
};

// USA: func_0206ef18
extern "C" ARM struct Struct_0206ef18* func_0206ef18(void* base, int key) {
    struct Struct_0206ef18* node = *(struct Struct_0206ef18**)base;
    while (node != 0) {
        if (node->id == key) {
            return node;
        }
        node = node->next;
    }
    return 0;
}
