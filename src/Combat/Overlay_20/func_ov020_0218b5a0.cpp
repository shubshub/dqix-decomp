#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void func_0200f3a4(void*);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void GX_SetGraphicsMode(int mode, int flagsA, int valB);
extern "C" void GXS_SetGraphicsMode(unsigned int mode);
extern "C" void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);
extern "C" unsigned char func_0200fb9c(char* obj);
extern "C" void G3i_OrthoW_(int a0, int a1, int a2, int a3, int b0, int b1, int b2, int gate, void* outBuf);

struct Struct_ov020_0218b5a0 {
    char pad0[0x8];
    int f8;
    #if defined(jpn)
    char pad1[0x400 - 0xc];
#else
    char pad1[0x470 - 0xc];
#endif
    SafeAllocator unknown_470_;
    SafeAllocator unknown_484_;
    char pad2[0x4ec - 0x498];
    int unknown_4ec_;
    int unknown_4f0_;
    int f4f4;
    char pad3[0x4fc - 0x4f8];
    int unknown_4fc_;
    int unknown_500_;
};

// USA: func_ov020_0218b5a0
extern "C" ARM void func_ov020_0218b5a0(struct Struct_ov020_0218b5a0* obj) {
    char* battleStruct = (char*)GameState::GetInstance();
    LinkSession_GetInstance();
    func_0200f3a4(battleStruct);
    MapVRAMBanksToMainBG(4);

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = *dispcnt & ~0x7000000;
    *dispcnt = *dispcnt & ~0x38000000;
    GX_SetGraphicsMode(1, 0, 1);
    GXS_SetGraphicsMode(0);

    volatile unsigned short* var2 = (volatile unsigned short*)0x4000008;
    var2[0] = var2[0] & ~0x3;
    var2[1] = (var2[1] & ~0x3) | 0x1;
    Set3DClearColor(0, 0, 0x7fff, 0x3f, 0);

    if (func_0200fb9c(battleStruct) == 6) {
        Set3DClearColor(0, 0x1f, 0x7fff, 0, 0);
    }

    G3i_OrthoW_(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, 0);

    *(volatile unsigned int*)0x400044c = 0;
    *(volatile unsigned short*)0x4000304 = *(volatile unsigned short*)0x4000304 & ~0x8000;
    *(volatile unsigned int*)0x4000580 = 0xbfff0000;

    obj->unknown_470_.ResetAllocatorPointer();
    obj->unknown_484_.ResetAllocatorPointer();

    obj->f8 = 0;
    obj->unknown_500_ = 0;
#if !defined(jpn)
    obj->unknown_4f0_ = 0;
    obj->unknown_4ec_ = 0;
    obj->unknown_4fc_ = 0;
    obj->f4f4 = 0;
#endif
}
