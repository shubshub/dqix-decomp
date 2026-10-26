#include <globaldefs.h>

struct Struct_ov027_021e33e0_18 {
	unsigned int field0;
	unsigned int field4;
	unsigned char* buf;
};

extern Struct_ov027_021e33e0_18 data_ov027_021e33e0;

// USA: func_ov027_021dd04c
extern "C" ARM int func_ov027_021dd04c() {
	unsigned char* p = data_ov027_021e33e0.buf;
	int a = (*(unsigned short*)(p + 0x12) != 0) ? 2 : 0;
	int b = (*(unsigned short*)(p + 0xe) != 0) ? 1 : 0;
	int c = (*(unsigned short*)(p + 0x14) != 0) ? 4 : 0;
	int d = (*(unsigned short*)(p + 0x16) != 0) ? 8 : 0;
	return (unsigned char)(b | a | c | d);
}
