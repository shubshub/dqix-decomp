#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "Graphics/CharacterModel.h"

class Struct_ov023_021fc518 {
public:
    unsigned short type_;
    unsigned short id_;
    unsigned short unknown_8_;
    unsigned short vramState_;
    unsigned char flags_;
    char unk_d[3];
    const char* file_;
    void* unknown_14_;
    void* unknown_18_;
    int state_;
    CharacterModel models_[2];
    int unknown_1860_;
    unsigned char current_ : 1;
    unsigned char unknown_1864_1_ : 1;
    unsigned char unknown_1864_2_ : 1;
    unsigned char unknown_1864_3_ : 1;
    void (**unknown_1868_)(void* script);
    void (**unknown_186c_)(void* script);

    virtual void inline_ov023_021fc518_54(void* script);
};

class Struct_ov023_021fc518_3 {
public:
    virtual void inline_ov023_021fc518_55();
    virtual void inline_ov023_021fc518_56();
    virtual void inline_ov023_021fc518_57();
    virtual void inline_ov023_021fc518_58();
    virtual void unk_10();
    virtual void unk_14();
    virtual void inline_ov023_021fc518();
    virtual void unk_1c();
    virtual void unk_20();
    virtual void unk_24();
    virtual void unk_28();
    virtual void unk_2c();
    virtual void inline_ov023_021fc518_7();
    virtual void inline_ov023_021fc518_8();
    virtual void inline_ov023_021fc518_9();
    virtual void unk_3c();
    virtual void unk_40();
    virtual void inline_ov023_021fc518_12();
    virtual void inline_ov023_021fc518_13();
    virtual void inline_ov023_021fc518_14();
    virtual void unk_50();
    virtual void unk_54();
    virtual void unk_58();
    virtual void unk_5c();
    virtual void inline_ov023_021fc518_19();
    virtual void unk_64();
    virtual void inline_ov023_021fc518_21();
    virtual void unk_6c();
    virtual void unk_70();
    virtual void inline_ov023_021fc518_24();
    virtual void inline_ov023_021fc518_25();
    virtual void inline_ov023_021fc518_26();
    virtual void inline_ov023_021fc518_27();
    virtual void inline_ov023_021fc518_28();
    virtual void inline_ov023_021fc518_29();
    virtual void inline_ov023_021fc518_30();
    virtual void inline_ov023_021fc518_31();
    virtual void inline_ov023_021fc518_32();
    virtual void inline_ov023_021fc518_33();
    virtual void inline_ov023_021fc518_34();
    virtual void inline_ov023_021fc518_35();
    virtual void inline_ov023_021fc518_36();
    virtual void inline_ov023_021fc518_37();
    virtual void unk_ac();
    virtual void unk_b0();
    virtual void inline_ov023_021fc518_40();
    virtual void unk_b8();
    virtual void unk_bc();
    virtual void unk_c0();
    virtual void inline_ov023_021fc518_44();
    virtual void inline_ov023_021fc518_45();
    virtual void inline_ov023_021fc518_46();
    virtual void inline_ov023_021fc518_47();
    virtual void inline_ov023_021fc518_48();
    virtual void unk_d8();
    virtual void unk_dc();
    virtual void inline_ov023_021fc518_51();
    virtual void inline_ov023_021fc518_52();
    virtual int inline_ov023_021fc518_53();
};

struct Struct_ov023_021fc518_2 {
    int unk_0;
    SafeAllocator allocator;
};

struct Struct_ov023_021f6ed8;
struct Foo0207df50;
struct Camera;
struct AngleTrig0202e9a4;

extern "C" void func_ov023_021f6ed8(Struct_ov023_021f6ed8* obj);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" Struct_ov023_021fc518_3* func_ov023_021f6880(void* list, int tag);
extern "C" Struct_ov023_021fc518_2* func_ov011_021845f8(void* ctx, int heap);
extern "C" void VramState_Rewind(Foo0207df50* p);
extern "C" void VramState_Restore(char* p);
extern "C" void VramState_Save(char* p);
extern "C" void CharacterModel_Init(void* model);
extern "C" void CharacterModel_CreateAllocators(void* model, SafeAllocator* allocator);
extern "C" void CharacterModel_ReserveVram(void* model);
extern "C" void CharacterModel_SetItemTable(void* model, int value);
extern "C" void CharacterModel_SetForceStandAnimation(void* model, unsigned char value);
extern "C" void CharacterModel_SetAngle(void* model, unsigned int value);
extern "C" void func_ov023_021fc71c(void* obj, int id, int arg2);
extern "C" char* GameState_GetFollowCamera(char* gameState);
extern "C" void Camera_SetPosition(Camera* camera, int x, int y, int z);
extern "C" void Camera_SetTarget(struct Camera* camera, int x, int y, int z);
extern "C" int func_0202e9ec(void* camera);
extern "C" void Camera_SetFieldOfView(AngleTrig0202e9a4* camera, int angle);
extern "C" void FollowCamera_DisableFollow(void* camera);

// USA: func_ov023_021fc518
extern "C" ARM int func_ov023_021fc518(Struct_ov023_021fc518* self, void* ctx, int id, int heap, int arg4, int character) {
    func_ov023_021f6ed8((Struct_ov023_021f6ed8*)self);
    self->type_ = 5;
    self->id_ = id;
    self->unknown_8_ = heap;
    self->vramState_ = 0;
    self->file_ = NULL;
    self->current_ = 0;
    self->unknown_1860_ = 0;
    self->unknown_1864_3_ = 0;
    self->unknown_1864_1_ = 0;
    self->unknown_1864_2_ = 0;
    self->unknown_1868_ = NULL;
    self->unknown_186c_ = NULL;

    Struct_ov023_021fc518_3* parent = func_ov023_021f6880(func_ov011_021849c8(ctx), arg4);
    Struct_ov023_021fc518_2* heapNode = func_ov011_021845f8(ctx, heap);
    int perspective = parent->inline_ov023_021fc518_53();

#if defined(jpn)
    char* pairTables = (char*)GetGameResources() + 0x27c;
#else
    char* pairTables = GetGameResources()->vramStates_;
#endif
    VramState_Rewind((Foo0207df50*)pairTables);
    VramState_Restore(pairTables);
    for (int i = 0; i < 2; i++) {
        CharacterModel_Init(&self->models_[i]);
        CharacterModel_CreateAllocators(&self->models_[i], &heapNode->allocator);
        CharacterModel_ReserveVram(&self->models_[i]);
        CharacterModel_SetItemTable(&self->models_[i], perspective);
        CharacterModel_SetForceStandAnimation(&self->models_[i], 1);
    }
    VramState_Save(pairTables);

    CharacterModel_SetAngle(&self->models_[0], 0x1eb);
    CharacterModel_SetAngle(&self->models_[1], 0x1eb);
    if (character >= 0)
        func_ov023_021fc71c(self, character, 0);

    char* camera = GameState_GetFollowCamera((char*)GameState::GetInstance());
    Camera_SetPosition((Camera*)camera, 0xb666, 0xb800, 0x42ccc);
    Camera_SetTarget((struct Camera*)camera, 0xb666, 0xb800, 0);
    self->unknown_1860_ = func_0202e9ec(camera);
    Camera_SetFieldOfView((AngleTrig0202e9a4*)camera, 0xf000);
    FollowCamera_DisableFollow(camera);
    return 1;
}
