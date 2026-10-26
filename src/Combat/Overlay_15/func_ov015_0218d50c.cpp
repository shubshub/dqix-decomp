#include <globaldefs.h>
#include "Filesystem/GPC.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/Object3D.h"

static inline int FxMul(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

struct Elem0218d50c {
    int head[2];
    unsigned int lo : 4;
    unsigned int kind : 5;
};

struct Struct_ov015_0218d50c_3 {
    void* container;
    int** unknown_4_;
    SafeAllocator* allocs;
    void* unknown_c_;
    char pad10[0x20 - 0x10];
    int* ids;
    Object3D* ents;
    char pad28[4];
    unsigned char state;
    char unknown_2d_[0x3c - 0x2d];
    unsigned char unknown_3c_;
    unsigned char c3d;
    unsigned char unknown_3e_;
    char unknown_3f_;
    short unknown_40_;
    short unknown_42_;
    char unknown_44_[0x58 - 0x44];
    int unknown_58_;
    Object3D* inline_ov015_0218d50c(int i) { return &ents[i]; }
};

struct Vector3i;
extern "C" void OS_WaitVBlankIntr();
extern "C" void func_02079a3c(void*);
struct Foo0207df50;
extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void VramState_Restore(char*);
extern "C" void VramState_Save(char*);
struct ItemTable;
extern "C" void* ItemTable_Find(ItemTable*, int);
extern "C" int func_ov015_0218c03c(void* self, char* buf, int i, int one);
extern "C" void func_ov015_0218c3a4(void* self, int v);
extern "C" void func_ov015_0218c920(void* self, int zero);
extern "C" void* CharacterColors_GetInstance();
void LockStagedTextureVRAMCopying();
void UnlockStagedTextureVRAMCopying();
extern "C" void MemoryMapTexturePalette();
extern "C" void LoadToTexturePalette(void* dst, const void* src, int size);
extern "C" void MemoryUnmapTexturePalette();
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" int fix32_Divide(int, int);

struct Struct_ov015_0218d50c {
    char pad0[0x148];
    int count;
};

extern int g_fileLoadBuffer __attribute__((aligned(4)));
extern char data_ov015_02194094;
extern int data_ov015_02193d64[];
extern char data_ov015_021940f0;

// USA: func_ov015_0218d50c
extern "C" ARM int func_ov015_0218d50c(Struct_ov015_0218d50c_3* self) {
    int off70;
    char* pairs;
    int var2;
    SafeAllocator* alloc;
    bool changed;
    short id;

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    OS_WaitVBlankIntr();
    id = self->inline_ov015_0218d50c(7)->unknown_2_;
    if (self->ids[7] != id) {
        self->inline_ov015_0218d50c(3)->unknown_2_ = -1;
        self->inline_ov015_0218d50c(4)->unknown_2_ = -1;
    }
    id = self->inline_ov015_0218d50c(1)->unknown_2_;
    if (self->ids[1] != id) {
        self->inline_ov015_0218d50c(0)->unknown_2_ = -1;
    }
    changed = false;
    id = self->inline_ov015_0218d50c(8)->unknown_2_;
    if (self->ids[8] != id ||
        self->ids[1] != (id = self->inline_ov015_0218d50c(1)->unknown_2_)) {
        changed = true;
    }

    unsigned int size = 0;
    char* buf = (char*)&g_fileLoadBuffer;
    unsigned int var8 = 0x30000;
    GPCReadPair pair;
    char name[0x80];
    func_02079a3c(&pair);
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, &data_ov015_02194094,
                                                   buf, size, var8, false, 0)) {
        buf += size;
        var8 -= size;
        for (int i = 0; i < 10; i++) {
            if (self->state != 2 && self->ids[i] == (id = self->ents[i].unknown_2_)) {
                continue;
            }
            pairs = (char*)*self->unknown_4_;
            off70 = i * 0x70;
            alloc = self->allocs;
            var2 = i * 0x14;
            ((SafeAllocator*)((char*)alloc + var2))->Reset();
            VramState_Rewind((Foo0207df50*)(pairs + off70));
            Vector3fix savedPos = self->inline_ov015_0218d50c(i)->position_;
            self->ents[i].Initialize();
            self->ents[i].position_ = savedPos;
            self->ents[i].unknown_2_ = self->ids[i];
            if (self->ids[i] < 0) {
                continue;
            }
            Elem0218d50c* elem = (Elem0218d50c*)ItemTable_Find((ItemTable*)((char*)self->container + 0x4c), (short)self->ids[i]);
            if (elem == 0) {
                continue;
            }
            if (func_ov015_0218c03c(self, name, i, 0) == 0) {
                self->ents[i].Initialize();
                self->ents[i].unknown_2_ = -1;
                continue;
            }
            self->ents[i].Destroy();
            if (i == 0) {
                int a = FxMul(self->unknown_40_, self->unknown_42_);
                short var15 = (int)(0.065f * (float)a);
                short var16 = (int)(0.065f * (float)self->unknown_40_);
                self->ents[i].SetScale(var15, var16, var15);
                changed = true;
            } else if (!(i != 2 && i != 3 && i != 7 && i != 8 && i != 9)) {
                int var17 = fix32_Divide(0x1000, FxMul(self->unknown_40_, self->unknown_42_));
                int var18 = fix32_Divide(0x1000, self->unknown_40_);
                int sz = var17;
                if (!(i != 2 && i != 3 && i != 7)) {
                    var17 = (int)(((long long)var17 * (int)((float)self->unknown_40_ - 0.5f * (float)(self->unknown_40_ - 0x1000)) + 0x800) >> 12);
                    var18 = (int)(((long long)var18 * (int)((float)self->unknown_40_ - 0.5f * (float)(self->unknown_40_ - 0x1000)) + 0x800) >> 12);
                    sz = (int)(((long long)sz * (int)((float)self->unknown_40_ - 0.5f * (float)(self->unknown_40_ - 0x1000)) + 0x800) >> 12);
                }
                self->ents[i].SetScale(var17, var18, sz);
            } else if (!(i != 6 && i != 5 && i != 1)) {
                int a = FxMul(self->unknown_40_, self->unknown_42_);
                short var21 = (int)(0.065f * (float)a);
                short var22 = (int)(0.065f * (float)self->unknown_40_);
                self->ents[i].SetScale(var21, var22, var21);
            }
            if (i == 8 || i == 1) {
                changed = true;
                if (elem->kind == 6) {
                    self->unknown_58_ = 1;
                } else {
                    self->unknown_58_ = 0;
                }
            }
            VramState_Restore(pairs + off70);
            DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf, size, var8, name);
            self->ents[i].SetModelFromFileCopy((SafeAllocator*)((char*)alloc + var2), buf, size, Model3D::TextureStagingMode_Normal);
            buf += size;
            var8 -= size;
            VramState_Save(pairs + off70);
            if (i == 4 && self->inline_ov015_0218d50c(3)->pModel_ != 0) {
                self->inline_ov015_0218d50c(3)->pModel_->ApplyTexturesFromModel(self->ents[i].pModel_);
            }
        }
        pair.Reset();
    }
    char* tbl = (char*)CharacterColors_GetInstance();
    unsigned int n = ((Struct_ov015_0218d50c*)*self->unknown_4_)->count;
    unsigned int cnt = (n << 16) >> 13;
    if (cnt != 0) {
        CleanInvalidateCacheRange(tbl + self->unknown_3c_ * 4, 4);
        CleanInvalidateCacheRange(tbl + 0x108 + self->c3d * 4, 4);
        CleanInvalidateCacheRange(tbl + 0x88 + self->unknown_3e_ * 16, 0x10);
        OS_WaitVBlankIntr();
        LockStagedTextureVRAMCopying();
        MemoryMapTexturePalette();
        LoadToTexturePalette(tbl + self->unknown_3c_ * 4, (char*)cnt + 0x24, 4);
        LoadToTexturePalette(tbl + 0x108 + self->c3d * 4, (char*)cnt + 0x28, 4);
        LoadToTexturePalette(tbl + 0x88 + self->unknown_3e_ * 16, (char*)cnt + 0x30, 0x10);
        MemoryUnmapTexturePalette();
        UnlockStagedTextureVRAMCopying();
    }
    for (int k = 0; data_ov015_02193d64[k] >= 0; k++) {
        func_ov015_0218c3a4(self, data_ov015_02193d64[k]);
    }
    if (changed) {
        func_ov015_0218c920(self, 0);
    }
    self->state = 0;
    self->unknown_c_ = &data_ov015_021940f0;
    BackgroundLoader::RemoveLockGlobal();
    int result = 1;
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
    return result;
}
