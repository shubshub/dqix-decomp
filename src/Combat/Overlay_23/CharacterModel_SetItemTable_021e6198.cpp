#include <globaldefs.h>

// Overlay 23, originally SetIntC0C_021e6198 (USA/EUR 0x021e6198, JPN 0x021e637c)
extern "C" ARM void CharacterModel_SetItemTable(void* obj, int value) {
    *(int*)((char*)obj + 0xc0c) = value;
}
