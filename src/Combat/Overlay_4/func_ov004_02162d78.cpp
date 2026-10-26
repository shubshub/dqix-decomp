#include <globaldefs.h>

extern "C" void func_ov023_021f66bc(void* a, int key, void* arg2);
extern "C" void* func_ov004_0215e47c(void* a, int key);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_02017d68(void* obj);

// USA: func_ov004_02162d78
extern "C" ARM int func_ov004_02162d78(void* a) {
    func_ov023_021f66bc(a, 0x83, (void*)1);
    for (int i = 0; i < 9; i++) {
        unsigned char* node = (unsigned char*)func_ov004_0215e47c(a, 0x83 + i);
        if (node != NULL) node[0xc] &= ~0x20;
    }
    func_ov011_021848a0(a, 0x69);
    func_02017d68(Zone3D_GetInstance());
    return 0;
}
