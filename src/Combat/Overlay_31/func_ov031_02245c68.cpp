#include <globaldefs.h>


struct BlockedContextList;

int DisableIRQInterrupts();
int SetIRQInterruptState(int mask);
void SleepCurrentContext(unsigned int ticks);
void BlockCurrentContext(struct BlockedContextList* list);
extern "C" void HaltSystem(void);
extern "C" int func_ov031_0220cae0(void* local, void (*fn)(void));
extern "C" int func_ov031_0220cce4(void);
extern "C" int func_ov031_0220cdf4(int arg0, int arg1, int arg2);
extern "C" int func_ov031_0220cf6c(void);
extern "C" int func_ov031_0220d010(void* arg0, unsigned char* arg1, int arg2);
extern "C" int func_ov031_0220d214(void);
extern "C" int func_ov031_0220d330(void);
extern "C" void func_ov031_02245e5c(void);

struct Struct_ov031_0224c954 {
	int unknown_0_;
	char* unknown_4_;
	int unknown_8_;
	int unknown_c_;
};

struct Struct_ov031_02291f24_3 {
	int unknown_0_;
	int unknown_4_;
	unsigned int unknown_8_;
	int unknown_c_;
};

extern int data_ov031_02291f50;
extern int data_ov031_02292040;
extern struct BlockedContextList data_ov031_02291f3c;
extern struct Struct_ov031_0224c954 data_ov031_0224c954;
extern struct Struct_ov031_02291f24_3 data_ov031_02291f24;

// USA: func_ov031_02245c68
extern "C" ARM int func_ov031_02245c68(int arg0) {
	int var0 = 7;
	int var1 = DisableIRQInterrupts();

	for (;;) {
		switch (arg0) {
		case 1:
			var0 = func_ov031_0220cae0(&data_ov031_02291f50, func_ov031_02245e5c);
			break;
		case 2:
			var0 = func_ov031_0220cce4();
			break;
		case 3: {
			int var2 = data_ov031_02291f24.unknown_c_ != 0 ? 0xc00000 : 0x800000;
			char* var3 = data_ov031_0224c954.unknown_4_;
			int var4 = (data_ov031_0224c954.unknown_8_ | 0xbffe) | var2;
			var0 = func_ov031_0220cdf4((int)var3, (int)var3 + 0x58, var4);
			break;
		}
		case 4:
			var0 = func_ov031_0220cf6c();
			break;
		case 5: {
			char* var5 = data_ov031_0224c954.unknown_4_;
			var0 = func_ov031_0220d010(&data_ov031_02292040, (unsigned char*)(var5 + 6), data_ov031_0224c954.unknown_c_ | *(int*)(var5 + 0x78));
			break;
		}
		case 6:
			var0 = func_ov031_0220d214();
			break;
		case 9:
			var0 = func_ov031_0220d330();
			break;
		default:
			SetIRQInterruptState(var1);
			return var0;
		}

		switch (var0) {
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
			return var0;
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
			int var6;
			int var7 = data_ov031_02291f24.unknown_8_;
			switch (var7) {
			case 0:
			case 1:
				var6 = *(int*)((char*)&data_ov031_02291f24 + 8);
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
			return var6;
		}
	}
}
