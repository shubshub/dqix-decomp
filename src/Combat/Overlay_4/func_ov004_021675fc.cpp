#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void func_ov004_02166bd8(void* a1);
extern "C" int func_ov004_021666bc(void* a1, int* out);
extern "C" void* func_ov004_02165e70(void* a, int key);
struct Struct_0208becc;
extern "C" void func_0208becc(struct Struct_0208becc* obj, int value, unsigned char b);

// USA: func_ov004_021675fc
extern "C" ARM int func_ov004_021675fc(void* a) {
    int local;
    func_ov004_02166bd8(a);
    int ret = func_ov004_021666bc(a, &local);
    unsigned char byteVal = *(unsigned char*)&local;
    void* node = func_ov004_02165e70(a, 7);
    if (node) {
        func_0208becc((struct Struct_0208becc*)((char*)node + 0x34), ret, byteVal);
    }
    return 0;
}
