#include <globaldefs.h>

extern unsigned char data_ov031_02248998[];
extern int* data_ov031_02250bf0;

extern "C" void func_ov031_022238cc(void);
extern "C" int func_ov031_0223be70(int a, int b, int c);
extern "C" void func_ov031_0223bbd8(void* obj, int idx, int a, int b);

struct Struct_ov031_02222ce4 { unsigned char pad0[8]; void* list; unsigned char count; };
extern "C" void func_ov031_0223bcc8(Struct_ov031_02222ce4* obj, int idx, int val);

// USA: func_ov031_02223720
extern "C" ARM void func_ov031_02223720(int group, int b, int c, int d) {
	func_ov031_022238cc();
	unsigned char* p = &data_ov031_02248998[group * 2];
	int i = 0;
	int zero = 0;
	int var3 = 1;
	int var4 = -1;
	int var5 = var3;
	do {
		int val = func_ov031_0223be70(zero, *p++, var3);
		data_ov031_02250bf0[i] = val;
		func_ov031_0223bcc8((Struct_ov031_02222ce4*)data_ov031_02250bf0[i], var4, var5);
		i++;
	} while (i < 2);
	func_ov031_0223bbd8((void*)data_ov031_02250bf0[0], -1, b, d);
	func_ov031_0223bbd8((void*)data_ov031_02250bf0[1], -1, c, d);
}
