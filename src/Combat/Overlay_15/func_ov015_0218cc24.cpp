#include <globaldefs.h>
#include "Filesystem/GPC.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/Object3D.h"

static inline int FxMul(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

struct Elem0218cc24 {
    int head[2];
    unsigned int lo : 4;
    unsigned int kind : 5;
};

struct Struct_ov015_0218cc24_2 {
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
    char unknown_44_[0x50 - 0x44];
    unsigned char unknown_50_;
    char unknown_51_[3];
    int unknown_54_;
    Object3D* inline_ov015_0218cc24(int i) { return &ents[i]; }
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
extern "C" void func_ov015_0218c538(void* self, int zero);
extern "C" void func_ov015_0218c3a4(void* self, int v);
extern "C" void func_02099e18(void* a, int b, int c, int d);
struct Fields020407b4;
extern "C" void func_020407b4(Fields020407b4*, int, int, int);
extern "C" int fix32_Divide(int, int);

extern int g_fileLoadBuffer __attribute__((aligned(4)));
extern char data_ov015_021940c0;
extern char data_ov015_021940db;
extern char data_ov015_021940e1;
extern char data_ov015_021940e7;
extern int data_ov015_02193d48[];
extern char data_ov015_021940ed;

// USA: func_ov015_0218cc24
extern "C" ARM int func_ov015_0218cc24(Struct_ov015_0218cc24_2* self) {
    int off70;
    char* pairs;
    bool changed;
    int var3;
    SafeAllocator* alloc;
    short id;

    OS_WaitVBlankIntr();
    id = self->inline_ov015_0218cc24(7)->unknown_2_;
    if (self->ids[7] != id) {
        self->inline_ov015_0218cc24(3)->unknown_2_ = -1;
        self->inline_ov015_0218cc24(4)->unknown_2_ = -1;
    }
    id = self->inline_ov015_0218cc24(1)->unknown_2_;
    if (self->ids[1] != id) {
        self->inline_ov015_0218cc24(0)->unknown_2_ = -1;
    }
    changed = false;
    id = self->inline_ov015_0218cc24(8)->unknown_2_;
    if (self->ids[8] != id ||
        self->ids[1] != (id = self->inline_ov015_0218cc24(1)->unknown_2_) ||
        self->ids[6] != (id = self->inline_ov015_0218cc24(6)->unknown_2_)) {
        changed = true;
    }
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    unsigned int size = 0;
    char* buf = (char*)&g_fileLoadBuffer;
    unsigned int var8 = 0x30000;
    GPCReadPair pair;
    char name[0x80];
    func_02079a3c(&pair);
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, &data_ov015_021940c0,
                                                   buf, size, var8, false, 0)) {
        buf += size;
        var8 -= size;
        for (int i = 0; i < 10; i++) {
            if (self->state != 2 && self->ids[i] == (id = self->ents[i].unknown_2_)) {
                continue;
            }
            Vector3fix savedPos = self->ents[i].position_;
            pairs = (char*)*self->unknown_4_;
            off70 = i * 0x70;
            alloc = self->allocs;
            var3 = i * 0x14;
            ((SafeAllocator*)((char*)alloc + var3))->Reset();
            VramState_Rewind((Foo0207df50*)(pairs + off70));
            self->ents[i].Initialize();
            self->ents[i].position_ = savedPos;
            self->ents[i].unknown_2_ = self->ids[i];
            if (self->ids[i] < 0) {
                continue;
            }
            Elem0218cc24* elem = (Elem0218cc24*)ItemTable_Find((ItemTable*)((char*)self->container + 0x4c), (short)self->ids[i]);
            if (elem == 0) {
                continue;
            }
            if (func_ov015_0218c03c(self, name, i, 1) == 0) {
                continue;
            }
            self->ents[i].Destroy();
            if (!(i != 0 && i != 1)) {
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
                if (i == 8) {
                    void* m = self->inline_ov015_0218cc24(0)->pModel_;
                    self->unknown_54_ = 0;
                    if (elem->kind == 4) {
                        func_020407b4((Fields020407b4*)&self->ents[i], 0, 0, 0);
                        if (m) {
                            self->unknown_50_ = ((Model3D*)m)->GetBoneIndex(&data_ov015_021940db);
                        }
                    } else if (elem->kind == 6) {
                        func_020407b4((Fields020407b4*)&self->ents[i], 0, 0, 0);
                        if (m) {
                            self->unknown_50_ = ((Model3D*)m)->GetBoneIndex(&data_ov015_021940e1);
                        }
                        self->unknown_54_ = 1;
                    } else {
                        if (elem->kind == 0xb) {
                            short v = self->unknown_40_;
                            int x = (int)(((long long)v * 9830LL + 0x800) >> 12);
                            int y = (int)(((long long)v * -1638LL + 0x800) >> 12);
                            func_020407b4((Fields020407b4*)&self->ents[i], x, y, 0);
                            if (m) {
                                self->unknown_50_ = ((Model3D*)m)->GetBoneIndex(&data_ov015_021940e7);
                            }
                        } else {
                            short v = self->unknown_40_;
                            int x = (int)(((long long)v * -9830LL + 0x800) >> 12);
                            int y = (int)(((long long)v * -1638LL + 0x800) >> 12);
                            func_020407b4((Fields020407b4*)&self->ents[i], x, y, 0);
                            if (m) {
                                self->unknown_50_ = ((Model3D*)m)->GetBoneIndex(&data_ov015_021940e1);
                            }
                        }
                    }
                }
                if (i == 9) {
                    short v = self->unknown_40_;
                    func_020407b4((Fields020407b4*)&self->ents[i], (int)(((long long)v * 0x2000LL + 0x800) >> 12), 0, 0);
                }
            }
            VramState_Restore(pairs + off70);
            DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf, size, var8, name);
            self->ents[i].SetModelFromFileCopy((SafeAllocator*)((char*)alloc + var3), buf, size, Model3D::TextureStagingMode_Normal);
            buf += size;
            var8 -= size;
            VramState_Save(pairs + off70);
            if (i == 4 && self->inline_ov015_0218cc24(3)->pModel_ != 0) {
                ((Model3D*)self->inline_ov015_0218cc24(3)->pModel_)->ApplyTexturesFromModel((Model3D*)self->ents[i].pModel_);
            }
            void* model = self->ents[i].pModel_;
            if (model == 0) {
                continue;
            }
            if (i == 0) {
                ((Model3D*)model)->CreateBoneMatrixAndMaterialArrays((SafeAllocator*)((char*)alloc + var3), 7);
                ((Model3D*)model)->StoreBoneMatrixAndMaterialArrayPointers();
            } else if (!(i == 1 || i == 6 || i == 5 || i == 4)) {
                ((Model3D*)model)->CreateBoneMatrixAndMaterialArrays((SafeAllocator*)((char*)alloc + var3), 5);
                ((Model3D*)model)->StoreBoneMatrixAndMaterialArrayPointers();
            }
        }
        pair.Reset();
    }
    if (changed) {
        func_ov015_0218c538(self, 0);
    }
    void* var29 = self->inline_ov015_0218cc24(0)->pModel_;
    if (var29) {
        ((Model3D*)var29)->RemoveTextures();
        if (self->inline_ov015_0218cc24(5)->unknown_2_ >= 0 && self->inline_ov015_0218cc24(5)->pModel_) {
            ((Model3D*)var29)->ApplyTexturesFromModel((Model3D*)self->inline_ov015_0218cc24(5)->pModel_);
        }
        ((Model3D*)var29)->ApplyTexturesFromModel((Model3D*)var29);
    }
    void* var30 = self->inline_ov015_0218cc24(1)->pModel_;
    if (var30) {
        ((Model3D*)var30)->RemoveTextures();
        if (self->inline_ov015_0218cc24(6)->unknown_2_ >= 0 && self->inline_ov015_0218cc24(6)->pModel_) {
            ((Model3D*)var30)->ApplyTexturesFromModel((Model3D*)self->inline_ov015_0218cc24(6)->pModel_);
        }
        ((Model3D*)var30)->ApplyTexturesFromModel((Model3D*)var30);
    }
    func_02099e18(self->inline_ov015_0218cc24(2)->pModel_, self->unknown_3e_, self->unknown_3c_, self->c3d);
    for (int k = 0; data_ov015_02193d48[k] >= 0; k++) {
        func_ov015_0218c3a4(self, data_ov015_02193d48[k]);
    }
    BackgroundLoader::RemoveLockGlobal();
    self->state = 0;
    self->unknown_c_ = &data_ov015_021940ed;
    int result = 1;
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
    return result;
}
