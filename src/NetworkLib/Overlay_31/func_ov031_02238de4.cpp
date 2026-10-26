#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"


struct Struct_ov031_02238de4_2 {
	unsigned char unknown_0_;
	unsigned char unknown_1_;
	unsigned short unknown_2_[10];
};

struct Struct_ov031_02238de4_3 {
	struct Struct_ov031_02238de4_2 unknown_0_;
	unsigned char unknown_16_[6];
	unsigned short unknown_1c_;
};

struct Struct_ov031_02238de4_4 {
	unsigned short unknown_0_;
	unsigned short unknown_2_;
	unsigned short unknown_4_;
	unsigned short unknown_6_;
	unsigned short unknown_8_;
	unsigned short unknown_a_;
	unsigned short unknown_c_;
};

struct Struct_ov031_02238de4_5 {
	struct Struct_ov031_02238de4_4 unknown_0_;
	struct Struct_ov031_02238de4_3 unknown_e_[15];
	unsigned char unknown_1d0_[0x1b140 - 0x1d0];
	void* unknown_1b140_;
	void* unknown_1b144_;
};

struct Struct_ov031_02238de4_6 {
	unsigned short unknown_0_;
	unsigned short unknown_2_;
	unsigned short unknown_4_;
	unsigned short unknown_6_;
	unsigned short unknown_8_;
	unsigned char unknown_a_[6];
};

struct Struct_ov031_02238de4 {
	unsigned short unknown_0_;
};

unsigned short GetGlobal02290d14_0223911c(void);
void SetGlobal02290d14_02239108(unsigned short v);
void CallOv027IfFieldsMatch_02238db4(void);
extern "C" int func_ov031_02239188(int bitIdx);
extern "C" void func_ov031_022389b0(int index);
extern "C" void func_ov031_02238910(int index);
extern "C" void func_ov031_02238a88(int index);
extern "C" void* func_ov027_021d8a68(int index);
extern "C" void HaltSystem(void);

extern struct Struct_ov031_02238de4_5* data_ov031_02290d14;
#define sMbpState (data_ov031_02290d14->unknown_0_)
#define sChildInfo (data_ov031_02290d14->unknown_e_)

// USA: func_ov031_02238de4
extern "C" ARM void func_ov031_02238de4(unsigned short arg0, unsigned int arg1, void* arg2) {
	switch (arg1) {
	case 1:
		break;
	case 2: {
		if (func_ov031_0223911c() != 2) {
			break;
		}
		{
			unsigned short* var0 = &sMbpState.unknown_2_;
			int var1 = DisableIRQInterrupts();
			*var0 |= 1 << arg0;
			SetIRQInterruptState(var1);
		}
		{
			int var2 = (arg0 - 1) * sizeof(struct Struct_ov031_02238de4_3);
			const unsigned char* var3 = ((struct Struct_ov031_02238de4_6*)arg2)->unknown_a_;
			unsigned char* var4 = sChildInfo[0].unknown_16_ + var2;
			*var4 = *var3;
			*(var4 + 1) = *(var3 + 1);
			*(var4 + 2) = *(var3 + 2);
			*(var4 + 3) = *(var3 + 3);
			*(var4 + 4) = *(var3 + 4);
			*(var4 + 5) = *(var3 + 5);
			*(unsigned short*)((unsigned char*)&sChildInfo[0].unknown_1c_ + var2) = arg0;
		}
		break;
	}
	case 3:
		if (func_ov031_02239188(arg0) != 6) {
			unsigned short var5 = (unsigned short)~(1 << arg0);
			int var6 = DisableIRQInterrupts();
			sMbpState.unknown_2_ &= var5;
			sMbpState.unknown_4_ &= var5;
			sMbpState.unknown_6_ &= var5;
			sMbpState.unknown_8_ &= var5;
			sMbpState.unknown_a_ &= var5;
			sMbpState.unknown_c_ &= var5;
			SetIRQInterruptState(var6);
			func_ov031_02238db4();
		}
		break;
	case 4:
		break;
	case 10: {
		if (func_ov031_0223911c() != 2) {
			func_ov031_022389b0(arg0);
			break;
		}
		sMbpState.unknown_4_ |= 1 << arg0;
		func_ov031_02238910(arg0);
		void* var7 = func_ov027_021d8a68(arg0);
		if (var7 != NULL) {
			VectorizedInvertedMemcpy(var7, &sChildInfo[arg0 - 1].unknown_0_, sizeof(struct Struct_ov031_02238de4_2));
		}
		break;
	}
	case 5:
		break;
	case 14:
		sMbpState.unknown_4_ &= ~(1 << arg0);
		sMbpState.unknown_6_ |= 1 << arg0;
		if (func_ov031_0223911c() == 3) {
			func_ov031_02238a88(arg0);
		}
		break;
	case 6:
		break;
	case 7:
		sMbpState.unknown_8_ &= ~(1 << arg0);
		sMbpState.unknown_a_ |= 1 << arg0;
		break;
	case 8:
		break;
	case 9:
		sMbpState.unknown_a_ &= ~(1 << arg0);
		sMbpState.unknown_c_ |= 1 << arg0;
		func_ov031_02238db4();
		break;
	case 11:
		break;
	case 12:
		if (func_ov031_0223911c() == 4) {
			func_ov031_02239108(5);
		} else {
			func_ov031_02239108(0);
		}
		{
			struct Struct_ov031_02238de4_5* var8 = data_ov031_02290d14;
			if (var8->unknown_1b144_ != NULL) {
				var8->unknown_1b144_ = NULL;
			}
		}
		{
			struct Struct_ov031_02238de4_5* var9 = data_ov031_02290d14;
			if (var9->unknown_1b140_ != NULL) {
				var9->unknown_1b140_ = NULL;
			}
		}
		break;
	case 13:
		switch (((struct Struct_ov031_02238de4*)arg2)->unknown_0_) {
		case 8:
			break;
		case 1:
		case 2:
		case 9:
			func_ov031_02239108(7);
			break;
		}
		break;
	default:
		HaltSystem();
	}
}
