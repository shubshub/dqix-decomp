#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "Resource/GameResources.h"
#include "Grotto/Main/DetailedTreasureMapData.h"

struct Struct_ov004_0216342c {
    TreasureMapMetadata unknown_0_[99];
    DetailedTreasureMapData details[8];
    unsigned char unknown_18f4_;
    unsigned char unknown_18f5_;
    short page;
    short pageCount;
    unsigned char unknown_18fa_;
    unsigned char unknown_18fb_;
    unsigned char mode;
    unsigned char unknown_18fd_;
    unsigned char unknown_18fe_;
    unsigned char unknown_18ff_[0x15];
};

#if defined(jpn)
// USA: func_ov004_0216342c
extern "C" ARM void func_ov004_02163a20(void* a) {
#else
// USA: func_ov004_0216342c
extern "C" ARM void func_ov004_0216342c(void* a) {
#endif
    GameResources* resources = GetGameResources();
    VectorizedMemset(a, 0, sizeof(Struct_ov004_0216342c));
    Struct_ov004_0216342c* buffer = (Struct_ov004_0216342c*)a;
    buffer->unknown_18fa_ = ((unsigned char*)resources->unknown_41c8)[0x118];
    buffer->unknown_18fb_ = 0;
    buffer->mode = 0;
    buffer->unknown_18fd_ = 0;
    buffer->unknown_18fe_ = 0;
}
