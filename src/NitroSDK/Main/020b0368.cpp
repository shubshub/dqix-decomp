#include <globaldefs.h>
#include "NitroSDK/Cache.h"

extern "C" void MemoryMapTextureImage(void);
extern "C" void LoadToTextureImage(void* ptr, int a, int b);
extern "C" void MemoryUnmapTextureImage(void);
extern "C" int LoadToMainObjVRAM(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToSubObjVRAM(int, int, unsigned int);
extern "C" void func_020b0334(int* arr, int index, int value);

struct Struct_020b0368 {
    unsigned short f0;
    unsigned short f2;
    int f4;
    unsigned int f8;
    char unknown_c_[4];
    unsigned int f10;
    void* f14;
};

struct Struct_020b0368_2 {
    char pad0[0xc];
    int f0xc;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
};

// USA: func_020b0368
extern "C" ARM void func_020b0368(int local, int arg1, int arg2, void* objPtr) {
    struct Struct_020b0368* res = (struct Struct_020b0368*)local;
    struct Struct_020b0368_2* out = (struct Struct_020b0368_2*)objPtr;
    unsigned int flag8 = res->f8;

    if (arg2 != 0) {
        switch (arg2) {
        case 1:
            *(volatile unsigned int*)0x04000000 = (*(volatile unsigned int*)0x04000000 & 0xffcfffef) | flag8;
            break;
        case 2:
            *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & 0xffcfffef) | flag8;
            break;
        }
    }

    CleanInvalidateCacheRange(res->f14, res->f10);

    switch (arg2) {
    case 0:
        MemoryMapTextureImage();
        LoadToTextureImage(res->f14, arg1, res->f10);
        MemoryUnmapTextureImage();
        break;
    case 1:
        LoadToMainObjVRAM((int)res->f14, arg1, res->f10);
        break;
    case 2:
        LoadToSubObjVRAM((int)res->f14, arg1, res->f10);
        break;
    }

    if (res->f8 == 0) {
        int idx;
        switch (res->f2) {
        case 1: idx = 0; break;
        case 2: idx = 1; break;
        case 4: idx = 2; break;
        case 8: idx = 3; break;
        case 16: idx = 4; break;
        case 32: idx = 5; break;
        default: idx = 0; break;
        }
        out->f0xc = idx;

        switch (res->f0) {
        case 1: idx = 0; break;
        case 2: idx = 1; break;
        case 4: idx = 2; break;
        case 8: idx = 3; break;
        case 16: idx = 4; break;
        case 32: idx = 5; break;
        default: idx = 0; break;
        }
        out->unknown_10_ = idx;
    } else {
        out->f0xc = res->f2;
        out->unknown_10_ = res->f0;
    }

    out->unknown_14_ = res->f4;
    out->unknown_18_ = 0;
    out->unknown_1c_ = 1;
    out->unknown_20_ = res->f8;
    func_020b0334((int*)out, arg2, arg1);
}
