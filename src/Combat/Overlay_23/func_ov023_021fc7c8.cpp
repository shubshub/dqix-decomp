#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Input/Input.h"
#include "Graphics/CharacterModel.h"

class Struct_ov023_021fc7c8_2
{
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

    virtual void inline_ov023_021fc7c8(void* arg0);
};

struct Struct_ov009_02188454;

void SetFogState_020c54a4(int, unsigned int, unsigned int, unsigned short);
extern "C" void CharacterModel_Update(CharacterModel* model);
extern "C" Vector3i CharacterModel_GetRotation(CharacterModel* model);
char* GetFieldIfFlag4_020100f8(char* gameState);
void SetFlagsAt0x244_020a28a0(unsigned char* camera, unsigned char flags);
void ClearFlagBits_020a28b0(unsigned char* camera, int flags);
void Camera_EasePositionTo(struct Camera*, int, int);
void Camera_EaseTargetTo(struct Camera*, int, int);
void CharacterModel_SetRotation(void* model, Words021e60c4* rotation);

extern const Vector3i data_ov023_021fda08;
extern const Vector3i data_ov023_021fd9fc;
extern const Vector3i data_ov023_021fd9f0;
extern const Vector3i data_ov023_021fd9e4;

// USA: func_ov023_021fc7c8
extern "C" ARM void func_ov023_021fc7c8(Struct_ov023_021fc7c8_2* arg0, void* arg1)
{
    SetFogState_020c54a4(0, 0, 0, 0);
    GameState* gameState = GameState::GetInstance();
    unsigned int ticks = gameState->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    CharacterModel_Update(&self->models_[0]);
    CharacterModel_Update(&self->models_[1]);
    if (self->swap_)
    {
        int var2 = (arg0->unknown_1864_0_ + 1) % 2;
        if (!arg0->unknown_20_[var2].unknown_c12_)
        {
            arg0->unknown_1864_0_ = var2;
            arg0->unknown_1864_3_ = 0;
        }
    }
    CharacterModel* model = &self->models_[self->current_];
    Vector3i rotation = CharacterModel_GetRotation(model);
    int difference = fix32ReduceAngle0To2Pi(0x1eb - rotation.y);
    int angle = 0;
    if (g_keyManager.TestKeysHeld(0x200) && g_keyManager.TestKeysHeld(0x100))
    {
        if (!arg0->unknown_1864_1_)
            arg0->unknown_1864_1_ = 1;
    }
    if (g_keyManager.TestKeysHeld(0x40))
    {
        const Vector3i position = data_ov023_021fda08;
        const Vector3i target = data_ov023_021fd9fc;
        char* camera = GetFieldIfFlag4_020100f8((char*)gameState);
        SetFlagsAt0x244_020a28a0((unsigned char*)camera, 2);
        Camera_EasePositionTo((struct Camera*)camera, (int)&position, 0xa000);
        Camera_EaseTargetTo((struct Camera*)camera, (int)&target, 0xa000);
    }
    else if (g_keyManager.TestKeysHeld(0x80))
    {
        const Vector3i position = data_ov023_021fd9f0;
        const Vector3i target = data_ov023_021fd9e4;
        char* camera = GetFieldIfFlag4_020100f8((char*)gameState);
        ClearFlagBits_020a28b0((unsigned char*)camera, 2);
        Camera_EasePositionTo((struct Camera*)camera, (int)&position, 0xa000);
        Camera_EaseTargetTo((struct Camera*)camera, (int)&target, 0xa000);
    }
    if (arg0->unknown_1864_1_)
    {
        if (var5 >= 0 && var5 < 0x3244)
        {
            var6 = var4.y + var5 / 12;
            for (unsigned int var13 = 0; var13 < var1 - 1; var13++)
                var6 += fix32ReduceAngle0To2Pi(0x1eb - var6) / 12;
        }
        else if (var5 >= 0x3244 && var5 < 0x6488)
        {
            var6 = var4.y - (0x6488 - var5) / 12;
            for (unsigned int var14 = 0; var14 < var1 - 1; var14++)
                var6 -= (0x6488 - fix32ReduceAngle0To2Pi(0x1eb - var6)) / 12;
        }
        var4.y = fix32ReduceAngle0To2Pi(var6);
        int var15 = fix32ReduceAngle0To2Pi(0x1eb - var6);
        int var16 = var15 < 0 ? -var15 : var15;
        if (var16 < 0x28)
        {
            arg0->unknown_1864_1_ = 0;
        }
        else
        {
            var16 = 0x6488 - var15;
            if (var16 < 0)
                var16 = -var16;
            if (var16 < 0x28)
                arg0->unknown_1864_1_ = 0;
        }
        if (!arg0->unknown_1864_1_)
            var4.y = 0x1eb;
    }
    else if (g_keyManager.TestKeysHeld(0x200))
    {
        if (arg0->unknown_1868_ != NULL)
        {
            (*self->leftCallback_)(script);
            rotation = CharacterModel_GetRotation(model);
        }
        else
        {
            var4.y += (int)(4096.0f * (0.08f * var1));
            var4.y = fix32ReduceAngle0To2Pi(var4.y);
        }
    }
    else if (g_keyManager.TestKeysHeld(0x100))
    {
        if (arg0->unknown_186c_ != NULL)
        {
            (*self->rightCallback_)(script);
            rotation = CharacterModel_GetRotation(model);
        }
        else
        {
            var4.y += (int)(4096.0f * (-0.08f * var1));
            var4.y = fix32ReduceAngle0To2Pi(var4.y);
        }
    }
    CharacterModel_SetRotation(model, (Words021e60c4*)&rotation);
}
