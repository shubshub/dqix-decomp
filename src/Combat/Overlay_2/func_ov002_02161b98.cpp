#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0205d81c;
struct Struct_0205d0e0;
struct Struct_0205c4a8;
struct Struct_0205bb84;
struct Struct_0205bcdc;

struct Elem_0205d81c *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
int SelectField0x8Or0x58ByFlags_0205c6e4(unsigned char *p);
void AdvanceWrappedAccumulator0205c4a8(struct Struct_0205c4a8 *s, int delta);
int GridCursor_GetSelectedIndex(struct Struct_0205bb84 *s);
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc *p, int v);
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
    short var6 = *(short *) ((char *) var5 + 0xae);
    short var7 = *(short *) ((char *) var5 + 0xaa);
    var2 = *(short *) ((char *) var5 + 0xac);
    short var8 = *(short *) ((char *) var5 + 0xa8);
    short var9 = var6;
    var3 = var2;
    var3 += var8;
    var9 += var7;
    int var10 = var1;
    int var11 = (short) (var9 * 8);
    if (var11 - 16 <= var10 && var10 < var11) {
        var4 = arg0 + RG(0x2c8 + 0xc00, 0xe20);
        if (func_0205c6e4((unsigned char *) var4) == 1) {
            return 0;
        }
        int var12 = (short) (var2 * 8);
        if (var12 <= var0 && var0 < var12 + 16) {
            func_0205c4a8((struct Struct_0205c4a8 *) (var4 + 0x54), -1);
            *(int *) (arg0 + 0x1000 + RG(0xbc8, 0xa90)) = 1;
        }
        int var13 = var0;
        int var14 = (short) (var3 * 8);
        if (var14 - 16 <= var13 && var13 < var14) {
            func_0205c4a8((struct Struct_0205c4a8 *) (var4 + 0x54), 1);
            *(int *) (arg0 + 0x1000 + RG(0xbc8, 0xa90)) = 1;
        }
        int total = GridCursor_GetSelectedIndex((struct Struct_0205bb84 *) (list + 0x54));
        SetIndexIfValid0205bcdc((struct Struct_0205bcdc *) (list + 4), total);
        GridCursor_SetSelectedIndex(list + 0x54, total);
    }
    return 1;
ret0:
    return 0;
}
