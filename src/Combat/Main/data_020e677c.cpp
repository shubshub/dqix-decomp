#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct SafeAllocator;
extern "C" void func_020dbc48(struct SafeAllocator* obj);

extern struct SafeAllocator data_0214e4c8;

// USA: func_020e677c
extern "C" __declspec(initcode) ARM void __sinit_020e677c(void) {
    func_020dbc48(&data_0214e4c8);
}
