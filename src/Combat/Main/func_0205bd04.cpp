#include <globaldefs.h>

struct GridCursor;
extern "C" int GridCursor_GetSelectedIndex(struct GridCursor*);

struct Struct_0205bd04 {
    char pad[0x4e];
    unsigned char unknown_4e_;
};

// USA: func_0205bd04
extern "C" ARM int func_0205bd04(struct Struct_0205bd04* s) {
    if (s->unknown_4e_ == 0) return -1;
    return GridCursor_GetSelectedIndex((struct GridCursor*)s);
}
