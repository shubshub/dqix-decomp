#include <globaldefs.h>

struct Struct_ov006_021580b8
{
    char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
    char unknown_1c_[0x28 - 0x1c];
};

struct Struct_ov008_02188d74;

void SetBitfield0205af84(int renderer, void* sprite, int);
extern "C" void SpriteContext_DrawSprite(SpriteRenderer* renderer, Sprite* sprite);

extern const signed char data_ov008_0218b300[2];
extern const unsigned char data_ov008_0218b30c[4][2];
extern const int data_ov008_0218b314[2];

struct Struct_ov008_021842a0_2
{
    char unknown_0_[0x730];
    Struct_ov008_02188d74* unknown_730_;
    Struct_ov006_021580b8* unknown_734_;
    char unknown_738_[0x74c - 0x738];
    unsigned char unknown_74c_;
    char unknown_74d_[0xb18 - 0x74d];
    int unknown_b18_;
    char unknown_b1c_[0xb29 - 0xb1c];
    unsigned char unknown_b29_;
};

// USA: func_ov008_02188934
extern "C" ARM void func_ov008_02188934(Struct_ov008_021842a0_2* arg0)
{
    if (arg0->unknown_730_ == NULL)
        return;
    int var0 = arg0->unknown_b18_;
    if (!(var0 & 0x10))
        return;
    if (!(var0 & 0x80000))
        return;
    for (int var1 = 0; var1 < 2; var1++)
    {
        unsigned char var2 = arg0->unknown_b29_;
        if (arg0->unknown_74c_ == 7 && var2 == 1)
            var2 = 2;
        if (data_ov008_0218b30c[var2][var1])
        {
            Sprite* sprite = &self->sprites_[data_ov008_0218b300[i]];
            sprite->x_ = 0x46000;
            sprite->y_ = data_ov008_0218b314[i];
            SetBitfield0205af84((int)self->renderer_, &self->sprites_[data_ov008_0218b300[i]], 1);
            SpriteContext_DrawSprite(self->renderer_, &self->sprites_[data_ov008_0218b300[i]]);
        }
    }
}
