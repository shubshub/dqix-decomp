#include <globaldefs.h>
#pragma define_section initcode ".init" RX

struct Struct_020e5afc {
    struct Struct_020e5afc* next;
    int b;
    int c;
};

extern "C" void* ZoneRecords_Construct(void* obj);
extern "C" void* func_02028d2c(void* obj);
extern "C" ARM void __register_global_object(int c, int b, struct Struct_020e5afc* node);

extern void* data_020fdd44;
extern void* data_020fdd38;

// USA: func_020e5afc
extern "C" __declspec(initcode) ARM void __sinit_020e5afc(void) {
    ZoneRecords_Construct(&data_020fdd44);
    __register_global_object((int)&data_020fdd44, (int)func_02028d2c, (struct Struct_020e5afc*)&data_020fdd38);
}
