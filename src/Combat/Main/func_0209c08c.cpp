#include <globaldefs.h>

struct Struct_0209c08c {
    unsigned short items[0xc];
    unsigned short count;
};

// USA: func_0209c08c
extern "C" ARM void func_0209c08c(struct Struct_0209c08c* s, unsigned short value) {
    unsigned short count = s->count;
    if (count < 0xc) {
        s->count = count + 1;
        s->items[count] = value;
    }
}
