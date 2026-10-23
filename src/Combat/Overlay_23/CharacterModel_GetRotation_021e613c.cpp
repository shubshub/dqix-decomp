#include <globaldefs.h>

struct Block3_021e613c { unsigned int w[3]; };

// Overlay 23, originally func_ov023_021e613c (USA/EUR 0x021e613c, JPN 0x021e6320)
extern "C" ARM void CharacterModel_GetRotation(struct Block3_021e613c* dst, char* src) {
    *dst = *(struct Block3_021e613c*)(src + 0x50);
}
