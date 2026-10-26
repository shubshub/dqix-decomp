#include <globaldefs.h>

extern "C" int func_ov031_02204c84(int a);
unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);

struct Struct_ov031_0224c9e0_2 {
	unsigned int unknown_0_;
	unsigned int w1;
};
extern struct Struct_ov031_0224c9e0_2 data_ov031_0224c9e0;

// USA: func_ov031_02206ebc
extern "C" ARM int func_ov031_02206ebc(int a) {
	unsigned int state = DisableIRQInterrupts();
	unsigned int var1 = data_ov031_0224c9e0.unknown_0_;
	unsigned int w1 = data_ov031_0224c9e0.w1;
	data_ov031_0224c9e0.unknown_0_ = 0;
	data_ov031_0224c9e0.w1 = 0;
	int result = func_ov031_02204c84(a);
	data_ov031_0224c9e0.unknown_0_ = var1;
	data_ov031_0224c9e0.w1 = w1;
	SetIRQInterruptState(state);
	return result;
}
