#include "Combat/MenuNodeChain.h"
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct Struct_020e2490;
extern "C" void func_020e2490(struct Struct_020e2490* obj, int arg1, int arg2, void* arg3, SafeAllocator* alloc, int count, unsigned char flag);
struct BackgroundGraphics;
extern "C" void Background_Init(struct BackgroundGraphics* obj);
extern "C" void WindowPane_Init(void*);
struct Struct0205a198;
extern "C" void Sprite_Init(struct Struct0205a198*);

struct Struct_ov003_021544ec {
    char pad0[4];
    void* field4;
    void* field8;
    void* fieldC;
    char pad10[0x59 - 0x10];
    signed char unknown_59_;
};
extern "C" void func_ov003_0215376c(struct Struct_ov003_021544ec* obj);
extern "C" void func_ov003_021536e0(struct Struct_ov003_021544ec* obj, SafeAllocator* alloc);

struct Struct_ov003_0217f320 {
    unsigned int v[8];
};
extern Struct_ov003_0217f320 data_ov003_0217f320;

struct Struct_ov003_021544ec_2 {
    SafeAllocator* allocators;
    struct Struct_ov003_021544ec* unknown_4_;
    char pad8[4];
    void* unknown_c_;
    struct BackgroundGraphics* lists;
    char* buf14;
    Manager0207f7f0* unknown_18_;
    struct Struct_020e2490* entryManager;
    int* words;
    struct Struct0205a198* buf24;
    void* unknown_28_;
    char pad2c[0x90 - 0x2c];
    char field90[0xfc - 0x90];
    char unknown_fc_[0x114 - 0xfc];
    char unknown_114_[1];
};

#if defined(jpn)
enum { Enum_ov003_021544ec_128 = 0x68, kEntryCount = 3 };
#else
enum { Enum_ov003_021544ec_128 = 0x80, kEntryCount = 4 };
#endif

// USA: func_ov003_021544ec
extern "C" ARM void func_ov003_021544ec(struct Struct_ov003_021544ec_2* obj, SafeAllocator* alloc) {
    if (alloc != 0) {
        obj->allocators = (SafeAllocator*)alloc->Allocate(0xa0);
        obj->unknown_4_ = (struct Struct_ov003_021544ec*)alloc->Allocate(0x60);
        obj->unknown_c_ = alloc->Allocate(0x4c00);
        obj->lists = (struct BackgroundGraphics*)alloc->Allocate(0x40);
        obj->buf14 = (char*)alloc->Allocate(0x2a0);
        obj->unknown_18_ = static_cast<Manager0207f7f0*>(alloc->Allocate(Enum_ov003_021544ec_128));
        obj->words = (int*)alloc->Allocate(0x30);
        obj->buf24 = (struct Struct0205a198*)alloc->Allocate(0x190);
        obj->unknown_28_ = alloc->Allocate(8);
        obj->entryManager = (struct Struct_020e2490*)alloc->Allocate(0x24);
        func_020e2490(obj->entryManager, 0, 1, obj->unknown_28_, alloc, kEntryCount, 0x40);

        Struct_ov003_0217f320 sizes = data_ov003_0217f320;
        for (unsigned char i = 0; i < 8; i++) {
            SafeAllocator* allocators = obj->allocators;
            unsigned int size = sizes.v[i];
            allocators[i].ResetAllocatorPointer();
            allocators[i].CreateTypeA(alloc->Allocate(size), size);
            allocators[i].Reset();
        }
        for (unsigned char i = 0; i < 2; i++) {
            Background_Init((struct BackgroundGraphics*)((char*)obj->lists + i * 0x20));
        }
        for (unsigned char i = 0; i < 3; i++) {
            WindowPane_Init(obj->buf14 + i * 0xe0);
        }
        func_0207f84c(obj->unknown_18_);
        for (unsigned char i = 0; i < 12; i++) {
            obj->words[i] = 0;
        }
        for (unsigned char i = 0; i < 10; i++) {
            Sprite_Init((struct Struct0205a198*)((char*)obj->buf24 + i * 0x28));
        }
        GameState::GetInstance();
        struct Struct_ov003_021544ec* sub = obj->unknown_4_;
        func_ov003_0215376c(sub);
        func_ov003_021536e0(sub, alloc);
        sub->field8 = obj->field90;
        sub->field4 = obj->unknown_fc_;
        sub->fieldC = obj->unknown_114_;
        sub->unknown_59_ = -1;
    }
}
