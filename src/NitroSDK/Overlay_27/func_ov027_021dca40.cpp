#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/IPC.h"

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif

struct Struct_ov027_021dca40 {
	unsigned char pad0[0x32];
	unsigned short channel;
	unsigned short unknown_34_;
	unsigned short unknown_36_;
	unsigned char unknown_38_[0x500 - 0x38];
	unsigned short unknown_500_;
	unsigned short unknown_502_;
	unsigned char unknown_504_[4];
	void (*unknown_508_)(void);
	unsigned char unknown_50c_[0x518 - 0x50c];
	unsigned short unknown_518_;
	unsigned short unknown_51a_;
	void (*callback)(void);
	unsigned char unknown_520_[4];
	unsigned short mode;
};

struct Struct_ov027_021dca40_2 {
	unsigned char unknown_0_[0x1318];
	int unknown_1318_;
	unsigned char unknown_131c_[0x14e4 - 0x131c];
	void* unknown_14e4_;
	int unknown_14e8_[15];
	unsigned char unknown_1524_;
	unsigned char unknown_1525_;
	signed char unknown_1526_[15];
	unsigned char unknown_1535_[0x1538 - 0x1535];
	unsigned char unknown_1538_[0x1754 - 0x1538];
	unsigned char unknown_1754_[0x1e];
	unsigned char unknown_1772_[0x1788 - 0x1772];
	unsigned char unknown_1788_[0x5d40];
	int unknown_74c8_;
	unsigned char unknown_74cc_[0x7d00 - 0x74cc];
};

struct Struct_ov027_021e33e0_9 {
	unsigned int field0;
	unsigned char* unknown_4_;
	Struct_ov027_021dca40* param;
	Struct_ov027_021dca40_2* unknown_c_;
};

extern Struct_ov027_021e33e0_9 data_ov027_021e33e0;

extern "C" void func_ov027_021d8a40(void* cb);
extern "C" void func_ov027_021dd5a4(int val);
extern "C" void func_ov027_021dd5d4(void* obj);
extern "C" void func_ov027_021dadf0(void);
extern "C" void func_020ca390(int val, void* dst, unsigned int size);
extern "C" int func_ov027_021dc96c(void);
extern "C" void func_ov027_021d8c94(void);
extern "C" void func_ov027_021db524(void);
extern "C" void VectorizedMemset(void* dst, int val, int size);

// USA: func_ov027_021dca40
extern "C" ARM int func_ov027_021dca40(int channel) {
	int i, ret;
	void* var2;
	int enabled;

	enabled = DisableIRQInterrupts();
	data_ov027_021e33e0.param->channel = (unsigned short)channel;
	data_ov027_021e33e0.unknown_4_ =
		(unsigned char*)(((unsigned int)data_ov027_021e33e0.unknown_c_ + sizeof(Struct_ov027_021dca40_2) + 31) & ~31);
	var2 = data_ov027_021e33e0.unknown_c_->unknown_14e4_;

	func_020ca390(0, (void*)((unsigned int)data_ov027_021e33e0.unknown_c_ + 0x1340), sizeof(Struct_ov027_021dca40_2) - 0x1340);
	func_ov027_021d8a40(var2);

	data_ov027_021e33e0.unknown_c_->unknown_1318_ = data_ov027_021e33e0.param->unknown_500_ - 6;

	func_ov027_021dd5a4(data_ov027_021e33e0.param->unknown_502_);
	func_ov027_021dd5d4(data_ov027_021e33e0.unknown_c_->unknown_1538_);

	for (i = 0; i < 15; i++) {
		data_ov027_021e33e0.unknown_c_->unknown_14e8_[i] = 0;
		data_ov027_021e33e0.unknown_c_->unknown_1526_[i] = -1;
	}

	data_ov027_021e33e0.unknown_c_->unknown_1524_ = 0;

	func_020ca390(0, data_ov027_021e33e0.unknown_c_->unknown_1788_, sizeof(data_ov027_021e33e0.unknown_c_->unknown_1788_));
	VectorizedMemset(data_ov027_021e33e0.unknown_c_->unknown_1754_, 0, sizeof(data_ov027_021e33e0.unknown_c_->unknown_1754_));

	data_ov027_021e33e0.param->mode = 1;
	data_ov027_021e33e0.param->callback = func_ov027_021d8c94;
	data_ov027_021e33e0.param->unknown_508_ = func_ov027_021db524;

	data_ov027_021e33e0.param->unknown_34_ = data_ov027_021e33e0.param->unknown_500_;
	data_ov027_021e33e0.param->unknown_518_ =
		(unsigned short)((data_ov027_021e33e0.param->unknown_34_ + 0x23) & ~0x1f);

	data_ov027_021e33e0.param->unknown_36_ = data_ov027_021e33e0.param->unknown_502_;
	data_ov027_021e33e0.param->unknown_51a_ =
		(unsigned short)((((data_ov027_021e33e0.param->unknown_36_ + 0xe) * 15 + 0x29) & ~0x1f) << 1);

	func_ov027_021dadf0();
	ret = func_ov027_021dc96c();

	SetIRQInterruptState(enabled);
	data_ov027_021e33e0.unknown_c_->unknown_74c8_ = IsIPCCommandHandlerRegistered(0xf, IPCSide_Arm7);

	return ret;
}
