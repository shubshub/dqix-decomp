#include <globaldefs.h>

struct Struct_020de3ac {
    char unk[0x10];
    unsigned int low : 10;
    unsigned int fieldB : 10;
    unsigned int fieldA : 8;
};

// USA: func_020de3ac
extern "C" ARM int func_020de3ac(struct Struct_020de3ac* obj, int a, int unused, int b) {
    return obj->fieldA == a && obj->fieldB == b;
}
