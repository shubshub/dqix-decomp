#include <globaldefs.h>

extern "C" void func_020c9b10(void* buf);
extern "C" void func_ov031_02209e28(void* data, int len);
extern "C" ARM int func_ov031_02211848(void);

struct Struct_ov031_02211138 {
	int field0;
	unsigned char pad4[0xc];
	int field10;
	unsigned char unknown_14_[0x1c];
	int unknown_30_;
	int field34;
	int field38;
	unsigned char unknown_3c_[0x4];
	void (*field40)(void*, void*, int);
	int field44;
};

extern Struct_ov031_02211138* data_ov031_0224e590;

// USA: func_ov031_02211138
extern "C" ARM void func_ov031_02211138(void) {
	unsigned int buf[0x20 / 4];
	func_020c9b10(buf);
	func_ov031_02209e28(buf, 0x20);
	if (func_ov031_02211848()) return;

	Struct_ov031_02211138* obj = data_ov031_0224e590;
	if (obj == NULL) return;
	if (obj->field0 != 2) return;
	if (obj->field10 == 0 || obj->unknown_30_ == 0) return;

	obj->field10 = 0;
	data_ov031_0224e590->unknown_30_ = 0;
	obj = data_ov031_0224e590;
	void (*fn)(void*, void*, int) = obj->field40;
	if (fn == NULL) return;
	fn((void*)obj->field34, (void*)obj->field38, obj->field44);
}
