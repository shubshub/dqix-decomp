#include <globaldefs.h>

extern "C" void func_ov031_02211864(int a, int b);

struct Struct_ov031_02211440 {
	int field0;
	void* field4;
	char pad[0x34];
	void (*field3c)(void*);
};

extern Struct_ov031_02211440* data_ov031_0224e590;

// USA: func_ov031_02211440
extern "C" ARM void func_ov031_02211440(void* value) {
	if (data_ov031_0224e590 == NULL) return;
	data_ov031_0224e590->field4 = value;
	void (*fn)(void*) = data_ov031_0224e590->field3c;
	if (fn != NULL) {
		fn(value);
	} else {
		func_ov031_02211864(9, 9 - 0xb);
	}
}
