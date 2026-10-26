#include <globaldefs.h>

unsigned int DisableSpecificInterrupts(unsigned int mask);
unsigned int EnableSpecificInterrupts(unsigned int mask);

struct Struct_ov031_0223d8a0 { Struct_ov031_0223d8a0* next; Struct_ov031_0223d8a0* prev; };

// USA: func_ov031_0223d8a0
extern "C" ARM void func_ov031_0223d8a0(Struct_ov031_0223d8a0* p) {
	unsigned int old = DisableSpecificInterrupts(1);
	p->next->prev = p->prev;
	p->prev->next = p->next;
	p->prev = NULL;
	p->next = NULL;
	EnableSpecificInterrupts(old);
}
