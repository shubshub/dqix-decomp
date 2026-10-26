#include <globaldefs.h>

extern "C" int LoadToSubObjStandardPalette(int, int, unsigned int);

// USA: func_020bbbb0
extern "C" ARM int func_020bbbb0(int a, int b, unsigned int c) {
    return LoadToSubObjStandardPalette(a, b, c);
}
