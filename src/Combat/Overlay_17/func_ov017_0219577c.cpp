#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_ov017_021acd7c(void* obj);
extern "C" void func_ov017_021adb50(char* obj);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);
struct Field3f8Struct;
extern "C" Field3f8Struct* GameState_GetZoneTransition(GameState* bs);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int length);
struct ListHead02046b60;
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);
extern "C" void func_02046a8c(void* list, void* node);
extern "C" int GameState_UpdatePlayClocks(int commit);
extern "C" void func_ov017_021d1118(int a, int b, int c, int d);

struct Field3f8Struct0219577c {
    unsigned short field_0;
    unsigned char unknown_2_;
    unsigned char pad3;
    unsigned char unknown_4_;
    unsigned char pad5[2];
    unsigned char active;
    unsigned char field_8;
    unsigned char unknown_9_;
    unsigned char unknown_a_;
    signed char unknown_b_;
    unsigned char unknown_c_;
    unsigned char unknown_d_[3];
    Vector3i pos;
    short angle;
    short unknown_1e_;
    int field_20;
    int unknown_24_;
    int field_28;
    int unknown_2c_;
    unsigned char unknown_30_[0x35];
    unsigned char unknown_65_;
    unsigned char unknown_66_;
    unsigned char unknown_67_[5];
    short unknown_6c_;
};

struct Struct_ov017_0219577c {
    unsigned char pad0[2];
    unsigned char busy;
#if defined(jpn)
    unsigned char pad3[0x20c];
#else
    unsigned char pad3[0x27c];
#endif
    unsigned char unknown_27f_;
    unsigned char unknown_280_;
    unsigned char unknown_281_;
    unsigned char unknown_282_;
};

// USA: func_ov017_0219577c
extern "C" ARM void func_ov017_0219577c(unsigned char mode, int arg1, int append) {
#if defined(jpn)
 enum {regionalList=0x4ec,regionalNode=0x900,Enum_ov017_0219577c_3236=0xa84,Enum_ov017_0219577c_1804=0x4fc,Enum_ov017_0219577c_2968=0x978};
#else
 enum {regionalList=0x6fc,regionalNode=0xb20,Enum_ov017_0219577c_3236=0xca4,Enum_ov017_0219577c_1804=0x70c,Enum_ov017_0219577c_2968=0xb98};
#endif
    GameState* gs = GameState::GetInstance();
    char* ctx = (char*)GetGameResources();
    void* list = *(void**)(ctx + 0x3000 + regionalList);
    Zone3D_GetInstance();
    Struct_ov017_0219577c* node = *(Struct_ov017_0219577c**)(ctx + 0x3000 + regionalNode);
    if (node->busy) return;

    func_ov017_021acd7c(node);
    node->unknown_280_ = 1;
    node->unknown_27f_ = mode;
    node->unknown_281_ = arg1 == 0;
    node->unknown_282_ = append == 0;
    if (mode == 0 && append != 0) {
        func_ov017_021adb50((char*)node);
    }
    func_020469b4((struct TailList020469b4*)list, (struct TailNode020469b4*)node);

    if (arg1) {
        Field3f8Struct0219577c* field = (Field3f8Struct0219577c*)GameState_GetZoneTransition(gs);
        VectorizedMemset(field, 0, 0x70);
        field->unknown_4_ = 1;
        field->field_8 = 1;
        field->unknown_9_ = 1;
        field->unknown_b_ = -1;
        field->field_20 = -1;
        field->unknown_24_ = -1;
        field->field_28 = -1;
        field->unknown_2c_ = -1;
        field->unknown_1e_ = -1;
        field->unknown_c_ = 0;
        field->unknown_6c_ = -1;
        field->unknown_2_ = 1;
        field->field_0 = 0xc3b5;
        field->active = 1;
        field->angle = 0;
        field->pos.x = 0x48cc;
        field->pos.y = 0x199;
        field->pos.z = -0x733;
        field->unknown_66_ = 1;
        field->unknown_65_ = 1;

        if (func_02046b60((struct ListHead02046b60*)list, 0x4e)) {
            func_02046a8c(list, *(void**)(ctx + 0x3000 + Enum_ov017_0219577c_3236));
        }
        if (func_02046b60((struct ListHead02046b60*)list, 3)) {
            func_02046a8c(list, *(void**)(ctx + 0x3000 + Enum_ov017_0219577c_1804));
        }
    }
    if (func_02046b60((struct ListHead02046b60*)list, 0x40)) {
        func_02046a8c(list, *(void**)(ctx + 0x3000 + Enum_ov017_0219577c_2968));
    }
    GameState_UpdatePlayClocks(1);
    if (mode) {
        func_ov017_021d1118(-1, 1, 1, 2);
    }
}
