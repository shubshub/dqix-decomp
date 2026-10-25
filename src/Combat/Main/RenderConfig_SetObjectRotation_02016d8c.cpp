#include <globaldefs.h>

extern "C" void func_020ca528(void* a, void* b);
extern int data_0210a0cc;

struct FlagBlock02016d8c { int pad[0x3f]; int flags; };
extern FlagBlock02016d8c data_0210a010;

// Main, originally ClearGlobalFlagBits02016d8c (USA 0x02016d8c, EUR 0x02016d9c, JPN 0x02016b2c)
ARM void RenderConfig_SetObjectRotation(void* arg0) {
    func_020ca528(arg0, &data_0210a0cc);
    data_0210a010.flags &= ~0xa4;
}
