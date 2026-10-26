#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" void MemoryMapTexturePalette(void);
extern "C" void LoadToTexturePalette(void* ptr, int a, unsigned int b);
extern "C" void MemoryUnmapTexturePalette(void);
void LockStagedTextureVRAMCopying(void);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void UnlockStagedTextureVRAMCopying(void);

struct Struct_ov003_0217ca84 {
    SafeAllocator* allocator;
    char pad4[0x88 - 4];
    void* unknown_88_;
};

struct Struct_ov003_0217ca84_2 {
    char pad0[0x2c];
    int field2c;
    char unknown_30_[0x30 - 0x30];
    unsigned short unknown1_30_;
};

// USA: func_ov003_0217ca84
extern "C" ARM void func_ov003_0217ca84(Struct_ov003_0217ca84* obj, unsigned short arg1) {
    GameState::GetInstance();
    LockStagedTextureVRAMCopying();
    MemoryMapTexturePalette();

    void* var0 = obj->unknown_88_;
    if (var0 != NULL) {
        Struct_ov003_0217ca84_2* inner = (Struct_ov003_0217ca84_2*)((Model3D*)var0)->GetTEX0();
        if (inner != NULL) {
            int size = inner->field2c;
            if (((Object3D*)((unsigned char*)obj + 0x80))->GetTexturePaletteOffset()) {
                size = ((Object3D*)((unsigned char*)obj + 0x80))->GetTexturePaletteOffset();
            }

            void* buf;
            unsigned int allocSize = (unsigned int)inner->unknown1_30_ << 3;
            int var5 = (unsigned short)size << 3;

            buf = obj->allocator->Allocate(allocSize);
            if (buf != NULL) {
                unsigned int i;
                for (i = 0; i < allocSize / 2; i++) {
                    ((unsigned short*)buf)[i] = arg1;
                }
                CleanInvalidateCacheRange(buf, allocSize);
                LoadToTexturePalette(buf, var5, allocSize);
            }
        }
    }

    MemoryUnmapTexturePalette();
    UnlockStagedTextureVRAMCopying();
}
