#include <globaldefs.h>

extern "C" void CachedTextEntry_Clear(char* obj);

// Main, originally InitStruct0203be78 (USA 0x0203be78, EUR 0x0203be88, JPN 0x0203b8d0)
extern "C" ARM char* CachedTextEntry_Destroy(char* obj) {
    CachedTextEntry_Clear(obj);
    return obj;
}
