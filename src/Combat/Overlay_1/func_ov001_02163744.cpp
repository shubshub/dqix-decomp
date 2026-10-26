#include <globaldefs.h>

extern "C" unsigned short func_ov017_021d60f4(int a);

struct Struct0209c830 {
	char pad[0xc9];
	unsigned char active;
	char pad2[4];
	unsigned short value;
};
extern "C" void func_0209c830(Struct0209c830* p, int value);

extern struct Struct0209c830 g_bgmPlayer;

// USA: func_ov001_02163744
extern "C" ARM int func_ov001_02163744(int a) {
	func_0209c830(&g_bgmPlayer, func_ov017_021d60f4(a));
	return 1;
}
