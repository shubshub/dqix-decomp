#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long arg0, unsigned int arg1, unsigned int flag);
extern "C" int func_ov031_02214afc(unsigned int);
extern "C" int func_ov031_02214fc8(void* obj, int mode);
extern "C" int func_ov031_022151b0(void*, void*, int, int);

extern int data_ov031_02245fb0;

struct Struct_ov031_02214ea8 { unsigned char lo : 4; unsigned char hi : 4; };

// USA: func_ov031_02214ea8
extern "C" ARM int func_ov031_02214ea8(char* obj) {
	unsigned long long diff = GetCurrentTimestamp() - *(unsigned long long*)(obj + 0xcb0);
	unsigned long long var1 = _ll_udiv(diff << 6, 0x82ea, 0);
	if (var1 < 150) {
		unsigned char idx = obj[0xd0f];
		char* row = obj + idx * 0x24;
		Struct_ov031_02214ea8* var4 = (Struct_ov031_02214ea8*)(row + 0x300);
		if (var4->lo != 1) goto ret5;
	}

	{
		unsigned char var5 = obj[0xd0f];
		char* base2 = obj + 0x300;
		unsigned char v2 = base2[var5 * 0x24];
		v2 &= ~0xf;
		base2[var5 * 0x24] = v2;
	}
	int idx = *(unsigned char*)(obj + 0xd0f) + 1;
	obj[0xd0f] = idx;
	if (*(unsigned char*)(obj + 0xd10) <= (unsigned char)idx) {
		*(unsigned char*)(obj + 0xd15) = *(unsigned char*)(obj + 0xd15) + 1;
		obj[0xd0f] = 0;
		obj[0xd11] = (unsigned char)func_ov031_02214afc(*(unsigned char*)(obj + 0xd15));
	}

	if (*(signed char*)(obj + 0xd11) < 0) {
		obj[0xd15] = 0;
		return func_ov031_02214fc8(obj, 5);
	}

	*(unsigned long long*)(obj + 0xcb0) = GetCurrentTimestamp();
	idx = *(unsigned char*)(obj + 0xd0f);
	func_ov031_022151b0(&data_ov031_02245fb0, obj + 0x304 + idx * 0x24, *(signed char*)(obj + 0xd11), 0x300000);
ret5:
	return 5;
}
