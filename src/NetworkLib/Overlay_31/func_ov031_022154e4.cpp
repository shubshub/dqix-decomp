#include <globaldefs.h>

extern "C" int func_ov031_02213504(int);

// USA: func_ov031_022154e4
extern "C" ARM int func_ov031_022154e4(void* obj) {
	func_ov031_02213504(*(unsigned char*)((char*)obj + 0xd0d));
	return 0x10;
}
