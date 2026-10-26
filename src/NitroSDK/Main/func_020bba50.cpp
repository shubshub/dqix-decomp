#include <globaldefs.h>
#include "NitroSDK/LoadToVRAM.h"

// USA: func_020bba50
extern "C" ARM void func_020bba50(const void* data, unsigned int offset, unsigned int length) {
    LoadToMainBG2CharacterData(data, offset, length);
}
