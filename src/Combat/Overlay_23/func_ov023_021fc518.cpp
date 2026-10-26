#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "Graphics/CharacterModel.h"

class Struct_ov023_021fc518 {
public:
    unsigned short type_;
    unsigned short id_;
    unsigned short heap_;
    unsigned short vramState_;
    unsigned char flags_;
    char unk_d[3];
    const char* file_;
    void* prev_;
    void* next_;
    int state_;
    CharacterModel models_[2];
    int perspective_;
    unsigned char current_ : 1;
    unsigned char turnBack_ : 1;
    unsigned char unk_1864_2 : 1;
    unsigned char swap_ : 1;
    void (**leftCallback_)(void* script);
    void (**rightCallback_)(void* script);

    virtual void inline_ov023_021fc518_54(void* arg0);
};

class Struct_ov023_021fc518_3 {
public:
    virtual void inline_ov023_021fc518_55();
    virtual void inline_ov023_021fc518_56();
    virtual void inline_ov023_021fc518_57();
    virtual void inline_ov023_021fc518_58();
    virtual void inline_ov023_021fc518_59();
    virtual void inline_ov023_021fc518_60();
    virtual void inline_ov023_021fc518();
    virtual void inline_ov023_021fc518_2();
    virtual void inline_ov023_021fc518_3();
    virtual void inline_ov023_021fc518_4();
    virtual void inline_ov023_021fc518_5();
    virtual void inline_ov023_021fc518_6();
    virtual void inline_ov023_021fc518_7();
    virtual void inline_ov023_021fc518_8();
    virtual void inline_ov023_021fc518_9();
    virtual void inline_ov023_021fc518_10();
    virtual void inline_ov023_021fc518_11();
    virtual void inline_ov023_021fc518_12();
    virtual void inline_ov023_021fc518_13();
    virtual void inline_ov023_021fc518_14();
    virtual void inline_ov023_021fc518_15();
    virtual void inline_ov023_021fc518_16();
    virtual void inline_ov023_021fc518_17();
    virtual void inline_ov023_021fc518_18();
    virtual void inline_ov023_021fc518_19();
    virtual void inline_ov023_021fc518_20();
    virtual void inline_ov023_021fc518_21();
    virtual void inline_ov023_021fc518_22();
    virtual void inline_ov023_021fc518_23();
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
    virtual void inline_ov023_021fc518_38();
    virtual void inline_ov023_021fc518_39();
    virtual void inline_ov023_021fc518_40();
    virtual void inline_ov023_021fc518_41();
    virtual void inline_ov023_021fc518_42();
    virtual void inline_ov023_021fc518_43();
    virtual void inline_ov023_021fc518_44();
    virtual void inline_ov023_021fc518_45();
    virtual void inline_ov023_021fc518_46();
    virtual void inline_ov023_021fc518_47();
    virtual void inline_ov023_021fc518_48();
    virtual void inline_ov023_021fc518_49();
    virtual void inline_ov023_021fc518_50();
    virtual void inline_ov023_021fc518_51();
    virtual void inline_ov023_021fc518_52();
    virtual int inline_ov023_021fc518_53();
};

struct Struct_ov023_021fc518_2 {
    int unknown_0_;
    SafeAllocator unknown_4_;
};

struct ObjBase021f6ed8;
struct Foo0207df50;
struct Camera;
struct AngleTrig0202e9a4;

extern "C" void func_ov023_021f6ed8(ObjBase021f6ed8* obj);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" MenuNode_021fc518* func_ov023_021f6880(void* list, int tag);
extern "C" HeapNode_021fc518* func_ov011_021845f8(void* ctx, int heap);
void VramState_Rewind(Foo0207df50* p);
void VramState_Restore(char* p);
void VramState_Save(char* p);
void CharacterModel_Init(void* model);
void CharacterModel_CreateAllocators(void* model, SafeAllocator* allocator);
void CharacterModel_ReserveVram(void* model);
void CharacterModel_SetItemTable(void* model, int value);
void CharacterModel_SetForceStandAnimation(void* model, unsigned char value);
void CharacterModel_SetAngle(void* model, unsigned int value);
extern "C" void func_ov023_021fc71c(void* obj, int id, int flagArg);
char* GameState_GetFollowCamera(char* gameState);
void Camera_SetPosition(Camera* camera, int x, int y, int z);
void Camera_SetTarget(struct Camera* camera, int x, int y, int z);
int GetField0x58_0202e9ec(void* camera);
void Camera_SetFieldOfView(AngleTrig0202e9a4* camera, int angle);
void FollowCamera_DisableFollow(void* camera);

// USA: func_ov023_021fc518
extern "C" ARM int func_ov023_021fc518(Struct_ov023_021fc518* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5) {
    func_ov023_021f6ed8((Struct_ov023_021f6ed8*)arg0);
    arg0->unknown_4_ = 5;
    arg0->unknown_6_ = arg2;
    arg0->unknown_8_ = arg3;
    arg0->unknown_a_ = 0;
    arg0->unknown_10_ = NULL;
    arg0->unknown_1864_0_ = 0;
    arg0->unknown_1860_ = 0;
    arg0->unknown_1864_3_ = 0;
    arg0->unknown_1864_1_ = 0;
    arg0->unknown_1864_2_ = 0;
    arg0->unknown_1868_ = NULL;
    arg0->unknown_186c_ = NULL;

    Struct_ov023_021fc518_3* var0 = func_ov023_021f6880(func_ov011_021849c8(arg1), arg4);
    Struct_ov023_021fc518_2* var1 = func_ov011_021845f8(arg1, arg3);
    int var2 = var0->inline_ov023_021fc518_53();

#if defined(jpn)
    char* var3 = (char*)GetGameResources() + 0x27c;
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
    self->perspective_ = GetField0x58_0202e9ec(camera);
    Camera_SetFieldOfView((AngleTrig0202e9a4*)camera, 0xf000);
    FollowCamera_DisableFollow(camera);
    return 1;
}
