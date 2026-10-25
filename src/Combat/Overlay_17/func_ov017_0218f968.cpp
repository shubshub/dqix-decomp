#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Model3D.h"
#include "Graphics/VRAMStaging.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Cache.h"

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

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

// USA: func_ov017_0218f968
extern "C" ARM void func_ov017_0218f968(unsigned char* arg0, int arg1, unsigned short arg2) {
    GameState* var0 = GameState::GetInstance();

    unsigned short var1 = inline_ov017_0218f968(arg2);
    unsigned short var2 = inline_ov017_0218f968_2(arg2);
    unsigned short var3 = inline_ov017_0218f968_3(arg2);

    unsigned short* var4 = NULL;

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
                        unsigned short r = GetColorR(c);
                        unsigned short g = GetColorG(c);
                        unsigned short b = GetColorB(c);
                        r += addR;
                        g += addG;
                        b += addB;
                        if (r > 31) {
                            r = 31;
                        }
                        if (var14 > 31) {
                            var14 = 31;
                        }
                        if (var15 > 31) {
                            var15 = 31;
                        }
                        var4[var11] = var13 | (var14 << 5) | (var15 << 10);
                    }
                    CleanInvalidateCacheRange(var4, var8);
                    StageMemoryToVRAM(VRAMSubregion_TexturePalette, var4, var9, var8, false, true);
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
                    CleanInvalidateCacheRange(var4, var17);
                    StageMemoryToVRAM(VRAMSubregion_TexturePalette, var4, var18, var17, false, true);
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
                    float scaleR = addR / 31.0f;
                    float scaleG = addG / 31.0f;
                    float scaleB = addB / 31.0f;
                    for (unsigned int j = 0; j < size / 2; j++) {
                        unsigned short c = src[j];
                        unsigned short r = GetColorR(c);
                        unsigned short g = GetColorG(c);
                        unsigned short b = GetColorB(c);
                        unsigned short nr = r * scaleR;
                        unsigned short ng = g * scaleG;
                        unsigned short nb = b * scaleB;
                        buf[j] = nr | (ng << 5) | (nb << 10);
                    }
                    CleanInvalidateCacheRange(var4, var22);
                    StageMemoryToVRAM(VRAMSubregion_TexturePalette, var4, var21, var22, false, true);
                }
            }
        }
    }
    UnlockStagedTextureVRAMCopying();

    if (buf != NULL) {
        AllocatorUnion_Free(&g_mainAllocator, buf);
    }
}
