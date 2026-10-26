#include <globaldefs.h>

// Overlay 23, originally CopyAndClampShorts_021e5fdc (USA/EUR 0x021e5fdc, JPN 0x021e61c0)
extern "C" ARM void CharacterModel_GetPartModels(void *unused, short *dst, short *src) {
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
	dst[3] = src[3];
	dst[4] = src[3];
	dst[5] = src[4];
	dst[6] = src[5];
	dst[7] = src[6];
	dst[8] = src[7];
	dst[9] = src[8];
	if (dst[0] < 0) dst[0] = 0x3e8;
	if (dst[6] < 0) dst[6] = 0x3e2;
	if (dst[1] < 0) dst[1] = 0x1f41;
	if (dst[5] < 0) {
		dst[5] = src[0xb];
		if (dst[5] < 0) dst[5] = 0x1f4a;
	}
}
