#include <globaldefs.h>

struct Struct_ov031_0224e5e8_7 {
	char pad[8];
	void *field8;
};
extern struct Struct_ov031_0224e5e8_7 data_ov031_0224e5e8;

extern "C" void* VectorizedMemset(void *dst, int val, int n);
extern "C" void* VectorizedInvertedMemcpy(void *dst, void *src, int n);

// USA: func_ov031_02216b00
extern "C" ARM void func_ov031_02216b00(int *arg) {
	if (data_ov031_0224e5e8.field8 == 0) {
		VectorizedMemset(arg, 0, 0x1c4);
	}
	VectorizedInvertedMemcpy((char*)data_ov031_0224e5e8.field8 + 0x1008, arg, 0x1c4);
	int v = *arg;
	if (v < 20000 || v >= 30000) {
		*arg = 0x5206;
	}
	v = *arg;
	if (v >= 20100) {
		*arg = -v;
	}
}
