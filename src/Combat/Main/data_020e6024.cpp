#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct Struct_02108d5c;
extern "C" void func_020709b4(struct Struct_02108d5c* obj);

extern struct Struct_02108d5c data_02108d5c;

// USA: func_020e6024
extern "C" __declspec(initcode) ARM void __sinit_020e6024(void) {
    func_020709b4(&data_02108d5c);
}
