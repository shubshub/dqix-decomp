#include <globaldefs.h>
#include "Filesystem/GPC.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/Object3D.h"

static inline int inline_02061c04_5(int arg0, int arg1) { return (int)(((long long)arg0 * arg1 + 0x800) >> 12); }

struct Struct_ov015_0218d50c_2 {
    int unknown_0_[2];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 5;
};

struct Struct_ov015_0218d50c_3 {
    void* unknown_0_;
    int** unknown_4_;
    SafeAllocator* unknown_8_;
    void* unknown_c_;
    char unknown_10_[0x20 - 0x10];
    int* unknown_20_;
    Object3D* unknown_24_;
    char unknown_28_[4];
    unsigned char unknown_2c_;
    char unknown_2d_[0x3c - 0x2d];
    unsigned char unknown_3c_;
    unsigned char unknown_3d_;
    unsigned char unknown_3e_;
    char unknown_3f_;
    short unknown_40_;
    short unknown_42_;
    char unknown_44_[0x58 - 0x44];
    int unknown_58_;
    Object3D* inline_ov015_0218d50c(int arg0) { return &unknown_24_[arg0]; }
};

struct Vector3i;
void DelayThenSyncBit0_020c9820();
void ResetObjectState02079a3c(void*);
struct Foo0207df50;
void CopyInternalFields0207df50(Foo0207df50*);
void VramState_Restore(char*);
void VramState_Save(char*);
struct Container020dedd0;
void* FindElementByKey020dedd0(Container020dedd0*, int);
extern "C" int func_ov015_0218c03c(void* self, char* buf, int i, int one);
extern "C" void func_ov015_0218c3a4(void* self, int v);
extern "C" void func_ov015_0218c920(void* self, int zero);
void* GetVariantShortTable02109928_02099cac();
void LockStagedTextureVRAMCopying();
void UnlockStagedTextureVRAMCopying();
extern "C" void MemoryMapTexturePalette();
extern "C" void LoadToTexturePalette(void* dst, const void* src, int size);
extern "C" void MemoryUnmapTexturePalette();
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" int fix32_Divide(int, int);

struct Struct_ov015_0218d50c {
    char unknown_0_[0x148];
    int unknown_148_;
};

extern int data_0211e33c __attribute__((aligned(4)));
extern char data_ov015_02194094;
extern int data_ov015_02193d64[];
extern char data_ov015_021940f0;

