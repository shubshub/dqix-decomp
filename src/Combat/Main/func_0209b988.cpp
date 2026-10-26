#include <globaldefs.h>

struct Struct_0209ad40 { unsigned int w; unsigned short h; };
struct Struct_0209b988 { unsigned int w; unsigned short h; unsigned short pad; };
struct Struct_0209ad40_2 { unsigned int hdr; struct Struct_0209b988 cells[9]; };

// USA: func_0209b988
extern "C" ARM void func_0209b988(struct Struct_0209ad40_2 *base, int i, int j, struct Struct_0209ad40 *src) {
    base[i].cells[j].w = src->w;
    base[i].cells[j].h = src->h;
}
