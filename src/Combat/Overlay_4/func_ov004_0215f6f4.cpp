#include <globaldefs.h>

extern "C" void* func_ov004_0215e4c0(void* a, int key);
struct Struct_ov004_0215f6f4;
extern "C" void func_ov023_021f8944(struct Struct_ov004_0215f6f4* obj, int a1, int a2, int a3);

// USA: func_ov004_0215f6f4
extern "C" ARM void func_ov004_0215f6f4(void* a, short v1, short v2, int flag) {
    void* node = func_ov004_0215e4c0(a, 3);
    if (node == NULL) return;
    *(short*)((char*)node + 0x104) = v1;
    *(short*)((char*)node + 0x106) = v2;
    int a2 = 0;
    unsigned char var2 = 0xf;
    if (flag != 0) {
        var2 = 3;
        a2 = 1;
    }
    *(unsigned char*)((char*)node + 0x10a) = var2;
    func_ov023_021f8944((struct Struct_ov004_0215f6f4*)node, (int)(long)a, a2, 0);
}
