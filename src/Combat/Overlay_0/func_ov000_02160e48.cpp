#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/OverlayId.h"

extern int data_ov000_02184220;
extern "C" void func_020a1fd4(unsigned char value);

#if defined(jpn)
enum { stateOffset = 0xe24, Enum_ov000_02160e48_30512 = 0x7920 };
#else
enum { stateOffset = 0xea8, Enum_ov000_02160e48_30512 = 0x7730 };
#endif

// USA: func_ov000_02160e48
extern "C" ARM void func_ov000_02160e48(void* obj) {
    *(int*)((char*)obj + stateOffset) = 0x13;
    *(int*)((char*)obj + stateOffset + 4) = 0;
    data_ov000_02184220 = 1;
    *(short*)((char*)obj + Enum_ov000_02160e48_30512) = BackgroundLoader::GetInstance()->QueueLoadOverlay(OVERLAY_ID(25));
    func_020a1fd4(4);
}
