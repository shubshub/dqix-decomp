#include <globaldefs.h>

struct CharacterModelRotation { unsigned int xyz[3]; };

// Overlay 23, originally func_ov023_021e613c (USA/EUR 0x021e613c, JPN 0x021e6320)
extern "C" ARM void CharacterModel_GetRotation(struct CharacterModelRotation* result, char* model) {
    *result = *(struct CharacterModelRotation*)(model + 0x50);
}
