#include <globaldefs.h>

extern "C" unsigned char* func_ov031_022133f8(int flags);
extern "C" unsigned int func_ov031_022135ac(unsigned int x);

// USA: func_ov031_02213450
extern "C" ARM void func_ov031_02213450(unsigned char v) {
	unsigned char *p1, *p2;
	p1 = func_ov031_022133f8(1);
	p2 = func_ov031_022133f8(0x10);
	p1[9] = v;
	if (v >= 0x10) return;
	unsigned char old = p1[0x16];
	if (v > old) {
		p1[0x16] = v;
		if (v > 7) {
			p1[0x15] = (unsigned char)func_ov031_022135ac(p2[0xd0d]);
			unsigned char idx2 = p2[0xd13];
			unsigned char* q = p2 + (idx2 << 2);
			p1[0x14] = q[0x444];
		}
	}
}
