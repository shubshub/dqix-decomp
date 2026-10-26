#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" {
extern "C" void VramState_CopyCurrentTo(void *, void *);
void _ZN13SafeAllocator5ResetEv(void *);
extern "C" void VramState_Rewind(void *);
extern "C" void VramState_Restore(void *);
extern "C" void VramState_Save(void *);
extern "C" void func_02059f38(void *, void *);
extern "C" void func_020407b4(void *, int, int, int);
extern "C" int func_02098210(int, int);
unsigned short *Zone3D_GetInstance(void);
}

#if defined(jpn)
#define data_ov003_0217fdfa data_ov003_0217e613
#endif
extern const char data_ov003_0217fdfa[];
extern const char data_ov003_0217fe16[];

struct Struct_ov003_02158754 {
    char pad0[2];
    short f2;
};

struct Struct_ov003_02158754_2 {
    char pad0[4];
    short f4;
};

struct Struct_ov003_02158754_3 {
    void *alloc;
    char pad4[0x100 - 4];
#if defined(jpn)
    char unknown_100_[0xf3];
#else
    char unknown1_100_[0xf7];
#endif
    signed char f1f7;
    char pad1f8[0x208 - 0x1f8];
    unsigned char state;
    char unknown_209_[3];
    int task;
    char st210[0x280 - 0x210];
    char unknown_280_[0x32c - 0x280];
    int unknown_32c_;
};

#if defined(jpn)
enum { regionalOffset0 = 0x27c, regionalOffset1 = 0x860 };
#else
enum { regionalOffset0 = 0x2cc, regionalOffset1 = 0x840 };
#endif

// USA: func_ov003_02158754
extern "C" ARM int func_ov003_02158754(struct Struct_ov003_02158754_3 *self) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    if (self->state == 0) {
        loader->AddFence();
        self->task  = loader->QueueLoadFile(data_ov003_0217fdfa, 0);
        self->state = self->state + 1;
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->task) == 0) {
            return 0;
        }
        void *file        = 0;
        unsigned int size = 0;
        loader->GetLoadedFileByID(self->task, &file, &size);
        char *res = (char *) GetGameResources();
        VramState_CopyCurrentTo(res + regionalOffset0, self->st210);
        _ZN13SafeAllocator5ResetEv((char *) self->alloc + 0x8c);
        VramState_Rewind(self->st210);
        VramState_Restore(self->st210);
        Object3D *obj = (Object3D *) self->unknown_280_;
        obj->Initialize();
        ObjectArchiveLoadInfo info;
        info.fileData  = file;
        info.fileSize     = size;
        info.allocator = (SafeAllocator *) ((char *) self->alloc + 0x8c);
        info.unk_10    = 1;
        obj->LoadFromCHRArchive(&info);
        GameState *gs         = GameState::GetInstance();
        Object3D *pm          = (Object3D *) gs->GetPartyMemberByIndex(self->f1f7);
        struct Struct_ov003_02158754 *var8 = (struct Struct_ov003_02158754 *) gs->GetGameObjectByIndex(self->f1f7 * 0xc + 0x14);
        unsigned short *d     = Zone3D_GetInstance();
        unsigned int id       = d[0];
        if (pm->IsVisible() && pm->GetInheritedAlpha() != 0 && id != 10000) {
            if (TestFlags04((GameResources*)res, 4) == 0 || ((struct Struct_ov003_02158754_2 *) pm)->f4 == 0) {
                func_02059f38(obj, (char *) pm + 0x44);
                const Vector3fix &var11 = pm->GetScale();
                obj->SetScale(&var11);
                obj->SetAnimationByName(data_ov003_0217fe16, 9);
                obj->EnableFlag(0x40000);
            } else {
                if (var8 != 0 && func_02098210((int) ((char *) d + regionalOffset1), id) != 0) {
                    if (var8->f2 == 0x2347 || var8->f2 == 0x2348 || var8->f2 == 0x2349) {
                        if (var8->f2 == 0x2347) {
                            func_020407b4(obj, 0x2347 - 0x2200, 0x266, -13230);
                        } else if (var8->f2 == 0x2348) {
                            func_020407b4(obj, -7823, 0x266, -13230);
                        } else if (var8->f2 == 0x2349) {
                            func_020407b4(obj, 0x2d70, 0x266, -13230);
                        }
                        const Vector3fix &var12 = pm->GetScale();
                        obj->SetScale(&var12);
                        obj->SetAnimationByName(data_ov003_0217fe16, 9);
                        obj->EnableFlag(0x40000);
                    }
                }
            }
        } else {
            obj->EnableFlag(1);
        }
        VramState_Save(self->st210);
        self->unknown_32c_ = 1;
        loader->RemoveTask(self->task);
        self->task  = -1;
        self->state = 0;
        return 1;
    }
    return 0;
}
