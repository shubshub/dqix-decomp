#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov017_021d6134(void* param, int val);
extern "C" int* func_ov001_0215a818(int* arg0);
extern "C" void func_0205eb90(void* obj, int a, int b);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern int g_sePlayer;

// USA: func_ov001_02163564
extern "C" ARM int func_ov001_02163564(void* param, int mode) {
	int id = func_ov017_021d60f4(param);
	int var1;
	if (mode >= 2) {
		int* slot = func_ov001_0215a818(&var1);
		if (slot != NULL) {
			func_0205eb90(&g_sePlayer, id, (int)slot);
		}
		func_ov017_021d6134((char*)param + 8, var1);
	} else {
		SePlayer_Play((struct SePlayer*)&g_sePlayer, id, 0);
	}
	return 1;
}
