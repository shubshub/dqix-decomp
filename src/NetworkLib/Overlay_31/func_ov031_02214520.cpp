#include <globaldefs.h>


extern "C" void* func_ov031_022133f8(unsigned int flags);
extern "C" void func_020ca3ec(int val, void *dst, int size);
extern "C" int func_ov031_02214600(void *obj);
extern "C" int func_ov031_02214854(void *obj);
extern "C" int func_ov031_022148e4(void *obj);
extern "C" int func_ov031_02214660(void *obj);

// USA: func_ov031_02214520
extern "C" ARM int func_ov031_02214520(int mode) {
	void* handler = func_ov031_022133f8(0x10);
	switch (mode) {
	case 0:
		func_020ca3ec(0, (char*)handler + 0x300, 0x144);
		*((unsigned char*)handler + 0xd10) = (unsigned char)func_ov031_02214600(handler);
		break;
	case 1:
		*((unsigned char*)handler + 0xd10) = (unsigned char)func_ov031_02214854(handler);
		*((unsigned char*)handler + 0xd0f) = (unsigned char)func_ov031_022148e4(handler);
		break;
	case 2:
		func_020ca3ec(0, (char*)handler + 0x300, 0x144);
		*((unsigned char*)handler + 0xd0f) = 0;
		*((unsigned char*)handler + 0xd10) = (unsigned char)func_ov031_02214660(handler);
		break;
	}
	return *((unsigned char*)handler + 0xd10);
}
