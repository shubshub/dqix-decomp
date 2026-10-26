#include <globaldefs.h>
#pragma define_section initcode ".init" RX

struct Struct_020e5afc {
    struct Struct_020e5afc* next;
    int b;
    int c;
};

extern "C" char* OamManager_Construct(char* obj);
extern "C" char* func_0203c75c(char* obj);
extern "C" ARM void __register_global_object(int c, int b, struct Struct_020e5afc* node);

extern void* data_02105ab4;
extern void* data_02105248;

// USA: func_020e5c2c
extern "C" __declspec(initcode) ARM void __sinit_020e5c2c(void) {
    OamManager_Construct((char*)&data_02105ab4);
    __register_global_object((int)&data_02105ab4, (int)(void*)func_0203c75c, (struct Struct_020e5afc*)&data_02105248);
}
