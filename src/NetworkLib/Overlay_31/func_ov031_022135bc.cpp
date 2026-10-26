#include <globaldefs.h>

struct Struct_ov031_0224e5c4_9 {
	unsigned int field0;
	unsigned int field4;
	unsigned int field8;
	void* fieldc;
	unsigned int field10;
};

extern Struct_ov031_0224e5c4_9 data_ov031_0224e5c4;

extern "C" void func_ov031_02213270(unsigned int mask, int a1, int a2);

// USA: func_ov031_022135bc
extern "C" ARM void func_ov031_022135bc(void) {
	func_ov031_02213270(8, data_ov031_0224e5c4.field8, 0xc);
	func_ov031_02213270(0x10, data_ov031_0224e5c4.field10, 0xd18);
}
