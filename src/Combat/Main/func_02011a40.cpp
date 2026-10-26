#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "Grotto/Main/TreasureMapMetadata.h"

// USA: func_02011a40
extern "C" ARM void func_02011a40(char* obj) {
    TreasureMapMetadata local;
    local.SetMapType(TreasureMapType_Invalid);
#if defined(jpn)
    VectorizedInvertedMemcpy(&local, obj + 0x6202, 0x1c);
#else
    VectorizedInvertedMemcpy(&local, obj + 0x6482, 0x1c);
#endif
}
