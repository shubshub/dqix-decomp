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
struct Struct_0205cf1c;
extern "C" void func_0205cef8(void *p);
extern "C" void func_0205cf04(void *p);
extern "C" void func_0205cf10(void *p);
extern "C" void func_0205cf1c(struct Struct_0205cf1c *p);
extern "C" unsigned char func_02011804(GameState* gameState);
extern "C" int func_ov002_02157108(void *base, int id);
extern "C" void GridCursor_SetDimensions(struct GridCursor *p, int a, int b, int c);
extern "C" void GridCursor_SetCount(struct GridCursor *p, int v);
extern "C" void GridCursor_SelectIfValid(struct Struct_0205bcdc *p, int v);
extern "C" void GridCursor_SetSelectedIndex(void *p, int v);
extern "C" int func_020dc428();
extern "C" void func_ov002_02156080(void *self, short *out, short *outCount);

// USA: func_ov002_02161cf0
extern "C" ARM void func_ov002_02161cf0(char *base) {
    int cols;
    int rows;
    int total;
    int pages;
    int cursor;
    char *list = base + RG(0x2c8 + 0xc00, 0xe20);
    int flag;
    GameState::GetInstance();
    flag = 0;
    func_0205cef8(base + RG(0x2c8 + 0xc00, 0xe20));
    func_0205cf04(base + RG(0x2c8 + 0xc00, 0xe20));
    switch (*(int *) (base + 0x1000 + RG(0xbb8, 0xa80))) {
        case 1:
            cursor = *(short *) (base + RG(0x1b00 + 0xe0, 0x1a00 + 0xa8));
            cols   = 2;
            rows   = 3;
            total  = 6;
            pages  = 1;
            break;
        case 2:
            total  = *(signed char *) (base + RG(0x1c00 + 0x73, 0x1b00 + 0x37));
            cols   = 1;
            rows   = total;
            pages  = 1;
            cursor = *(short *) (base + RG(0x1b00 + 0xe2, 0x1a00 + 0xaa));
            break;
        case 3:
            pages  = 1;
            total  = 3;
            cols   = 1;
            rows   = 3;
            cursor = *(short *) (base + RG(0x1b00 + 0xe4, 0x1a00 + 0xac));
            if (func_02011804(GameState::GetInstance()) == 0) {
                total = 2;
                rows  = 2;
            }
            break;
        case 4:
            total = *(signed char *) (base + RG(0x1c00 + 0x73, 0x1b00 + 0x37)) + 2;
            pages = 1;
            rows  = total;
            cols  = pages;
            if (*(unsigned char *) (base + 0x2000 + RG(0x485, 0x2b5))) rows = total - 1;
            cursor = *(short *) (base + RG(0x1b00 + 0xe6, 0x1a00 + 0xae));
            break;
        case 5:
        case K(10, 11):
            if (*(short *) (base + RG(0x1b00 + 0xe6, 0x1a00 + 0xae)) >= 0) {
                *(signed char *) (base + 0x1000 + RG(0xc20, 0xae8)) =
                    *(signed char *) (base + *(short *) (base + RG(0x1b00 + 0xe6, 0x1a00 + 0xae)) + RG(0x1c00 + 0x6e, 0x1b00 + 0x32));
                if (*(short *) (base + RG(0x1b00 + 0xe6, 0x1a00 + 0xae)) == *(signed char *) (base + RG(0x1c00 + 0x73, 0x1b00 + 0x37)))
                    *(signed char *) (base + 0x1000 + RG(0xc20, 0xae8)) = 4;
                if (*(short *) (base + RG(0x1b00 + 0xe6, 0x1a00 + 0xae)) == *(signed char *) (base + RG(0x1c00 + 0x73, 0x1b00 + 0x37)) + 1)
                    *(signed char *) (base + 0x1000 + RG(0xc20, 0xae8)) = -1;
            }
            cols  = 1;
            rows  = 8;
            total = func_ov002_02157108(base, *(signed char *) (base + RG(0x1c00 + 0x20, 0x1a00 + 0xe8)));
            pages = (total + 7) / 8;
            if (total < 8) rows = total;
            if (total <= *(short *) (base + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0))) *(short *) (base + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0)) = total - 1;
            cursor = *(short *) (base + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0));
            break;
        case K(6, 7):
            pages  = 1;
            total  = 4;
            cols   = 1;
            rows   = 4;
            cursor = *(short *) (base + RG(0x1b00 + 0xea, 0x1a00 + 0xb2));
            break;
        case K(7, 8):
            pages = 1;
            cols  = 1;
            if (*(unsigned char *) (base + 0x1000 + RG(0xc84, 0xb48)) == 7)
                total = *(signed char *) (base + RG(0x1c00 + 0x73, 0x1b00 + 0x37));
            else
                total = *(unsigned char *) (base + 0x1000 + RG(0xc6d, 0xb31));
            cursor = *(short *) (base + RG(0x1b00 + 0xec, 0x1a00 + 0xb4));
            rows   = total;
            break;
        case K(9, 10):
            total  = *(unsigned char *) (base + 0x1000 + RG(0xc6d, 0xb31)) + 1;
            pages  = 1;
            cols   = 1;
            rows   = total;
            cursor = *(short *) (base + RG(0x1b00 + 0xee, 0x1a00 + 0xb6));
            break;
        case K(11, 12):
            total  = *(int *) (base + 0x1000 + RG(0xc38, 0xafc)) + 1;
            pages  = 1;
            cols   = 1;
            rows   = total;
            cursor = *(short *) (base + RG(0x1b00 + 0xf0, 0x1a00 + 0xb8));
            break;
        case K(12, 13):
            pages  = 1;
            total  = 2;
            cols   = 1;
            rows   = 2;
            cursor = *(short *) (base + RG(0x1b00 + 0xf2, 0x1a00 + 0xba));
            break;
        case K(13, 14):
            cols  = 1;
            rows  = 8;
            total = func_ov002_02157108(base, *(signed char *) (base + RG(0x1c00 + 0x21, 0x1a00 + 0xe9))) + 1;
            pages = 1;
            if (total > 8) total = 8;
            if (total < 8) rows = total;
            cursor = *(short *) (base + RG(0x1b00 + 0xf4, 0x1a00 + 0xbc));
            break;
        case K(14, 15): {
            signed char n = func_020dc428();
            total         = n + 1;
            if (*(short *) (base + RG(0x1b00 + 0xf6, 0x1a00 + 0xbe)) > n) *(short *) (base + RG(0x1b00 + 0xf6, 0x1a00 + 0xbe)) = n;
            cols  = 1;
            rows  = total;
            pages = 1;
            if (*(short *) (base + RG(0x1b00 + 0xf6, 0x1a00 + 0xbe)) < 0) *(short *) (base + RG(0x1b00 + 0xf6, 0x1a00 + 0xbe)) = 0;
            cursor = *(short *) (base + RG(0x1b00 + 0xf6, 0x1a00 + 0xbe));
            break;
        }
        case K(16, 17):
            total  = *(signed char *) (base + RG(0x1c00 + 0x73, 0x1b00 + 0x37));
            cols   = 1;
            rows   = total;
            pages  = 1;
            cursor = *(short *) (base + RG(0x1b00 + 0xf8, 0x1a00 + 0xc0));
            break;
        case K(17, 18):
            total = *(unsigned char *) (base + 0x2000 + RG(0x520, 0x350));
            rows  = 8;
            cols  = 1;
            pages = (total + 7) / 8;
            if (total < 8) rows = total;
            cursor = *(short *) (base + RG(0x1b00 + 0xfa, 0x1a00 + 0xc2));
            break;
        case K(20, 21): {
            char *p = *(char **) (base + 0x2000 + RG(0x474, 0x2a4));
            if (p != NULL) {
                total = *(unsigned short *) (p + 0xc);
                rows  = 6;
                cols  = 1;
                if (total < 6) rows = total;
                cursor = *(short *) (base + RG(0x1b00 + 0xfc, 0x1a00 + 0xc4));
                pages  = (total - 1) / 6 + 1;
            } else {
                cols   = flag;
                rows   = cols;
                total  = cols;
                cursor = cols;
                pages  = cols;
            }
            break;
        }
        case K(21, 22): {
            short count = 0;
            short items[9];
            func_ov002_02156080(base, items, &count);
            total  = count;
            cols   = 1;
            rows   = total;
            pages  = 1;
            cursor = *(short *) (base + RG(0x1b00 + 0xfe, 0x1a00 + 0xc6));
            break;
        }
        case K(23, 24): break;
        case K(24, 25):
            cursor = *(short *) (base + RG(0x1c00 + 0x2, 0x1a00 + 0xca));
            cols   = 3;
            rows   = *(signed char *) (base + RG(0x1c00 + 0x73, 0x1b00 + 0x37)) + 1;
            total  = rows * 3;
            pages  = 1;
            break;
        case K(25, 26):
            pages  = 1;
            total  = 6;
            cols   = 1;
            rows   = 6;
            cursor = *(short *) (base + RG(0x1c00 + 0x4, 0x1a00 + 0xcc));
            break;
        case K(28, 29):
            rows   = 4;
            pages  = 1;
            cols   = 4;
            flag   = 1;
            cursor = *(short *) (base + RG(0x1c00 + 0x6, 0x1a00 + 0xce));
            total  = 0x10;
            break;
        case K(31, 32):
            total  = *(signed char *) (base + RG(0x1c00 + 0x73, 0x1b00 + 0x37));
            pages  = 1;
            cols   = 1;
            rows   = total;
            cursor = *(short *) (base + RG(0x1c00 + 0x8, 0x1a00 + 0xd0));
            break;
        case K(33, 36):
            pages  = 1;
            total  = 8;
            cols   = 1;
            rows   = 8;
            cursor = *(short *) (base + RG(0x1c00 + 0xa, 0x1a00 + 0xd2));
            break;
        case K(34, 37):
            cols   = 2;
            pages  = 2;
            cursor = *(short *) (base + RG(0x1c00 + 0xc, 0x1a00 + 0xd4));
            rows   = 8;
            total  = 0x20;
            flag   = 1;
            break;
        case K(35, 38):
            pages  = 1;
            total  = 3;
            cols   = 1;
            rows   = 3;
            cursor = *(short *) (base + RG(0x1c00 + 0xe, 0x1a00 + 0xd6));
            break;
        case K(36, 39):
            pages  = 1;
            total  = 2;
            cols   = 1;
            rows   = 2;
            cursor = *(short *) (base + RG(0x1c00 + 0x10, 0x1a00 + 0xd8));
            break;
        case K(37, 40):
            pages  = 1;
            total  = 2;
            cols   = 1;
            rows   = 2;
            cursor = *(short *) (base + RG(0x1c00 + 0x12, 0x1a00 + 0xda));
            break;
        case K(39, 42):
            pages  = 1;
            total  = 2;
            cols   = 1;
            rows   = 2;
            cursor = *(short *) (base + RG(0x1c00 + 0x14, 0x1a00 + 0xdc));
            break;
        default:
            func_0205cf10(base + RG(0x2c8 + 0xc00, 0xe20));
            func_0205cf1c((struct Struct_0205cf1c *) (base + RG(0x2c8 + 0xc00, 0xe20)));
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
