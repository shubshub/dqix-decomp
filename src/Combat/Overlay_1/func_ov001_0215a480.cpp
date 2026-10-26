#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov001_02159f54(void*);

struct Struct_ov001_0215a480 {
    unsigned int unknown_0_;
    unsigned int w1;
    unsigned int w2;
};

// USA: func_ov001_0215a480
extern "C" ARM void func_ov001_0215a480(void* ctx, struct Struct_ov001_0215a480 payload, unsigned int a, unsigned int b) {
    void* node = func_ov001_02159f54(ctx);
    if (node != NULL) {
        *(int*)node = 8;
        memcpy((char*)node + 0x4, &payload, sizeof(payload));
        *(unsigned int*)((char*)node + 0x10) = a;
        *(unsigned int*)((char*)node + 0x14) = b;
    }
}
