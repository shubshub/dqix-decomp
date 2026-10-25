#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" {
void _Z23VramState_CopyCurrentToP13State0207dfc8S0_(void *, void *);
void _ZN13SafeAllocator5ResetEv(void *);
void _Z16VramState_RewindP11Foo0207df50(void *);
void _Z17VramState_RestorePc(void *);
void _Z14VramState_SavePc(void *);
void _Z19CopyVec3ToField0x44P14Target02059f38P13Vec3_02059f38(void *, void *);
void _Z13SetFields0x44P14Fields020407b4iii(void *, int, int, int);
int _Z17IsIdInSet02098210ii(int, int);
unsigned short *Zone3D_GetInstance(void);
}

#if defined(jpn)
#define data_ov003_0217fdfa data_ov003_0217e613
#endif
extern const char data_ov003_0217fdfa[];
extern const char data_ov003_0217fe16[];

struct Struct_ov003_02158754 {
    char unknown_0_[2];
    short unknown_2_;
};

struct Struct_ov003_02158754_2 {
    char unknown_0_[4];
    short unknown_4_;
};

struct Struct_ov003_02158754_3 {
    void *unknown_0_;
    char unknown_4_[0x100 - 4];
#if defined(jpn)
    char unknown_100_[0xf3];
#else
    char unknown1_100_[0xf7];
#endif
    signed char unknown_1f7_;
    char unknown_1f8_[0x208 - 0x1f8];
    unsigned char unknown_208_;
    char unknown_209_[3];
    int unknown_20c_;
    char unknown_210_[0x280 - 0x210];
    char unknown_280_[0x32c - 0x280];
    int unknown_32c_;
};

#if defined(jpn)
enum { Enum_ov003_02158754_716 = 0x27c, Enum_ov003_02158754_2112 = 0x860 };
#else
enum { Enum_ov003_02158754_716 = 0x2cc, Enum_ov003_02158754_2112 = 0x840 };
#endif

// USA: func_ov003_02158754
extern "C" ARM int func_ov003_02158754(struct Struct_ov003_02158754_3 *arg0) {
    BackgroundLoader *var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_208_ == 0) {
        var0->AddFence();
        arg0->unknown_20c_  = var0->QueueLoadFile(data_ov003_0217fdfa, 0);
        arg0->unknown_208_ = arg0->unknown_208_ + 1;
    } else if (arg0->unknown_208_ == 1) {
        if (var0->GetTaskStatus(arg0->unknown_20c_) == 0) {
            return 0;
        }
        void *file        = 0;
        unsigned int size = 0;
        loader->GetLoadedFileByID(self->task, &file, &size);
        char *res = (char *) GetGameResources();
        _Z23VramState_CopyCurrentToP13State0207dfc8S0_(res + regionalOffset0, self->st210);
        _ZN13SafeAllocator5ResetEv((char *) self->alloc + 0x8c);
        _Z16VramState_RewindP11Foo0207df50(self->st210);
        _Z17VramState_RestorePc(self->st210);
        Object3D *obj = (Object3D *) self->obj280;
        obj->Initialize();
        ObjectArchiveLoadInfo info;
        info.fileData  = file;
        info.fileSize     = size;
        info.allocator = (SafeAllocator *) ((char *) self->alloc + 0x8c);
        info.unk_10    = 1;
        obj->LoadFromCHRArchive(&info);
        GameState *gs         = GameState::GetInstance();
        Object3D *pm          = (Object3D *) gs->GetPartyMemberByIndex(self->f1f7);
        struct GO02158754 *go = (struct GO02158754 *) gs->GetGameObjectByIndex(self->f1f7 * 0xc + 0x14);
        unsigned short *d     = Zone3D_GetInstance();
        unsigned int id       = d[0];
        if (pm->IsVisible() && pm->GetInheritedAlpha() != 0 && id != 10000) {
            if (TestFlags04((GameResources*)res, 4) == 0 || ((struct PM02158754 *) pm)->f4 == 0) {
                _Z19CopyVec3ToField0x44P14Target02059f38P13Vec3_02059f38(obj, (char *) pm + 0x44);
                const Vector3fix &sc2 = pm->GetScale();
                obj->SetScale(&sc2);
                obj->SetAnimationByName(data_ov003_0217fe16, 9);
                obj->EnableFlag(0x40000);
            } else {
                if (var8 != 0 && func_02098210((int) ((char *) var9 + Enum_ov003_02158754_2112), var10) != 0) {
                    if (var8->unknown_2_ == 0x2347 || var8->unknown_2_ == 0x2348 || var8->unknown_2_ == 0x2349) {
                        if (var8->unknown_2_ == 0x2347) {
                            func_020407b4(var4, 0x2347 - 0x2200, 0x266, -13230);
                        } else if (var8->unknown_2_ == 0x2348) {
                            func_020407b4(var4, -7823, 0x266, -13230);
                        } else if (var8->unknown_2_ == 0x2349) {
                            func_020407b4(var4, 0x2d70, 0x266, -13230);
                        }
                        const Vector3fix &sc = pm->GetScale();
                        obj->SetScale(&sc);
                        obj->SetAnimationByName(data_ov003_0217fe16, 9);
                        obj->EnableFlag(0x40000);
                    }
                }
            }
        } else {
            var4->EnableFlag(1);
        }
        _Z14VramState_SavePc(self->st210);
        self->f32c = 1;
        loader->RemoveTask(self->task);
        self->task  = -1;
        self->state = 0;
        return 1;
    }
    return 0;
}
