#include <globaldefs.h>

extern "C" char* func_ov031_022133f8(int);
extern "C" int func_ov031_0220d540(void);
extern "C" int func_ov031_02214b64(int);
extern "C" void func_ov031_0220cf6c(void);
extern "C" void func_ov031_0220d214(void);
extern "C" void func_ov031_0220d330(void);
extern "C" void func_ov031_022134cc(int v);

// USA: func_ov031_02214928
extern "C" ARM int func_ov031_02214928(void) {
	char* obj = func_ov031_022133f8(0x10);
	unsigned int result = 9;

	switch (func_ov031_0220d540()) {
	case 3: {
		unsigned char b = obj[0xd0c];
		result = *(unsigned char*)(obj + 0xd0e);
		unsigned int v = ((unsigned int)b << 0x18) >> 0x1e;
		if (v == 1) {
			unsigned char idx = obj[0xd13];
			char* p = obj + idx * 4;
			p[0x444] = 0;
			result = 7;
		} else if (result >= 3 && result <= 5) {
			func_ov031_02214b64(result);
		}
		break;
	}
	case 6:
		func_ov031_0220cf6c();
		break;
	case 9:
		func_ov031_0220d214();
		break;
	case 12:
		func_ov031_0220d330();
		func_ov031_022134cc(4);
		result = 0x11;
		break;
	case 11:
		func_ov031_022134cc(0);
		result = 0x11;
		break;
	default:
		break;
	}

	return result;
}
