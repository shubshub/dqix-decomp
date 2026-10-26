#include <globaldefs.h>

extern unsigned char data_ov031_02290c5c;
extern unsigned short data_ov031_02248e12[];
extern unsigned short data_ov031_02248e16[];
extern unsigned short data_ov031_02248e14[];
extern unsigned short data_ov031_02248e18[];

extern "C" int FastIntModulus(int arg0, int arg1);
extern "C" int func_ov031_02236878(int index);
extern "C" void func_ov031_022237dc(unsigned short, unsigned short, unsigned short, unsigned short);

// USA: func_ov031_022296b8
extern "C" ARM void func_ov031_022296b8(int mode) {
	if (mode == 1) {
		int rem = FastIntModulus(data_ov031_02290c5c + 2, 3);
		data_ov031_02290c5c = (unsigned char)rem;
	} else {
		int rem = FastIntModulus(data_ov031_02290c5c + 1, 3);
		data_ov031_02290c5c = (unsigned char)rem;
	}
	func_ov031_02236878(8);
	int off = data_ov031_02290c5c << 3;
	unsigned short a = *(unsigned short*)((char*)data_ov031_02248e12 + off);
	unsigned short b = *(unsigned short*)((char*)data_ov031_02248e16 + off);
	unsigned short c = *(unsigned short*)((char*)data_ov031_02248e14 + off);
	unsigned short d = *(unsigned short*)((char*)data_ov031_02248e18 + off);
	func_ov031_022237dc(a, b, c, d);
}
