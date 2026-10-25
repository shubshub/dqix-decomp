#include <globaldefs.h>

void CallVTableFnAt240_021f66bc(void* a, int key, void* arg3);
extern "C" void* func_ov004_0215e47c(void* a, int key);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void* Zone3D_GetInstance(void);
void SetFlagBytes02017d68(void* obj);

// USA: func_ov004_02162d78
ARM int LoopClearBitndNotify_02162d78_02162d78(void* a) {
    CallVTableFnAt240_021f66bc(a, 0x83, (void*)1);
    for (int i = 0; i < 9; i++) {
        unsigned char* node = (unsigned char*)func_ov004_0215e47c(a, 0x83 + i);
        if (node != NULL) node[0xc] &= ~0x20;
    }
    func_ov011_021848a0(a, 0x69);
    SetFlagBytes02017d68(Zone3D_GetInstance());
    return 0;
}
