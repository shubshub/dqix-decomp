#include <globaldefs.h>

struct GridCursor;
extern "C" void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);
extern "C" void GridCursor_SetCount(struct GridCursor* s, int val);
struct Struct_0205bcdc;
extern "C" void GridCursor_SelectIfValid(struct Struct_0205bcdc* s, int index);
extern "C" void GridCursor_SetSelectedIndex(void* s, int n);

// USA: func_ov003_0215b3bc
extern "C" ARM void func_ov003_0215b3bc(char* obj) {
    int count, isSet, idx;
    unsigned char state = *(unsigned char*)(obj + 0x1a4);
    switch (state) {
    case 1:
        count = *(unsigned char*)(obj + 0x589);
        idx = *(signed char*)(obj + 0x584);
        isSet = 1;
        break;
    case 2:
        count = *(unsigned char*)(obj + 0x590);
        idx = *(signed char*)(obj + 0x585);
        isSet = 1;
        break;
    case 3:
        idx = *(signed char*)(obj + 0x586);
        isSet = 1;
        count = 2;
        break;
    }

    GridCursor_SetDimensions((struct GridCursor*)(obj + 0xf8), isSet, count, 0);
    GridCursor_SetDimensions((struct GridCursor*)(obj + 0x148), isSet, count, 0);
    GridCursor_SetCount((struct GridCursor*)(obj + 0xf8), count);
    GridCursor_SetCount((struct GridCursor*)(obj + 0x148), count);
    *(int*)(obj + 0xfc) = isSet;
    *(int*)(obj + 0x14c) = isSet;
    GridCursor_SelectIfValid((struct Struct_0205bcdc*)(obj + 0xf8), idx);
    GridCursor_SetSelectedIndex((void*)(obj + 0x148), idx);
}
