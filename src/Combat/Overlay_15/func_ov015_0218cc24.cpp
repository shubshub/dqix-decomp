#include <globaldefs.h>
#include "Filesystem/GPC.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/Object3D.h"

static inline int inline_02061c04_5(int arg0, int arg1) { return (int)(((long long)arg0 * arg1 + 0x800) >> 12); }

struct Struct_ov015_0218cc24 {
    int unknown_0_[2];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 5;
};

struct Struct_ov015_0218cc24_2 {
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
    char unknown_44_[0x50 - 0x44];
    unsigned char unknown_50_;
    char unknown_51_[3];
    int unknown_54_;
    Object3D* inline_ov015_0218cc24(int arg0) { return &unknown_24_[arg0]; }
};

struct Vector3i;
void DelayThenSyncBit0_020c9820();
void ResetObjectState02079a3c(void*);
struct Foo0207df50;
void VramState_Rewind(Foo0207df50*);
void VramState_Restore(char*);
void VramState_Save(char*);
struct ItemTable;
void* ItemTable_Find(ItemTable*, int);
extern "C" int func_ov015_0218c03c(void* self, char* buf, int i, int one);
extern "C" void func_ov015_0218c538(void* self, int zero);
extern "C" void func_ov015_0218c3a4(void* self, int v);
extern "C" void func_02099e18(void* a, int b, int c, int d);
struct Fields020407b4;
void SetFields0x44(Fields020407b4*, int, int, int);
extern "C" int fix32_Divide(int, int);

extern int g_fileLoadBuffer __attribute__((aligned(4)));
extern char data_ov015_021940c0;
extern char data_ov015_021940db;
extern char data_ov015_021940e1;
extern char data_ov015_021940e7;
extern int data_ov015_02193d48[];
extern char data_ov015_021940ed;

