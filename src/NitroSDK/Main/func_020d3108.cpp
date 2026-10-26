#include <globaldefs.h>

struct Struct_020d3108 {
    unsigned int remaining;
    char* cursor;
};

// USA: func_020d3108
extern "C" ARM void func_020d3108(struct Struct_020d3108* sink, char* src, int count) {
    unsigned int i;
    unsigned int limit;
    if (count <= 0) {
        return;
    }
    limit = sink->remaining;
    if (limit > (unsigned int)count) {
        limit = count;
    }
    i = 0;
    if (i < limit) {
        do {
            sink->cursor[i] = src[i];
            i++;
        } while (i < limit);
    }
    sink->remaining = sink->remaining - limit;
    sink->cursor = sink->cursor + count;
}
