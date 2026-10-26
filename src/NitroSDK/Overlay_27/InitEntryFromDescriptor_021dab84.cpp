#include <globaldefs.h>
#include "NitroSDK/Filesystem/NitroVM.h"

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

extern "C" void func_020ca390(int val, void* dst, unsigned int size);
extern "C" void MIi_CpuClearFast(unsigned int value, void* dest, int count);
extern "C" int func_020ca3b8(int src, int dst, int size);
CBool ReadFileWithSizeCheck_021dac74(const char* path, void* dst, int large);
int CountU16UntilZero_021dad84(unsigned short* p);

struct SrcDesc021dab84 {
    unsigned char pad0[4];
    unsigned short* field4;
    void* field8;
    const char* fieldc;
    const char* field10;
    unsigned int field14;
    unsigned char field18;
};

// USA: func_ov027_021dab84  (semantic: InitEntryFromDescriptor_021dab84)
extern "C" ARM void func_ov027_021dab84(void* obj, SrcDesc021dab84* src, int extra) {
    func_020ca390(0, obj, 0x4c0);
    *((unsigned char*)obj + 0x4b2) = 0;

    unsigned int fail1 = ReadFileWithSizeCheck_021dac74(src->fieldc, obj, 1) == 0;
    unsigned int fail2 = ReadFileWithSizeCheck_021dac74(src->field10, obj, 0) == 0;
    if (fail1 | fail2) {
        *((unsigned char*)obj + 0x4b2) = 1;
        MIi_CpuClearFast(0, obj, 0x220);
    }

    *(unsigned int*)((char*)obj + 0x4b8) = src->field14;
    if (extra != 0) {
        func_020ca3b8(extra, (int)((char*)obj + 0x220), 0x16);
    }

    *((unsigned char*)obj + 0x236) = src->field18;

    int count = CountU16UntilZero_021dad84(src->field4);
    unsigned short byteSize = (unsigned short)(count * 2);
    func_020ca3b8((int)src->field4, (int)((char*)obj + 0x238), byteSize);

    func_020ca3b8((int)src->field8, (int)((char*)obj + 0x298), 0xc0);

    *((unsigned char*)obj + 0x358) = 1;
    *(unsigned short*)((char*)obj + 0x300 + 0x5a) = 1;
    *(unsigned short*)((char*)obj + 0x400 + 0xb0) = 1;
}
