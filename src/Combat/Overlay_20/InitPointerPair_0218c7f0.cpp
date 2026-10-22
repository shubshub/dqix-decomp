#include <globaldefs.h>

struct Struct_0205ba68;
struct Node0205bacc;
void GridCursor_SetDimensions(struct Struct_0205ba68* s, int a, int b, int mode);
void GridCursor_SetCount(struct Node0205bacc* s, int val);

// USA: func_ov020_0218c7f0  (semantic: InitPointerPair_0218c7f0)
extern "C" ARM void func_ov020_0218c7f0(unsigned char* obj, int a, int b) {
    GridCursor_SetDimensions((struct Struct_0205ba68*)(obj + 0x20), a, b, 0);
    GridCursor_SetDimensions((struct Struct_0205ba68*)(obj + 0x70), a, b, 0);
    int prod = a * b;
    GridCursor_SetCount((struct Node0205bacc*)(obj + 0x20), prod);
    GridCursor_SetCount((struct Node0205bacc*)(obj + 0x70), prod);
}
