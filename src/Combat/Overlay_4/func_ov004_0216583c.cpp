#include <globaldefs.h>
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

extern char* data_ov004_02171010;
extern "C" void func_ov011_021848a0(void* obj, int val);

#if defined(jpn)
// USA: func_ov004_0216583c
extern "C" ARM int func_ov004_021660cc(void* obj) {
#else
// USA: func_ov004_0216583c
extern "C" ARM int func_ov004_0216583c(void* obj) {
#endif
    Struct_ov004_0216342c* buffer = (Struct_ov004_0216342c*)data_ov004_02171010;
    buffer->unknown_18fd_ = 1;
    func_ov011_021848a0(obj, 0x65);
    return 0;
}
