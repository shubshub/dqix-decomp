#include <globaldefs.h>

struct Sprite
{
    char unk_0[0x14];
    int x_;
    int y_;
    char unk_1c[0x28 - 0x1c];
};

struct SpriteRenderer;

extern "C" void func_0205af84(int renderer, void* sprite, int);
extern "C" void SpriteContext_DrawSprite(SpriteRenderer* renderer, Sprite* sprite);

extern const signed char data_ov008_0218b300[2];
extern const unsigned char data_ov008_0218b30c[4][2];
extern const int data_ov008_0218b314[2];

struct Struct_ov008_021842a0_2
{
    char unk_0[0x730];
    SpriteRenderer* renderer_;
    Sprite* sprites_;
    char unknown_738_[0x74c - 0x738];
    unsigned char unknown_74c_;
    char unknown_74d_[0xb18 - 0x74d];
    int flags_;
    char unknown_b1c_[0xb29 - 0xb1c];
    unsigned char unknown_b29_;
};

// USA: func_ov008_02188934
extern "C" ARM void func_ov008_02188934(Struct_ov008_021842a0_2* self)
{
    if (self->renderer_ == NULL)
        return;
    int flags = self->flags_;
    if (!(flags & 0x10))
        return;
    if (!(flags & 0x80000))
        return;
    for (int i = 0; i < 2; i++)
    {
        unsigned char top = self->unknown_b29_;
        if (self->unknown_74c_ == 7 && top == 1)
            top = 2;
        if (data_ov008_0218b30c[top][i])
        {
            Sprite* sprite = &self->sprites_[data_ov008_0218b300[i]];
            sprite->x_ = 0x46000;
            sprite->y_ = data_ov008_0218b314[i];
            func_0205af84((int)self->renderer_, &self->sprites_[data_ov008_0218b300[i]], 1);
            SpriteContext_DrawSprite(self->renderer_, &self->sprites_[data_ov008_0218b300[i]]);
        }
    }
}