// USA: func_ov015_0218cc24
extern "C" ARM int func_ov015_0218cc24(Struct_ov015_0218cc24_2* arg0) {
    int var0;
    char* var1;
    bool var2;
    int var3;
    SafeAllocator* var4;
    short var5;

    func_020c9820();
    var5 = arg0->inline_ov015_0218cc24(7)->unknown_2_;
    if (arg0->unknown_20_[7] != var5) {
        arg0->inline_ov015_0218cc24(3)->unknown_2_ = -1;
        arg0->inline_ov015_0218cc24(4)->unknown_2_ = -1;
    }
    var5 = arg0->inline_ov015_0218cc24(1)->unknown_2_;
    if (arg0->unknown_20_[1] != var5) {
        arg0->inline_ov015_0218cc24(0)->unknown_2_ = -1;
    }
    var2 = false;
    var5 = arg0->inline_ov015_0218cc24(8)->unknown_2_;
    if (arg0->unknown_20_[8] != var5 ||
        arg0->unknown_20_[1] != (var5 = arg0->inline_ov015_0218cc24(1)->unknown_2_) ||
        arg0->unknown_20_[6] != (var5 = arg0->inline_ov015_0218cc24(6)->unknown_2_)) {
        var2 = true;
    }
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    unsigned int size = 0;
    char* buf = (char*)&g_fileLoadBuffer;
    unsigned int room = 0x30000;
    GPCReadPair pair;
    char name[0x80];
    ResetObjectState02079a3c(&pair);
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, &data_ov015_021940c0,
                                                   buf, size, room, false, 0)) {
        buf += size;
        room -= size;
        for (int i = 0; i < 10; i++) {
            if (self->state != 2 && self->ids[i] == (id = self->ents[i].unknown_2_)) {
                continue;
            }
            Vector3fix savedPos = self->ents[i].position_;
            pairs = (char*)*self->pairsRoot;
            off70 = i * 0x70;
            alloc = self->allocs;
            off14 = i * 0x14;
            ((SafeAllocator*)((char*)alloc + off14))->Reset();
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
            if (func_ov015_0218c03c(arg0, var10, var11, 1) == 0) {
                continue;
            }
            arg0->unknown_24_[var11].Destroy();
            if (!(var11 != 0 && var11 != 1)) {
                int var14 = inline_02061c04_5(arg0->unknown_40_, arg0->unknown_42_);
                short var15 = (int)(0.065f * (float)var14);
                short var16 = (int)(0.065f * (float)arg0->unknown_40_);
                arg0->unknown_24_[var11].SetScale(var15, var16, var15);
                var2 = true;
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
                if (var11 == 8) {
                    void* var20 = arg0->inline_ov015_0218cc24(0)->pModel_;
                    arg0->unknown_54_ = 0;
                    if (var13->unknown_8_4_ == 4) {
                        func_020407b4((Struct_02040774_2*)&arg0->unknown_24_[var11], 0, 0, 0);
                        if (var20) {
                            arg0->unknown_50_ = ((Model3D*)var20)->GetBoneIndex(&data_ov015_021940db);
                        }
                    } else if (var13->unknown_8_4_ == 6) {
                        func_020407b4((Struct_02040774_2*)&arg0->unknown_24_[var11], 0, 0, 0);
                        if (var20) {
                            arg0->unknown_50_ = ((Model3D*)var20)->GetBoneIndex(&data_ov015_021940e1);
                        }
                        arg0->unknown_54_ = 1;
                    } else {
                        if (var13->unknown_8_4_ == 0xb) {
                            short var21 = arg0->unknown_40_;
                            int var22 = (int)(((long long)var21 * 9830LL + 0x800) >> 12);
                            int var23 = (int)(((long long)var21 * -1638LL + 0x800) >> 12);
                            func_020407b4((Struct_02040774_2*)&arg0->unknown_24_[var11], var22, var23, 0);
                            if (var20) {
                                arg0->unknown_50_ = ((Model3D*)var20)->GetBoneIndex(&data_ov015_021940e7);
                            }
                        } else {
                            short var24 = arg0->unknown_40_;
                            int var25 = (int)(((long long)var24 * -9830LL + 0x800) >> 12);
                            int var26 = (int)(((long long)var24 * -1638LL + 0x800) >> 12);
                            func_020407b4((Struct_02040774_2*)&arg0->unknown_24_[var11], var25, var26, 0);
                            if (var20) {
                                arg0->unknown_50_ = ((Model3D*)var20)->GetBoneIndex(&data_ov015_021940e1);
                            }
                        }
                    }
                }
                if (var11 == 9) {
                    short var27 = arg0->unknown_40_;
                    func_020407b4((Struct_02040774_2*)&arg0->unknown_24_[var11], (int)(((long long)var27 * 0x2000LL + 0x800) >> 12), 0, 0);
                }
            }
            VramState_Restore(pairs + off70);
            DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf, size, room, name);
            self->ents[i].SetModelFromFileCopy((SafeAllocator*)((char*)alloc + off14), buf, size, Model3D::TextureStagingMode_Normal);
            buf += size;
            room -= size;
            VramState_Save(pairs + off70);
            if (i == 4 && self->GetEnt(3)->pModel_ != 0) {
                ((Model3D*)self->GetEnt(3)->pModel_)->ApplyTexturesFromModel((Model3D*)self->ents[i].pModel_);
            }
            void* var28 = arg0->unknown_24_[var11].pModel_;
            if (var28 == 0) {
                continue;
            }
            if (var11 == 0) {
                ((Model3D*)var28)->CreateBoneMatrixAndMaterialArrays((SafeAllocator*)((char*)var4 + var3), 7);
                ((Model3D*)var28)->StoreBoneMatrixAndMaterialArrayPointers();
            } else if (!(var11 == 1 || var11 == 6 || var11 == 5 || var11 == 4)) {
                ((Model3D*)var28)->CreateBoneMatrixAndMaterialArrays((SafeAllocator*)((char*)var4 + var3), 5);
                ((Model3D*)var28)->StoreBoneMatrixAndMaterialArrayPointers();
            }
        }
        var9.Reset();
    }
    if (var2) {
        func_ov015_0218c538(arg0, 0);
    }
    void* var29 = arg0->inline_ov015_0218cc24(0)->pModel_;
    if (var29) {
        ((Model3D*)var29)->RemoveTextures();
        if (arg0->inline_ov015_0218cc24(5)->unknown_2_ >= 0 && arg0->inline_ov015_0218cc24(5)->pModel_) {
            ((Model3D*)var29)->ApplyTexturesFromModel((Model3D*)arg0->inline_ov015_0218cc24(5)->pModel_);
        }
        ((Model3D*)var29)->ApplyTexturesFromModel((Model3D*)var29);
    }
    void* var30 = arg0->inline_ov015_0218cc24(1)->pModel_;
    if (var30) {
        ((Model3D*)var30)->RemoveTextures();
        if (arg0->inline_ov015_0218cc24(6)->unknown_2_ >= 0 && arg0->inline_ov015_0218cc24(6)->pModel_) {
            ((Model3D*)var30)->ApplyTexturesFromModel((Model3D*)arg0->inline_ov015_0218cc24(6)->pModel_);
        }
        ((Model3D*)var30)->ApplyTexturesFromModel((Model3D*)var30);
    }
    func_02099e18(arg0->inline_ov015_0218cc24(2)->pModel_, arg0->unknown_3e_, arg0->unknown_3c_, arg0->unknown_3d_);
    for (int var31 = 0; data_ov015_02193d48[var31] >= 0; var31++) {
        func_ov015_0218c3a4(arg0, data_ov015_02193d48[var31]);
    }
    BackgroundLoader::RemoveLockGlobal();
    arg0->unknown_2c_ = 0;
    arg0->unknown_c_ = &data_ov015_021940ed;
    int var32 = 1;
    var9.Reset();
    ZeroDestroyGPCPointer(&var9.pGPCFile);
    return var32;
}
