#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void);
extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov017_021d6134(void* param, int val);
int TestBitWithBias0206eb98(unsigned char*, int);

// USA: func_ov001_021633ec
ARM int NotifyBitWithBiasTest_021633ec(void* param) {
	unsigned char* base = (unsigned char*)Scenario_GetInstance();
	int id = func_ov017_021d60f4(param);
	int bit = TestBitWithBias0206eb98(base, id);
	if (bit != 0) {
		func_ov017_021d6134((char*)param + 8, 1);
	} else {
		func_ov017_021d6134((char*)param + 8, 0);
	}
	return 1;
}
