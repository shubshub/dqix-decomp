#include <globaldefs.h>

extern "C" void func_ov031_0223b710(int);
extern "C" void func_ov031_0223bf48(int, void*);
extern int data_ov031_02290c40;

// USA: func_ov031_02227688
extern "C" ARM void func_ov031_02227688(void *a) {
    func_ov031_0223b710(*(int*)((char*)a + 8));
    int v = data_ov031_02290c40;
    func_ov031_0223bf48(*(int*)(v + 0x60), a);
}
