#include <globaldefs.h>


void SetGlobal02290d14_02239108(unsigned short v);
int SetFlagThenDispatch_021dcc24_021dcc24(int a);
extern "C" int func_ov031_0223883c(int a);
extern "C" void HaltSystem(void);

// USA: func_ov031_022387f4
ARM void DispatchOrRetryLoad_022387f4(int a0, int a1) {
	SetGlobal02290d14_02239108(2);
	if (SetFlagThenDispatch_021dcc24_021dcc24(a1) != 0) {
		SetGlobal02290d14_02239108(7);
		return;
	}
	if (func_ov031_0223883c(a0) == 0) {
		HaltSystem();
	}
}
