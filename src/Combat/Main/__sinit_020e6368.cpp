#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020f1708[8];
extern float data_02109bcc[8];

extern "C" void func_0209cdf8(void*);
struct Struct_0209cbb8;
extern "C" void func_0209ce00(Struct_0209cbb8*);
extern "C" ARM void func_0209cdfc(void);
extern "C" void __register_global_object(void* arg0, void* arg1, void* arg2);

extern int g_bgmPlayer;
extern int data_02109be8;
extern int data_02109be0;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020e6368
extern "C" __declspec(initcode) ARM void __sinit_020e6368(void) {
    float var0;
    float var1;
    data_02109bcc[1] = data_020f1708[0] + (data_020f1708[1] + (data_020f1708[2] + data_020f1708[3]));
    t = data_02109bcc[0] + data_020f1708[2];
    a = data_020f1708[3];
    data_02109bcc[4] = t;
    t = t + a;
    data_02109bcc[3] = t;
    t = t + data_020f1708[1];
    data_02109bcc[2] = t;
    BlankFunction0209cdf8(&g_bgmPlayer);
    __register_global_object(&g_bgmPlayer, (void*)BlankFunction0209cdfc, &data_02109be8);
    ResetWordListReturnSelf0209ce00((WordList0209cbb8*)&data_02109be0);
}
