#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020116c8_25572 = 0x6184, Enum_020116c8_25573 = 0x6185 };
#else
enum { Enum_020116c8_25572 = 0x63e4, Enum_020116c8_25573 = 0x63e5 };
#endif
#include "Grotto/Main/TreasureMapMetadata.h"

extern "C" int func_020ac760(void* dst);
extern "C" int func_020ac734(void* arg);

extern "C" {
    void func_ov017_021cfabc(void);
    void func_ov017_021cf730(int, int);
}

// USA: func_020116c8
extern "C" ARM void func_020116c8(void* obj) {
    unsigned char* p = (unsigned char*)obj;
    p[Enum_020116c8_25572] = 0;
    p[Enum_020116c8_25573] = 0;

    unsigned char localBuf[0xad8];
    func_020ac760(localBuf);

    for (int i = 0; i < localBuf[0]; i++) {
        ((TreasureMapMetadata*)(localBuf + 2 + i * 0x1c))->ClearInitialByteUnknownBit();
    }

    func_020ac734(localBuf);
    func_ov017_021cfabc();
    func_ov017_021cf730(-1, 0);
}
