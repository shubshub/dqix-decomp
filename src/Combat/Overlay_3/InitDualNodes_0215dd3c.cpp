#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue148_160 = 0x160 };
enum { kRegionValue3C0_3D8 = 0x3d8 };
enum { kRegionValue3C1_3D9 = 0x3d9 };
enum { kRegionValue9C_B4 = 0xb4 };
enum { kRegionValueEC_104 = 0x104 };
enum { kRegionValueA0_B8 = 0xb8 };
enum { kRegionValueF0_108 = 0x108 };
#else
enum { kRegionValue148_160 = 0x148 };
enum { kRegionValue3C0_3D8 = 0x3c0 };
enum { kRegionValue3C1_3D9 = 0x3c1 };
enum { kRegionValue9C_B4 = 0x9c };
enum { kRegionValueEC_104 = 0xec };
enum { kRegionValueA0_B8 = 0xa0 };
enum { kRegionValueF0_108 = 0xf0 };
#endif


struct Struct_0205ba68;
void GridCursor_SetDimensions(struct Struct_0205ba68* s, int a, int b, int mode);
struct Node0205bacc;
void GridCursor_SetCount(struct Node0205bacc* s, int val);
struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index);
extern "C" void GridCursor_SetSelectedIndex(void* s, int n);

// USA: func_ov003_0215dd3c  (semantic: InitDualNodes_0215dd3c)
extern "C" ARM void func_ov003_0215dd3c(char* obj) {
    int a, b, c;
    if (*(unsigned char*)(obj + kRegionValue148_160) == 1) {
        a = *(unsigned char*)(obj + kRegionValue3C0_3D8);
        b = 1;
        c = *(signed char*)(obj + kRegionValue3C1_3D9);
    }
    GridCursor_SetDimensions((struct Struct_0205ba68*)(obj + kRegionValue9C_B4), b, a, 0);
    GridCursor_SetDimensions((struct Struct_0205ba68*)(obj + kRegionValueEC_104), b, a, 0);
    GridCursor_SetCount((struct Node0205bacc*)(obj + kRegionValue9C_B4), a);
    GridCursor_SetCount((struct Node0205bacc*)(obj + kRegionValueEC_104), a);
    *(int*)(obj + kRegionValueA0_B8) = b;
    *(int*)(obj + kRegionValueF0_108) = b;
    SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)(obj + kRegionValue9C_B4), c);
    GridCursor_SetSelectedIndex((void*)(obj + kRegionValueEC_104), c);
}
