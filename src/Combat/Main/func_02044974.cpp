#include <globaldefs.h>

struct Struct_0204483c {
    unsigned char* cursor;
};

// USA: func_02044974
extern "C" ARM void func_02044974(struct Struct_0204483c* stream, int value) {
    unsigned short v = value;
    unsigned char* p = stream->cursor;
    stream->cursor = p + 1;
    *p = v;
    p = stream->cursor;
    stream->cursor = p + 1;
    *p = v >> 8;
}
