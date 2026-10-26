#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD 0x4108
#else
#define REGION_FIELD 0x4328
#endif

// Overlay 17, originally GetField4328_0218d268 (USA/EUR 0x0218d268, JPN 0x0218de48)
ARM int GameResources_GetTouchWalk(void* obj) {
	return *(int*)((char*)obj + REGION_FIELD);
}
