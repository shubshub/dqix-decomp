#include <globaldefs.h>
extern "C" void LoadClearDepthBuffer(int, int);

extern "C" void MemoryMapClearTexture(int a, int b, int c);
extern "C" void MemoryUnmapClearTexture(void);

// USA: func_020bba14
extern "C" ARM void func_020bba14(int a, int b, int c) {
    MemoryMapClearTexture(a, b, c);
    LoadClearDepthBuffer((int)(a), (int)(c));
    MemoryUnmapClearTexture();
}
