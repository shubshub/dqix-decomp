#include <globaldefs.h>
#include "Graphics/Background.h"
#include <Memory/SafeAllocator.h>
#include <Graphics/Vector.h>
#include <World/Object3D.h>
#include "Input/Input.h"

struct Struct_01ff8b48_26 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct TextTable {
    int unknown_0_[0x18 / 4];
};


struct TextWindow {
    int unknown_0_[0xbc / 4];
};

struct Canvas {
    int unknown_0_[0xe0 / 4];
};

struct WindowCursor {
    int unknown_0_[0x40 / 4];
};

struct Struct_ov008_021842a0_2 {
    SafeAllocator allocator_;
    SafeAllocator unknown_14_;
    SafeAllocator textAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator iconAllocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator titleAllocator_;
    SafeAllocator unknown_8c_;
    TextTable texts_;
    char* text_;
    char unknown_bc_[0x14];
    BackgroundGraphics backgrounds_[3];
    TextWindow window_;
    Canvas canvases_[6];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    void* iconRenderer_;
    void* iconSprite_;
    unsigned char items_[8];
    unsigned char unknown_74c_;
    WindowCursor cursor_;
    Object3D model_;
    char camera_[0x2c8];
    void* titles_;
    void* unknown_b08_;
    void* page_;
    signed char state_;
    unsigned char step_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int flags_;
    int unknown_b1c_;
    int task_;
    int mode_;
    unsigned char kind_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
    int titleX_;
    const void* unknown_b30_;
    void* unknown_b34_;
    void* unknown_b38_;
    void* guestTitles_;
    Struct_01ff8b48_26 unknown_b40_[2];
};

// USA: func_ov008_02186e4c
extern "C" ARM void func_ov008_02186e4c(Struct_ov008_021842a0_2* self, unsigned int ticks)
{
    int flags = self->flags_;
    if (flags & 0x40)
    {
        Vector3fix rotation = self->model_.rotation_;
        int done = 0;
        int y;
        int angle = fix32ReduceAngle0To2Pi(0x5ccc - rotation.y);
        if (angle >= 0 && angle < 0x3244)
        {
            y = rotation.y + angle / 12;
            for (unsigned int i = 0; i < ticks - 1; i++)
                y += fix32ReduceAngle0To2Pi(0x5ccc - y) / 12;
        }
        else if (angle >= 0x3244 && angle < 0x6488)
        {
            y = rotation.y - (0x6488 - angle) / 12;
            for (unsigned int i = 0; i < ticks - 1; i++)
                y -= (0x6488 - fix32ReduceAngle0To2Pi(0x5ccc - y)) / 12;
        }
        rotation.y = fix32ReduceAngle0To2Pi(y);
        self->model_.rotation_ = rotation;
        int difference = fix32ReduceAngle0To2Pi(0x5ccc - rotation.y);
        int distance = difference < 0 ? -difference : difference;
        if (distance < 0x28)
        {
            done = 1;
        }
        else
        {
            distance = 0x6488 - difference;
            if (distance < 0)
                distance = -distance;
            if (distance < 0x28)
                done = 1;
        }
        if (done)
        {
            rotation.y = fix32ReduceAngle0To2Pi(0x5ccc);
            self->model_.rotation_ = rotation;
            self->flags_ &= ~0x40;
        }
    }
    else if (flags & 0x20)
    {
        int left = 0;
        int right = 0;
        if (g_keyManager.TestKeysHeld(0x200))
            left = 1;
        if (g_keyManager.TestKeysHeld(0x100))
            right = 1;
        if (left && right)
        {
            self->flags_ |= 0x40;
            return;
        }
        if (!left && !right)
            return;
        Vector3fix rotation = self->model_.rotation_;
        if (left)
            rotation.y += (int)(4096.0f * (0.08f * ticks));
        if (right)
            rotation.y -= (int)(4096.0f * (0.08f * ticks));
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y);
        self->model_.rotation_ = rotation;
    }
}
