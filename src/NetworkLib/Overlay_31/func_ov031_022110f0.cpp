#include <globaldefs.h>

extern "C" void func_ov031_02211864(int a, int b);
extern "C" int func_ov031_022113c0(void*);

struct Struct_ov031_022110f0 {
	char pad[0x3c];
	void (*field3c)(void*);
};

extern Struct_ov031_022110f0* data_ov031_0224e590;

// USA: func_ov031_022110f0
extern "C" ARM void func_ov031_022110f0(void (*callback)(void*)) {
	if (data_ov031_0224e590 != NULL && func_ov031_022113c0(data_ov031_0224e590) == 0) {
		goto store;
	}
	func_ov031_02211864(9, 9 - 0xb);
	return;
store:
	data_ov031_0224e590->field3c = callback;
}
