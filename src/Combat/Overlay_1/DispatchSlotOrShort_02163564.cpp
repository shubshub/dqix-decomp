#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov017_021d6134(void* param, int val);
int* FindFreeSlot_0215a818(int* outIdx);
void DispatchIfField0xc4NonNeg_0205eb90(void* obj, int a, int b);
struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern int g_sePlayer;

// USA: func_ov001_02163564
ARM int DispatchSlotOrShort_02163564(void* param, int mode) {
	int id = func_ov017_021d60f4(param);
	int outIdx;
	if (mode >= 2) {
		int* slot = FindFreeSlot_0215a818(&outIdx);
		if (slot != NULL) {
			DispatchIfField0xc4NonNeg_0205eb90(&g_sePlayer, id, (int)slot);
		}
		func_ov017_021d6134((char*)param + 8, outIdx);
	} else {
		SePlayer_Play((struct SePlayer*)&g_sePlayer, id, 0);
	}
	return 1;
}
