#include <globaldefs.h>

struct Struct_020b2a58 {
    unsigned short* cursor; // 0x0
};

// USA: func_020b2a58
extern "C" ARM unsigned short func_020b2a58(struct Struct_020b2a58* s) {
    unsigned short* p = s->cursor;
    unsigned short v = *p++;
    s->cursor = p;
    return v;
}
