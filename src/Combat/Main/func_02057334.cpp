#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_020546c8;
struct Struct_02055ed0_3
{
    unsigned char padding[0x148];
    Struct_02055ed0_3* next;
};
struct Struct_02055c30;

struct Struct_02057334_2
{
    unsigned char unknown_0_[4];
    unsigned int frame;
    unsigned int endFrame;
    unsigned char repeat;
    unsigned char unknown_d_[0x23];
    Struct_020546c8* resource;
    Struct_02055ed0_3* head;
    unsigned char flags;
    unsigned char unknown_39_[0x13];
    float unknown_4c_[4];
    unsigned char unknown_5c_[8];
    float unknown_64_[3];
    float unknown_70_[3];
    float unknown_7c_[3];
    unsigned char unknown_88_[0x14];
    float unknown_9c_;
    unsigned char unknown_a0_[4];
    float unknown_a4_[3];
    float unknown_b0_[3];
    unsigned char unknown_bc_[0x5c];
    float unknown_118_[4];
    float unknown_128_[3];
    float rotation[3];
    float scale[3];
    float duration;
    int delay;
    unsigned int unknown_154_;
    float extra[3];
    float vector[3];
};

struct Struct_02057334
{
    unsigned char padding[6];
    unsigned char unknown_6_;
};

extern "C" int func_02057854(Struct_02057334_2*);
extern "C" void func_02058c88(Struct_02055ed0_3*);
extern "C" void* func_020550c0(Struct_020546c8*);
extern "C" void func_02055c30(Struct_02055c30*);
extern "C" void func_02056d80(Struct_02057334_2*);
extern "C" void func_020557a4(Struct_02057334_2*);
extern "C" void func_020559cc(Struct_02057334_2*);
extern "C" void func_02055ccc(Struct_02057334_2*);
extern "C" void func_02059720(Struct_02055ed0_3*);
extern "C" void func_02055f5c(Struct_02057334_2*, int, int);

// USA: func_02057334
extern "C" ARM int func_02057334(Struct_02057334_2* self)
{
    int steps = 0;
    int var1 = 0;
    int ticks = GameState::GetInstance()->GetTickCount();
    if (!func_02057854(self))
    {
        if (self->frame > self->endFrame && self->flags)
        {
            Struct_02055ed0_3* child = self->head;
            while (child)
            {
                func_02058c88(child);
                child = child->next;
            }
        }
        else if (self->frame > self->endFrame && !self->flags)
        {
            var1 = 1;
        }
        if (self->frame > self->endFrame && self->repeat)
        {
            func_02056d80(self);
            var1 = 1;
        }
        if (!var1)
        {
            if (self->frame > self->unknown_154_)
            {
                self->delay -= ticks;
                if (self->delay < 0)
                {
                    int var4 = ((Struct_02057334*)func_020550c0(self->resource))->unknown_6_;
                    self->delay = var4;
                    if (ticks < var4 + 1)
                    {
                        steps = 1;
                    }
                    else
                    {
                        steps = ticks / (var4 + 1);
                    }
                }
            }
            self->unknown_118_[0] += self->unknown_4c_[0] * (float)ticks;
            self->unknown_118_[1] += self->unknown_4c_[1] * (float)ticks;
            self->unknown_118_[2] += self->unknown_4c_[2] * (float)ticks;
            self->unknown_118_[3] += self->unknown_4c_[3] * (float)ticks;
            for (int i = 0; i < 3; i++)
            {
                self->unknown_128_[i] += (float)ticks * self->unknown_64_[i];
                self->rotation[i] += (float)ticks * self->unknown_70_[i];
                self->scale[i] += (float)ticks * self->unknown_7c_[i];
                self->extra[i] += (float)ticks * self->unknown_a4_[i];
                self->vector[i] += (float)ticks * self->unknown_b0_[i];
            }
            self->duration += self->unknown_9c_ * (float)ticks;
            func_020557a4(self);
            func_020559cc(self);
            func_02055c30((Struct_02055c30*)self);
            func_02055ccc(self);
        }
    }
    if (!func_02057854(self) || !self->flags)
    {
        Struct_02055ed0_3* child = self->head;
        while (child)
        {
            func_02059720(child);
            child = child->next;
        }
    }
    if (steps)
    {
        func_02055f5c(self, ticks, steps);
    }
    if (!func_02057854(self))
    {
        self->frame += ticks;
    }
    return steps != 0;
}
