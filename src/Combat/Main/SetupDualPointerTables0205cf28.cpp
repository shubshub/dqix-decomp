#include <globaldefs.h>

struct Struct_0205ba68;
struct Node0205bacc;
void GridCursor_SetDimensions(struct Struct_0205ba68* s, int a, int b, int mode);
void GridCursor_SetCount(struct Node0205bacc* s, int val);

// USA: func_0205cf28
ARM void SetupDualPointerTables0205cf28(unsigned char* p, int a, int b, int c) {
    GridCursor_SetDimensions((struct Struct_0205ba68*)(p + 4), a, b, c);
    GridCursor_SetDimensions((struct Struct_0205ba68*)(p + 0x54), a, b, c);
    int prod = a * b;
    GridCursor_SetCount((struct Node0205bacc*)(p + 4), prod);
    GridCursor_SetCount((struct Node0205bacc*)(p + 0x54), prod);
}
