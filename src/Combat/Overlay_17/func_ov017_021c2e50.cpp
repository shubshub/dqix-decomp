#include <globaldefs.h>

extern "C" void SePlayer_UnloadExtraArchiveB(void* obj);
extern "C" void SePlayer_LoadExtraArchiveB(void* obj, int arg1, int arg2);
extern "C" void SePlayer_PlayExtra(void* obj, int a, int b);
unsigned long long GetCurrentTimestamp(void);
extern "C" void* func_0208a9b4(void);

struct Struct_0208b494;
extern "C" void func_0208b494(struct Struct_0208b494* obj);

extern int g_sePlayer;

// USA: func_ov017_021c2e50
extern "C" ARM void func_ov017_021c2e50(char* self) {
    SePlayer_UnloadExtraArchiveB((void*)&g_sePlayer);
    SePlayer_LoadExtraArchiveB((void*)&g_sePlayer, 0xb3, 0xb3);
    SePlayer_PlayExtra((void*)&g_sePlayer, 0, 0);
    *(unsigned long long*)(self + 0x98) = GetCurrentTimestamp();
    func_0208b494((struct Struct_0208b494*)func_0208a9b4());
    self[0x8c] = 3;
}
