#include <globaldefs.h>

extern "C" THUMB int func_ov031_0221e27c(void* ctx);

// USA: func_ov031_0221e250
extern "C" THUMB void func_ov031_0221e250(void* ctx, unsigned char* dst, unsigned char* src, unsigned int count) {
    unsigned int i = 0;
    if (count != 0) {
        do {
            unsigned char k = (unsigned char)func_ov031_0221e27c(ctx);
            dst[i] = src[i] ^ k;
            i++;
        } while (i < count);
    }
}
