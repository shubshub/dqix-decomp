#include <globaldefs.h>

extern int g_sePlayer;
extern int data_ov001_0216587c;
extern "C" void SoundPlayer_StopSeq(void* obj, void* target, int arg);

// USA: func_ov001_021599b8
extern "C" ARM int func_ov001_021599b8(void) {
    SoundPlayer_StopSeq(&g_sePlayer, &data_ov001_0216587c, 0);
    return 0;
}
