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
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);

struct Struct_0205c4a8;
void AdvanceWrappedAccumulator0205c4a8(struct Struct_0205c4a8* s, int delta);
struct Struct_0205bb84;
int GridCursor_GetSelectedIndex(struct Struct_0205bb84* s);
struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index);
extern "C" void func_0205bb04(void* s, int value);

struct ScrollList {
    char pad0[0x4];
    char indexState[0x50];
    char scrollState[0x40];
};

struct Obj0217e1e4 {
    char pad0[kRegionValue90_8C];
    struct ScrollList* list;
};

// USA: func_ov003_0217e1e4
extern "C" ARM int func_ov003_0217e1e4(struct Obj0217e1e4* self) {
    int x;
    int y;
    if (g_touchInput.pressed_ == 0) {
        goto fail;
    }
    g_touchInput.GetTouchPoint(&x, &y);
    struct Elem_0205d81c* e = FindElementByC40205d81c((struct Struct_0205d81c*)self->list, 0);
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
        struct ScrollList* list = self->list;
        short left = e->x << 3;
        if (x >= left && x < left + 16) {
            AdvanceWrappedAccumulator0205c4a8((struct Struct_0205c4a8*)list->scrollState, -1);
        }
        right <<= 3;
        if (right - 16 <= x && x < right) {
            AdvanceWrappedAccumulator0205c4a8((struct Struct_0205c4a8*)list->scrollState, 1);
        }
        int index = GridCursor_GetSelectedIndex((struct Struct_0205bb84*)list->scrollState);
        SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)list->indexState, index);
        func_0205bb04(list->scrollState, index);
    }
    return 1;
fail:
    return 0;
}
