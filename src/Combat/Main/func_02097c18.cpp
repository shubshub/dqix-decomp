#include <globaldefs.h>

void LockStagedTextureVRAMCopying();
extern "C" void MapVRAMBanksToTextureImage(int handle);
extern "C" void MapVRAMBanksToTexturePalette(int value);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToMainObj(int mode);
extern "C" ARM void func_020bb48c(unsigned int mode, int arg1);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void MapVRAMBanksToSubObj(int value);
void UpdateVRAMStagingVRAMBanks(void);
void UnlockStagedTextureVRAMCopying(void);

struct Struct_02097c18 {
    char pad[0x1e];
    unsigned char unknown_1e_;
};

// USA: func_02097c18
extern "C" ARM void func_02097c18(struct Struct_02097c18* obj, unsigned char flags, unsigned int arg2, int field4Val, int arg4, int arg5, int arg6, int arg7) {
    LockStagedTextureVRAMCopying();
    obj->unknown_1e_ = flags;
    if (flags & 1) {
        unsigned int mask;
        unsigned short count;

        MapVRAMBanksToTextureImage(arg2);
        MapVRAMBanksToTexturePalette(field4Val);
        MapVRAMBanksToMainBG(arg4);
        MapVRAMBanksToMainObj(arg5);

        mask = arg2;
        count = 0;
        while (mask != 0) {
            count = count + 1;
            mask &= mask - 1;
        }
        func_020bb48c(count, 1);
    }
    if (flags & 2) {
        MapVRAMBanksToSubBG(arg6);
        MapVRAMBanksToSubObj(arg7);
    }
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
}
