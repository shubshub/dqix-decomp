#include <globaldefs.h>

extern "C" void func_020d1c24(unsigned int* table, unsigned int arg1);
extern "C" unsigned int func_020d1cf0(const unsigned int* table, const unsigned char* data, unsigned int len);

// USA: func_ov031_02211720
extern "C" ARM unsigned int func_ov031_02211720(const unsigned char* data) {
	unsigned int table[0x100];
	func_020d1c24(table, 0xedb88320);
	return func_020d1cf0(table, data, 0x3c);
}
