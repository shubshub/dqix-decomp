#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD_0 0x41e8
#else
#define REGION_FIELD_0 0x4498
#endif


#pragma optimize_for_size off
// Overlay 17, originally HasNonZeroByteAtOfField498_0218d75c_0218d75c (USA/EUR 0x0218d75c, JPN 0x0218e33c)
ARM int GameResources_IsSpecialItemEffectPlaying(void* obj) {
    void* p = *(void**)((char*)obj + REGION_FIELD_0);
    return p != NULL && *(unsigned char*)((char*)p + 0x14) != 0;
}
