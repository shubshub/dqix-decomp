#include <globaldefs.h>

extern "C" void* func_020d41d8(void);
extern "C" int func_020d41e8(void);
extern "C" void InvalidateDataCacheRange(const void* addr, unsigned int size);

struct Struct_020d4ac8 {
    unsigned char pad0[4];
    void* sub;
};

// USA: func_020d4ac8
extern "C" ARM int func_020d4ac8(void) {
    struct Struct_020d4ac8* ctx = (struct Struct_020d4ac8*)func_020d41d8();
    if (func_020d41e8() != 0) return 0;

    InvalidateDataCacheRange((const void*)ctx->sub, 2);
    unsigned short code = *(unsigned short*)ctx->sub;

    if (code != 9) {
        if (code != 10 && code != 11) goto return_zero;
    } else {
        InvalidateDataCacheRange((const void*)((char*)ctx->sub + 0x182), 2);
        if (*(unsigned short*)((char*)ctx->sub + 0x182) == 0) return 0;
    }

    InvalidateDataCacheRange((const void*)((char*)ctx->sub + 0xbc), 2);
    return *(unsigned short*)((char*)ctx->sub + 0xbc);
return_zero:
    return 0;
}
