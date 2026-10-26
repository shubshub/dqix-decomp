#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" int func_ov031_0223be70(int a, int b, int c);
extern unsigned char data_ov031_02248940[];
extern unsigned char data_ov031_02248924[];
extern void* data_ov031_02250ba8;
extern "C" void func_ov031_02222eb0(void*);
extern "C" void func_ov031_02222f44(void*);
extern "C" ARM void* func_ov031_0223e218(void* a, void* b, void* c, int d);

struct Struct_ov031_02222ce4;
extern "C" void func_ov031_0223bcc8(Struct_ov031_02222ce4* obj, int idx, int val);

// USA: func_ov031_02222ce4
extern "C" ARM void func_ov031_02222ce4(int key) {
	int count = data_ov031_02248940[key];

	void* obj = func_ov031_0223cf4c(0x1c, 4);
	data_ov031_02250ba8 = obj;
	int var2 = -2;
	((signed char*)obj)[0x16] = (signed char)var2;
	((unsigned char*)data_ov031_02250ba8)[0x17] = (unsigned char)key;

	int i = 0;
	if (count > 0) {
		unsigned char* p = data_ov031_02248924 + key * 2;
		int one = 1;
		do {
			unsigned char b = *p++;
			int r = func_ov031_0223be70(0, b, one);
			((int*)data_ov031_02250ba8)[i] = r;
			func_ov031_0223bcc8((Struct_ov031_02222ce4*)((int*)data_ov031_02250ba8)[i], var2 + 1, one);
			i++;
		} while (i < count);
	}

	int r2 = func_ov031_0223be70(0, 1, 1);
	((int*)data_ov031_02250ba8)[2] = r2;
	func_ov031_0223bcc8((Struct_ov031_02222ce4*)((int*)data_ov031_02250ba8)[2], var2 + 1, 1);

	func_ov031_02222eb0((void*)0xc0);

	void* res = func_ov031_0223e218((void*)0, (void*)func_ov031_02222f44, (void*)0, 0x78);
	((int*)data_ov031_02250ba8)[3] = (int)res;
}
