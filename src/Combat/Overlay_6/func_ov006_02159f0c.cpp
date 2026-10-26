#include <globaldefs.h>

struct SePlayer;

extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern int g_sePlayer;

// USA: func_ov006_02159f0c
extern "C" ARM int func_ov006_02159f0c(char* self) {
    int flag = *(int*)(self + 0x3ac);
    if (flag != 0) {
        return flag;
    }
    int gate = *(int*)(self + 0x3a4);
    if (gate == 0) {
        return gate;
    }
    switch (*(int*)(self + 0x39c)) {
    case 0:
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 0xa, 0);
        break;
    case 1:
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 0xc, 0);
        break;
    case 2:
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 0xb, 0);
        break;
    default:
        break;
    }
    *(int*)(self + 0x3ac) = 1;
    return 1;
}
