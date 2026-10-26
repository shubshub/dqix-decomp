#include <globaldefs.h>


struct Struct_ov031_02239e68 {
	unsigned char unknown_0_[0x40];
	int unknown_40_;
	unsigned char unknown_44_[0x18];
	unsigned short unknown_5c_;
	unsigned char unknown_5e_[2];
	unsigned short unknown_60_;
};

typedef void (*Type_0201282c)(int, void*, unsigned short);

struct Struct_ov031_02290d18 {
	Type_0201282c unknown_0_;
	Struct_ov031_02239e68* unknown_4_;
};

extern OuterStruct02239e68 data_ov031_02290d18;
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

	unsigned short var0 = func_ov031_02239ee0(data_ov031_02290d18.unknown_4_->unknown_60_);
	data_ov031_02290d18.unknown_4_->unknown_5c_ = var0;

	if (data_ov031_02290d18.unknown_0_) {
		data_ov031_02290d18.unknown_0_(0x8000000, &data_ov031_0224c464, data_ov031_02290d18.unknown_4_->unknown_5c_);
	}

	return data_ov031_02290d18.unknown_4_->unknown_5c_;
}
