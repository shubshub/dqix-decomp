#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Model3D.h"
#include "Graphics/VRAMStaging.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Cache.h"

extern "C" GameObject* func_ov017_021bdbc0(unsigned char* base);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

struct Struct_ov017_021d6260 {
    int v[14];
};
extern struct Struct_ov017_021d6260 data_ov017_021d6260;
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

static inline unsigned int inline_ov017_0218fd34(NSBXXTex* tex) {
    return (tex->block4VRAMLoadOffset_ & 0xffff) << 3;
}

// USA: func_ov017_0218fd34
extern "C" ARM void func_ov017_0218fd34(unsigned char* ov, int idx, unsigned short color) {
    GameState* battleStruct = GameState::GetInstance();

    struct Struct_ov017_021d6260 table = data_ov017_021d6260;
    int base = idx * 12;
    table.v[0] = idx;
    table.v[1] = base + 0x13;
    table.v[2] = base + 0x14;
    table.v[3] = base + 0x16;
    table.v[4] = base + 0x17;
    table.v[5] = base + 0x18;
    table.v[6] = base + 0x19;
    table.v[7] = base + 0x1a;
    table.v[8] = base + 0x1b;
    table.v[9] = base + 0x1c;
    table.v[10] = base + 0x1d;

    unsigned short var3 = inline_ov017_0218f968(color);
    unsigned short var4 = inline_ov017_0218f968_2(color);
    unsigned short var5 = inline_ov017_0218f968_3(color);

    unsigned short* bufs[13] = {0};

    int mode = 0;
    GameObject* first = battleStruct->GetGameObjectByIndex(table.v[0]);
    if (first != NULL) {
        mode = first->obj3D_.GetField9e();
    }
    LockStagedTextureVRAMCopying();

    int i;
    int id;
    for (i = 0; (id = table.v[i]) > -1; i++) {
        GameObject* obj;
        if (id == 0xff) {
            obj = func_ov017_021bdbc0(ov);
        } else {
            obj = battleStruct->GetGameObjectByIndex(id);
        }
        if (obj == NULL) {
            continue;
        }
        if (obj->obj3D_.unknown_2_ <= -1 && id != 0xff) {
            continue;
        }
        Model3D* model = obj->obj3D_.pModel_;
        if (model == NULL) {
            continue;
        }
        NSBXXTex* tex = model->GetTEX0();
        if (tex == NULL) {
            continue;
        }
        unsigned short* src;
        unsigned int size;
        unsigned int offset;
        offset = inline_ov017_0218fd34(tex);
        src = (unsigned short*)((char*)tex + tex->block4Offset_);
        size = tex->block4NumEightBytes_ << 3;

        if (mode == 0) {
            bufs[i] = (unsigned short*)AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
            if (bufs[i] == NULL) {
                continue;
            }
            for (unsigned int j = 0; j < size / 2; j++) {
                unsigned short c = src[j];
                unsigned short r = inline_ov017_0218f968(c);
                unsigned short g = inline_ov017_0218f968_2(c);
                unsigned short b = inline_ov017_0218f968_3(c);
                r += var3;
                g += var4;
                b += var5;
                if (r > 31) {
                    r = 31;
                }
                if (g > 31) {
                    g = 31;
                }
                if (b > 31) {
                    b = 31;
                }
                bufs[i][j] = r | (g << 5) | (b << 10);
            }
            CleanInvalidateCacheRange(bufs[i], size);
            StageMemoryToVRAM(VRAMSubregion_TexturePalette, bufs[i], offset, size, false, true);
        } else if (mode == 1) {
            bufs[i] = (unsigned short*)AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
            if (bufs[i] == NULL) {
                continue;
            }
            for (unsigned int j = 0; j < size / 2; j++) {
                bufs[i][j] = color;
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
            for (unsigned int j = 0; j < size / 2; j++) {
                unsigned short c = src[j];
                unsigned short r = inline_ov017_0218f968(c);
                unsigned short g = inline_ov017_0218f968_2(c);
                unsigned short b = inline_ov017_0218f968_3(c);
                unsigned short var31 = r * var23;
                unsigned short var32 = g * var24;
                unsigned short nb = b * var25;
                bufs[i][j] = var31 | (var32 << 5) | (nb << 10);
            }
            CleanInvalidateCacheRange(bufs[i], size);
            StageMemoryToVRAM(VRAMSubregion_TexturePalette, bufs[i], offset, size, false, true);
        }
    }
    UnlockStagedTextureVRAMCopying();

    for (unsigned int k = 0; k < 13; k++) {
        if (bufs[k] != NULL) {
            AllocatorUnion_Free(&g_mainAllocator, bufs[k]);
        }
    }
}
