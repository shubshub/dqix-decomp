#include <globaldefs.h>

struct GridCursor;
void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);
void GridCursor_SetCount(struct GridCursor* s, int val);

// USA: func_ov020_0218c7f0  (semantic: InitPointerPair_0218c7f0)
extern "C" ARM void func_ov020_0218c7f0(unsigned char* obj, int a, int b) {
    GridCursor_SetDimensions((struct GridCursor*)(obj + 0x20), a, b, 0);
    GridCursor_SetDimensions((struct GridCursor*)(obj + 0x70), a, b, 0);
    int prod = a * b;
    GridCursor_SetCount((struct GridCursor*)(obj + 0x20), prod);
    GridCursor_SetCount((struct GridCursor*)(obj + 0x70), prod);
}
