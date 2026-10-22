#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* a);
void ForwardToTargetOrDefault0205eabc(void* obj, void* target, int arg);
void ClearField0x0_020bc078(int* field);
extern int data_ov001_02165958[16];
extern int g_sePlayer;

// USA: func_ov001_021635d0
ARM int ForwardSlotOrClear_021635d0(void* param, int mode) {
	unsigned int id = (unsigned int)func_ov017_021d60f4(param);
	if (id >= 16) {
		return 0;
	}
	int* slot = &data_ov001_02165958[id];
	if (*slot == 0) {
		return 0;
	}
	int val = 0;
	if (mode >= 2) {
		val = func_ov017_021d60f4((char*)param + 8);
	}
	ForwardToTargetOrDefault0205eabc(&g_sePlayer, slot, val);
	ClearField0x0_020bc078(slot);
	return 1;
}
