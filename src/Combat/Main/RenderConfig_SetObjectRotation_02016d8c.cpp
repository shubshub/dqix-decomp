#include <globaldefs.h>
#include "NitroSDK/NSBXX/RenderConfig.h"

extern "C" void MI_Copy36B(void* a, void* b);
extern int data_0210a0cc;   // data_0210a010.objectRotationPosition (RenderConfig +0xbc)

// Main, originally ClearGlobalFlagBits02016d8c (USA 0x02016d8c, EUR 0x02016d9c, JPN 0x02016b2c)
extern "C" ARM void RenderConfig_SetObjectRotation(void* rotation) {
    MI_Copy36B(rotation, &data_0210a0cc);
    data_0210a010.flags &= ~((1 << RENDER_CONFIG_FLAG_2) | (1 << RENDER_CONFIG_FLAG_5) | (1 << RENDER_CONFIG_FLAG_WORLDVIEW_CACHE_VALID));
}
