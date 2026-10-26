#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int state);
extern "C" int func_020d4aa8(void);
extern "C" int func_020d3fdc(void);
extern "C" int func_020d472c(void* param);
extern "C" int func_020d4e48(int a);
extern "C" int func_020d3dcc(int a, int b);
extern "C" void func_ov031_0220da1c(int);
extern "C" void func_ov031_0220d61c(int, int);
extern "C" void func_ov031_0220dc40(void);
struct Struct_ov031_0220dbc8;
extern "C" void func_ov031_0220dbc8(struct Struct_ov031_0220dbc8* s);
extern int data_ov031_0224e53c;

// USA: func_ov031_0220cae0
extern "C" ARM int func_ov031_0220cae0(int a0, int a1) {
	unsigned int state = DisableIRQInterrupts();
	if (data_ov031_0224e53c == 0) {
		SetIRQInterruptState(state);
		return 1;
	}
	int v = *(int*)((char*)data_ov031_0224e53c + 0x2260);
	switch (v) {
	case 1:
		func_ov031_0220d61c(a0, a1);
		break;
	case 2:
		SetIRQInterruptState(state);
		return 2;
	case 3:
		SetIRQInterruptState(state);
		return 0;
	default:
		SetIRQInterruptState(state);
		return 1;
	}

	int var2 = (unsigned short)(*(int*)((char*)data_ov031_0224e53c + 0x226c));
	int result = func_020d3dcc(data_ov031_0224e53c, var2);
	switch (result) {
	case 3:
		func_ov031_0220da1c(0xb);
		SetIRQInterruptState(state);
		return 7;
	case 4:
		SetIRQInterruptState(state);
		return 5;
	case 1:
	case 2:
	case 5:
	case 6:
	default:
		func_ov031_0220da1c(0xb);
		SetIRQInterruptState(state);
		return 7;
	case 0: {
		int shared = func_020d4aa8();
		if (shared == 0) {
			if (func_020d3fdc() != 0) {
				func_ov031_0220da1c(0xb);
				SetIRQInterruptState(state);
				return 7;
			}
			SetIRQInterruptState(state);
			return 5;
		}
		if (func_020d472c((void*)func_ov031_0220dbc8) != 0) {
			func_ov031_0220da1c(0xb);
			SetIRQInterruptState(state);
			return 7;
		}
		int var5 = func_020d4e48((int)func_ov031_0220dc40);
		switch (var5) {
		case 2:
			func_ov031_0220da1c(2);
			*(unsigned short*)((char*)data_ov031_0224e53c + 0x2280) = 1;
			goto ret3;
		case 8:
			func_ov031_0220da1c(0xc);
			SetIRQInterruptState(state);
			return 1;
		case 3:
		default:
			func_ov031_0220da1c(0xb);
			SetIRQInterruptState(state);
			return 7;
		}
	ret3:
		SetIRQInterruptState(state);
		return 3;
	}
	}
}
