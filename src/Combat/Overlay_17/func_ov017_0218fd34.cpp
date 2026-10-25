#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Model3D.h"
#include "Graphics/VRAMStaging.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Cache.h"

GameObject* GetField4334_021bdbc0(unsigned char* base);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

struct Struct_ov017_021d6260 {
    int unknown_0_[14];
};
extern struct SlotIdTable_0218fd34 data_ov017_021d6260;
extern AllocatorUnion g_mainAllocator;

static inline unsigned short inline_ov017_0218f968(unsigned short arg0) {
    return arg0 & 0x1f;
}

static inline unsigned short inline_ov017_0218f968_2(unsigned short arg0) {
    return (arg0 & 0x3e0) >> 5;
}

static inline unsigned short inline_ov017_0218f968_3(unsigned short arg0) {
    return (arg0 & 0x7c00) >> 10;
}

static inline unsigned int inline_ov017_0218fd34(NSBXXTex* arg0) {
    return (arg0->block4VRAMLoadOffset_ & 0xffff) << 3;
}

// USA: func_ov017_0218fd34
extern "C" ARM void func_ov017_0218fd34(unsigned char* arg0, int arg1, unsigned short arg2) {
    GameState* var0 = GameState::GetInstance();

    struct Struct_ov017_021d6260 var1 = data_ov017_021d6260;
    int var2 = arg1 * 12;
    var1.unknown_0_[0] = arg1;
    var1.unknown_0_[1] = var2 + 0x13;
    var1.unknown_0_[2] = var2 + 0x14;
    var1.unknown_0_[3] = var2 + 0x16;
    var1.unknown_0_[4] = var2 + 0x17;
    var1.unknown_0_[5] = var2 + 0x18;
    var1.unknown_0_[6] = var2 + 0x19;
    var1.unknown_0_[7] = var2 + 0x1a;
    var1.unknown_0_[8] = var2 + 0x1b;
    var1.unknown_0_[9] = var2 + 0x1c;
    var1.unknown_0_[10] = var2 + 0x1d;

    unsigned short var3 = inline_ov017_0218f968(arg2);
    unsigned short var4 = inline_ov017_0218f968_2(arg2);
    unsigned short var5 = inline_ov017_0218f968_3(arg2);

    unsigned short* var6[13] = {0};

    int var7 = 0;
    GameObject* var8 = var0->GetGameObjectByIndex(var1.unknown_0_[0]);
    if (var8 != NULL) {
        var7 = var8->obj3D_.GetField9e();
    }
    LockStagedTextureVRAMCopying();

    int var9;
    int var10;
    for (var9 = 0; (var10 = var1.unknown_0_[var9]) > -1; var9++) {
        GameObject* var11;
        if (var10 == 0xff) {
            var11 = func_ov017_021bdbc0(arg0);
        } else {
            var11 = var0->GetGameObjectByIndex(var10);
        }
        if (var11 == NULL) {
            continue;
        }
        if (var11->obj3D_.unknown_2_ <= -1 && var10 != 0xff) {
            continue;
        }
        Model3D* var12 = var11->obj3D_.pModel_;
        if (var12 == NULL) {
            continue;
        }
        NSBXXTex* var13 = var12->GetTEX0();
        if (var13 == NULL) {
            continue;
        }
        unsigned short* var14;
        unsigned int var15;
        unsigned int var16;
        var16 = inline_ov017_0218fd34(var13);
        var14 = (unsigned short*)((char*)var13 + var13->block4Offset_);
        var15 = var13->block4NumEightBytes_ << 3;

        if (mode == 0) {
            bufs[i] = (unsigned short*)AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
            if (bufs[i] == NULL) {
                continue;
            }
            for (unsigned int var17 = 0; var17 < var15 / 2; var17++) {
                unsigned short var18 = var14[var17];
                unsigned short var19 = inline_ov017_0218f968(var18);
                unsigned short var20 = inline_ov017_0218f968_2(var18);
                unsigned short var21 = inline_ov017_0218f968_3(var18);
                var19 += var3;
                var20 += var4;
                var21 += var5;
                if (var19 > 31) {
                    var19 = 31;
                }
                if (var20 > 31) {
                    var20 = 31;
                }
                if (var21 > 31) {
                    var21 = 31;
                }
                var6[var9][var17] = var19 | (var20 << 5) | (var21 << 10);
            }
            CleanInvalidateCacheRange(bufs[i], size);
            StageMemoryToVRAM(VRAMSubregion_TexturePalette, bufs[i], offset, size, false, true);
        } else if (mode == 1) {
            bufs[i] = (unsigned short*)AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
            if (bufs[i] == NULL) {
                continue;
            }
            for (unsigned int var22 = 0; var22 < var15 / 2; var22++) {
                var6[var9][var22] = arg2;
            }
            CleanInvalidateCacheRange(bufs[i], size);
            StageMemoryToVRAM(VRAMSubregion_TexturePalette, bufs[i], offset, size, false, true);
        } else if (mode == 2) {
            bufs[i] = (unsigned short*)AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
            if (bufs[i] == NULL) {
                continue;
            }
            float var23 = var3 / 31.0f;
            float var24 = var4 / 31.0f;
            float var25 = var5 / 31.0f;
            for (unsigned int var26 = 0; var26 < var15 / 2; var26++) {
                unsigned short var27 = var14[var26];
                unsigned short var28 = inline_ov017_0218f968(var27);
                unsigned short var29 = inline_ov017_0218f968_2(var27);
                unsigned short var30 = inline_ov017_0218f968_3(var27);
                unsigned short var31 = var28 * var23;
                unsigned short var32 = var29 * var24;
                unsigned short var33 = var30 * var25;
                var6[var9][var26] = var31 | (var32 << 5) | (var33 << 10);
            }
            CleanInvalidateCacheRange(var6[var9], var15);
            StageMemoryToVRAM(VRAMSubregion_TexturePalette, var6[var9], var16, var15, false, true);
        }
    }
    UnlockStagedTextureVRAMCopying();

    for (unsigned int k = 0; k < 13; k++) {
        if (bufs[k] != NULL) {
            AllocatorUnion_Free(&g_mainAllocator, bufs[k]);
        }
    }
}
