#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0205d81c;
struct Elem_0205d81c;
struct GridCursor;
struct Struct_0205bcdc;

struct Elem_0205d81c *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
int Window_GetPageCount(unsigned char *p);
void GridCursor_TurnPage(struct GridCursor *s, int delta);
int GridCursor_GetSelectedIndex(struct GridCursor *s);
void GridCursor_SelectIfValid(struct Struct_0205bcdc *p, int v);
extern "C" void GridCursor_SetSelectedIndex(void *p, int v);

// USA: func_ov002_02161b98
extern "C" ARM int func_ov002_02161b98(char *arg0) {
    int var0;
    int var1;
    short var2;
    short var3;
    char *var4;
    struct Struct_0205d0e0 *var5;
    if (g_touchInput.pressed_ == 0) {
        goto ret0;
    }
    g_touchInput.GetTouchPoint(&var0, &var1);
    var5 = func_0205d81c((struct Struct_0205d81c *) (arg0 + RG(0x2c8 + 0xc00, 0xe20)),
                                   *(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80)) & 0xff);
    if (var5 == 0) {
        goto ret0;
    }
    short ey = *(short *) ((char *) elem + 0xae);
    short eh = *(short *) ((char *) elem + 0xaa);
    ex = *(short *) ((char *) elem + 0xac);
    short ew = *(short *) ((char *) elem + 0xa8);
    short sy = ey;
    sx = ex;
    sx += ew;
    sy += eh;
    int cyv = cy;
    int baseY = (short) (sy * 8);
    if (baseY - 16 <= cyv && cyv < baseY) {
        list = base + RG(0x2c8 + 0xc00, 0xe20);
        if (Window_GetPageCount((unsigned char *) list) == 1) {
            return 0;
        }
        int ex8 = (short) (ex * 8);
        if (ex8 <= cx && cx < ex8 + 16) {
            GridCursor_TurnPage((struct GridCursor *) (list + 0x54), -1);
            *(int *) (base + 0x1000 + RG(0xbc8, 0xa90)) = 1;
        }
        int cxv = cx;
        int W = (short) (sx * 8);
        if (W - 16 <= cxv && cxv < W) {
            GridCursor_TurnPage((struct GridCursor *) (list + 0x54), 1);
            *(int *) (base + 0x1000 + RG(0xbc8, 0xa90)) = 1;
        }
        int total = GridCursor_GetSelectedIndex((struct GridCursor *) (list + 0x54));
        GridCursor_SelectIfValid((struct Struct_0205bcdc *) (list + 4), total);
        GridCursor_SetSelectedIndex(list + 0x54, total);
    }
    return 1;
ret0:
    return 0;
}
