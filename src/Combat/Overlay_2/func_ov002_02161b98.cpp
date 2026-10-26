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

extern "C" struct Elem_0205d81c *func_0205d81c(struct Struct_0205d81c *s, int key);
extern "C" int Window_GetPageCount(unsigned char *p);
extern "C" void GridCursor_TurnPage(struct GridCursor *s, int delta);
extern "C" int GridCursor_GetSelectedIndex(struct GridCursor *s);
extern "C" void GridCursor_SelectIfValid(struct Struct_0205bcdc *p, int v);
extern "C" void GridCursor_SetSelectedIndex(void *p, int v);

// USA: func_ov002_02161b98
extern "C" ARM int func_ov002_02161b98(char *base) {
    int cx;
    int var1;
    short var2;
    short var3;
    char *list;
    struct Elem_0205d81c *elem;
    if (g_touchInput.pressed_ == 0) {
        goto ret0;
    }
    g_touchInput.GetTouchPoint(&cx, &var1);
    elem = func_0205d81c((struct Struct_0205d81c *) (base + RG(0x2c8 + 0xc00, 0xe20)),
                                   *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) & 0xff);
    if (elem == 0) {
        goto ret0;
    }
    short var6 = *(short *) ((char *) elem + 0xae);
    short var7 = *(short *) ((char *) elem + 0xaa);
    var2 = *(short *) ((char *) elem + 0xac);
    short var8 = *(short *) ((char *) elem + 0xa8);
    short var9 = var6;
    var3 = var2;
    var3 += var8;
    var9 += var7;
    int var10 = var1;
    int var11 = (short) (var9 * 8);
    if (var11 - 16 <= var10 && var10 < var11) {
        list = base + RG(0x2c8 + 0xc00, 0xe20);
        if (Window_GetPageCount((unsigned char *) list) == 1) {
            return 0;
        }
        int var12 = (short) (var2 * 8);
        if (var12 <= cx && cx < var12 + 16) {
            GridCursor_TurnPage((struct GridCursor *) (list + 0x54), -1);
            *(int *) (base + 0x1000 + RG(0xbc8, 0xa90)) = 1;
        }
        int var13 = cx;
        int var14 = (short) (var3 * 8);
        if (var14 - 16 <= var13 && var13 < var14) {
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
