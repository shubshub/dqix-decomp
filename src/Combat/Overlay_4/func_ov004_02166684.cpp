#include <globaldefs.h>

extern "C" void* func_ov023_021f6524(int a, int b);
extern "C" int func_ov023_021f9bc8(void);

// USA: func_ov004_02166684
extern "C" ARM short func_ov004_02166684(int a) {
	short field = 0;
	void* p = func_ov023_021f6524(a, 0x5b);
	if (p != NULL) {
		field = *(short*)((char*)p + 0x5c);
	}
	short b = (short)func_ov023_021f9bc8();
	short var3 = field * 8;
	return var3 + b;
}
