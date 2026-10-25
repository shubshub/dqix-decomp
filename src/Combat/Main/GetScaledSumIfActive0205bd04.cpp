#include <globaldefs.h>

struct GridCursor;
int GridCursor_GetSelectedIndex(struct GridCursor*);

struct Struct_0205bd04 {
    char pad[0x4e];
    unsigned char field4e;
};

// USA: func_0205bd04
ARM int GetScaledSumIfActive0205bd04(struct Struct_0205bd04* s) {
    if (s->field4e == 0) return -1;
    return GridCursor_GetSelectedIndex((struct GridCursor*)s);
}
