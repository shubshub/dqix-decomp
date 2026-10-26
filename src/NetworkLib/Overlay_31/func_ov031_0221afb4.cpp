#include <globaldefs.h>

extern "C" int func_ov031_0221b6f0(int a, int b, void* c);

extern int data_ov031_0224e6a0[];

// USA: func_ov031_0221afb4
extern "C" ARM int func_ov031_0221afb4(void* self) {
    if (!func_ov031_0221b6f0(0x20, 0x20, self)) {
        return 0;
    }
    unsigned short v = *(unsigned short*)self;
    *(int*)((char*)data_ov031_0224e6a0 + 8) = (v << 3) - 0x400;
    return 1;
}
