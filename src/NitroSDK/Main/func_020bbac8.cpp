#include <globaldefs.h>
extern "C" void LoadToMainObjExtendedPalette(int, int, int);

extern "C" void MemoryMapMainObjExtendedPalette(int a, int b, int c);
extern "C" void MemoryUnmapMainObjExtendedPalette(void);

// USA: func_020bbac8
extern "C" ARM void func_020bbac8(int a, int b, int c) {
    MemoryMapMainObjExtendedPalette(a, b, c);
    LoadToMainObjExtendedPalette((int)(a), (int)(b), (int)(c));
    MemoryUnmapMainObjExtendedPalette();
}
