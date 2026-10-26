#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct func_0207d7c0;
struct Struct_0207d798;
extern "C" ARM void* func_0207ddf0(Struct_0207d798*);
extern "C" ARM void* func_0207de1c(Struct_0207d798*);

extern "C" void __register_global_object(int c, int b, void* node);

extern func_0207d7c0 data_02108ea8;
extern int data_02108e9c;

// USA: func_020e6260
extern "C" __declspec(initcode) ARM void __sinit_020e6260(void) {
    func_0207ddf0((Struct_0207d798*)&data_02108ea8);
    __register_global_object((int)&data_02108ea8, (int)func_0207de1c, &data_02108e9c);
}
