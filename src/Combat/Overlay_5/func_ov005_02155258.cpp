#include <globaldefs.h>

#if defined(jpn)
#define func_02045f3c func_02046c78
#endif

int MessageSystem_GetInstance();
#if defined(jpn)
extern "C" void func_02046c78(void*, void*, int, int, int, int, int, int);
#define DRAW_DIGIT(ctx, rec, x, y, color) func_02046c78(ctx, rec, x, y, color, 8, 0, 0)
#define DIGIT_BASE 0x3d84
#define DIGIT_STEP 8
#else
extern "C" void func_02045f3c(void*, void*, int, int, int, int, int, int, int, int);
#define DRAW_DIGIT(ctx, rec, x, y, color) func_02045f3c(ctx, rec, x, y, color, 8, 0, 0, 0, 0x11)
#define DIGIT_BASE 0x3e0c
#define DIGIT_STEP 5
#endif

// USA: func_ov005_02155258
extern "C" ARM void func_ov005_02155258(void* arg0, int arg1,
#if defined(jpn)
    int arg2, int arg3
#else
    short arg2, short arg3
#endif
    , unsigned short color) {
    int drawContext = MessageSystem_GetInstance();
    volatile unsigned int* ports = (volatile unsigned int*)0x04000444;
    ports[0] = 0;
    ports[0x2f] = 1;
    ports[0xb] = 0;
    ports[0xb] = 0;
    ports[0xb] = 0xffc01000;
    int tens = value / 10;
    int units = value % 10;
    #if defined(jpn)
    int var4 = arg2;
#else
    short var4 = arg2;
#endif
    if (var2 != 0) {
#if !defined(jpn)
        if (var3 == 1) var4++;
        if (var2 == 1) var4++;
#endif
        DRAW_DIGIT((void*)var0, (char*)arg0 + DIGIT_BASE + var2 * 6, var4, arg3, arg4);
    }
    var4 = arg2 + DIGIT_STEP;
#if !defined(jpn)
    if (var3 == 1) var4++;
#endif
    DRAW_DIGIT((void*)var0, (char*)arg0 + DIGIT_BASE + var3 * 6, var4, arg3, arg4);
    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
}
