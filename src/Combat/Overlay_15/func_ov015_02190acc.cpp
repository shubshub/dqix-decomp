#include <globaldefs.h>

struct Struct_ov015_0218c03c_2
{
    char unk_0[0x3a];
    unsigned char unknown_3a_;
    char unknown_3b_[0x44 - 0x3b];
    int unknown_44_;
    int battle_;
};

struct Struct_ov015_02190acc
{
    char unk_0[0x30];
    Struct_ov015_0218c03c_2* current_;
    char unknown_34_[0x194 - 0x34];
    int menu_;
    char unknown_198_[0x1a1 - 0x198];
    unsigned char unknown_1a1_;
    char unknown_1a2_[2];
    int page_;
};

extern "C" void func_020290e8(int x, int y, const char* text, ...);
extern "C" int func_ov015_02190c2c(Struct_ov015_02190acc* self);

extern char data_ov015_021942a2[];
extern char data_ov015_021942ae[];
extern char data_ov015_021942ba[];
extern char data_ov015_021942c8[];
extern char data_ov015_021942d4[];
extern char data_ov015_021942e0[];
extern char data_ov015_021942ec[];
extern char data_ov015_021942f6[];
extern char data_ov015_02194302[];
extern char data_ov015_0219430e[];
extern char data_ov015_0219431a[];
extern char data_ov015_02194324[];

// USA: func_ov015_02190acc
extern "C" ARM void func_ov015_02190acc(Struct_ov015_02190acc* self)
{
    func_020290e8(0x87, 0xa, data_ov015_021942a2);
    func_020290e8(0x91, 0x18, data_ov015_021942ae);
    if (self->menu_ == 1)
    {
        func_020290e8(0x91, 0x26, data_ov015_021942ba);
        if (self->current_->unknown_44_ == 0)
            func_020290e8(0x91, 0x34, data_ov015_021942c8);
        else
            func_020290e8(0x91, 0x34, data_ov015_021942d4);
        if (self->current_->unknown_3a_)
        {
            func_020290e8(0x91, 0x42, data_ov015_021942e0);
            func_020290e8(0x91, 0x50, data_ov015_021942ec);
            return;
        }
        func_020290e8(0x91, 0x42, data_ov015_021942f6);
        return;
    }
    if (self->page_ == 0x22 || func_ov015_02190c2c(self))
    {
        if (self->current_->battle_ == 0)
            func_020290e8(0x91, 0x26, data_ov015_02194302);
        else
            func_020290e8(0x91, 0x26, data_ov015_0219430e);
    }
    if (self->page_ != 6)
        return;
    if (self->unknown_1a1_)
    {
        func_020290e8(0x91, 0x26, data_ov015_0219431a);
        return;
    }
    func_020290e8(0x91, 0x26, data_ov015_02194324);
}
