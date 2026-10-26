#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov024_021f5c80
#define data_ov023_021ff5b4 data_ov023_021fe83c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "Graphics/CharacterModel.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM int func_ov023_021fc518(void* obj, void* script, int id, int arg3, int unk2, int unk);
extern "C" void CharacterModel_Init(void* model);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

extern char data_ov023_021ff5b4;

struct Struct_ov011_02187720 {
    int id;
    SafeAllocator allocator;
};

struct Struct_ov011_02187720_3 {
    void* unknown_0_;
    char unk_4[0x1c];
    CharacterModel models[2];
    char unknown_1860_[0x10];
};

// USA: func_ov011_02187720
extern "C" ARM int func_ov011_02187720(struct TaggedNumber02184c30* params, int count) {
    Struct_ov011_02187720_3 prototype;
    void* object;
    SafeAllocator* allocator;
    CharacterModel* model;
    int unk;
    Struct_ov011_02187720* heap;
    void* script;
    int var7;
    int unk2;
    int id;

    id = func_ov011_02184c30(&params[0]);
    var7 = func_ov011_02184c30(&params[1]);
    unk2 = func_ov011_02184c30(&params[2]);
    func_ov011_02184c30(&params[3]);
    script = func_ov017_021b2164();
    heap = (Struct_ov011_02187720*)func_ov011_021845f8(script, var7);
    if (heap == 0)
        return 0;

    heap->allocator.GetSizeWithLargestBlockRemoved();
    unk = (*(int**)((char*)GetGameResources() + R(0x392c, 0x3b4c)))[0x13];
    object = heap->allocator.Allocate(sizeof(Struct_ov011_02187720_3));
    if (object == 0)
        return 0;

    prototype.unknown_0_ = &data_ov023_021ff5b4;
    model = prototype.models;
    do {
        allocator = model->allocators_;
        do {
            allocator->ResetAllocatorPointer();
            allocator++;
        } while (allocator < model->allocators_ + 10);
        model->animationAllocator_.ResetAllocatorPointer();
        CharacterModel_Init(model);
        model++;
    } while (model < prototype.models + 2);
    memcpy(object, &prototype, sizeof(Struct_ov011_02187720_3));
    if (!func_ov023_021fc518(object, script, id, var7, unk2, unk))
        return 0;

    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)func_ov011_021849c8(script), (struct Struct_ov004_0215c30c_2*)object);
    return 1;
}
