#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void);
extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov017_021d6134(void* param, int val);
int Scenario_TestFlag(int, unsigned char*, int);

// USA: func_ov001_02163390
ARM int NotifyBitTestByIndex16_02163390(void* param) {
	unsigned char* base = (unsigned char*)Scenario_GetInstance();
	int id = func_ov017_021d60f4(param);
	int idx = base[0x332];
	int bit = Scenario_TestFlag((int)base, base + idx * 0x1c + 0x10, id);
	if (bit != 0) {
		func_ov017_021d6134((char*)param + 8, 1);
	} else {
		func_ov017_021d6134((char*)param + 8, 0);
	}
	return 1;
}
