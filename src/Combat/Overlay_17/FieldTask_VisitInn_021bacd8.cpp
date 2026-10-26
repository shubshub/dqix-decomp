#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { Fieldf43c = 0xf454, Enum_ov017_021bacd8_1020 = 0x414 };
#else
enum { Fieldf43c = 0xf43c, Enum_ov017_021bacd8_1020 = 0x3fc };
#endif

extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a28a0(unsigned char* obj, unsigned char mask);
extern "C" void func_020a28b0(unsigned char* obj, int mask);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void func_020a1df8(int id);

struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

struct Struct_ov017_021bac8c;
extern "C" void func_ov017_021bac8c(struct Struct_ov017_021bac8c* self);

extern "C" void func_020a0cc4(unsigned int);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" int func_ov017_021959b4(void);

extern "C" void func_ov003_0215c650(void* p);
extern "C" void func_ov003_0215c568(void* p, void* alloc);
extern "C" void func_ov003_0215caa4(void* p);
extern "C" int func_ov003_0215c924(void* p, int scale);
extern "C" void func_ov003_0215c800(void* p);

extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;

struct Obj021bacd8 {
    char pad0;
    unsigned char flag1;
    char pad2[6];
    int state;
    SafeAllocator alloc;
    void* field20;
};

// Overlay 17, originally func_ov017_021bacd8 (USA/EUR 0x021bacd8, JPN 0x021bb2cc)
extern "C" ARM void FieldTask_VisitInn(Obj021bacd8* self) {
    GameState* battle = GameState::GetInstance();
    unsigned int* ov = ((unsigned int*)GetGameResources());
    GameObject* c = battle->GetLeader();
    int flagResult = GameState_GetFollowCamera((char*)battle);
    SetFlags04((GameResources*)ov, 0xc0);
    GameObject_DisableControl((struct Obj020397cc*)c, 1);
    func_020a28a0((unsigned char*)flagResult, 3);
    int scale = (int)battle->GetTickCount();
    if (scale < 0) {
        scale = 1;
    }
    int state = self->state;
    if (state == 0) {
        func_020a0cc4(Fieldf43c);
        void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, Fieldf43c);
        if (buf == NULL) {
            ROMFilesystem_InitFileTables();
            self->flag1 = 1;
            return;
        }
        self->alloc.CreateTypeA(buf, Fieldf43c);
        self->alloc.Reset();
        void* mem = self->alloc.Allocate(Enum_ov017_021bacd8_1020);
        self->field20 = mem;
        if (mem == NULL) {
            ROMFilesystem_InitFileTables();
            self->flag1 = 1;
            return;
        }
        func_020a1df8(3);
        func_ov003_0215c650(self->field20);
        func_ov003_0215c568(self->field20, &self->alloc);
        self->state += 1;
        return;
    }
    if (state == 1) {
        if (func_ov017_021959b4() != 0) {
            func_ov003_0215caa4(self->field20);
        }
        if (func_ov003_0215c924(self->field20, scale) != 0) {
            self->state += 1;
        }
        return;
    }
    if (state == 2) {
        func_ov003_0215c800(self->field20);
        self->state += 1;
        return;
    }
    if (state != 3) {
        return;
    }
    func_ov017_021bac8c((struct Struct_ov017_021bac8c*)self);
    ClearFlags04((GameResources*)ov, 0xc0);
    GameObject_EnableControl(c);
    func_020a28b0((unsigned char*)flagResult, 3);
    ROMFilesystem_InitFileTables();
    self->flag1 = 1;
}
