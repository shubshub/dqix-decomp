#include <globaldefs.h>

extern unsigned char* data_ov031_02290d20;

extern "C" int func_ov031_0223a718(void);
extern "C" void func_ov031_0223ab6c(void);
extern "C" int func_ov031_0223ac14(void);
extern "C" void func_ov031_0223ac38(void);
extern "C" void func_ov031_0223adf0(void);
extern "C" void func_ov031_0223ae1c(void);
extern "C" void func_ov031_0223aff8(void);
extern "C" int func_ov031_0223b010(void);
extern "C" void func_ov027_021dcd20(void);
extern "C" int func_ov031_02239be8(void);
extern "C" void func_ov031_0223a47c(void);
extern "C" void func_ov031_0223a374(void);

// USA: func_ov031_0223a794
extern "C" ARM void func_ov031_0223a794(void) {
	switch (data_ov031_02290d20[0xa90]) {
	case 0:
	case 12:
	case 13:
	case 14:
	case 15:
	case 20:
	case 23:
	case 26:
	case 29:
	case 31:
	case 34:
		break;
	case 1: {
		unsigned char var0 = data_ov031_02290d20[0xaac];
		if (var0 == 1) {
			data_ov031_02290d20[0xaac] = 0;
			func_ov031_0223a718();
			break;
		}
		if (var0 != 2) break;
		data_ov031_02290d20[0xaac] = 0;
		data_ov031_02290d20[0xa90] = 0x22;
		break;
	}
	case 2:
		func_ov031_0223ab6c();
		break;
	case 3:
		func_ov031_0223ac14();
		data_ov031_02290d20[0xa90] = 4;
		break;
	case 4:
		(*(int*)(data_ov031_02290d20 + 0xa98))++;
		func_ov031_0223ac38();
		break;
	case 5:
	case 6:
		func_ov031_0223ac38();
		break;
	case 7:
		func_ov031_0223adf0();
		break;
	case 8:
	case 9:
	case 10:
		func_ov031_0223ae1c();
		break;
	case 11:
		func_ov031_0223aff8();
		break;
	case 16:
		*(int*)(data_ov031_02290d20 + 0xa9c) = 0;
		data_ov031_02290d20[0xa90] = 0x11;
		break;
	case 17: {
		unsigned int v = *(unsigned int*)(data_ov031_02290d20 + 0xa9c);
		*(unsigned int*)(data_ov031_02290d20 + 0xa9c) = v + 1;
		if (v <= 0x1e) break;
		func_ov031_0223b010();
		break;
	}
	case 18:
		func_ov027_021dcd20();
		*(int*)(data_ov031_02290d20 + 0xa9c) = 0;
		data_ov031_02290d20[0xa90] = 0x16;
		break;
	case 19: {
		unsigned int v = *(unsigned int*)(data_ov031_02290d20 + 0xa9c);
		*(unsigned int*)(data_ov031_02290d20 + 0xa9c) = v + 1;
		if (v <= 0x1e) break;
		if (func_ov031_02239be8() != 1) break;
		func_ov031_0223a47c();
		data_ov031_02290d20[0xa90] = 0x14;
		break;
	}
	case 21:
		func_ov031_0223a374();
		*(int*)(data_ov031_02290d20 + 0xa9c) = 0;
		data_ov031_02290d20[0xa90] = 0x16;
		break;
	case 22: {
		unsigned int v = *(unsigned int*)(data_ov031_02290d20 + 0xa9c);
		*(unsigned int*)(data_ov031_02290d20 + 0xa9c) = v + 1;
		if (v <= 0x1e) break;
		if (func_ov031_02239be8() != 1) break;
		func_ov031_0223a47c();
		data_ov031_02290d20[0xa90] = 0x17;
		break;
	}
	case 24:
		func_ov031_0223a374();
		*(int*)(data_ov031_02290d20 + 0xa9c) = 0;
		data_ov031_02290d20[0xa90] = 0x19;
		break;
	case 25: {
		unsigned int v = *(unsigned int*)(data_ov031_02290d20 + 0xa9c);
		*(unsigned int*)(data_ov031_02290d20 + 0xa9c) = v + 1;
		if (v <= 0x1e) break;
		if (func_ov031_02239be8() != 1) break;
		func_ov031_0223a47c();
		data_ov031_02290d20[0xa90] = 0x1a;
		break;
	}
	case 27:
		func_ov031_0223a374();
		*(int*)(data_ov031_02290d20 + 0xa9c) = 0;
		data_ov031_02290d20[0xa90] = 0x1c;
		break;
	case 28: {
		unsigned int v = *(unsigned int*)(data_ov031_02290d20 + 0xa9c);
		*(unsigned int*)(data_ov031_02290d20 + 0xa9c) = v + 1;
		if (v <= 0x1e) break;
		if (func_ov031_02239be8() == 1) {
			func_ov031_0223a47c();
			data_ov031_02290d20[0xa90] = 0x1d;
			break;
		}
		{
			unsigned int cnt = *(unsigned int*)(data_ov031_02290d20 + 0xa9c);
			if (cnt % 30 != 1) break;
			if (cnt <= 0x37) break;
			func_ov031_0223a374();
		}
		break;
	}
	case 32:
		func_ov031_0223a374();
		*(int*)(data_ov031_02290d20 + 0xa9c) = 0;
		data_ov031_02290d20[0xa90] = 0x21;
		break;
	case 33: {
		unsigned int v = *(unsigned int*)(data_ov031_02290d20 + 0xa9c);
		*(unsigned int*)(data_ov031_02290d20 + 0xa9c) = v + 1;
		if (v <= 0x1e) break;
		if (func_ov031_02239be8() != 1) break;
		func_ov031_0223a47c();
		data_ov031_02290d20[0xa90] = 0x22;
		break;
	}
	case 30:
		func_ov031_0223a374();
		break;
	}
}
