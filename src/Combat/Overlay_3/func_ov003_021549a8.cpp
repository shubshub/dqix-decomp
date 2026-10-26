#include <globaldefs.h>
#include "Combat/MenuNodeChain.h"
#if defined(jpn)
enum { Enum_ov003_021549a8_728 = 0x228 };
enum { Enum_ov003_021549a8_732 = 0x22c };
enum { Enum_ov003_021549a8_742 = 0x236 };
enum { Enum_ov003_021549a8_743 = 0x237 };
enum { Enum_ov003_021549a8_2456 = 0x868 };
enum { Enum_ov003_021549a8_352 = 0x15c };
enum { Enum_ov003_021549a8_464 = 0x1cc };
enum { Enum_ov003_021549a8_468 = 0x1d0 };
enum { Enum_ov003_021549a8_516 = 0x200 };
enum { Enum_ov003_021549a8_520 = 0x204 };
enum { Enum_ov003_021549a8_524 = 0x208 };
#else
enum { Enum_ov003_021549a8_728 = 0x2d8 };
enum { Enum_ov003_021549a8_732 = 0x2dc };
enum { Enum_ov003_021549a8_742 = 0x2e6 };
enum { Enum_ov003_021549a8_743 = 0x2e7 };
enum { Enum_ov003_021549a8_2456 = 0x998 };
enum { Enum_ov003_021549a8_352 = 0x160 };
enum { Enum_ov003_021549a8_464 = 0x1d0 };
enum { Enum_ov003_021549a8_468 = 0x1d4 };
enum { Enum_ov003_021549a8_516 = 0x204 };
enum { Enum_ov003_021549a8_520 = 0x208 };
enum { Enum_ov003_021549a8_524 = 0x20c };
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Cache.h"
#include "std_library_functions.h"

extern "C" void func_ov023_021eb26c(void* obj);
struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* obj);
struct Struct_0207fcb8;
extern "C" void func_0207fcb8(struct Struct_0207fcb8* obj);
struct Struct_0207fd44_2;
extern "C" void func_0207fd44(struct Struct_0207fd44_2* obj);
struct Struct_0207fd88;
extern "C" void func_0207fd88(struct Struct_0207fd88* obj);
extern "C" int LoadToMainBG1CharacterData(int src, int offset, unsigned int size);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(void* self);

struct Controller020421a0 {
    char pad0[Enum_ov003_021549a8_728];
    int unknown_2d8_;
    char unknown_2dc_[Enum_ov003_021549a8_742 - Enum_ov003_021549a8_732];
    unsigned char unknown_2e6_;
    char unknown_2e7_[Enum_ov003_021549a8_2456 - Enum_ov003_021549a8_743];
    int active;
};
extern "C" Controller020421a0* MessageSystem_GetInstance(void);

struct Struct_ov003_021549a8_2 {
    SafeAllocator* allocs;
    char pad04[0xc - 0x4];
    void* unknown_c_;
    char pad10[0x18 - 0x10];
    Manager0207f7f0* list;
    char unknown_1c_[Enum_ov003_021549a8_352 - 0x1c];
    char unknown_160_[Enum_ov003_021549a8_464 - Enum_ov003_021549a8_352];
    int task;
    char unknown_1d4_[Enum_ov003_021549a8_516 - Enum_ov003_021549a8_468];
    void* scene;
    char unknown_208_[Enum_ov003_021549a8_524 - Enum_ov003_021549a8_520];
    int unknown_20c_;
};

// USA: func_ov003_021549a8
extern "C" ARM void func_ov003_021549a8(Struct_ov003_021549a8_2* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->task >= 0) {
        loader->RemoveTask(self->task);
        self->task = -1;
    }
    if (self->unknown_20c_ >= 0) {
        loader->RemoveTask(self->unknown_20c_);
        self->unknown_20c_ = -1;
    }
    if (self->scene != NULL) {
        func_ov023_021eb26c(self->scene);
        self->scene = NULL;
    }

    unsigned int* reg = (unsigned int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(unsigned short*)0x4000050 = 0;
    func_02074bd0((struct Struct_02074bd0*)self->unknown_160_);

    Manager0207f7f0* list = self->list;
    if (list != NULL) {
        func_0207fcb8((struct Struct_0207fcb8*)list);
        func_0207fd44((struct Struct_0207fd44_2*)list);
        func_0207fd88((struct Struct_0207fd88*)list);
        func_0207f8bc(list);
    }

    if (self->unknown_c_ != NULL) {
        memset(self->unknown_c_, 0, 0x20);
        CleanInvalidateCacheRange(self->unknown_c_, 0x20);
        LoadToMainBG1CharacterData((int)self->unknown_c_, 0, 0x20);
    }
    self->unknown_c_ = NULL;

    Controller020421a0* g = MessageSystem_GetInstance();
    if (g->active != 0) {
        MessageSystem_Reset((char*)g);
        MessageSystem_Stop(g);
    }
    g->unknown_2d8_ = 0;
    g->unknown_2e6_ = 1;

    if (self->allocs != NULL) {
        for (unsigned char i = 0; i < 8; i++) {
            self->allocs[i].Destroy();
        }
    }
}
