#include <globaldefs.h>

struct Struct0209c830;
extern "C" void func_0209c830(Struct0209c830*, int);

extern struct Struct0209c830 g_bgmPlayer;

// USA: func_ov004_0216dfbc
extern "C" ARM int func_ov004_0216dfbc(void) {
    func_0209c830(&g_bgmPlayer, 0x3d);
    return 0;
}
