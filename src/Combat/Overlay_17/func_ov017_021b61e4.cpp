#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_02046e08;
extern "C" void func_02046e08(struct Struct_02046e08* obj);

struct Struct_ov017_021b61e4 {
	unsigned char byte0;
	unsigned char pad1[0xfb];
	unsigned char unknown_fc_;
	unsigned char unknown_fd_;
	unsigned short unknown_fe_;
	unsigned short unknown_100_;
};

// USA: func_ov017_021b61e4
extern "C" ARM void func_ov017_021b61e4(struct Struct_ov017_021b61e4* p) {
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 0x16;
	func_02046e08((struct Struct_02046e08*)((char*)p + 0xc));
	p->unknown_fc_ = 0;
	p->unknown_fe_ = 0;
	p->unknown_100_ = 0;
	p->unknown_fd_ = 0;
}
