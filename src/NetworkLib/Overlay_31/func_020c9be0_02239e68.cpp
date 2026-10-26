#include <globaldefs.h>


struct Struct_ov031_02239e68 {
	unsigned char pad0[0x40];
	int field40;
	unsigned char pad1[0x18];
	unsigned short unknown_5c_;
	unsigned char pad2[2];
	unsigned short field60;
};

typedef void (*Type_0201282c)(int, void*, unsigned short);

struct Struct_ov031_02290d18 {
	Type_0201282c field0;
	Struct_ov031_02239e68* field4;
};

extern Struct_ov031_02290d18 data_ov031_02290d18;
extern "C" ARM void HaltSystem(void);
extern "C" ARM void func_ov031_02239368(int v);
extern "C" ARM unsigned short func_ov031_02239ee0(unsigned short v);
extern void* data_ov031_0224c464;

// USA: func_ov031_02239e68
extern "C" ARM unsigned short func_ov031_02239e68(void) {
	if (data_ov031_02290d18.field4->field40 != 7) {
		HaltSystem();
	}

	func_ov031_02239368(1);

	unsigned short r = func_ov031_02239ee0(data_ov031_02290d18.field4->field60);
	data_ov031_02290d18.field4->unknown_5c_ = r;

	if (data_ov031_02290d18.field0) {
		data_ov031_02290d18.field0(0x8000000, &data_ov031_0224c464, data_ov031_02290d18.field4->unknown_5c_);
	}

	return data_ov031_02290d18.field4->unknown_5c_;
}
