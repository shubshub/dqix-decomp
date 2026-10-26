#include <globaldefs.h>
extern "C" void LoadClearImage(int, int);

extern "C" void MemoryMapClearTexture(int a, int b, int c);
extern "C" void MemoryUnmapClearTexture(void);

// USA: func_020bb9f0
extern "C" ARM void func_020bb9f0(int a, int b, int c) {
    MemoryMapClearTexture(a, b, c);
    LoadClearImage((int)(a), (int)(c));
    MemoryUnmapClearTexture();
}
