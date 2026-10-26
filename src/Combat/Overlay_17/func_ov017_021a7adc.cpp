#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

// USA: func_ov017_021a7adc
extern "C" ARM void func_ov017_021a7adc(char* obj) {
	func_0204693c((ByteHeader0204693c*)obj);
	obj[0] = 0x40;
	*(int*)(obj+8) = 0;
	obj[0xc] = 1;
	obj[0xd] = 0;
	*(short*)(obj+0xe) = 0;
	*(short*)(obj+0x10) = 0;
	*(int*)(obj+0x14) = -1;
	obj[0x18] = 0;
	obj[0x19] = 0;
	obj[0x1a] = 0;
	*(short*)(obj+0x1c) = -1;
	obj[0x1b] = 0;
	*(int*)(obj+0x20) = 0;
	obj[0x1e] = 2;
}
