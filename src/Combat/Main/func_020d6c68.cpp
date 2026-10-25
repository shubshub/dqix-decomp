#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/Overlay_33/Ov33BackgroundLoader.h"
#include "NitroSDK/OverlayId.h"

extern "C" void func_020a1940(unsigned int id);
extern char g_fileLoadBuffer;

// USA: func_020d6c68
extern "C" ARM void func_020d6c68() {
    if (BackgroundLoader::GetInstance() != NULL) {
        return;
    }
    func_020a1940(OVERLAY_ID(34));
    PopulateOv33BackgroundLoader(&g_fileLoadBuffer, 0x30000, 0x14);
}
