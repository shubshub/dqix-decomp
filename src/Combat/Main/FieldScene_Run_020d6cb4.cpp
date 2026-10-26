#include <globaldefs.h>
#include "NitroSDK/OverlayId.h"

#if defined(jpn)
#define func_ov023_021d8a40 func_ov030_021d8a40
#define func_ov024_021d92f0 func_ov030_021d92f0
#endif

extern "C" void Overlay_Load(unsigned int id);
extern "C" int Overlay_Unload(unsigned int id);
extern "C" void* func_ov023_021d8a40(void* data, int* out);
extern "C" void func_ov017_0218b688(void* obj);
extern "C" void func_ov024_021d92f0(void* obj, void* data, int* out);
extern char g_mainAllocator;

// Main, originally GuardedOverlayDispatch020d6cb4 (USA 0x020d6cb4, EUR 0x020d6cc4, JPN 0x020d86bc)
extern "C" ARM void FieldScene_Run() {
    unsigned int id = OVERLAY_ID(30);
    int result = 0;
    Overlay_Load(id);
    void* obj = func_ov023_021d8a40(&g_mainAllocator, &result);
    Overlay_Unload(id);
    func_ov017_0218b688(obj);
    Overlay_Load(id);
    func_ov024_021d92f0(obj, &g_mainAllocator, &result);
    Overlay_Unload(id);
}
