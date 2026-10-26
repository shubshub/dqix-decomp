#include <globaldefs.h>

struct Canvas_021e67f4 {
    char pad0[0xac];
    short x_;
    short y_;
    char unknown_b0_[0xbc - 0xb0];
    short unk_bc;
    short unknown_be_;
};

struct Animation_021e67f4 {
    char pad0[4];
    short x_;
    short y_;
    char pad8[0x15 - 8];
    unsigned char flags_;
};

struct Struct_0205d81c;
struct Container0205a3d0;
struct Container0205a330;

extern "C" Canvas_021e67f4* Window_GetActivePane(struct Struct_0205d81c* s);
extern "C" int WindowPane_IsOpen(unsigned char* obj);
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
extern "C" Animation_021e67f4* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);
extern "C" void SpriteContext_DrawEntries(void* obj);

#if defined(jpn)
struct Struct_ov023_021e67f4 {
    char pad0[0x90];
    char window_[0x1334 - 0x90];
    void* renderer_;
    void* unk_1360;
    char unknown_133c_[0x1368 - 0x133c];
    unsigned char unknown_13a0_;
    char unknown_1369_[3];
    int unk_13a4;
};

#else
struct Struct_ov023_021e67f4 {
    char pad0[0xac];
    char window_[0x135c - 0xac];
    void* renderer_;
    void* unk_1360;
    char unknown_1364_[0x13a0 - 0x1364];
    unsigned char unknown_13a0_;
    char unknown_13a1_[3];
    int unk_13a4;
};

#endif
// USA: func_ov023_021e67f4
extern "C" ARM void func_ov023_021e67f4(Struct_ov023_021e67f4* self)
{
    if (self->unknown_13a0_ == 0)
        return;
    Canvas_021e67f4* canvas = Window_GetActivePane((Struct_0205d81c*)self->window_);
    if (canvas == NULL)
        return;
    if (!WindowPane_IsOpen((unsigned char*)canvas))
        return;
    short x = canvas->x_ * 8;
    short y = canvas->y_ * 8;
    x += canvas->unk_bc;
    y += canvas->unknown_be_;
    SpriteEntryList_PlayAnimation((Container0205a3d0*)self->unk_1360, 0);
    Animation_021e67f4* animation = SpriteEntryList_Find((Container0205a3d0*)self->unk_1360, 0);
    if (animation != NULL)
        animation->flags_ |= 8;
    SpriteEntryList_AdvanceAnimations((Container0205a330*)self->unk_1360, self->unk_13a4);
    animation = SpriteEntryList_Find((Container0205a3d0*)self->unk_1360, 0);
    if (animation != NULL)
    {
        animation->x_ = x - 8;
        animation->y_ = y - 2;
    }
    SpriteContext_DrawEntries(self->renderer_);
}
