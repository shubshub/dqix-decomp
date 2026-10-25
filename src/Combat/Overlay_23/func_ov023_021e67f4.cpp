#include <globaldefs.h>

struct Struct_ov023_021e67f4_3 {
    char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_[0xbc - 0xb0];
    short unknown_bc_;
    short unknown_be_;
};

struct Struct_ov023_021e67f4_2 {
    char unknown_0_[4];
    short unknown_4_;
    short unknown_6_;
    char unknown_8_[0x15 - 8];
    unsigned char unknown_15_;
};

struct Struct_0205d81c;
struct Struct_0205a254;
struct Struct_0205a330;

Canvas_021e67f4* Window_GetActivePane(struct Struct_0205d81c* s);
int WindowPane_IsOpen(unsigned char* obj);
void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
Animation_021e67f4* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);
extern "C" void SpriteContext_DrawEntries(void* obj);

#if defined(jpn)
struct Struct_ov023_021e67f4 {
    char unknown_0_[0x90];
    char unknown_ac_[0x1334 - 0x90];
    void* unknown_135c_;
    void* unknown_1360_;
    char unknown_133c_[0x1368 - 0x133c];
    unsigned char unknown_13a0_;
    char unknown_1369_[3];
    int unknown_13a4_;
};

#else
struct Struct_ov023_021e67f4 {
    char unknown_0_[0xac];
    char unknown_ac_[0x135c - 0xac];
    void* unknown_135c_;
    void* unknown_1360_;
    char unknown_1364_[0x13a0 - 0x1364];
    unsigned char unknown_13a0_;
    char unknown_13a1_[3];
    int unknown_13a4_;
};

#endif
// USA: func_ov023_021e67f4
extern "C" ARM void func_ov023_021e67f4(Struct_ov023_021e67f4* arg0)
{
    if (arg0->unknown_13a0_ == 0)
        return;
    Canvas_021e67f4* canvas = Window_GetActivePane((Struct_0205d81c*)self->window_);
    if (canvas == NULL)
        return;
    if (!WindowPane_IsOpen((unsigned char*)canvas))
        return;
    short x = canvas->x_ * 8;
    short y = canvas->y_ * 8;
    x += canvas->unk_bc;
    y += canvas->unk_be;
    SpriteEntryList_PlayAnimation((Container0205a3d0*)self->unk_1360, 0);
    Animation_021e67f4* animation = SpriteEntryList_Find((Container0205a3d0*)self->unk_1360, 0);
    if (animation != NULL)
        animation->flags_ |= 8;
    SpriteEntryList_AdvanceAnimations((Container0205a330*)self->unk_1360, self->unk_13a4);
    animation = SpriteEntryList_Find((Container0205a3d0*)self->unk_1360, 0);
    if (animation != NULL)
    {
        var3->unknown_4_ = var1 - 8;
        var3->unknown_6_ = var2 - 2;
    }
    SpriteContext_DrawEntries(self->renderer_);
}
