#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_0215dd3c_328 = 0x160 };
enum { Enum_ov003_0215dd3c_960 = 0x3d8 };
enum { Enum_ov003_0215dd3c_961 = 0x3d9 };
enum { kRegionValue9C_B4 = 0xb4 };
enum { kRegionValueEC_104 = 0x104 };
enum { Enum_ov003_0215dd3c_160 = 0xb8 };
enum { Enum_ov003_0215dd3c_240 = 0x108 };
#else
enum { Enum_ov003_0215dd3c_328 = 0x148 };
enum { Enum_ov003_0215dd3c_960 = 0x3c0 };
enum { Enum_ov003_0215dd3c_961 = 0x3c1 };
enum { kRegionValue9C_B4 = 0x9c };
enum { kRegionValueEC_104 = 0xec };
enum { Enum_ov003_0215dd3c_160 = 0xa0 };
enum { Enum_ov003_0215dd3c_240 = 0xf0 };
#endif


struct GridCursor;
extern "C" void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);
extern "C" void GridCursor_SetCount(struct GridCursor* s, int val);
struct Struct_0205bcdc;
extern "C" void GridCursor_SelectIfValid(struct Struct_0205bcdc* s, int index);
extern "C" void GridCursor_SetSelectedIndex(void* s, int n);

// USA: func_ov003_0215dd3c
extern "C" ARM void func_ov003_0215dd3c(char* obj) {
    int a, b, c;
    if (*(unsigned char*)(obj + Enum_ov003_0215dd3c_328) == 1) {
        a = *(unsigned char*)(obj + Enum_ov003_0215dd3c_960);
        b = 1;
        c = *(signed char*)(obj + Enum_ov003_0215dd3c_961);
    }
    GridCursor_SetDimensions((struct GridCursor*)(obj + kRegionValue9C_B4), b, a, 0);
    GridCursor_SetDimensions((struct GridCursor*)(obj + kRegionValueEC_104), b, a, 0);
    GridCursor_SetCount((struct GridCursor*)(obj + kRegionValue9C_B4), a);
    GridCursor_SetCount((struct GridCursor*)(obj + kRegionValueEC_104), a);
    *(int*)(obj + Enum_ov003_0215dd3c_160) = b;
    *(int*)(obj + Enum_ov003_0215dd3c_240) = b;
    GridCursor_SelectIfValid((struct Struct_0205bcdc*)(obj + kRegionValue9C_B4), c);
    GridCursor_SetSelectedIndex((void*)(obj + kRegionValueEC_104), c);
}
