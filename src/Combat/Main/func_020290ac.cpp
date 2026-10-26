#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"
#include "NitroSDK/LoadToVRAM.h"

// USA: func_020290ac
extern "C" ARM void func_020290ac(int arg0) {
    if (glyphBitmapContext.buffer == NULL) return;
    if (arg0 == 0) {
        LoadToMainBG1CharacterData(glyphBitmapContext.buffer, 0, 256 * 192 / 2);
    } else {
        LoadToSubBG0CharacterData(glyphBitmapContext.buffer, 0, 256 * 192 / 2);
    }
}
