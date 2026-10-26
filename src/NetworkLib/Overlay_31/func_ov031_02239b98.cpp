#include <globaldefs.h>

extern "C" int func_ov031_02239368(int);

// USA: func_ov031_02239b98
extern "C" ARM void func_ov031_02239b98(short* p) {
	if (*(unsigned short*)((char*)p + 2) != 0) {
		func_ov031_02239368(10);
	} else {
		func_ov031_02239368(0);
	}
}
