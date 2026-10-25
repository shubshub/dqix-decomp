#include "Combat/MenuNodeChain.h"
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct EntryManager020e2490;
void InitEntryManager020e2490(struct EntryManager020e2490* obj, int arg1, int arg2, void* arg3, SafeAllocator* alloc, int count, unsigned char flag);
struct BackgroundGraphics;
void Background_Init(struct BackgroundGraphics* obj);
extern "C" void WindowPane_Init(void*);
struct Struct0205a198;
void Sprite_Init(struct Struct0205a198*);

struct Struct_ov003_021544ec {
    char unknown_0_[4];
    void* unknown_4_;
    void* unknown_8_;
    void* unknown_c_;
    char unknown_10_[0x59 - 0x10];
    signed char unknown_59_;
};
extern "C" void func_ov003_0215376c(struct Struct_ov003_021544ec* arg0);
extern "C" void func_ov003_021536e0(struct Struct_ov003_021544ec* arg0, SafeAllocator* arg1);

struct Struct_ov003_0217f320 {
    unsigned int unknown_0_[8];
};
extern Struct_ov003_0217f320 data_ov003_0217f320;

struct Obj021544ec {
    SafeAllocator* allocators;
    struct CombatSubsystem0215376c* subsystem;
    char pad8[4];
    void* bufC;
    struct BackgroundGraphics* lists;
    char* buf14;
    Manager0207f7f0* buf18;
    struct EntryManager020e2490* entryManager;
    int* words;
    struct Struct0205a198* buf24;
    void* buf28;
    char pad2c[0x90 - 0x2c];
    char field90[0xfc - 0x90];
    char fieldFc[0x114 - 0xfc];
    char field114[1];
};

#if defined(jpn)
enum { Enum_ov003_021544ec_128 = 0x68, Enum_ov003_021544ec_4 = 3 };
#else
enum { Enum_ov003_021544ec_128 = 0x80, Enum_ov003_021544ec_4 = 4 };
#endif

// USA: func_ov003_021544ec
extern "C" ARM void func_ov003_021544ec(struct Obj021544ec* obj, SafeAllocator* alloc) {
    if (alloc != 0) {
        obj->allocators = (SafeAllocator*)alloc->Allocate(0xa0);
        obj->subsystem = (struct CombatSubsystem0215376c*)alloc->Allocate(0x60);
        obj->bufC = alloc->Allocate(0x4c00);
        obj->lists = (struct BackgroundGraphics*)alloc->Allocate(0x40);
        obj->buf14 = (char*)alloc->Allocate(0x2a0);
        obj->buf18 = static_cast<Manager0207f7f0*>(alloc->Allocate(kNotificationBufferSize));
        obj->words = (int*)alloc->Allocate(0x30);
        obj->buf24 = (struct Struct0205a198*)alloc->Allocate(0x190);
        obj->buf28 = alloc->Allocate(8);
        obj->entryManager = (struct EntryManager020e2490*)alloc->Allocate(0x24);
        InitEntryManager020e2490(obj->entryManager, 0, 1, obj->buf28, alloc, kEntryCount, 0x40);

        Struct_ov003_0217f320 var0 = data_ov003_0217f320;
        for (unsigned char var1 = 0; var1 < 8; var1++) {
            SafeAllocator* var2 = arg0->unknown_0_;
            unsigned int var3 = var0.unknown_0_[var1];
            var2[var1].ResetAllocatorPointer();
            var2[var1].CreateTypeA(arg1->Allocate(var3), var3);
            var2[var1].Reset();
        }
        for (unsigned char i = 0; i < 2; i++) {
            Background_Init((struct BackgroundGraphics*)((char*)obj->lists + i * 0x20));
        }
        for (unsigned char i = 0; i < 3; i++) {
            WindowPane_Init(obj->buf14 + i * 0xe0);
        }
        func_0207f84c(arg0->unknown_18_);
        for (unsigned char var6 = 0; var6 < 12; var6++) {
            arg0->unknown_20_[var6] = 0;
        }
        for (unsigned char i = 0; i < 10; i++) {
            Sprite_Init((struct Struct0205a198*)((char*)obj->buf24 + i * 0x28));
        }
        GameState::GetInstance();
        struct Struct_ov003_021544ec* var8 = arg0->unknown_4_;
        func_ov003_0215376c(var8);
        func_ov003_021536e0(var8, arg1);
        var8->unknown_8_ = arg0->unknown_90_;
        var8->unknown_4_ = arg0->unknown_fc_;
        var8->unknown_c_ = arg0->unknown_114_;
        var8->unknown_59_ = -1;
    }
}
