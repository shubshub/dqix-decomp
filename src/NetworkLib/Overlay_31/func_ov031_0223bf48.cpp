#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"


extern "C" int FastIntModulus(int, int);
extern "C" void HaltSystem(void);

struct Struct_ov031_0223bf48 {
	unsigned short field0;
	unsigned char field2;
	unsigned char volatile unknown_3_;
	int arr[64];
};

// USA: func_ov031_0223bf48
extern "C" ARM void func_ov031_0223bf48(struct Struct_ov031_0223bf48* p, int value) {
	unsigned int state = DisableSpecificInterrupts(1);
	int rem = FastIntModulus(p->unknown_3_ + 1, p->field0);
	if (rem == p->field2) {
		HaltSystem();
	}
	p->arr[p->unknown_3_] = value;
	p->unknown_3_ = rem;
	EnableSpecificInterrupts(state);
}
