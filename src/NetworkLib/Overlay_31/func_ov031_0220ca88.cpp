#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

extern void* data_ov031_0224e53c;

// USA: func_ov031_0220ca88
extern "C" ARM int func_ov031_0220ca88(void) {
	unsigned int mask = DisableIRQInterrupts();
	void* base = data_ov031_0224e53c;
	if (base == 0) {
		SetIRQInterruptState(mask);
		return 1;
	}
	int status = *(int*)((char*)base + 0x2260);
	if (status != 1) {
		SetIRQInterruptState(mask);
		return 1;
	}
	data_ov031_0224e53c = 0;
	SetIRQInterruptState(mask);
	return 0;
}
