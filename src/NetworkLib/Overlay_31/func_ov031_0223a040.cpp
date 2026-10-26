#include <globaldefs.h>


extern "C" int func_ov031_02239368(int);
extern "C" void HaltSystem(void);

// USA: func_ov031_0223a040
extern "C" ARM void func_ov031_0223a040(short* arg0) {
	if (*(unsigned short*)((char*)arg0 + 2) == 8) {
		func_ov031_02239368(9);
		HaltSystem();
	}
}
