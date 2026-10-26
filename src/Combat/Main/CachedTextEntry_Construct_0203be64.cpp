#include <globaldefs.h>

extern "C" void CachedTextEntry_Clear(char* entry);

// Main, originally InitStruct0203be64 (USA 0x0203be64, EUR 0x0203be74, JPN 0x0203b8bc)
extern "C" ARM char* CachedTextEntry_Construct(char* entry) {
    CachedTextEntry_Clear(entry);
    return entry;
}
