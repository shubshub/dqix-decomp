#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void);
extern int data_ov001_02165958;
extern int g_sePlayer;
extern "C" void func_0205eb48(void* obj, void* target, int arg);

// USA: func_ov001_02163a18
extern "C" ARM int func_ov001_02163a18(void) {
    int idx = func_ov017_021d60f4();
    if (idx < 0 || idx >= 0x10) return 0;
    func_0205eb48(&g_sePlayer, (&data_ov001_02165958) + idx, 0);
    return 1;
}
