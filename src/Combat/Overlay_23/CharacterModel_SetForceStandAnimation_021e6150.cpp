#include <globaldefs.h>

// Overlay 23, originally SetByteC11_021e6150 (USA/EUR 0x021e6150, JPN 0x021e6334)
extern "C" ARM void CharacterModel_SetForceStandAnimation(void* obj, unsigned char value) {
    *(unsigned char*)((char*)obj + 0xc11) = value;
}
