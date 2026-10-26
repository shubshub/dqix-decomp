#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct Struct_ov031_0224e540_3 {
	int pad[10]; /* 0x0-0x24 */
	int field28;
};
extern Struct_ov031_0224e540_3 data_ov031_0224e540;

// USA: func_ov031_0220f0e4
extern "C" ARM void func_ov031_0220f0e4(int v) {
	unsigned int mask = DisableIRQInterrupts();
	data_ov031_0224e540.field28 = v;
	SetIRQInterruptState(mask);
}
