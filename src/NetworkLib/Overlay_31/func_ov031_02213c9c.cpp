#include <globaldefs.h>

extern "C" int func_ov031_022134b0(void);
extern "C" void* func_ov031_022133f8(unsigned int flags);
extern "C" int func_ov031_02213ce0(void* obj);
extern "C" int func_ov031_02213dd8(void* obj);

// USA: func_ov031_02213c9c
extern "C" ARM int func_ov031_02213c9c(void) {
	int result = func_ov031_022134b0();
	void* obj = func_ov031_022133f8(0x10);
	switch (result) {
	case 7:
		result = func_ov031_02213ce0(obj);
		break;
	case 8:
		result = func_ov031_02213dd8(obj);
		break;
	}
	return result;
}
