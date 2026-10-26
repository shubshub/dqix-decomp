#include <globaldefs.h>


extern "C" int func_ov031_02239368(int);
extern "C" void HaltSystem(void);

// USA: func_ov031_0223a040
extern "C" ARM void func_ov031_0223a040(short* p) {
	if (*(unsigned short*)((char*)p + 2) == 8) {
		func_ov031_02239368(9);
		HaltSystem();
	}
}
