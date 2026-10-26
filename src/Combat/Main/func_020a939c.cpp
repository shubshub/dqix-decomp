#include <globaldefs.h>

struct Struct_020a939c {
    unsigned char data[0x40];
};

struct Struct_020a939c_2 {
    unsigned int count : 12;
    struct Struct_020a939c *elements;
};

// USA: func_020a939c
extern "C" ARM struct Struct_020a939c* func_020a939c(struct Struct_020a939c_2 *c, int index) {
    if (index < 0 || index >= (int)c->count || c->elements == 0) {
        return 0;
    }
    return &c->elements[index];
}
