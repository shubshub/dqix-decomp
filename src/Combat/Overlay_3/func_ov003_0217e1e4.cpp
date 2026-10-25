#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov003_0217e1e4_144 = 0x8c };
#else
enum { Enum_ov003_0217e1e4_144 = 0x90 };
#endif

struct Struct_0205d0e0 {
    char unknown_0_[0xa8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
};

struct Struct_0205d81c;
extern "C" struct Struct_0205d0e0* func_0205d81c(struct Struct_0205d81c* arg0, int arg1);

struct GridCursor;
void GridCursor_TurnPage(struct GridCursor* s, int delta);
int GridCursor_GetSelectedIndex(struct GridCursor* s);
struct Struct_0205bcdc;
void GridCursor_SelectIfValid(struct Struct_0205bcdc* s, int index);
extern "C" void GridCursor_SetSelectedIndex(void* s, int value);

struct Struct_ov003_0217e1e4 {
    char unknown_0_[0x4];
    char unknown_4_[0x50];
    char unknown_54_[0x40];
};

struct Struct_ov003_0217e1e4_2 {
    char unknown_0_[Enum_ov003_0217e1e4_144];
    struct Struct_ov003_0217e1e4* unknown_90_;
};

// USA: func_ov003_0217e1e4
extern "C" ARM int func_ov003_0217e1e4(struct Struct_ov003_0217e1e4_2* arg0) {
    int var0;
    int var1;
    if (g_touchInput.pressed_ == 0) {
        goto fail;
    }
    g_touchInput.GetTouchPoint(&var0, &var1);
    struct Struct_0205d0e0* var2 = func_0205d81c((struct Struct_0205d81c*)arg0->unknown_90_, 0);
    if (var2 == NULL) {
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
