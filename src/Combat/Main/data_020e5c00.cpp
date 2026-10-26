#include <globaldefs.h>
#pragma define_section initcode ".init" RX

extern "C" void NumberPopups_Construct(void* obj);
class Container0203a54c;
extern "C" void func_0203a8d4(Container0203a54c* obj);

struct Struct_02104b60 {
    struct Struct_02104b60* next;
    int b;
    int c;
};

extern "C" void __register_global_object(int c, int b, struct Struct_02104b60* node);

extern int data_02104b6c;
extern struct Struct_02104b60 data_02104b60;

// USA: func_020e5c00
extern "C" __declspec(initcode) ARM void __sinit_020e5c00(void) {
    NumberPopups_Construct(&data_02104b6c);
    __register_global_object((int)&data_02104b6c, (int)func_0203a8d4, &data_02104b60);
}
