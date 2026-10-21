#include <globaldefs.h>

// Overlay 23, originally func_ov023_021e6158 (USA/EUR 0x021e6158, JPN 0x021e633c)
extern "C" ARM void CharacterModel_InvalidatePart(char* obj, int index) {
    *(short*)(obj + index * 0xac + 0x2) = -1;
}
