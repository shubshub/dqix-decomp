#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/Overlay_33/Ov33BackgroundLoader.h"
#include "NitroSDK/OverlayId.h"

extern "C" void Overlay_Load(unsigned int id);
extern char g_fileLoadBuffer;

// USA: func_020d6c68
extern "C" ARM void func_020d6c68() {
    if (BackgroundLoader::GetInstance() != NULL) {
        return;
    }
    Overlay_Load(OVERLAY_ID(34));
    PopulateOv33BackgroundLoader(&g_fileLoadBuffer, 0x30000, 0x14);
}
