#include <globaldefs.h>

struct Struct_ov031_022183b4 {
	int a;
	int b;
};

typedef void (*Type_ov031_02218f18)(void*, int, int);

extern int data_ov031_02249fd8;
extern int data_ov031_02249ff4;

// USA: func_ov031_02218f18
extern "C" ARM void func_ov031_02218f18(void* obj, struct Struct_ov031_022183b4* arr, int count) {
	Type_ov031_02218f18 fn = *(Type_ov031_02218f18*)((char*)obj + 0x1014);
	int i = 0;
	if (count <= 0) return;

	void* p0 = &data_ov031_02249fd8;
	void* p1 = &data_ov031_02249ff4;
	do {
		int var4 = arr[i].a;
		if (var4 != 0) {
			fn(p0, var4, 0);
			arr[i].a = 0;
		}
		int var5 = arr[i].b;
		if (var5 != 0) {
			fn(p1, var5, 0);
			arr[i].b = 0;
		}
		i++;
	} while (i < count);
}
