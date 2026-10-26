#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "World/ZoneFeatures.h"

// USA: func_0201d424
ARM void ZoneFeatures::Opcode6aEntry::func_0201d424() {
    VectorizedMemset(this, 0, sizeof(Opcode6aEntry));
    unk_0 = 0;
    maybeType = 0;
    angle = 0;
    unk_22 = 0;
    unk_24 = 0;
    unk_8.vec.x = 0;
    unk_8.vec.y = 0;
    unk_8.vec.z = 0;
    unk_14.vec.x = 0;
    unk_14.vec.y = 0;
    unk_14.vec.z = 0;
    unk_28 = 0;
    pNext = NULL;
}
