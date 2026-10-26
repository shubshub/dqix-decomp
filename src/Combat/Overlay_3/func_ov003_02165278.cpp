#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0207fe44;
struct Container0205a3d0;
struct Elem0205a3d0 {
    char pad0[0x15];
    unsigned char flags;
};
struct Struct020a9ea4;
struct Obj020397cc;
struct FlagWord020466f4;

struct Struct_ov003_02165278 {
    unsigned char unknown_0_[RG(0x3c9, 0x139)];
    unsigned char unknown_3c9_0_ : 1;
};

struct Struct_ov003_02165278_2 {
    char pad0[RG(0x324, 0x20c)];
    struct Struct_0207fe44* model;
    char unknown_328_[RG(0x38c - 0x328, 0x274 - 0x210)];
    struct Container0205a3d0* container;
    char unknown_390_[RG(0x464 - 0x390, 0x28c - 0x278)];
    unsigned int flags;
    char unknown_468_[0x484 - 0x468];
    short unknown_484_;
    short unknown_486_;
    short unknown_488_;
    char unknown_48a_[0x4a3 - 0x48a];
    unsigned char code;
    unsigned char step;
};

extern "C" void* GlobalFlags_GetInstance(void);
extern "C" Struct_ov003_02165278* func_020936f8(void);
extern "C" void func_ov003_021612c0(struct Struct_ov003_02165278_2* obj);
extern "C" int func_ov003_02161344(struct Struct_ov003_02165278_2* obj);
extern "C" void func_0207fe44(struct Struct_0207fe44* model);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" void func_020a9ea4(struct Struct020a9ea4* p);
extern "C" int func_020aad1c(void* a, void* b, int c, int d);
extern int g_fileLoadBuffer;
extern "C" struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void func_020939dc(void* p);
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg);
extern "C" void func_ov017_021c35ac(void);

// USA: func_ov003_02165278
extern "C" ARM void func_ov003_02165278(struct Struct_ov003_02165278_2* obj) {
    void* data = GlobalFlags_GetInstance();
    Struct_ov003_02165278* global = func_020936f8();
    unsigned char step = obj->step;
    struct Struct_0207fe44* model = obj->model;

    if (step == 0xb) {
        obj->unknown_484_ = 0x19;
        obj->step++;
    } else if (step == 0xc) {
        func_ov003_021612c0(obj);
        obj->step++;
    } else if (step == 0xd) {
        int result = func_ov003_02161344(obj);
        if (result != -1) {
            if (result != 1) {
                return;
            }
            func_0207fe44(model);
            obj->unknown_484_ = 0x1a;
            obj->step++;
            global->unknown_3c9_0_ = 0;
        } else {
            obj->unknown_488_ = -1;
            obj->unknown_484_ = 0x3b;
            obj->unknown_486_ = 1;
            func_0207fe44(model);
            obj->code = 10;
            obj->step = 0;
        }
    } else if (step == 0xe) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() != 0) {
            return;
        }
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x80);
        func_020a9ea4((struct Struct020a9ea4*)((char*)obj + RG(0x4b4, 0x2dc)));
        obj->step++;
    } else if (step == 0xf) {
        obj->flags |= 0x2000000;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        if (func_020aad1c((char*)obj + RG(0x4b4, 0x2dc), &g_fileLoadBuffer, 10, 0) == 1) {
            struct Elem0205a3d0* entry = SpriteEntryList_Find(obj->container, 0);
            if (entry != NULL) {
                entry->flags |= 8;
            }
            entry = SpriteEntryList_Find(obj->container, 1);
            if (entry != NULL) {
                entry->flags &= ~8;
            }
            obj->flags &= ~0x2000000;
            obj->unknown_484_ = 0x30;
            obj->step++;
            FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80);
        }
        BackgroundLoader::RemoveLockGlobal();
    } else if (step == 0x10) {
        func_ov017_021c35ac();
        func_020939dc(global);
        FlagWord_ClearBits((struct FlagWord020466f4*)data, 0x20);
        obj->unknown_484_ = 0x1b;
        obj->step++;
        GameObject* protagonist = GameState::GetInstance()->GetProtagonist();
        if (protagonist == NULL) {
            return;
        }
        GameObject_DisableControl((struct Obj020397cc*)protagonist, 1);
    } else if (step == 0x11) {
        func_ov003_021612c0(obj);
        obj->step++;
    } else if (step == 0x12) {
        int result = func_ov003_02161344(obj);
        if (result != -1) {
            if (result != 1) {
                return;
            }
            obj->unknown_484_ = 0x1c;
            obj->code = 0x10;
            obj->step = 0;
        } else {
            obj->unknown_484_ = 0x1d;
            obj->code = 0x10;
            obj->step = 0;
        }
    }
}
