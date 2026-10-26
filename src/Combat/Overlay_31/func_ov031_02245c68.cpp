#include <globaldefs.h>


struct BlockedContextList;

int DisableIRQInterrupts();
int SetIRQInterruptState(int mask);
void SleepCurrentContext(unsigned int ticks);
void BlockCurrentContext(struct BlockedContextList* list);
extern "C" void HaltSystem(void);
extern "C" int func_ov031_0220cae0(void* local, void (*fn)(void));
extern "C" int func_ov031_0220cce4(void);
extern "C" int func_ov031_0220cdf4(int a, int b, int c);
extern "C" int func_ov031_0220cf6c(void);
extern "C" int func_ov031_0220d010(void* a, unsigned char* b, int c);
extern "C" int func_ov031_0220d214(void);
extern "C" int func_ov031_0220d330(void);
extern "C" void func_ov031_02245e5c(void);

struct Struct_ov031_0224c954 {
	int unk0;
	char* slot;
	int flagsA;
	int unknown_c_;
};

struct Struct_ov031_02291f24_3 {
	int unk0;
	int field4;
	unsigned int field8;
	int fieldC;
};

extern int data_ov031_02291f50;
extern int data_ov031_02292040;
extern struct BlockedContextList data_ov031_02291f3c;
extern struct Struct_ov031_0224c954 data_ov031_0224c954;
extern struct Struct_ov031_02291f24_3 data_ov031_02291f24;

// USA: func_ov031_02245c68
extern "C" ARM int func_ov031_02245c68(int mode) {
	int result = 7;
	int var1 = DisableIRQInterrupts();

	for (;;) {
		switch (mode) {
		case 1:
			result = func_ov031_0220cae0(&data_ov031_02291f50, func_ov031_02245e5c);
			break;
		case 2:
			result = func_ov031_0220cce4();
			break;
		case 3: {
			int bits = data_ov031_02291f24.fieldC != 0 ? 0xc00000 : 0x800000;
			char* slot = data_ov031_0224c954.slot;
			int flags = (data_ov031_0224c954.flagsA | 0xbffe) | bits;
			result = func_ov031_0220cdf4((int)slot, (int)slot + 0x58, flags);
			break;
		}
		case 4:
			result = func_ov031_0220cf6c();
			break;
		case 5: {
			char* slot = data_ov031_0224c954.slot;
			result = func_ov031_0220d010(&data_ov031_02292040, (unsigned char*)(slot + 6), data_ov031_0224c954.unknown_c_ | *(int*)(slot + 0x78));
			break;
		}
		case 6:
			result = func_ov031_0220d214();
			break;
		case 9:
			result = func_ov031_0220d330();
			break;
		default:
			SetIRQInterruptState(var1);
			return result;
		}

		switch (result) {
		case 4:
			SleepCurrentContext(1);
			continue;
		case 2:
		case 3:
			BlockCurrentContext(&data_ov031_02291f3c);
			goto wake;
		case 0:
		case 1:
			SetIRQInterruptState(var1);
			return result;
		case 5:
			HaltSystem();
			break;
		case 6:
		case 7:
		default:
			break;
		}

		SetIRQInterruptState(var1);
		for (;;) {
			SleepCurrentContext(10000);
		}

wake:
		{
			int value;
			int state = data_ov031_02291f24.field8;
			switch (state) {
			case 0:
			case 1:
				value = *(int*)((char*)&data_ov031_02291f24 + 8);
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			default:
				SetIRQInterruptState(var1);
				for (;;) {
					SleepCurrentContext(10000);
				}
			}
			SetIRQInterruptState(var1);
			return value;
		}
	}
}
