#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct Struct_020401e4;
extern "C" void func_020404ac(struct Struct_020401e4* obj);

extern struct Struct_020401e4 data_021077dc;

// USA: func_020e5ce8
extern "C" __declspec(initcode) ARM void __sinit_020e5ce8(void) {
    func_020404ac(&data_021077dc);
}
