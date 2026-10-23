#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct Struct_02000c9c_75 {
    char unknown_0_[0xc20];
};

class Struct_ov023_021fc518 {
public:
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned char unknown_c_;
    char unknown_d_[3];
    const char* unknown_10_;
    void* unknown_14_;
    void* unknown_18_;
    int unknown_1c_;
    Struct_02000c9c_75 unknown_20_[2];
    int unknown_1860_;
    unsigned char unknown_1864_0_ : 1;
    unsigned char unknown_1864_1_ : 1;
    unsigned char unknown_1864_2_ : 1;
    unsigned char unknown_1864_3_ : 1;
    void (**unknown_1868_)(void* script);
    void (**unknown_186c_)(void* script);

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

struct Struct_ov023_021f6ed8;
struct Struct_0203d028;
struct Struct_0202e5c0;
struct Struct_0202df68;

extern "C" void func_ov023_021f6ed8(ObjBase021f6ed8* obj);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" MenuNode_021fc518* func_ov023_021f6880(void* list, int tag);
extern "C" HeapNode_021fc518* func_ov011_021845f8(void* ctx, int heap);
void CopyInternalFields0207df50(Foo0207df50* p);
void VramState_Restore(char* p);
void VramState_Save(char* p);
void CharacterModel_Init(void* model);
void CharacterModel_CreateAllocators(void* model, SafeAllocator* allocator);
void CharacterModel_ReserveVram(void* model);
void CharacterModel_SetItemTable(void* model, int value);
void SetByteC11_021e6150(void* model, unsigned char value);
void CharacterModel_SetAngle(void* model, unsigned int value);
extern "C" void func_ov023_021fc71c(void* obj, int id, int flagArg);
char* GetFieldIfFlag4_020100f8(char* gameState);
void Camera_SetPosition(Vec3Target0202e5c0* camera, int x, int y, int z);
void Camera_SetTarget(unsigned char* camera, int x, int y, int z);
int GetField0x58_0202e9ec(void* camera);
void SetAngleAndTrigTable0202e9a4(AngleTrig0202e9a4* camera, int angle);
void SetField0x238False_020a27a0(void* camera);

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
    char* var3 = GetGameResources()->unknown_2cc_;
#endif
    CopyInternalFields0207df50((Foo0207df50*)pairTables);
    VramState_Restore(pairTables);
    for (int i = 0; i < 2; i++) {
        CharacterModel_Init(&self->models_[i]);
        CharacterModel_CreateAllocators(&self->models_[i], &heapNode->allocator);
        CharacterModel_ReserveVram(&self->models_[i]);
        CharacterModel_SetItemTable(&self->models_[i], perspective);
        SetByteC11_021e6150(&self->models_[i], 1);
    }
    VramState_Save(pairTables);

    CharacterModel_SetAngle(&self->models_[0], 0x1eb);
    CharacterModel_SetAngle(&self->models_[1], 0x1eb);
    if (character >= 0)
        func_ov023_021fc71c(self, character, 0);

    char* camera = GetFieldIfFlag4_020100f8((char*)GameState::GetInstance());
    Camera_SetPosition((Vec3Target0202e5c0*)camera, 0xb666, 0xb800, 0x42ccc);
    Camera_SetTarget((unsigned char*)camera, 0xb666, 0xb800, 0);
    self->perspective_ = GetField0x58_0202e9ec(camera);
    SetAngleAndTrigTable0202e9a4((AngleTrig0202e9a4*)camera, 0xf000);
    SetField0x238False_020a27a0(camera);
    return 1;
}
