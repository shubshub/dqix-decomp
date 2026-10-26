#include <globaldefs.h>

struct Words021e60c4 { unsigned int x, y, z; };

// Overlay 23, originally SetWords_021e60c4_021e60c4 (USA/EUR 0x021e60c4, JPN 0x021e62a8)
extern "C" ARM void Object3D_SetRotation(void* obj, struct Words021e60c4* src) {
	struct Words021e60c4* dst = (struct Words021e60c4*)((char*)obj + 0x50);
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}
