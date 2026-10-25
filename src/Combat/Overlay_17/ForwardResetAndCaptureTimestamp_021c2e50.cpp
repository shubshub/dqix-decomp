#include <globaldefs.h>

void SePlayer_UnloadExtraArchiveB(void* obj);
void SePlayer_LoadExtraArchiveB(void* obj, int arg1, int arg2);
void SePlayer_PlayExtra(void* obj, int a, int b);
unsigned long long GetCurrentTimestamp(void);
void* GetData02108f0c_0208a9b4(void);

struct Obj0208b494;
void CaptureValueOnce0208b494(struct Obj0208b494* obj);

extern int g_sePlayer;

// USA: func_ov017_021c2e50
ARM void ForwardResetAndCaptureTimestamp_021c2e50(char* self) {
    SePlayer_UnloadExtraArchiveB((void*)&g_sePlayer);
    SePlayer_LoadExtraArchiveB((void*)&g_sePlayer, 0xb3, 0xb3);
    SePlayer_PlayExtra((void*)&g_sePlayer, 0, 0);
    *(unsigned long long*)(self + 0x98) = GetCurrentTimestamp();
    CaptureValueOnce0208b494((struct Obj0208b494*)GetData02108f0c_0208a9b4());
    self[0x8c] = 3;
}
