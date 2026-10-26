#include <globaldefs.h>

void CachedTextEntry_Clear(char* entry);

// Main, originally InitStruct0203be64 (USA 0x0203be64, EUR 0x0203be74, JPN 0x0203b8bc)
ARM char* CachedTextEntry_Construct(char* entry) {
    CachedTextEntry_Clear(entry);
    return entry;
}
