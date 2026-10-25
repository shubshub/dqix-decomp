#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern int g_bgmPlayer;

// USA: func_ov001_021636d0
ARM int ClampAndDispatchState_021636d0(void* param, int mode) {
	int id = func_ov017_021d60f4(param);
	if (id < 0) {
		id = 0;
	} else if (id > 0x7f) {
		id = 0x7f;
	}
	int extra = 0;
	if (mode >= 2) {
		extra = func_ov017_021d60f4((char*)param + 8);
	}
	func_0209c2e0(&g_bgmPlayer, id, extra);
	return 1;
}
