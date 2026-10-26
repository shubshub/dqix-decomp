#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x47c
#else
#define REGION_OFFSET_0 0x43c
#endif


struct Struct_ov000_021754e0 { char pad[REGION_OFFSET_0]; unsigned char flags; };

extern "C" struct Struct_ov000_021754e0* func_ov000_02161318(int, int);

// USA: func_ov000_021754e0
extern "C" ARM void func_ov000_021754e0(int a, int b) {
    struct Struct_ov000_021754e0* p = func_ov000_02161318(a, b);
    if (p) {
        p->flags |= 0x2;
    }
}
