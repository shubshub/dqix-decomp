#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { kRegionValue90_8C = 0x8c };
#else
enum { kRegionValue90_8C = 0x90 };
#endif

struct Elem_0205d81c {
    char pad0[0xa8];
    short width;
    short height;
    short x;
    short y;
};

struct Struct_0205d81c;
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);

struct GridCursor;
extern "C" void GridCursor_TurnPage(struct GridCursor* s, int delta);
extern "C" int GridCursor_GetSelectedIndex(struct GridCursor* s);
struct Struct_0205bcdc;
extern "C" void GridCursor_SelectIfValid(struct Struct_0205bcdc* s, int index);
extern "C" void GridCursor_SetSelectedIndex(void* s, int value);

struct Struct_ov003_0217e1e4 {
    char pad0[0x4];
    char indexState[0x50];
    char scrollState[0x40];
};

struct Struct_ov003_0217e1e4_2 {
    char pad0[kRegionValue90_8C];
    struct Struct_ov003_0217e1e4* list;
};

// USA: func_ov003_0217e1e4
extern "C" ARM int func_ov003_0217e1e4(struct Struct_ov003_0217e1e4_2* self) {
    int x;
    int y;
    if (g_touchInput.pressed_ == 0) {
        goto fail;
    }
    g_touchInput.GetTouchPoint(&x, &y);
    struct Elem_0205d81c* e = func_0205d81c((struct Struct_0205d81c*)self->list, 0);
    if (e == NULL) {
        goto fail;
    }
    short right = e->x;
    short bottom = e->y;
    short height = e->height;
    right += e->width;
    bottom += height;
    bottom <<= 3;
    if (bottom - 16 <= y && y < bottom) {
        struct Struct_ov003_0217e1e4* list = self->list;
        short left = e->x << 3;
        if (x >= left && x < left + 16) {
            GridCursor_TurnPage((struct GridCursor*)list->scrollState, -1);
        }
        right <<= 3;
        if (right - 16 <= x && x < right) {
            GridCursor_TurnPage((struct GridCursor*)list->scrollState, 1);
        }
        int index = GridCursor_GetSelectedIndex((struct GridCursor*)list->scrollState);
        GridCursor_SelectIfValid((struct Struct_0205bcdc*)list->indexState, index);
        GridCursor_SetSelectedIndex(list->scrollState, index);
    }
    return 1;
fail:
    return 0;
}
