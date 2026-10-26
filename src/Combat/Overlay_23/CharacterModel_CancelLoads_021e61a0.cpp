#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


// Overlay 23, originally func_ov023_021e61a0 (USA/EUR 0x021e61a0, JPN 0x021e6384)
extern "C" ARM void CharacterModel_CancelLoads(void* obj) {
    int var0 = (int)BackgroundLoader::GetInstance();
    for (int i = 0; i < 0xc; i++) {
        if (*(short*)((char*)obj + (i << 1) + 0xb00 + 0xf4) > -1) {
            ((BackgroundLoader*)(var0))->RemoveTask((int)(*(short*)((char*)obj + (i << 1) + 0xb00 + 0xf4)));
        }
        *(short*)((char*)obj + (unsigned int)(i << 1) + 0xb00 + 0xf4) = -1;
    }
}
