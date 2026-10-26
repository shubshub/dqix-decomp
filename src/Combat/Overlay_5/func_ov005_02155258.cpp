#include <globaldefs.h>
#if defined(jpn)
#define func_02046c78 func_02047a98
#endif

#if defined(jpn)
#define func_02045f3c func_02046c78
#endif

extern "C" int MessageSystem_GetInstance();
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
extern "C" ARM void func_ov005_02155258(void* context, int value,
#if defined(jpn)
    int x, int y
#else
    short x, short y
#endif
    , unsigned short color) {
    int drawContext = MessageSystem_GetInstance();
    volatile unsigned int* var1 = (volatile unsigned int*)0x04000444;
    var1[0] = 0;
    var1[0x2f] = 1;
    var1[0xb] = 0;
    var1[0xb] = 0;
    var1[0xb] = 0xffc01000;
    int var2 = value / 10;
    int var3 = value % 10;
    #if defined(jpn)
    int position = x;
#else
    short position = x;
#endif
    if (var2 != 0) {
#if !defined(jpn)
        if (var3 == 1) position++;
        if (var2 == 1) position++;
#endif
        DRAW_DIGIT((void*)drawContext, (char*)context + DIGIT_BASE + var2 * 6, position, y, color);
    }
    position = x + DIGIT_STEP;
#if !defined(jpn)
    if (var3 == 1) position++;
#endif
    DRAW_DIGIT((void*)drawContext, (char*)context + DIGIT_BASE + var3 * 6, position, y, color);
    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
}
