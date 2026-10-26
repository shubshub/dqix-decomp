#include <globaldefs.h>

int DisableIRQInterrupts(void);
void SetIRQInterruptState(int mask);
extern "C" void func_ov031_0220da1c(int);

struct Struct_ov031_0220cf6c {
	char pad[0x2260];
	int state;
	char pad2[0x2280 - 0x2264];
	short unknown_2280_;
};
extern Struct_ov031_0220cf6c* data_ov031_0224e53c;

// USA: func_ov031_0220cf6c
extern "C" ARM int func_ov031_0220cf6c(void) {
	int mask = DisableIRQInterrupts();
	Struct_ov031_0220cf6c* base = data_ov031_0224e53c;
	if (base == 0) {
		SetIRQInterruptState(mask);
		return 1;
	}

	switch (base->state) {
		case 6:
			func_ov031_0220da1c(7);
			data_ov031_0224e53c->unknown_2280_ = 4;
			goto epilogue3;
		case 7:
			SetIRQInterruptState(mask);
			return 2;
		case 3:
			SetIRQInterruptState(mask);
			return 0;
		default:
			SetIRQInterruptState(mask);
			return 1;
	}
epilogue3:
	SetIRQInterruptState(mask);
	return 3;
}
