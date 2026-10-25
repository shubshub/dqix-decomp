#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205d81c;
struct GridCursor;
struct Struct_0205bcdc;

struct Struct_ov023_021e6448 {
    char unknown_0_[0xa8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
};

struct Struct_ov023_021e6448_2 {
    char unknown_0_[0x50];
};

struct Struct_ov023_021e6448_3 {
    char unknown_0_[0x4];
    Struct_ov023_021e6448_2 unknown_4_[2];
};

static inline Struct_ov023_021e6448_2* inline_ov017_021c6d50_4(Struct_ov023_021e6448_3* arg0, int arg1) { return &arg0->unknown_4_[arg1]; }

struct Struct_ov023_021e6448_4 {
#if defined(jpn)
    char unknown_0_[0x90];
#else
    char unknown1_0_[0xac];
#endif

    Struct_ov023_021e6448_3 unknown_ac_;
#if defined(jpn)
    char unknown_134_[0x1341 - 0x90 - sizeof(Struct_ov023_021e6448_3)];
#else
    char unknown_150_[0x1371 - 0xac - sizeof(Struct_ov023_021e6448_3)];
#endif

    unsigned char unknown_1371_;
#if defined(jpn)
    char unknown_1342_[0x1360 - 0x1342];
#else
    char unknown_1372_[0x1398 - 0x1372];
#endif

    int unknown_1398_;
};

int Window_GetPageCount(unsigned char* obj);
Element_021e6448* FindElementByC40205d81c(Struct_0205d81c* s, int key);
void GridCursor_TurnPage(GridCursor* s, int delta);
int GridCursor_GetSelectedIndex(GridCursor* s);
void GridCursor_SelectIfValid(Struct_0205bcdc* s, int index);
extern "C" void GridCursor_SetSelectedIndex(void* s, int index);

// USA: func_ov023_021e6448
extern "C" ARM int func_ov023_021e6448(ListMenu_021e6448* self) {
    if (Window_GetPageCount((unsigned char*)&self->list_) <= 1)
        return 0;
    if (g_touchInput.pressed_ != 0) {
        int x, y;
        g_touchInput.GetTouchPoint(&x, &y);
        Element_021e6448* e = FindElementByC40205d81c((Struct_0205d81c*)&self->list_, self->selectedKey_);
        if (e != NULL) {
            short right = e->x;
            short bottom = e->y;
            short height = e->height;
            right += e->width;
            bottom += height;
            bottom <<= 3;
            if (bottom - 16 <= y && y < bottom) {
                ListState_021e6448* scroll = GetState(&self->list_, 1);
                short left = e->x << 3;
                if (x >= left && x < left + 16) {
                    GridCursor_TurnPage((GridCursor*)scroll, -1);
                    self->scrolled_ = 1;
                }
                right <<= 3;
                if (right - 16 <= x && x < right) {
                    GridCursor_TurnPage((GridCursor*)scroll, 1);
                    self->scrolled_ = 1;
                }
                int index = GridCursor_GetSelectedIndex((GridCursor*)scroll);
                GridCursor_SelectIfValid((Struct_0205bcdc*)&self->list_.states[0], index);
                GridCursor_SetSelectedIndex(&self->list_.states[1], index);
            }
            return 1;
        }
    }
    return 0;
}
