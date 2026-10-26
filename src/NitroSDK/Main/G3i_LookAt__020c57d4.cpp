#include <globaldefs.h>

#if defined(jpn)
#define func_020c5188 func_020c6c54
#endif

extern "C" void Mat4x3_WriteViewMatrix(int, int, int, void*);
extern "C" void func_020c5188(int cmd);

// Main, originally SubmitGeometryJob_020c57d4 (USA 0x020c57d4, EUR 0x020c57e4, JPN 0x020c72a0)
extern "C" ARM void G3i_LookAt_(int a, int b, int c, int flag, void* buf) {
    unsigned char local[0x30];
    void* dst = buf ? buf : local;
    Mat4x3_WriteViewMatrix(a, b, c, dst);
    if (!flag) return;
    *(volatile int*)0x4000440 = 2;
    func_020c5188((int)dst);
}
