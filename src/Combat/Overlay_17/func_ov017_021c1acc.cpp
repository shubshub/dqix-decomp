#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

// USA: func_ov017_021c1acc
extern "C" ARM void func_ov017_021c1acc(unsigned char* self) {
	func_0204693c((struct ByteHeader0204693c*)self);
	self[0] = 0x37;
	*(int*)(self + 8) = 0;
	*(int*)(self + 0xc) = 0;
}
