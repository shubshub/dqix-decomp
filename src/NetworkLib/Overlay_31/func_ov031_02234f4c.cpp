#include <globaldefs.h>

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

extern "C" int func_020ca3b8(int, int, int);
extern unsigned char* data_ov031_02290ce8;

// USA: func_ov031_02234f4c
extern "C" ARM void func_ov031_02234f4c(void* a, int offset, int c, int count) {
	int cnt = count;
	void* obj = a;
	unsigned char* dst = data_ov031_02290ce8 + 4 + (offset << 1);
	int i = 0;
	if (cnt <= 0) return;
	int c2 = c << 1;
	do {
		func_020ca3b8((int)obj, (int)dst, c2);
		i++;
		obj = (char*)obj + 0x40;
		dst += 0x40;
	} while (i < cnt);
}
