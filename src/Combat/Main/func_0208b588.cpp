#include <globaldefs.h>

// USA: func_0208b588
// Packs the GX POLYGON_ATTR register (0x040004A4).
extern "C" ARM void func_0208b588(unsigned int a0, unsigned int a1, unsigned int a2,
                                  unsigned int a3, unsigned int a4, unsigned int a5) {
    *(volatile unsigned int*)0x40004a4 =
        a0 | (a1 << 4) | (a2 << 6) | a5 | (a3 << 24) | (a4 << 16);
}
