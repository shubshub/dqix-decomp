#include <globaldefs.h>
extern "C" void* VectorizedInvertedMemcpy(void *dst, void *src, int n);
extern char data_ov031_0224e6ac[0xe];
// USA: func_ov031_0221b140
extern "C" ARM void* func_ov031_0221b140(void *dst) {
    return VectorizedInvertedMemcpy(dst, data_ov031_0224e6ac, 0xe);
}
