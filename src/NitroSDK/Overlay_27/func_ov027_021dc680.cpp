#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif

struct Struct_ov027_021dc680_2 {
	unsigned char unknown_0_;
	unsigned char nameLength;
	unsigned short name[10];
};

struct Struct_ov027_021dc680_3 {
	unsigned char pad0[8];
	unsigned int unknown_8_;
	unsigned short tgid;
	unsigned short unknown_e_;
	unsigned short unknown_10_;
	unsigned short unknown_12_;
	unsigned short unknown_14_;
	unsigned short unknown_16_;
	unsigned short unknown_18_;
	unsigned char pad1a[0x500 - 0x1a];
	unsigned short unknown_500_;
	unsigned short unknown_502_;
	unsigned char* unknown_504_;
	unsigned char unknown_508_[4];
	unsigned char unknown_50c_;
	unsigned char unknown_50d_;
	unsigned char unknown_50e_[0x518 - 0x50e];
	unsigned short unknown_518_;
	unsigned short unknown_51a_;
	unsigned char unknown_51c_[0x52c - 0x51c];
	unsigned short unknown_52c_;
	unsigned char unknown_52e_[2];
	unsigned short unknown_530_[4];
	unsigned short unknown_538_[16];
	unsigned char unknown_558_[0x1e00 - 0x558];
};

struct Struct_ov027_021dc680 {
	unsigned char pad0[0x400];
	unsigned char buf[0x1300 - 0x400];
	Struct_ov027_021dc680_2 unknown_1300_;
	unsigned short unknown_1316_;
	int unknown_1318_;
	int unknown_131c_;
	unsigned char unknown_1320_[0x1340 - 0x1320];
};

struct Struct_ov027_021e33e0_6 {
	unsigned short unknown_0_;
	unsigned char* unknown_4_;
	Struct_ov027_021dc680_3* param;
	Struct_ov027_021dc680* unknown_c_;
};

extern Struct_ov027_021e33e0_6 data_ov027_021e33e0;

unsigned short data_ov027_021dd8ec = 5;
unsigned short data_ov027_021dd8f2 = 0xffff;
unsigned short data_ov027_021dd8f0 = 40;
unsigned short data_ov027_021dd8ee = 40;

static inline void inline_ov027_021dc680(Struct_ov027_021dc680_3* param, const Struct_ov027_021dc680_2* arg1) {
	static const wchar_t* gameName = L"multiboot";
	int i;
	{
		unsigned short* dst = param->unknown_530_;
		for (i = 0; i < arg1->nameLength; i++) {
			*dst++ = arg1->name[i];
		}
	}
	{
		unsigned short* dst = param->unknown_538_;
		for (i = 0; i < 16; i++) {
			unsigned short c = *gameName;
			if (c == 0) break;
			gameName++;
			*dst++ = c;
		}
	}
}

int data_ov027_021dd8f8 = 1;

extern "C" unsigned short func_020d4dd4(void);
extern "C" void func_020ca3ec(int val, void* dst, unsigned int size);
extern "C" void func_020ca390(int val, void* dst, unsigned int size);
extern "C" unsigned int func_ov027_021dc618(void);

// USA: func_ov027_021dc680
extern "C" ARM int func_ov027_021dc680(void* work, const Struct_ov027_021dc680_2* arg1, unsigned int arg2, unsigned int tgid, unsigned int arg4) {
	Struct_ov027_021dc680_3* param;
	Struct_ov027_021dc680* var1;
	int enabled;

	if (data_ov027_021e33e0.unknown_c_ != 0 && data_ov027_021e33e0.unknown_c_->unknown_1316_ != 0) {
		return 2;
	}
	param = (Struct_ov027_021dc680_3*)(((unsigned int)work + 31) & ~31);
	var1 = (Struct_ov027_021dc680*)(((unsigned int)param + sizeof(Struct_ov027_021dc680_3) + 31) & ~31);
	if (tgid == 0x10000) {
		tgid = func_020d4dd4();
	}
	enabled = DisableIRQInterrupts();
	data_ov027_021dd8f2 = 0xffff;
	data_ov027_021dd8ec = 5;
	data_ov027_021dd8ee = 40;
	data_ov027_021dd8f0 = 40;
	data_ov027_021dd8f8 = 1;
	data_ov027_021e33e0.unknown_0_ = arg4;
	data_ov027_021e33e0.param = param;
	data_ov027_021e33e0.unknown_c_ = var1;
	func_020ca3ec(0, param, sizeof(Struct_ov027_021dc680_3));
	func_020ca390(0, var1, sizeof(Struct_ov027_021dc680));
	inline_ov027_021dc680(param, arg1);
	VectorizedInvertedMemcpy(arg1, &var1->unknown_1300_, sizeof(Struct_ov027_021dc680_2));
	if (arg1->nameLength < 10) {
		var1->unknown_1300_.name[arg1->nameLength] = 0;
	}
	param->unknown_500_ = 0x100;
	param->unknown_502_ = 8;
	param->unknown_518_ = 0;
	param->unknown_51a_ = 0;
	param->unknown_52c_ = 1;
	param->unknown_504_ = var1->buf;
	param->unknown_e_ = 0;
	param->unknown_12_ = 0;
	param->unknown_16_ = 1;
	param->unknown_14_ = 0;
	param->unknown_8_ = arg2;
	param->tgid = tgid;
	param->unknown_18_ = func_ov027_021dc618() + 200;
	param->unknown_10_ = 15;
	param->unknown_50c_ = 0;
	param->unknown_50d_ = 0;
	var1->unknown_1316_ = 1;
	var1->unknown_131c_ = 0;
	SetIRQInterruptState(enabled);
	return 0;
}
