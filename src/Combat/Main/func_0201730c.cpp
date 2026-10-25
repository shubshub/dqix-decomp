#include <globaldefs.h>
#include "GameState/Field3b0.h"

#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "NitroSDK/Graphics.h"

struct Struct_0201730c;
struct Struct_0201730c_2;

struct Struct_0201730c_3 {
    char unknown_0_[0x8];
    void* unknown_8_;
    char unknown_c_[0x1c - 0xc];
    Vector3i unknown_1c_;
    char unknown_28_[0x34 - 0x28];
    Vector3i unknown_34_;
    char unknown_40_[0x80 - 0x40];
    unsigned short unknown_80_;
    char unknown_82_[0x88 - 0x82];
};

struct Struct_0201730c_2 {
    char unknown_0_[0xc];
    void* unknown_c_;
    char unknown_10_[0x1c - 0x10];
    Vector3i unknown_1c_;
    char unknown_28_[0x80 - 0x28];
    unsigned short unknown_80_;
    char unknown_82_[0x88 - 0x82];
};

struct Struct_0201730c_4 {
    short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    char unknown_6_[0x8 - 6];
    Struct_0201730c_3 unknown_8_;
    Struct_0201730c_2 unknown_90_;
    Struct_0201730c_3 unknown_118_[4];
    Vector3i unknown_338_[4];
};

struct Struct_02016874_3 {
    #if defined(jpn)
    char unknown_0_[0x496];
#else
    char unknown1_0_[0x476];
#endif
    unsigned char unknown_476_;
    char unknown_477_[1];
    Struct_0201730c_4* unknown_478_;
    #if defined(jpn)
    char unknown_49c_[0x2790 - 0x49c];
#else
    char unknown_47c_[0x2750 - 0x47c];
#endif
    void* unknown_2750_;
};

void* GetPtrField0x144_0202ed74(void* obj);
void RenderConfig_SetObjectRotation(void* arg);
int GetBoxTestResult_020c56b0(int* out);
void SubmitGxCommands02047648(unsigned char* obj, int idx, int something);
void AdvanceStreamRecord0204724c(Obj0204724C* obj);
void RenderTransformedFlaggedIndexedEntry(StructAt020472e4* obj, int param);

extern Vector3i data_020e6e20;
extern int data_020e6e64[4];

// USA: func_0201730c
extern "C" ARM void func_0201730c(Struct_02016874_3* arg0) {
    if (arg0->unknown_2750_ == NULL) return;

    GameState* game = GameState::GetInstance();
    void* camera = game->GetCamera();
    if (camera == NULL) return;
    game->GetTickCount();
    unsigned short lightColor = LightingManager::GetInstance()->maybePotBarrelDiffuseColor_;
    RenderConfig_SetObjectRotation(GetPtrField0x144_0202ed74(camera));

    for (int var3 = 0; var3 < arg0->unknown_476_; var3++) {
        Struct_0201730c_4* var4 = &arg0->unknown_478_[var3];
        if (var4->unknown_2_ == -1) continue;

        RenderConfig::SetObjectPosition(&var4->unknown_8_.unknown_1c_);

        Vector3i var5 = data_020e6e20;
        RenderConfig::SetObjectScale(&var5);
        RenderConfig::SubmitToFifo();

        union {
            struct {
                short unknown_0_;
                short unknown_2_;
                short unknown_4_;
                short unknown_6_;
                short unknown_8_;
                short unknown_a_;
            } unknown_0_;
            struct {
                unsigned int unknown_0_;
                unsigned int unknown_4_;
                unsigned int unknown_8_;
            } unknown1_0_;
        } var6;
        var6.unknown_0_.unknown_0_ = -0x800;
        var6.unknown_0_.unknown_2_ = 0;
        var6.unknown_0_.unknown_4_ = -0x800;
        var6.unknown_0_.unknown_6_ = 0x1000;
        var6.unknown_0_.unknown_8_ = 0x1000;
        var6.unknown_0_.unknown_a_ = 0x1000;
        GXFIFO_TEST_BOX = var6.unknown1_0_.unknown_0_;
        GXFIFO_TEST_BOX = var6.unknown1_0_.unknown_4_;
        GXFIFO_TEST_BOX = var6.unknown1_0_.unknown_8_;

        int var7;
        while (func_020c56b0(&var7) != 0) {}
        if (var7 == 0) continue;

        var5 = var4->unknown_8_.unknown_34_;
        RenderConfig::SetObjectScale(&var5);
        RenderConfig::SubmitToFifo();

        var4->unknown_8_.unknown_80_ = var2;
        var4->unknown_90_.unknown_80_ = var2;
        for (int var8 = 0; var8 < 4; var8++) var4->unknown_118_[var8].unknown_80_ = var2;

        if (var4->unknown_2_ != 3) {
            func_02047648((unsigned char*)&var4->unknown_8_, 0, 1);
        } else if (var4->unknown_2_ == 3) {
            if (var4->unknown_4_ < 12) {
                func_0204724c((Struct_0201730c*)&var4->unknown_90_);
                func_020472e4(&var4->unknown_90_, 1);
            }
            for (int j = 0; j < 4; j++) {
                CombatRecord* segment = &entry->segments[j];
                RenderConfig::SetObjectPosition(&segment->position);
                Matrix3x3* viewMatrix = (Matrix3x3*)GetPtrField0x144_0202ed74(camera);
                Matrix3x3 rotation;
                Matrix3x3 transformed;
                fix32_t angle = data_020e6e64[j];
                fix32_t cosine = fix32cos(angle);
                fix32_t sine = fix32sin(angle);
                Mat3x3_WriteRotationY(&rotation, sine, cosine);
                Mat3x3_Multiply(viewMatrix, &rotation, &transformed);
                RenderConfig_SetObjectRotation(&transformed);
                RenderConfig::SubmitToFifo();
                func_02047648((unsigned char*)var10, 0, 1);
            }
        }
    }
}
