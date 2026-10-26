#include <globaldefs.h>

struct Struct_0208becc;
extern "C" void* func_ov004_02165e70(void* a, int key);
extern "C" void func_0208becc(struct Struct_0208becc* obj, int value, unsigned char b);

// USA: func_ov004_02167648
extern "C" ARM int func_ov004_02167648(void* a) {
    void* node = func_ov004_02165e70(a, 7);
    if (node) {
        func_0208becc((struct Struct_0208becc*)((char*)node + 0x34), 0x270f, 0);
    }
    return 0;
}