// USA: func_ov015_0218d50c
extern "C" ARM int func_ov015_0218d50c(Struct_ov015_0218d50c_3* arg0) {
    int var0;
    char* var1;
    int var2;
    SafeAllocator* var3;
    bool var4;
    short var5;

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    func_020c9820();
    var5 = arg0->inline_ov015_0218d50c(7)->unknown_2_;
    if (arg0->unknown_20_[7] != var5) {
        arg0->inline_ov015_0218d50c(3)->unknown_2_ = -1;
        arg0->inline_ov015_0218d50c(4)->unknown_2_ = -1;
    }
    var5 = arg0->inline_ov015_0218d50c(1)->unknown_2_;
    if (arg0->unknown_20_[1] != var5) {
        arg0->inline_ov015_0218d50c(0)->unknown_2_ = -1;
    }
    var4 = false;
    var5 = arg0->inline_ov015_0218d50c(8)->unknown_2_;
    if (arg0->unknown_20_[8] != var5 ||
        arg0->unknown_20_[1] != (var5 = arg0->inline_ov015_0218d50c(1)->unknown_2_)) {
        var4 = true;
    }

    unsigned int var6 = 0;
    char* var7 = (char*)&data_0211e33c;
    unsigned int var8 = 0x30000;
    GPCReadPair var9;
    char var10[0x80];
    func_02079a3c(&var9);
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&var9.pGPCFile, var9.machine, &data_ov015_02194094,
                                                   var7, var6, var8, false, 0)) {
        var7 += var6;
        var8 -= var6;
        for (int var11 = 0; var11 < 10; var11++) {
            if (arg0->unknown_2c_ != 2 && arg0->unknown_20_[var11] == (var5 = arg0->unknown_24_[var11].unknown_2_)) {
                continue;
            }
            var1 = (char*)*arg0->unknown_4_;
            var0 = var11 * 0x70;
            var3 = arg0->unknown_8_;
            var2 = var11 * 0x14;
            ((SafeAllocator*)((char*)var3 + var2))->Reset();
            func_0207df50((Struct_0203d028*)(var1 + var0));
            Vector3fix var12 = arg0->inline_ov015_0218d50c(var11)->position_;
            arg0->unknown_24_[var11].Initialize();
            arg0->unknown_24_[var11].position_ = var12;
            arg0->unknown_24_[var11].unknown_2_ = arg0->unknown_20_[var11];
            if (arg0->unknown_20_[var11] < 0) {
                continue;
            }
            Struct_ov015_0218d50c_2* var13 = (Struct_ov015_0218d50c_2*)func_020dedd0((Struct_0201099c_10*)((char*)arg0->unknown_0_ + 0x4c), (short)arg0->unknown_20_[var11]);
            if (var13 == 0) {
                continue;
            }
            if (func_ov015_0218c03c(arg0, var10, var11, 0) == 0) {
                arg0->unknown_24_[var11].Initialize();
                arg0->unknown_24_[var11].unknown_2_ = -1;
                continue;
            }
            arg0->unknown_24_[var11].Destroy();
            if (var11 == 0) {
                int var14 = inline_02061c04_5(arg0->unknown_40_, arg0->unknown_42_);
                short var15 = (int)(0.065f * (float)var14);
                short var16 = (int)(0.065f * (float)arg0->unknown_40_);
                arg0->unknown_24_[var11].SetScale(var15, var16, var15);
                var4 = true;
            } else if (!(var11 != 2 && var11 != 3 && var11 != 7 && var11 != 8 && var11 != 9)) {
                int var17 = fix32_Divide(0x1000, inline_02061c04_5(arg0->unknown_40_, arg0->unknown_42_));
                int var18 = fix32_Divide(0x1000, arg0->unknown_40_);
                int var19 = var17;
                if (!(var11 != 2 && var11 != 3 && var11 != 7)) {
                    var17 = (int)(((long long)var17 * (int)((float)arg0->unknown_40_ - 0.5f * (float)(arg0->unknown_40_ - 0x1000)) + 0x800) >> 12);
                    var18 = (int)(((long long)var18 * (int)((float)arg0->unknown_40_ - 0.5f * (float)(arg0->unknown_40_ - 0x1000)) + 0x800) >> 12);
                    var19 = (int)(((long long)var19 * (int)((float)arg0->unknown_40_ - 0.5f * (float)(arg0->unknown_40_ - 0x1000)) + 0x800) >> 12);
                }
                arg0->unknown_24_[var11].SetScale(var17, var18, var19);
            } else if (!(var11 != 6 && var11 != 5 && var11 != 1)) {
                int var20 = inline_02061c04_5(arg0->unknown_40_, arg0->unknown_42_);
                short var21 = (int)(0.065f * (float)var20);
                short var22 = (int)(0.065f * (float)arg0->unknown_40_);
                arg0->unknown_24_[var11].SetScale(var21, var22, var21);
            }
            if (var11 == 8 || var11 == 1) {
                var4 = true;
                if (var13->unknown_8_4_ == 6) {
                    arg0->unknown_58_ = 1;
                } else {
                    arg0->unknown_58_ = 0;
                }
            }
            VramState_Restore(pairs + off70);
            DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf, size, room, name);
            self->ents[i].SetModelFromFileCopy((SafeAllocator*)((char*)alloc + off14), buf, size, Model3D::TextureStagingMode_Normal);
            buf += size;
            room -= size;
            VramState_Save(pairs + off70);
            if (i == 4 && self->GetEnt(3)->pModel_ != 0) {
                self->GetEnt(3)->pModel_->ApplyTexturesFromModel(self->ents[i].pModel_);
            }
        }
        var9.Reset();
    }
    char* var23 = (char*)func_02099cac();
    unsigned int var24 = ((Struct_ov015_0218d50c*)*arg0->unknown_4_)->unknown_148_;
    unsigned int var25 = (var24 << 16) >> 13;
    if (var25 != 0) {
        CleanInvalidateCacheRange(var23 + arg0->unknown_3c_ * 4, 4);
        CleanInvalidateCacheRange(var23 + 0x108 + arg0->unknown_3d_ * 4, 4);
        CleanInvalidateCacheRange(var23 + 0x88 + arg0->unknown_3e_ * 16, 0x10);
        func_020c9820();
        LockStagedTextureVRAMCopying();
        MemoryMapTexturePalette();
        LoadToTexturePalette(var23 + arg0->unknown_3c_ * 4, (char*)var25 + 0x24, 4);
        LoadToTexturePalette(var23 + 0x108 + arg0->unknown_3d_ * 4, (char*)var25 + 0x28, 4);
        LoadToTexturePalette(var23 + 0x88 + arg0->unknown_3e_ * 16, (char*)var25 + 0x30, 0x10);
        MemoryUnmapTexturePalette();
        UnlockStagedTextureVRAMCopying();
    }
    for (int var26 = 0; data_ov015_02193d64[var26] >= 0; var26++) {
        func_ov015_0218c3a4(arg0, data_ov015_02193d64[var26]);
    }
    if (var4) {
        func_ov015_0218c920(arg0, 0);
    }
    arg0->unknown_2c_ = 0;
    arg0->unknown_c_ = &data_ov015_021940f0;
    BackgroundLoader::RemoveLockGlobal();
    int var27 = 1;
    var9.Reset();
    ZeroDestroyGPCPointer(&var9.pGPCFile);
    return var27;
}
