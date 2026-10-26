#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { Enum_ov017_021bacd8_62524 = 0xf454, Enum_ov017_021bacd8_1020 = 0x414 };
#else
enum { Enum_ov017_021bacd8_62524 = 0xf43c, Enum_ov017_021bacd8_1020 = 0x3fc };
#endif

int GameState_GetFollowCamera(char* obj);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void GameObject_EnableControl(void* obj);
void PushInputLogA_020a1df8(int id);

struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

struct Struct_ov017_021bac8c;
extern "C" void func_ov017_021bac8c(struct Struct_ov017_021bac8c* arg0);

extern "C" void func_020a0cc4(unsigned int);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" int func_ov017_021959b4(void);

extern "C" void func_ov003_0215c650(void* arg0);
extern "C" void func_ov003_0215c568(void* arg0, void* arg1);
extern "C" void func_ov003_0215caa4(void* arg0);
extern "C" int func_ov003_0215c924(void* arg0, int arg1);
extern "C" void func_ov003_0215c800(void* arg0);

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;

struct Struct_ov017_021bacd8 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    int unknown_8_;
    SafeAllocator unknown_c_;
    void* unknown_20_;
};

// Overlay 17, originally func_ov017_021bacd8 (USA/EUR 0x021bacd8, JPN 0x021bb2cc)
extern "C" ARM void FieldTask_VisitInn(Obj021bacd8* self) {
    GameState* battle = GameState::GetInstance();
    unsigned int* ov = ((unsigned int*)GetGameResources());
    GameObject* c = battle->GetLeader();
    int flagResult = GameState_GetFollowCamera((char*)battle);
    SetFlags04((GameResources*)ov, 0xc0);
    GameObject_DisableControl((struct Obj020397cc*)c, 1);
    SetFlagsAt0x244_020a28a0((unsigned char*)flagResult, 3);
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
        void* mem = self->alloc.Allocate(Field3fc);
        self->field20 = mem;
        if (mem == NULL) {
            ROMFilesystem_InitFileTables();
            self->flag1 = 1;
            return;
        }
        func_020a1df8(3);
        func_ov003_0215c650(arg0->unknown_20_);
        func_ov003_0215c568(arg0->unknown_20_, &arg0->unknown_c_);
        arg0->unknown_8_ += 1;
        return;
    }
    if (var5 == 1) {
        if (func_ov017_021959b4() != 0) {
            func_ov003_0215caa4(arg0->unknown_20_);
        }
        if (func_ov003_0215c924(arg0->unknown_20_, var4) != 0) {
            arg0->unknown_8_ += 1;
        }
        return;
    }
    if (var5 == 2) {
        func_ov003_0215c800(arg0->unknown_20_);
        arg0->unknown_8_ += 1;
        return;
    }
    if (var5 != 3) {
        return;
    }
    func_ov017_021bac8c((struct Obj021bac8c*)self);
    ClearFlags04((GameResources*)ov, 0xc0);
    GameObject_EnableControl(c);
    ClearFlagBits_020a28b0((unsigned char*)flagResult, 3);
    ROMFilesystem_InitFileTables();
    self->flag1 = 1;
}
