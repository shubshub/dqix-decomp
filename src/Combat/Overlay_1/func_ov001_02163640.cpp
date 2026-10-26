#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* a);
struct Actor0209c3b4;
extern "C" void func_0209c3b4(struct Actor0209c3b4* actor, int val);
struct Actor0209c678;
extern "C" void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
extern int g_bgmPlayer;

// USA: func_ov001_02163640
extern "C" ARM int func_ov001_02163640(void* param, int mode) {
	int val = -1;
	if (mode == 2) {
		int id = func_ov017_021d60f4(param);
		val = func_ov017_021d60f4((char*)param + 8);
	} else if (mode == 1) {
		val = func_ov017_021d60f4(param);
	}
	if (val < 0) {
		return 0;
	}
	func_0209c3b4((struct Actor0209c3b4*)&g_bgmPlayer, val);
	BgmPlayer_FadeOut((struct Actor0209c678*)&g_bgmPlayer, 0);
	return 1;
}
