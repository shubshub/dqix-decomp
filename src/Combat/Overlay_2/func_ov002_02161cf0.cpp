#include "GameState/GameState.h"
#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#define K(u, j) (j)
#else
#define RG(u, j) (u)
#define K(u, j) (u)
#endif

struct GridCursor;
struct Struct_0205bcdc;
struct Struct0205cf1c;
void SetChannelAFlag0205cef8(void *p);
void SetChannelBFlag0205cf04(void *p);
void ClearChannelAFlag0205cf10(void *p);
void ClearFlagByte0205cf1c(struct Struct0205cf1c *p);
unsigned char ReadBattleField0x64f4Byte_02011804(GameState* gameState);
int GetCountByType02157108(void *base, int id);
void GridCursor_SetDimensions(struct GridCursor *p, int a, int b, int c);
void GridCursor_SetCount(struct GridCursor *p, int v);
void GridCursor_SelectIfValid(struct Struct_0205bcdc *p, int v);
extern "C" void GridCursor_SetSelectedIndex(void *p, int v);
extern "C" int func_020dc428();
extern "C" void func_ov002_02156080(void *arg0, short *arg1, short *arg2);

// USA: func_ov002_02161cf0
extern "C" ARM void func_ov002_02161cf0(char *arg0) {
    int var0;
    int var1;
    int var2;
    int var3;
    int var4;
    char *var5 = arg0 + RG(0x2c8 + 0xc00, 0xe20);
    int var6;
    GameState::GetInstance();
    var6 = 0;
    func_0205cef8(arg0 + RG(0x2c8 + 0xc00, 0xe20));
    func_0205cf04(arg0 + RG(0x2c8 + 0xc00, 0xe20));
    switch (*(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80))) {
        case 1:
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xe0, 0x1a00 + 0xa8));
            var0   = 2;
            var1   = 3;
            var2  = 6;
            var3  = 1;
            break;
        case 2:
            var2  = *(signed char *) (arg0 + RG(0x1c00 + 0x73, 0x1b00 + 0x37));
            var0   = 1;
            var1   = var2;
            var3  = 1;
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xe2, 0x1a00 + 0xaa));
            break;
        case 3:
            var3  = 1;
            var2  = 3;
            var0   = 1;
            var1   = 3;
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xe4, 0x1a00 + 0xac));
            if (func_02011804(GameState::GetInstance()) == 0) {
                var2 = 2;
                var1  = 2;
            }
            break;
        case 4:
            var2 = *(signed char *) (arg0 + RG(0x1c00 + 0x73, 0x1b00 + 0x37)) + 2;
            var3 = 1;
            var1  = var2;
            var0  = var3;
            if (*(unsigned char *) (arg0 + 0x2000 + RG(0x485, 0x2b5))) var1 = var2 - 1;
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xe6, 0x1a00 + 0xae));
            break;
        case 5:
        case K(10, 11):
            if (*(short *) (arg0 + RG(0x1b00 + 0xe6, 0x1a00 + 0xae)) >= 0) {
                *(signed char *) (arg0 + 0x1000 + RG(0xc20, 0xae8)) =
                    *(signed char *) (arg0 + *(short *) (arg0 + RG(0x1b00 + 0xe6, 0x1a00 + 0xae)) + RG(0x1c00 + 0x6e, 0x1b00 + 0x32));
                if (*(short *) (arg0 + RG(0x1b00 + 0xe6, 0x1a00 + 0xae)) == *(signed char *) (arg0 + RG(0x1c00 + 0x73, 0x1b00 + 0x37)))
                    *(signed char *) (arg0 + 0x1000 + RG(0xc20, 0xae8)) = 4;
                if (*(short *) (arg0 + RG(0x1b00 + 0xe6, 0x1a00 + 0xae)) == *(signed char *) (arg0 + RG(0x1c00 + 0x73, 0x1b00 + 0x37)) + 1)
                    *(signed char *) (arg0 + 0x1000 + RG(0xc20, 0xae8)) = -1;
            }
            var0  = 1;
            var1  = 8;
            var2 = func_ov002_02157108(arg0, *(signed char *) (arg0 + RG(0x1c00 + 0x20, 0x1a00 + 0xe8)));
            var3 = (var2 + 7) / 8;
            if (var2 < 8) var1 = var2;
            if (var2 <= *(short *) (arg0 + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0))) *(short *) (arg0 + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0)) = var2 - 1;
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0));
            break;
        case K(6, 7):
            var3  = 1;
            var2  = 4;
            var0   = 1;
            var1   = 4;
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xea, 0x1a00 + 0xb2));
            break;
        case K(7, 8):
            var3 = 1;
            var0  = 1;
            if (*(unsigned char *) (arg0 + 0x1000 + RG(0xc84, 0xb48)) == 7)
                var2 = *(signed char *) (arg0 + RG(0x1c00 + 0x73, 0x1b00 + 0x37));
            else
                var2 = *(unsigned char *) (arg0 + 0x1000 + RG(0xc6d, 0xb31));
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xec, 0x1a00 + 0xb4));
            var1   = var2;
            break;
        case K(9, 10):
            var2  = *(unsigned char *) (arg0 + 0x1000 + RG(0xc6d, 0xb31)) + 1;
            var3  = 1;
            var0   = 1;
            var1   = var2;
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xee, 0x1a00 + 0xb6));
            break;
        case K(11, 12):
            var2  = *(int *) (arg0 + 0x1000 + RG(0xc38, 0xafc)) + 1;
            var3  = 1;
            var0   = 1;
            var1   = var2;
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xf0, 0x1a00 + 0xb8));
            break;
        case K(12, 13):
            var3  = 1;
            var2  = 2;
            var0   = 1;
            var1   = 2;
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xf2, 0x1a00 + 0xba));
            break;
        case K(13, 14):
            var0  = 1;
            var1  = 8;
            var2 = func_ov002_02157108(arg0, *(signed char *) (arg0 + RG(0x1c00 + 0x21, 0x1a00 + 0xe9))) + 1;
            var3 = 1;
            if (var2 > 8) var2 = 8;
            if (var2 < 8) var1 = var2;
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xf4, 0x1a00 + 0xbc));
            break;
        case K(14, 15): {
            signed char var7 = func_020dc428();
            var2         = var7 + 1;
            if (*(short *) (arg0 + RG(0x1b00 + 0xf6, 0x1a00 + 0xbe)) > var7) *(short *) (arg0 + RG(0x1b00 + 0xf6, 0x1a00 + 0xbe)) = var7;
            var0  = 1;
            var1  = var2;
            var3 = 1;
            if (*(short *) (arg0 + RG(0x1b00 + 0xf6, 0x1a00 + 0xbe)) < 0) *(short *) (arg0 + RG(0x1b00 + 0xf6, 0x1a00 + 0xbe)) = 0;
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xf6, 0x1a00 + 0xbe));
            break;
        }
        case K(16, 17):
            var2  = *(signed char *) (arg0 + RG(0x1c00 + 0x73, 0x1b00 + 0x37));
            var0   = 1;
            var1   = var2;
            var3  = 1;
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xf8, 0x1a00 + 0xc0));
            break;
        case K(17, 18):
            var2 = *(unsigned char *) (arg0 + 0x2000 + RG(0x520, 0x350));
            var1  = 8;
            var0  = 1;
            var3 = (var2 + 7) / 8;
            if (var2 < 8) var1 = var2;
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xfa, 0x1a00 + 0xc2));
            break;
        case K(20, 21): {
            char *var8 = *(char **) (arg0 + 0x2000 + RG(0x474, 0x2a4));
            if (var8 != NULL) {
                var2 = *(unsigned short *) (var8 + 0xc);
                var1  = 6;
                var0  = 1;
                if (var2 < 6) var1 = var2;
                var4 = *(short *) (arg0 + RG(0x1b00 + 0xfc, 0x1a00 + 0xc4));
                var3  = (var2 - 1) / 6 + 1;
            } else {
                var0   = var6;
                var1   = var0;
                var2  = var0;
                var4 = var0;
                var3  = var0;
            }
            break;
        }
        case K(21, 22): {
            short var9 = 0;
            short var10[9];
            func_ov002_02156080(arg0, var10, &var9);
            var2  = var9;
            var0   = 1;
            var1   = var2;
            var3  = 1;
            var4 = *(short *) (arg0 + RG(0x1b00 + 0xfe, 0x1a00 + 0xc6));
            break;
        }
        case K(23, 24): break;
        case K(24, 25):
            var4 = *(short *) (arg0 + RG(0x1c00 + 0x2, 0x1a00 + 0xca));
            var0   = 3;
            var1   = *(signed char *) (arg0 + RG(0x1c00 + 0x73, 0x1b00 + 0x37)) + 1;
            var2  = var1 * 3;
            var3  = 1;
            break;
        case K(25, 26):
            var3  = 1;
            var2  = 6;
            var0   = 1;
            var1   = 6;
            var4 = *(short *) (arg0 + RG(0x1c00 + 0x4, 0x1a00 + 0xcc));
            break;
        case K(28, 29):
            var1   = 4;
            var3  = 1;
            var0   = 4;
            var6   = 1;
            var4 = *(short *) (arg0 + RG(0x1c00 + 0x6, 0x1a00 + 0xce));
            var2  = 0x10;
            break;
        case K(31, 32):
            var2  = *(signed char *) (arg0 + RG(0x1c00 + 0x73, 0x1b00 + 0x37));
            var3  = 1;
            var0   = 1;
            var1   = var2;
            var4 = *(short *) (arg0 + RG(0x1c00 + 0x8, 0x1a00 + 0xd0));
            break;
        case K(33, 36):
            var3  = 1;
            var2  = 8;
            var0   = 1;
            var1   = 8;
            var4 = *(short *) (arg0 + RG(0x1c00 + 0xa, 0x1a00 + 0xd2));
            break;
        case K(34, 37):
            var0   = 2;
            var3  = 2;
            var4 = *(short *) (arg0 + RG(0x1c00 + 0xc, 0x1a00 + 0xd4));
            var1   = 8;
            var2  = 0x20;
            var6   = 1;
            break;
        case K(35, 38):
            var3  = 1;
            var2  = 3;
            var0   = 1;
            var1   = 3;
            var4 = *(short *) (arg0 + RG(0x1c00 + 0xe, 0x1a00 + 0xd6));
            break;
        case K(36, 39):
            var3  = 1;
            var2  = 2;
            var0   = 1;
            var1   = 2;
            var4 = *(short *) (arg0 + RG(0x1c00 + 0x10, 0x1a00 + 0xd8));
            break;
        case K(37, 40):
            var3  = 1;
            var2  = 2;
            var0   = 1;
            var1   = 2;
            var4 = *(short *) (arg0 + RG(0x1c00 + 0x12, 0x1a00 + 0xda));
            break;
        case K(39, 42):
            var3  = 1;
            var2  = 2;
            var0   = 1;
            var1   = 2;
            var4 = *(short *) (arg0 + RG(0x1c00 + 0x14, 0x1a00 + 0xdc));
            break;
        default:
            func_0205cf10(arg0 + RG(0x2c8 + 0xc00, 0xe20));
            func_0205cf1c((struct Struct_0205cf1c *) (arg0 + RG(0x2c8 + 0xc00, 0xe20)));
            return;
    }
    GridCursor_SetDimensions((struct GridCursor *) (list + 4), cols, rows, flag);
    GridCursor_SetDimensions((struct GridCursor *) (list + 0x54), cols, rows, flag);
    GridCursor_SetCount((struct GridCursor *) (list + 4), total);
    GridCursor_SetCount((struct GridCursor *) (list + 0x54), total);
    *(int *) (list + 8)    = pages;
    *(int *) (list + 0x58) = pages;
    GridCursor_SelectIfValid((struct Struct_0205bcdc *) (list + 4), cursor);
    GridCursor_SetSelectedIndex(list + 0x54, cursor);
    *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) &= ~4;
}
