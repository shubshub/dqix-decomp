#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include "NitroSDK/Memory.h"
#include <globaldefs.h>

struct Global0216bcfc {
#if defined(jpn)
    char unk_0[0x28];
    char *text_;
    char unk_2c[0x868 - 0x2c];
#else
    char unk_0[0x5c];
    char *text_;
    char unknown_60_[0x998 - 0x60];
#endif
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
};

struct Struct_ov003_0216bcfc_3 {
    char unk_0[4];
    short state_;
    short step_;
    char unk_8[4];
    int task_;
#if defined(jpn)
    char unk_10[0x428 - 0x10];
    char unknown_410_[0x500 - 0x428];
    void *unknown_4e8_;
    char unknown_504_[0x10f4 - 0x504];
#else
    char unk_10[0x410 - 0x10];
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
    SafeAllocator allocator_;
    char unknown_12e8_[0x1310 - 0x12e8];
    SafeAllocator allocators_[1];
    char unknown_1324_[0x1334 - 0x1324];
};

struct AllocatorUnion;
struct Struct_ov003_0216bcfc;
struct PacRecord;

extern "C" int LinkSession_IsActive(int *p);
extern "C" int Pac_CountFiles(PacRecord *archive);
extern "C" void *Pac_GetFile(PacRecord *archive, int index, void **name, int *size);
extern "C" void *AllocatorUnion_AllocateRounded(AllocatorUnion *alloc, unsigned int size);
extern "C" void AllocatorUnion_Free(AllocatorUnion *alloc, void *p);
extern "C" void SpriteContext_Destroy(void *p);
extern "C" void func_ov003_021700bc(Struct_ov003_0216bcfc *p);
extern "C" void *LinkSession_GetInstance();
extern "C" void LinkSession_UpdateMemberCount();
extern "C" void MessageSystem_Stop(void *p);
extern "C" void SpriteContext_LoadFile(void *renderer, void *file, unsigned int size, SafeAllocator *allocator);
#if defined(jpn)
extern "C" void func_ov003_0216d8d4(void *self, int a);
extern "C" void func_ov003_0216e02c(void *sub, SafeAllocator *allocator);
extern char data_ov003_0217e985[];
#define func_ov003_0216d8d4(self, a, b, c, d) func_ov003_0216d8d4(self, a)
#define data_ov003_021801c9 data_ov003_0217e985
#else
extern "C" void func_ov003_0216d8d4(void *self, int a, int b, int c, int d);
extern "C" void func_ov003_0216e02c(void *sub, SafeAllocator *allocator);
#endif
extern "C" int func_ov003_0216e124(void *sub);
extern "C" void func_ov003_021700dc(void *sub);
extern "C" void *MessageSystem_GetInstance();
extern "C" void *memset(void *dst, int value, unsigned int length);

extern char g_mainAllocator;
extern char data_ov003_021801c9[];

// USA: func_ov003_0216bcfc
extern "C" ARM void func_ov003_0216bcfc(Struct_ov003_0216bcfc_3 *self) {
    Global0216bcfc *global   = (Global0216bcfc *) MessageSystem_GetInstance();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    void *obj                = LinkSession_GetInstance();

    if (self->step_ == 0) {
        LinkSession_UpdateMemberCount();
        if (LinkSession_IsActive((int *) obj) != 0 && (int) *((unsigned char *) obj + 0x100d) > 1) {
            func_ov003_0216d8d4(self, 0x5d, -1, -1, -1);
            self->step_  = 0;
            self->state_ = 2;
            self->step_  = 0;
            return;
        }
        Global0216bcfc *global2 = (Global0216bcfc *) MessageSystem_GetInstance();
#if defined(jpn)
        memset(global2->text_, 0, 0x800);
#else
        memset(global2->text_, 0, 0x960);
#endif
        void *buffer = AllocatorUnion_AllocateRounded((AllocatorUnion *) &g_mainAllocator, 0x8000);
        VectorizedMemset(buffer, 0, 0x8000);
        self->allocator_.CreateTypeA(buffer, 0x8000);
        self->allocator_.Reset();
        func_ov003_021700bc((Struct_ov003_0216bcfc *) self->unknown_410_);
        func_ov003_0216e02c(self->unknown_410_, &self->allocator_);
        self->unknown_4e8_ = &self->unknown_1324_;
        char pixels[0x20];
        memset(pixels, 0, 0x20);
        CleanInvalidateCacheRange(pixels, 0x20);
        LoadToMainBG1CharacterData(pixels, 0, 0x20);
        self->step_ = 1;
        MessageSystem_Stop(global2);
    }
    if (self->step_ == 1) {
        if (func_ov003_0216e124(self->unknown_410_) == 0) self->step_ = 2;
    }
    if (self->step_ == 2) {
        func_ov003_021700dc(self->unknown_410_);
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
        self->unknown_12bc_ = 0;
        self->unknown_12ac_ = self->unknown_1264_;
        self->unknown_12b8_ = 0xf;
        self->unknown_12a8_ = self->unknown_1268_;
        self->allocators_[0].Reset();
        self->task_ = loader->QueueLoadFile(data_ov003_021801c9, 0);
        self->step_ = 3;
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
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        func_ov003_0216d8d4(self, 0x29, -1, -1, -1);
        global->unknown_998_ = 1;
        self->step_     = 0;
        self->state_    = 2;
        self->step_     = 0;
    }
    if (self->step_ == 0xc8 && global->unknown_9a0_ == 0) {
        func_ov003_0216d8d4(self, 0x29, -1, -1, -1);
        self->step_  = 0;
        self->state_ = 2;
        self->step_  = 0;
    }
}
