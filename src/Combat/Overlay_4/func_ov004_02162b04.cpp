#include <globaldefs.h>

extern "C" void* func_ov004_0215e47c(void* a, int key);
extern "C" void func_ov023_021fccec(void* node, void* a);
extern "C" void func_ov023_021f66bc(void* a, int key, void* arg2);

// USA: func_ov004_02162b04
extern "C" ARM int func_ov004_02162b04(void* a) {
    void* node = func_ov004_0215e47c(a, 0x82);
    if (node != NULL) {
        func_ov023_021fccec(node, a);
        func_ov023_021f66bc(a, 0x87, (void*)1);
    }
    return 0;
}
