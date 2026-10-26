#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Model3D.h"
#include "Graphics/VRAMStaging.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Cache.h"

extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern AllocatorUnion g_mainAllocator;

static inline unsigned short inline_ov017_0218f968(unsigned short c) {
    return c & 0x1f;
}

static inline unsigned short inline_ov017_0218f968_2(unsigned short c) {
    return (c & 0x3e0) >> 5;
}

static inline unsigned short inline_ov017_0218f968_3(unsigned short c) {
    return (c & 0x7c00) >> 10;
}

// USA: func_ov017_0218f968
extern "C" ARM void func_ov017_0218f968(unsigned char* ov, int idx, unsigned short color) {
    GameState* battleStruct = GameState::GetInstance();

    unsigned short var1 = inline_ov017_0218f968(color);
    unsigned short var2 = inline_ov017_0218f968_2(color);
    unsigned short var3 = inline_ov017_0218f968_3(color);

    unsigned short* buf = NULL;

    LockStagedTextureVRAMCopying();

    GameObject* obj = battleStruct->GetGameObjectByIndex(idx);
    if (obj != NULL && obj->obj3D_.pModel_ != NULL) {
        NSBXXTex* tex = obj->obj3D_.pModel_->GetTEX0();
        if (tex != NULL) {
            if (obj->obj3D_.GetField9e() == 0) {
                unsigned int offset = tex->block4VRAMLoadOffset_;
                offset = obj->obj3D_.GetTexturePaletteOffset() != 0 ? obj->obj3D_.GetTexturePaletteOffset() : offset;
                unsigned int size = tex->block4NumEightBytes_ << 3;
                unsigned int vramOffset = (offset & 0xffff) << 3;
                unsigned short* src = (unsigned short*)((char*)tex + tex->block4Offset_);
                buf = (unsigned short*)AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
                if (buf != NULL) {
                    for (unsigned int j = 0; j < size / 2; j++) {
                        unsigned short c = src[j];
                        unsigned short r = inline_ov017_0218f968(c);
                        unsigned short g = inline_ov017_0218f968_2(c);
                        unsigned short b = inline_ov017_0218f968_3(c);
                        r += var1;
                        g += var2;
                        b += var3;
                        if (r > 31) {
                            r = 31;
                        }
                        if (g > 31) {
                            g = 31;
                        }
                        if (b > 31) {
                            b = 31;
                        }
                        buf[j] = r | (g << 5) | (b << 10);
                    }
                    CleanInvalidateCacheRange(buf, size);
                    StageMemoryToVRAM(VRAMSubregion_TexturePalette, buf, vramOffset, size, false, true);
                }
            } else if (obj->obj3D_.GetField9e() == 1) {
                unsigned int offset = tex->block4VRAMLoadOffset_;
                offset = obj->obj3D_.GetTexturePaletteOffset() != 0 ? obj->obj3D_.GetTexturePaletteOffset() : offset;
                unsigned int size = tex->block4NumEightBytes_ << 3;
                unsigned int vramOffset = (offset & 0xffff) << 3;
                buf = (unsigned short*)AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
                if (buf != NULL) {
                    for (unsigned int j = 0; j < size / 2; j++) {
                        buf[j] = color;
                    }
                    CleanInvalidateCacheRange(buf, size);
                    StageMemoryToVRAM(VRAMSubregion_TexturePalette, buf, vramOffset, size, false, true);
                }
            } else if (obj->obj3D_.GetField9e() == 2) {
                unsigned short* src;
                unsigned int offset = tex->block4VRAMLoadOffset_;
                offset = obj->obj3D_.GetTexturePaletteOffset() != 0 ? obj->obj3D_.GetTexturePaletteOffset() : offset;
                unsigned int size = tex->block4NumEightBytes_ << 3;
                offset = (offset & 0xffff) << 3;
                src = (unsigned short*)((char*)tex + tex->block4Offset_);
                buf = (unsigned short*)AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
                if (buf != NULL) {
                    float var23 = var1 / 31.0f;
                    float var24 = var2 / 31.0f;
                    float var25 = var3 / 31.0f;
                    for (unsigned int j = 0; j < size / 2; j++) {
                        unsigned short c = src[j];
                        unsigned short r = inline_ov017_0218f968(c);
                        unsigned short g = inline_ov017_0218f968_2(c);
                        unsigned short b = inline_ov017_0218f968_3(c);
                        unsigned short var31 = r * var23;
                        unsigned short var32 = g * var24;
                        unsigned short nb = b * var25;
                        buf[j] = var31 | (var32 << 5) | (nb << 10);
                    }
                    CleanInvalidateCacheRange(buf, size);
                    StageMemoryToVRAM(VRAMSubregion_TexturePalette, buf, offset, size, false, true);
                }
            }
        }
    }
    UnlockStagedTextureVRAMCopying();

    if (buf != NULL) {
        AllocatorUnion_Free(&g_mainAllocator, buf);
    }
}
