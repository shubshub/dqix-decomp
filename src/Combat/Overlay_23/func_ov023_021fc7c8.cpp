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

    virtual void inline_ov023_021fc7c8(void* script);
};

struct Words021e60c4;

extern "C" void func_020c54a4(int, unsigned int, unsigned int, unsigned short);
extern "C" void CharacterModel_Update(CharacterModel* model);
extern "C" Vector3i CharacterModel_GetRotation(CharacterModel* model);
extern "C" char* GameState_GetFollowCamera(char* gameState);
extern "C" void func_020a28a0(unsigned char* camera, unsigned char flags);
extern "C" void func_020a28b0(unsigned char* camera, int flags);
extern "C" void Camera_EasePositionTo(struct Camera*, int, int);
extern "C" void Camera_EaseTargetTo(struct Camera*, int, int);
extern "C" void CharacterModel_SetRotation(void* model, Words021e60c4* rotation);

extern const Vector3i data_ov023_021fda08;
extern const Vector3i data_ov023_021fd9fc;
extern const Vector3i data_ov023_021fd9f0;
extern const Vector3i data_ov023_021fd9e4;

// USA: func_ov023_021fc7c8
extern "C" ARM void func_ov023_021fc7c8(Struct_ov023_021fc7c8_2* self, void* script)
{
    func_020c54a4(0, 0, 0, 0);
    GameState* gameState = GameState::GetInstance();
    unsigned int ticks = gameState->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    CharacterModel_Update(&self->models_[0]);
    CharacterModel_Update(&self->models_[1]);
    if (self->unknown_1864_3_)
    {
        int next = (self->current_ + 1) % 2;
        if (!self->models_[next].loading_)
        {
            self->current_ = next;
            self->unknown_1864_3_ = 0;
        }
    }
    CharacterModel* model = &self->models_[self->current_];
    Vector3i rotation = CharacterModel_GetRotation(model);
    int difference = fix32ReduceAngle0To2Pi(0x1eb - rotation.y);
    int angle = 0;
    if (g_keyManager.TestKeysHeld(0x200) && g_keyManager.TestKeysHeld(0x100))
    {
        if (!self->unknown_1864_1_)
            self->unknown_1864_1_ = 1;
    }
    if (g_keyManager.TestKeysHeld(0x40))
    {
        const Vector3i position = data_ov023_021fda08;
        const Vector3i target = data_ov023_021fd9fc;
        char* camera = GameState_GetFollowCamera((char*)gameState);
        func_020a28a0((unsigned char*)camera, 2);
        Camera_EasePositionTo((struct Camera*)camera, (int)&position, 0xa000);
        Camera_EaseTargetTo((struct Camera*)camera, (int)&target, 0xa000);
    }
    else if (g_keyManager.TestKeysHeld(0x80))
    {
        const Vector3i position = data_ov023_021fd9f0;
        const Vector3i target = data_ov023_021fd9e4;
        char* camera = GameState_GetFollowCamera((char*)gameState);
        func_020a28b0((unsigned char*)camera, 2);
        Camera_EasePositionTo((struct Camera*)camera, (int)&position, 0xa000);
        Camera_EaseTargetTo((struct Camera*)camera, (int)&target, 0xa000);
    }
    if (self->unknown_1864_1_)
    {
        if (difference >= 0 && difference < 0x3244)
        {
            angle = rotation.y + difference / 12;
            for (unsigned int i = 0; i < ticks - 1; i++)
                angle += fix32ReduceAngle0To2Pi(0x1eb - angle) / 12;
        }
        else if (difference >= 0x3244 && difference < 0x6488)
        {
            angle = rotation.y - (0x6488 - difference) / 12;
            for (unsigned int i = 0; i < ticks - 1; i++)
                angle -= (0x6488 - fix32ReduceAngle0To2Pi(0x1eb - angle)) / 12;
        }
        rotation.y = fix32ReduceAngle0To2Pi(angle);
        int left = fix32ReduceAngle0To2Pi(0x1eb - angle);
        int distance = left < 0 ? -left : left;
        if (distance < 0x28)
        {
            self->unknown_1864_1_ = 0;
        }
        else
        {
            distance = 0x6488 - left;
            if (distance < 0)
                distance = -distance;
            if (distance < 0x28)
                self->unknown_1864_1_ = 0;
        }
        if (!self->unknown_1864_1_)
            rotation.y = 0x1eb;
    }
    else if (g_keyManager.TestKeysHeld(0x200))
    {
        if (self->unknown_1868_ != NULL)
        {
            (*self->unknown_1868_)(script);
            rotation = CharacterModel_GetRotation(model);
        }
        else
        {
            rotation.y += (int)(4096.0f * (0.08f * ticks));
            rotation.y = fix32ReduceAngle0To2Pi(rotation.y);
        }
    }
    else if (g_keyManager.TestKeysHeld(0x100))
    {
        if (self->unknown_186c_ != NULL)
        {
            (*self->unknown_186c_)(script);
            rotation = CharacterModel_GetRotation(model);
        }
        else
        {
            rotation.y += (int)(4096.0f * (-0.08f * ticks));
            rotation.y = fix32ReduceAngle0To2Pi(rotation.y);
        }
    }
    CharacterModel_SetRotation(model, (Words021e60c4*)&rotation);
}
