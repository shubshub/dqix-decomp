#if defined(jpn)
#define R(j,u) (j)
#define func_ov023_021f66f4 func_ov023_021f66bc
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov004_0215e47c(void* a, int key);
extern "C" void func_ov023_021fcc68(void* node, void* a);
#if defined(jpn)
#define func_ov023_021f66f4 func_ov023_021f66bc
extern "C" void func_ov023_021f66f4(void* a, int key, void* arg2);
#else
extern "C" void func_ov023_021f66f4(void* a, int key, void* arg2);
#endif

// USA: func_ov004_02162acc
extern "C" ARM int func_ov004_02162acc(void* a) {
    void* node = func_ov004_0215e47c(a, 0x82);
    if (node != NULL) {
        func_ov023_021fcc68(node, a);
        func_ov023_021f66f4(a, 0x86, (void*)1);
    }
    return 0;
}
