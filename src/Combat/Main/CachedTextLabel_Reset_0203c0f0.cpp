#include <globaldefs.h>

struct State0xc0cc;
void CachedTextLabel_Release(char* label);
void CachedTextLabel_Init(struct State0xc0cc* label);

// Main, originally ReinitFieldState0203c0f0 (USA 0x0203c0f0, EUR 0x0203c100, JPN 0x0203bc3c)
ARM void CachedTextLabel_Reset(struct State0xc0cc* label) {
    CachedTextLabel_Release((char*)label);
    CachedTextLabel_Init(label);
}
