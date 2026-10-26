#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void __register_global_object(void* obj, void* func, void* node);
extern "C" void* LinkSession_Construct(void* obj);
extern "C" ARM void* func_0202c7a8(void* obj);
extern "C" ARM void* LinkMessageQueue_Construct(void* obj);
extern "C" ARM void* func_0202c814(void* obj);

extern int data_020fefec;
extern int data_020fefe0;
extern int data_02100044;
extern int data_020fefd4;

// USA: func_020e5b28
extern "C" __declspec(initcode) ARM void __sinit_020e5b28(void) {
    LinkSession_Construct(&data_020fefec);
    __register_global_object(&data_020fefec, (void*)func_0202c7a8, &data_020fefe0);
    LinkMessageQueue_Construct(&data_02100044);
    __register_global_object(&data_02100044, (void*)func_0202c814, &data_020fefd4);
}
