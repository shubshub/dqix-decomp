#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" ARM void func_ov031_0220b8a0(unsigned int* ctx);
extern "C" ARM void func_ov031_0220afe0(void* ctx);
extern "C" int func_ov031_022032a4(void* self);
extern "C" int func_ov031_0220a474(void* self);

// USA: func_ov031_0220a540
extern "C" ARM int func_ov031_0220a540(void* self) {
    unsigned char state = *(unsigned char*)((char*)self + 0x8);
    void* base = *(void**)((char*)self + 0xc);
    if (state != 4) {
        if (func_ov031_022032a4(self) != 0) return 1;
    }
    *(unsigned char*)((char*)base + 0x455) = 0;
    *(int*)((char*)base + 0x1d4) = 0;
    *(unsigned char*)((char*)base + 0x454) = 0;
    func_ov031_0220b8a0((unsigned int*)((char*)base + 0x2ec));
    func_ov031_0220afe0((char*)base + 0x3a4);
    return func_ov031_0220a474(self);
}
