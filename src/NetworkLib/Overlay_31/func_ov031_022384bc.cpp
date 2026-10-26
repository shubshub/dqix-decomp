#include <globaldefs.h>

struct Struct_ov031_022384bc {
	unsigned char pad[0x1d];
	unsigned char unknown_1d_;
};

extern struct Struct_ov031_022384bc* data_ov031_02290d10;

extern "C" void func_ov031_0223e2b8(int, int);
extern "C" void func_ov031_022384f8(void);

// USA: func_ov031_022384bc
extern "C" ARM void func_ov031_022384bc(int a) {
	data_ov031_02290d10->unknown_1d_++;
	if (data_ov031_02290d10->unknown_1d_ < 8) return;
	func_ov031_0223e2b8(a, (int)func_ov031_022384f8);
}
