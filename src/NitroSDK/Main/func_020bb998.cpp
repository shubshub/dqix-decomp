#include <globaldefs.h>

extern "C" void MemoryMapTextureImage(int, int, int);
extern "C" void LoadToTextureImage(int, int, int);
extern "C" void MemoryUnmapTextureImage(void);

// USA: func_020bb998
extern "C" ARM void func_020bb998(int a, int b, int c) {
    MemoryMapTextureImage(a, b, c);
    LoadToTextureImage(a, b, c);
    MemoryUnmapTextureImage();
}
