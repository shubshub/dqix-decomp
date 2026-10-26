#include <globaldefs.h>

struct Table0215e9a4 {
    char pad0;
    signed char width;
    signed char height;
    char pad3;
    short* data;
};

// USA: func_ov003_0215e9a4
#pragma optimize_for_size off
extern "C" ARM int func_ov003_0215e9a4(Table0215e9a4* t, int row, int col) {
    if (row < 0) goto fail;
    if (row >= t->width) goto fail;
    if (col < 0) goto fail;
    if (col >= t->height) goto fail;
    return (t->data + t->width * col)[row];
fail:
    return -1;
}
