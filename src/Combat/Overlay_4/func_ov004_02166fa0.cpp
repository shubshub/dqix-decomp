#include <globaldefs.h>

extern "C" int func_ov004_021666bc(void* a1, int* out);
extern "C" void* func_ov004_02165e70(void* a, int key);
struct Struct_02065990_2;
extern "C" void func_0208bf28(struct Struct_02065990_2* obj, int value, unsigned char b);

// USA: func_ov004_02166fa0
extern "C" ARM int func_ov004_02166fa0(void* a1) {
    int local;
    int key = func_ov004_021666bc(a1, &local);
    unsigned char b = *(unsigned char*)&local;

    void* node = func_ov004_02165e70(a1, 7);
    if (node) {
        func_0208bf28((struct Struct_02065990_2*)((char*)node + 0x34), key, b);
    }
    return 0;
}
