#include <globaldefs.h>
#include "Filesystem/Overlay_33/Ov33BackgroundLoader.h"
#include "NitroSDK/OverlayId.h"

extern "C" void Overlay_Load(unsigned int id);
extern char g_fileLoadBuffer;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
#if defined(jpn)
#define func_020d6c0c func_020d8614
extern "C" ARM void func_020d6c0c(void);
#endif

// USA: func_020d6c0c
extern "C" ARM void func_020d6c0c() {
    Overlay_Load(OVERLAY_ID(34));
    PopulateOv33BackgroundLoader(&g_fileLoadBuffer, 0x30000, 0x14);
}
