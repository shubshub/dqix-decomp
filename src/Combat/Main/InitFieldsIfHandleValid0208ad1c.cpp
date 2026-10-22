#include <globaldefs.h>
void SetColoredEffectParam02070950(struct EffectParam02070950*, struct Rgb02070950*, int, int, int);

extern "C" void* func_020704fc(void*);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

// USA: func_0208ad1c
ARM void InitFieldsIfHandleValid0208ad1c(void* obj) {
    void* handle = func_020704fc(obj);
    if (handle != NULL) {
        SetColoredEffectParam02070950((struct EffectParam02070950*)handle, (struct Rgb02070950*)((char*)obj + 0xc), 0x14, 5, 0xf);
        SePlayer_Play(&g_sePlayer, 0x78, 0);
    }
}
