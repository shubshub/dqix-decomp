#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct SafeAllocator;
extern "C" void func_020466d0(struct SafeAllocator* alloc);

extern struct SafeAllocator data_ov031_02291e3c;

// USA: func_ov031_02249650
extern "C" __declspec(initcode) ARM void __sinit_ov031_02249650(void) {
    func_020466d0(&data_ov031_02291e3c);
}
