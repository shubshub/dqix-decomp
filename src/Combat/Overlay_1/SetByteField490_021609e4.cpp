#include <globaldefs.h>


extern "C" int func_ov017_021d60f4(void* p);
extern "C" void* Scenario_GetInstance(void);

// USA: func_ov001_021609e4
ARM int SetByteField490_021609e4(void* p) {
	int v = func_ov017_021d60f4(p);
	*((unsigned char*)Scenario_GetInstance() + 0x490) = (unsigned char)v;
	return 1;
}
