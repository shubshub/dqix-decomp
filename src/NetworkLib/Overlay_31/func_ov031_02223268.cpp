#include <globaldefs.h>

struct Struct_ov031_022269d8;
struct Struct_ov031_02223268_2;
struct Struct_ov031_02222ce4;

struct Struct_ov031_02223268 {
	Struct_ov031_022269d8* item[4];
	void* unknown_10_;
	unsigned short field14;
	signed char unknown_16_;
	unsigned char type;
};
extern Struct_ov031_02223268* data_ov031_02250ba8;
extern unsigned char data_ov031_02248940[];
extern unsigned char data_ov031_02248924[][2];

extern "C" Struct_ov031_02223268_2* func_ov031_0223baa0(Struct_ov031_022269d8* obj, int idx);
extern "C" void func_ov031_0223bdb0(int a, int b, void* c);
extern "C" ARM void func_ov031_0223bcc8(Struct_ov031_02222ce4* obj, int idx, int val);
extern "C" ARM void func_ov031_02222eb0(void* obj);
extern "C" ARM void func_ov031_0223e2c0(int a, int b);

// USA: func_ov031_02223268
extern "C" ARM void func_ov031_02223268(int param) {
	data_ov031_02250ba8->field14++;
	if (data_ov031_02250ba8->field14 < 16) return;
	int count = data_ov031_02248940[data_ov031_02250ba8->type];
	int i = 0;
	if (count > 0) {
		do {
			unsigned char v = data_ov031_02248924[data_ov031_02250ba8->type][i];
			Struct_ov031_02223268_2* elem = func_ov031_0223baa0(data_ov031_02250ba8->item[i], 0);
			func_ov031_0223bdb0(0, v, elem);
			func_ov031_0223bcc8((Struct_ov031_02222ce4*)data_ov031_02250ba8->item[i], -1, 1);
			i++;
		} while (i < count);
	}
	func_ov031_02222eb0((void*)0xa8);
	data_ov031_02250ba8->field14 = 0;
	data_ov031_02250ba8->unknown_16_ = -1;
	if (data_ov031_02250ba8->unknown_10_) {
		data_ov031_02250ba8->unknown_10_ = 0;
		func_ov031_0223e2c0(0, param);
	}
}
