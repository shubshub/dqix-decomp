#include <globaldefs.h>

struct Struct0209c830;
void SetValueAndActivate0209c830(Struct0209c830*, int);

extern struct Struct0209c830 g_bgmPlayer;

// USA: func_ov004_0216dfa0  (semantic: SetOv009cbb830To53_0216dfa0)
extern "C" ARM int func_ov004_0216dfa0(void) {
    SetValueAndActivate0209c830(&g_bgmPlayer, 0x35);
    return 0;
}
