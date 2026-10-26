#include <globaldefs.h>

extern "C" void (* volatile data_ov031_02290fc8)(void*);

extern "C" void func_ov031_02240e1c(void*);

struct Struct_ov031_02240e70 {
	char pad[0x800];
	void* unknown_800_;
};

struct Struct_ov031_02240e70_2 {
	char pad20[0x20];
	Struct_ov031_02240e70* field20;
	void* field24;
	char unknown_28_[0x34 - 0x28];
	void* field34;
	void* field38;
};

// USA: func_ov031_02240e70
extern "C" ARM int func_ov031_02240e70(Struct_ov031_02240e70_2* obj) {
	func_ov031_02240e1c(obj->field34);
	func_ov031_02240e1c(obj->field38);

	if (obj->field20) {
		if (obj->field20->unknown_800_)
			data_ov031_02290fc8(obj->field20->unknown_800_);
		data_ov031_02290fc8(obj->field20);
	}
	data_ov031_02290fc8(obj->field24);
	data_ov031_02290fc8(obj);
	return 1;
}
