#include <globaldefs.h>

extern "C" int func_020c7130(char*, const char*, ...);
extern char* data_ov031_02290cfc;
extern const char data_ov031_0224be50[];

// USA: func_ov031_02235f30
extern "C" ARM void func_ov031_02235f30(char* destination) {
	unsigned char b0 = data_ov031_02290cfc[0x4c0];
	unsigned char b1 = data_ov031_02290cfc[0x4c1];
	unsigned char b2 = data_ov031_02290cfc[0x4c2];
	unsigned char b3 = data_ov031_02290cfc[0x4c3];
	func_020c7130(destination, data_ov031_0224be50, b0, b1, b2, b3);
}
