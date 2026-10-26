#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void func_0205ec2c(void* obj);
extern "C" void func_0205ec30(void* obj);
extern "C" void __register_global_object(int c, int b, void* node);

extern void* g_sePlayer;
extern void* data_02108754;

// USA: func_020e5ee0
extern "C" __declspec(initcode) ARM void __sinit_020e5ee0(void) {
    func_0205ec2c(&g_sePlayer);
    __register_global_object((int)&g_sePlayer, (int)func_0205ec30, &data_02108754);
}
