#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern int KeyTable_Construct;
extern int data_02153680;
extern int data_02153694;
struct SafeAllocator;
extern "C" unsigned int func_020466d0(SafeAllocator*);
extern "C" unsigned int __cxa_vec_ctor(unsigned int, unsigned int, unsigned int, unsigned int);

// USA: func_020e68f4
extern "C" __declspec(initcode) ARM unsigned int __sinit_020e68f4(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int var0[1];
    unsigned int var1 = 0;
    r0 = (unsigned int)&data_02153694;
    var1 = 0x0;
    r3 = (unsigned int)&KeyTable_Construct;
    r1 = 0x2;
    r2 = 0x18;
    *(unsigned int*)((char*)var0 + 0x0) = (unsigned int)var1;
    r0 = (unsigned int)__cxa_vec_ctor(r0, r1, r2, r3);
    r0 = (unsigned int)&data_02153680;
    r0 = (unsigned int)func_020466d0((SafeAllocator*)r0);
    return r0;
}
