#include <globaldefs.h>
extern "C" void LoadToMainBGExtendedPalette(int, int, int);

extern "C" void MemoryMapMainBGExtendedPalette(int a, int b, int c);
extern "C" void MemoryUnmapMainBGExtendedPalette(void);

// USA: func_020bbaf4
extern "C" ARM void func_020bbaf4(int a, int b, int c) {
    MemoryMapMainBGExtendedPalette(a, b, c);
    LoadToMainBGExtendedPalette((int)(a), (int)(b), (int)(c));
    MemoryUnmapMainBGExtendedPalette();
}
