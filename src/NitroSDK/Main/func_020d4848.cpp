#include <globaldefs.h>


extern "C" void* func_020d41d8(void);
extern "C" int func_020d41e8(void);
extern "C" void InvalidateDataCacheRange(const void* addr, unsigned int size);
extern "C" int func_020ca4b4(void*, void*, int);

struct Struct_020d4848 {
    unsigned char pad0[4];
    void* buffer;
};

// USA: func_020d4848
extern "C" ARM int func_020d4848(void* src) {
    struct Struct_020d4848* ctx = (struct Struct_020d4848*)func_020d41d8();
    int state = func_020d41e8();
    if (state != 0) {
        return state;
    }
    if (src == NULL) {
        return 6;
    }
    InvalidateDataCacheRange((const void*)((int)ctx->buffer), 0x7d0);
    func_020ca4b4(ctx->buffer, src, 0x7d0);
    return 0;
}
