#include <globaldefs.h>

extern int g_bgmPlayer;
unsigned int IsAnimationActive0209ca2c(void*);
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);

// USA: func_ov011_02188438
extern "C" ARM unsigned int func_ov011_02188438(unsigned int arg0) {
    func_ov011_02184c68(arg0, IsAnimationActive0209ca2c((void*)((unsigned int)&g_bgmPlayer)));
    return 1;
}
