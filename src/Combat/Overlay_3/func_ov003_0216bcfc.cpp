#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include "NitroSDK/Memory.h"
#include <globaldefs.h>

struct Struct_ov003_0216bcfc_2 {
#if defined(jpn)
    char unknown_0_[0x28];
    char *unknown_28_;
    char unknown_2c_[0x868 - 0x2c];
#else
    char unknown1_0_[0x5c];
    char *unknown_5c_;
    char unknown_60_[0x998 - 0x60];
#endif
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
};

struct Struct_ov003_0216bcfc_3 {
    char unknown_0_[4];
    short unknown_4_;
    short unknown_6_;
    char unknown_8_[4];
    int unknown_c_;
#if defined(jpn)
    char unknown_10_[0x428 - 0x10];
    char unknown_410_[0x500 - 0x428];
    void *unknown_4e8_;
    char unknown_504_[0x10f4 - 0x504];
#else
    char unknown1_10_[0x410 - 0x10];
    char unknown_410_[0x4e8 - 0x410];
    void *unknown_4e8_;
    char unknown_4ec_[0x1264 - 0x4ec];
#endif
    int unknown_1264_;
    int unknown_1268_;
    char unknown_126c_[0x12a8 - 0x126c];
    int unknown_12a8_;
    int unknown_12ac_;
    char unknown_12b0_[0x12b8 - 0x12b0];
    short unknown_12b8_;
    char unknown_12ba_[2];
    unsigned char unknown_12bc_;
    char unknown_12bd_[0x12d4 - 0x12bd];
    SafeAllocator unknown_12d4_;
    char unknown_12e8_[0x1310 - 0x12e8];
    SafeAllocator unknown_1310_[1];
    char unknown_1324_[0x1334 - 0x1324];
};

struct AllocatorUnion;
struct S021700bc;
struct PacRecord;

int CheckField0NonZero_0202b7d8(int *p);
int Pac_CountFiles(PacRecord *archive);
void *Pac_GetFile(PacRecord *archive, int index, void **name, int *size);
void *AllocatorUnion_AllocateRounded(AllocatorUnion *alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion *alloc, void *p);
void SpriteContext_Destroy(void *p);
void InitField170_021700bc(S021700bc *p);
extern "C" void *func_0202ae18();
extern "C" void func_0202c288();
extern "C" void MessageSystem_Stop(void *p);
extern "C" void SpriteContext_LoadFile(void *renderer, void *file, unsigned int size, SafeAllocator *allocator);
#if defined(jpn)
extern "C" void func_ov003_0216d8d4(void *arg0, int arg1);
extern "C" void func_ov003_0216e02c(void *arg0, SafeAllocator *arg1);
extern char data_ov003_0217e985[];
#define func_ov003_0216d8d4(self, a, b, c, d) func_ov003_0216d8d4(self, a)
#define data_ov003_021801c9 data_ov003_0217e985
#else
extern "C" void func_ov003_0216d8d4(void *arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_ov003_0216e02c(void *arg0, SafeAllocator *arg1);
#endif
extern "C" int func_ov003_0216e124(void *sub);
extern "C" void func_ov003_021700dc(void *sub);
void *MessageSystem_GetInstance();
extern "C" void *memset(void *dst, int value, unsigned int length);

extern char g_mainAllocator;
extern char data_ov003_021801c9[];

// USA: func_ov003_0216bcfc
extern "C" ARM void func_ov003_0216bcfc(Menu0216bcfc *self) {
    Global0216bcfc *global   = (Global0216bcfc *) MessageSystem_GetInstance();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    void *obj                = func_0202ae18();

    if (arg0->unknown_6_ == 0) {
        func_0202c288();
        if (func_0202b7d8((int *) var2) != 0 && (int) *((unsigned char *) var2 + 0x100d) > 1) {
            func_ov003_0216d8d4(arg0, 0x5d, -1, -1, -1);
            arg0->unknown_6_  = 0;
            arg0->unknown_4_ = 2;
            arg0->unknown_6_  = 0;
            return;
        }
        Global0216bcfc *global2 = (Global0216bcfc *) MessageSystem_GetInstance();
#if defined(jpn)
        memset(var3->unknown_28_, 0, 0x800);
#else
        memset(var3->unknown_5c_, 0, 0x960);
#endif
        void *buffer = AllocatorUnion_AllocateRounded((AllocatorUnion *) &g_mainAllocator, 0x8000);
        VectorizedMemset(buffer, 0, 0x8000);
        self->allocator_.CreateTypeA(buffer, 0x8000);
        self->allocator_.Reset();
        InitField170_021700bc((S021700bc *) self->sub_410);
        func_ov003_0216e02c(self->sub_410, &self->allocator_);
        self->unk_4e8 = &self->unk_1324;
        char pixels[0x20];
        memset(pixels, 0, 0x20);
        CleanInvalidateCacheRange(pixels, 0x20);
        LoadToMainBG1CharacterData(pixels, 0, 0x20);
        self->step_ = 1;
        MessageSystem_Stop(global2);
    }
    if (arg0->unknown_6_ == 1) {
        if (func_ov003_0216e124(arg0->unknown_410_) == 0) arg0->unknown_6_ = 2;
    }
    if (self->step_ == 2) {
        func_ov003_021700dc(self->sub_410);
        SignedAllocatorHeader *signedAlloc = self->allocator_.GetSignedAllocator();
        if (signedAlloc != 0) {
            self->allocator_.Destroy();
            AllocatorUnion_Free((AllocatorUnion *) &g_mainAllocator, signedAlloc);
        }
#if defined(jpn)
        SpriteContext_Destroy((char *) self + 0x10fc);
#else
        SpriteContext_Destroy((char *) self + 0x126c);
#endif
        arg0->unknown_12bc_ = 0;
        arg0->unknown_12ac_ = arg0->unknown_1264_;
        arg0->unknown_12b8_ = 0xf;
        arg0->unknown_12a8_ = arg0->unknown_1268_;
        arg0->unknown_1310_[0].Reset();
        arg0->unknown_c_ = var1->QueueLoadFile(data_ov003_021801c9, 0);
        arg0->unknown_6_ = 3;
    }
    if (self->step_ == 3 && loader->GetTaskStatus(self->task_) != 0) {
        void *name;
        void *file;
        unsigned int size;
        int fileSize;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int count            = Pac_CountFiles((PacRecord *) file);
        SafeAllocator *alloc = &self->allocators_[0];
        for (int i = 0; i < count; i++) {
            void *data = Pac_GetFile((PacRecord *) file, i, &name, &fileSize);
#if defined(jpn)
            SpriteContext_LoadFile((char *) self + 0x10fc, data, fileSize, alloc);
#else
            SpriteContext_LoadFile((char *) self + 0x126c, data, fileSize, alloc);
#endif
        }
        var1->RemoveTask(arg0->unknown_c_);
        arg0->unknown_c_ = -1;
        func_ov003_0216d8d4(arg0, 0x29, -1, -1, -1);
        var0->unknown_998_ = 1;
        arg0->unknown_6_     = 0;
        arg0->unknown_4_    = 2;
        arg0->unknown_6_     = 0;
    }
    if (arg0->unknown_6_ == 0xc8 && var0->unknown_9a0_ == 0) {
        func_ov003_0216d8d4(arg0, 0x29, -1, -1, -1);
        arg0->unknown_6_  = 0;
        arg0->unknown_4_ = 2;
        arg0->unknown_6_  = 0;
    }
}
