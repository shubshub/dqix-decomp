#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

struct Struct_ov031_022035e0 {
	unsigned char pad[0x8];
	unsigned char field8;
	unsigned char pad2[0x33];
	int field3c;
	void* field40;
	int field44;
};

extern "C" void* memmove(void*, const void*, unsigned int);
extern "C" int func_ov031_02201f84(int, int);

// USA: func_ov031_022035e0
extern "C" ARM void func_ov031_022035e0(int amount, Struct_ov031_022035e0* obj) {
	int state = DisableIRQInterrupts();
	int end = obj->field44;
	int limit = obj->field3c;
	int flag = 0;
	if (end == limit) {
		if (amount != 0) flag = 1;
	}
	if ((unsigned int)amount >= (unsigned int)end) {
		obj->field44 = 0;
	} else {
		void* base = obj->field40;
		int rem = end - amount;
		obj->field44 = rem;
		memmove(base, (char*)base + amount, rem);
	}
	SetIRQInterruptState(state);
	if (obj->field8 == 10) return;
	if (obj->field8 == 11) return;
	if (obj->field44 != 0 && flag == 0) return;
	func_ov031_02201f84((int)obj, 0x1b);
}
