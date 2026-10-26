#include <globaldefs.h>

extern "C" void MemoryMapTexturePalette(int, int, int);
extern "C" void LoadToTexturePalette(int, int, int);
extern "C" void MemoryUnmapTexturePalette(void);

// USA: func_020bb9c4
extern "C" ARM void func_020bb9c4(int a, int b, int c) {
    MemoryMapTexturePalette(a, b, c);
    LoadToTexturePalette(a, b, c);
    MemoryUnmapTexturePalette();
}
