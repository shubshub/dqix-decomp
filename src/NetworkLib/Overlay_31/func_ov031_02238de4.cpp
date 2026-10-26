#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"


struct Struct_ov031_02238de4_2 {
	unsigned char b0;
	unsigned char nameLength;
	unsigned short name[10];
};

struct Struct_ov031_02238de4_3 {
	struct Struct_ov031_02238de4_2 unknown_0_;
	unsigned char macAddress[6];
	unsigned short unknown_1c_;
};

struct Struct_ov031_02238de4_4 {
	unsigned short state;
	unsigned short unknown_2_;
	unsigned short unknown_4_;
	unsigned short unknown_6_;
	unsigned short unknown_8_;
	unsigned short unknown_a_;
	unsigned short unknown_c_;
};

struct Struct_ov031_02238de4_5 {
	struct Struct_ov031_02238de4_4 state;
	struct Struct_ov031_02238de4_3 child[15];
	unsigned char pad[0x1b140 - 0x1d0];
	void* unknown_1b140_;
	void* unknown_1b144_;
};

struct Struct_ov031_02238de4_6 {
	unsigned short unknown_0_;
	unsigned short unknown_2_;
	unsigned short unknown_4_;
	unsigned short unknown_6_;
	unsigned short state;
	unsigned char macAddress[6];
};

struct Struct_ov031_02238de4 {
	unsigned short unknown_0_;
};

extern "C" unsigned short func_ov031_0223911c(void);
extern "C" void func_ov031_02239108(unsigned short v);
extern "C" void func_ov031_02238db4(void);
extern "C" int func_ov031_02239188(int arg0);
extern "C" void func_ov031_022389b0(int index);
extern "C" void func_ov031_02238910(int index);
extern "C" void func_ov031_02238a88(int index);
extern "C" void* func_ov027_021d8a68(int index);
extern "C" void HaltSystem(void);

extern struct Struct_ov031_02238de4_5* data_ov031_02290d14;
#define sMbpState (data_ov031_02290d14->state)
#define sChildInfo (data_ov031_02290d14->child)

// USA: func_ov031_02238de4
extern "C" ARM void func_ov031_02238de4(unsigned short aid, unsigned int status, void* arg) {
	switch (status) {
	case 1:
		break;
	case 2: {
		if (func_ov031_0223911c() != 2) {
			break;
		}
		{
			unsigned short* var0 = &sMbpState.unknown_2_;
			int e = DisableIRQInterrupts();
			*var0 |= 1 << aid;
			SetIRQInterruptState(e);
		}
		{
			int off = (aid - 1) * sizeof(struct Struct_ov031_02238de4_3);
			const unsigned char* src = ((struct Struct_ov031_02238de4_6*)arg)->macAddress;
			unsigned char* dst = sChildInfo[0].macAddress + off;
			*dst = *src;
			*(dst + 1) = *(src + 1);
			*(dst + 2) = *(src + 2);
			*(dst + 3) = *(src + 3);
			*(dst + 4) = *(src + 4);
			*(dst + 5) = *(src + 5);
			*(unsigned short*)((unsigned char*)&sChildInfo[0].unknown_1c_ + off) = aid;
		}
		break;
	}
	case 3:
		if (func_ov031_02239188(aid) != 6) {
			unsigned short mask = (unsigned short)~(1 << aid);
			int var6 = DisableIRQInterrupts();
			sMbpState.unknown_2_ &= mask;
			sMbpState.unknown_4_ &= mask;
			sMbpState.unknown_6_ &= mask;
			sMbpState.unknown_8_ &= mask;
			sMbpState.unknown_a_ &= mask;
			sMbpState.unknown_c_ &= mask;
			SetIRQInterruptState(var6);
			func_ov031_02238db4();
		}
		break;
	case 4:
		break;
	case 10: {
		if (func_ov031_0223911c() != 2) {
			func_ov031_022389b0(aid);
			break;
		}
		sMbpState.unknown_4_ |= 1 << aid;
		func_ov031_02238910(aid);
		void* var7 = func_ov027_021d8a68(aid);
		if (var7 != NULL) {
			VectorizedInvertedMemcpy(var7, &sChildInfo[aid - 1].unknown_0_, sizeof(struct Struct_ov031_02238de4_2));
		}
		break;
	}
	case 5:
		break;
	case 14:
		sMbpState.unknown_4_ &= ~(1 << aid);
		sMbpState.unknown_6_ |= 1 << aid;
		if (func_ov031_0223911c() == 3) {
			func_ov031_02238a88(aid);
		}
		break;
	case 6:
		break;
	case 7:
		sMbpState.unknown_8_ &= ~(1 << aid);
		sMbpState.unknown_a_ |= 1 << aid;
		break;
	case 8:
		break;
	case 9:
		sMbpState.unknown_a_ &= ~(1 << aid);
		sMbpState.unknown_c_ |= 1 << aid;
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
			struct Struct_ov031_02238de4_5* w = data_ov031_02290d14;
			if (w->unknown_1b144_ != NULL) {
				w->unknown_1b144_ = NULL;
			}
		}
		{
			struct Struct_ov031_02238de4_5* w = data_ov031_02290d14;
			if (w->unknown_1b140_ != NULL) {
				w->unknown_1b140_ = NULL;
			}
		}
		break;
	case 13:
		switch (((struct Struct_ov031_02238de4*)arg)->unknown_0_) {
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
