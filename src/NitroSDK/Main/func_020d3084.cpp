#include <globaldefs.h>


struct Struct_020d3084 {
    int remaining;
    unsigned char* ptr;
};

// USA: func_020d3084
extern "C" ARM void func_020d3084(struct Struct_020d3084* s, int c) {
    if (s->remaining != 0) {
        *s->ptr = c;
        s->remaining--;
    }
    s->ptr++;
}
