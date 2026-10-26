#include <globaldefs.h>


extern "C" int func_ov031_02222a10();
extern "C" void HaltSystem(void);
extern "C" int func_ov031_0223cf70(void*);
extern char data_ov031_02290c48;

// USA: func_ov031_02227ba4
ARM int CheckStateThenProcess_02227ba4(void) {
	if (func_ov031_02222a10() != 1) HaltSystem();
	return func_ov031_0223cf70(&data_ov031_02290c48);
}
