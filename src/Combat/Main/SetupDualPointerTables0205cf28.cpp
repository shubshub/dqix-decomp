#include <globaldefs.h>

struct GridCursor;
void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);
void GridCursor_SetCount(struct GridCursor* s, int val);

// USA: func_0205cf28
ARM void SetupDualPointerTables0205cf28(unsigned char* p, int a, int b, int c) {
    GridCursor_SetDimensions((struct GridCursor*)(p + 4), a, b, c);
    GridCursor_SetDimensions((struct GridCursor*)(p + 0x54), a, b, c);
    int prod = a * b;
    GridCursor_SetCount((struct GridCursor*)(p + 4), prod);
    GridCursor_SetCount((struct GridCursor*)(p + 0x54), prod);
}
