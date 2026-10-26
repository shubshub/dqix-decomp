#include <globaldefs.h>

struct Struct_ov031_02222eb0 {
	int arr[1];
	unsigned char pad[19];
	unsigned char type;
};
extern Struct_ov031_02222eb0* data_ov031_02250ba8;

extern "C" void func_ov031_0223bbd8(void* a, int b, int c, int d);
extern unsigned char data_ov031_02248940[];
extern unsigned char data_ov031_02248932[];
extern unsigned short data_ov031_0224891c[];

// USA: func_ov031_02222eb0
extern "C" ARM void func_ov031_02222eb0(void* obj) {
	Struct_ov031_02222eb0* p = data_ov031_02250ba8;
	int count = data_ov031_02248940[p->type];
	func_ov031_0223bbd8((void*)p->arr[2], -1, 0, (int)obj);
	int i = 0;
	if (count <= 0) return;
	int var3 = -1;
	do {
		p = data_ov031_02250ba8;
		void* item = (void*)((int*)p)[i];
		unsigned char var5 = p->type;
		unsigned char* row = data_ov031_02248932 + var5 * 2;
		unsigned char idx = row[i];
		unsigned short val = data_ov031_0224891c[idx * 2];
		func_ov031_0223bbd8(item, var3, val, (int)obj + 4);
		i++;
	} while (i < count);
}
