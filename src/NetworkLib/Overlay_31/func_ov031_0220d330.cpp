#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
void SetIRQInterruptState(int mask);
extern "C" void InvalidateDataCacheRange(const void* addr, unsigned int size);
extern "C" int func_020d3fdc(void);
extern "C" int func_020d4ebc(int value);
extern "C" int func_020d4f3c(int fn);
extern "C" int func_020d5004(int fn);
extern "C" unsigned short* func_020d46a8(void);
extern "C" void func_ov031_0220da1c(int);
extern "C" void func_ov031_0220dc40(void);
extern "C" void func_ov031_0220e7b0(void);

struct Struct_ov031_0220d330 {
	char pad[0x2260];
	int state;
	char pad2[0x226b - 0x2264];
	unsigned char unknown_226b_;
	char pad3[0x2280 - 0x226c];
	short unknown_2280_;
};

extern Struct_ov031_0220d330* data_ov031_0224e53c;

// USA: func_ov031_0220d330
extern "C" ARM int func_ov031_0220d330(void) {
	int mask = DisableIRQInterrupts();
	if (data_ov031_0224e53c == 0) {
		SetIRQInterruptState(mask);
		return 1;
	}

	int result;
	switch (data_ov031_0224e53c->state) {
		case 13:
			SetIRQInterruptState(mask);
			return 2;
		case 1:
			SetIRQInterruptState(mask);
			return 0;
		case 6:
			func_ov031_0220da1c(0xd);
			data_ov031_0224e53c->unknown_2280_ = 9;
			SetIRQInterruptState(mask);
			return 3;
		case 0:
		case 2:
		case 4:
		case 5:
		case 7:
		case 8:
		case 10:
		case 11:
		default:
			SetIRQInterruptState(mask);
			return 1;
		case 3:
		case 9:
		case 12:
			if (data_ov031_0224e53c->unknown_226b_ == 1) {
				func_ov031_0220da1c(0xd);
				data_ov031_0224e53c->unknown_2280_ = 9;
				goto epilogue3;
			}
			{
				unsigned short* field4 = func_020d46a8();
				InvalidateDataCacheRange(field4, 2);
				switch (*field4) {
					case 0:
						result = func_020d3fdc();
						if (result != 0) break;
						func_ov031_0220da1c(1);
						data_ov031_0224e53c->unknown_2280_ = 0;
						SetIRQInterruptState(mask);
						return 0;
					case 1:
						result = func_020d4ebc((int)func_ov031_0220dc40);
						break;
					case 2:
						result = func_020d4f3c((int)func_ov031_0220dc40);
						break;
					default:
						data_ov031_0224e53c->unknown_226b_ = 1;
						result = func_020d5004((int)func_ov031_0220e7b0);
						break;
				}
			}
			break;
	}

	switch (result) {
		case 2:
			func_ov031_0220da1c(0xd);
			data_ov031_0224e53c->unknown_2280_ = 9;
			goto epilogue3;
		case 8:
			SetIRQInterruptState(mask);
			return 4;
		case 3:
		default:
			func_ov031_0220da1c(0xb);
			SetIRQInterruptState(mask);
			return 7;
	}

epilogue3:
	SetIRQInterruptState(mask);
	return 3;
}
