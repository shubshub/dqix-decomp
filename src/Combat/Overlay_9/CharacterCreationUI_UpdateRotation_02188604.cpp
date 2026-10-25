#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "Input/Input.h"


struct Words021e60c4;

extern "C" Vector3fix CharacterModel_GetRotation(void* character);
int fix32ReduceAngle0To2Pi(int angle);
void CharacterModel_SetAngle(void* character, unsigned int angle);
void CharacterModel_SetRotation(void* character, Words021e60c4* rotation);

// Turning towards targetAngle: each tick turns 1/Divisor of what's left, and within Snap it snaps there.
enum RotationTurn
{
    RotationTurn_Divisor = 12,
    RotationTurn_Snap = 40,
};

// The two rotate arrows at the bottom left of the touchscreen (seen in-game: tapping (18, 173) turned the
// preview by +0x2652 a tap, (63, 173) back by the same).
enum RotateArrow
{
    RotateArrow_Top = 0xa9,
    RotateArrow_Bottom = 0xb1,
    RotateArrow_LeftStart = 0xe,
    RotateArrow_LeftEnd = 0x17,
    RotateArrow_RightStart = 0x3b,
    RotateArrow_RightEnd = 0x44,
};

#define ROTATE_SPEED 0.08f // radians per tick while L, R or an arrow is held

// Overlay 9, originally func_ov009_02188604 (USA/EUR 0x02188604, JPN 0x021893c4)
extern "C" ARM void CharacterCreationUI_UpdateRotation(CharacterCreationUI* self, unsigned int ticks)
{
    if (self->flags & CreationFlag_TurnToTarget)
    {
        int done = 0;
        Vector3fix rotation = CharacterModel_GetRotation(self->character);
        int angle;
        int y = rotation.y;
        int difference = fix32ReduceAngle0To2Pi(self->targetAngle - y);
        if (difference >= 0 && difference < CreationAngle_HalfTurn)
        {
            angle = y + difference / RotationTurn_Divisor;
            for (unsigned int i = 0; i < ticks - 1; i++)
                angle += fix32ReduceAngle0To2Pi(self->targetAngle - angle) / RotationTurn_Divisor;
        }
        else if (difference >= CreationAngle_HalfTurn && difference < CreationAngle_FullTurn)
        {
            angle = y - (CreationAngle_FullTurn - difference) / RotationTurn_Divisor;
            for (unsigned int i = 0; i < ticks - 1; i++)
                angle -= (CreationAngle_FullTurn - fix32ReduceAngle0To2Pi(self->targetAngle - angle)) / RotationTurn_Divisor;
        }
        CharacterModel_SetAngle(self->character, fix32ReduceAngle0To2Pi(angle));
        int remaining = fix32ReduceAngle0To2Pi(self->targetAngle - angle);
        if ((remaining < 0 ? -remaining : remaining) < RotationTurn_Snap)
            done = 1;
        else if (((CreationAngle_FullTurn - remaining) < 0 ? -(CreationAngle_FullTurn - remaining) : (CreationAngle_FullTurn - remaining)) < RotationTurn_Snap)
            done = 1;
        if (done)
        {
            CharacterModel_SetAngle(self->character, fix32ReduceAngle0To2Pi(self->targetAngle));
            self->targetAngle = 0;
            self->flags &= ~CreationFlag_TurnToTarget;
        }
    }
    else if (self->flags & CreationFlag_StylusRotation)
    {
        int left = 0;
        int right = 0;
        int touched = 0;
        int x;
        int y;
        g_touchInput.GetTouchPoint(&x, &y);
        if (g_touchInput.pressed_ != 0 || (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) ||
            g_touchInput.released_ != 0)
        {
            touched = 1;
            if (y >= RotateArrow_Top && y <= RotateArrow_Bottom)
            {
                if (x >= RotateArrow_LeftStart && x <= RotateArrow_LeftEnd)
                    left = 1;
                if (x >= RotateArrow_RightStart && x <= RotateArrow_RightEnd)
                    right = 1;
            }
        }
        if (touched == 0)
        {
            if (g_keyManager.TestKeysHeld(KEY_L))
                left = 1;
            if (g_keyManager.TestKeysHeld(KEY_R))
                right = 1;
        }
        if (left != 0 && right != 0)
        {
            self->targetAngle = CreationAngle_Default;
            self->flags |= CreationFlag_TurnToTarget;
        }
        else if (left != 0 || right != 0)
        {
            Vector3fix rotation = CharacterModel_GetRotation(self->character);
            if (left != 0)
                rotation.y += (int)(4096.0f * (ROTATE_SPEED * ticks));
            if (right != 0)
                rotation.y -= (int)(4096.0f * (ROTATE_SPEED * ticks));
            rotation.y = fix32ReduceAngle0To2Pi(rotation.y);
            CharacterModel_SetRotation(self->character, (Words021e60c4*)&rotation);
        }
    }
}
