#include <globaldefs.h>

struct Struct_020de38c {
    char unk[0x10];
    unsigned int low : 10;
    unsigned int fieldB : 10;
    unsigned int fieldA : 8;
};

// USA: func_020de38c
extern "C" ARM int func_020de38c(struct Struct_020de38c* obj, int a, int b) {
    return obj->fieldA == a && obj->low == b;
}
