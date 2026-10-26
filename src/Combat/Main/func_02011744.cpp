#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02011744_25572 = 0x6184, Enum_02011744_1104 = 0x1d0 };
#else
enum { Enum_02011744_25572 = 0x63e4, Enum_02011744_1104 = 0x450 };
#endif
#include "Grotto/Main/TreasureMapMetadata.h"
#include "NitroSDK/Memory.h"

extern "C" int func_020ac760(void* dst);
extern "C" int func_020ac734(void* arg);

// USA: func_02011744
extern "C" ARM void func_02011744(void* obj) {
    if (((unsigned char*)obj)[Enum_02011744_25572] == 0) {
        return;
    }

    unsigned char localBuf[0xad8];
    func_020ac760(localBuf);

    for (int i = 0; i < localBuf[0]; i++) {
        if (((TreasureMapMetadata*)(localBuf + 2 + i * 0x1c))->GetInitialByteUnknownBit()) {
            VectorizedInvertedMemcpy((char*)obj + Enum_02011744_1104 + 0x6000, localBuf + 2 + i * 0x1c, 0x1c);
            func_020ac734(localBuf);
            return;
        }
    }
}
