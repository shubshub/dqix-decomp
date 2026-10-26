#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

// USA: func_ov017_021c16a8
extern "C" ARM void func_ov017_021c16a8(unsigned char* self) {
	func_0204693c((struct ByteHeader0204693c*)self);
	self[0] = 0x30;
	self[8] = 0;
	self[9] = 0;
}
