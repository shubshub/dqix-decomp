#include <globaldefs.h>

struct Struct_ov023_021f9f78_2
{
    unsigned short id_;
    unsigned char kind_;
    unsigned char phase_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int position_[3];
    int unknown_1c_[3];
};

class Struct_ov023_021f9f78
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
    unsigned short count_;
    Struct_ov023_021f9f78_2* unknown_24_;

    virtual void inline_ov023_021f9f78(void* script);
};

typedef void (Struct_ov023_021f9f78::*Type_ov023_021f9f78)(void* script, Struct_ov023_021f9f78_2* move);

struct Struct_ov023_021fd92c
{
    Type_ov023_021f9f78 steps[3];
};

extern Struct_ov023_021fd92c data_ov023_021fd92c;
extern Type_ov023_021f9f78 __ptmf_null;

// USA: func_ov023_021f9f78
extern "C" ARM void func_ov023_021f9f78(Struct_ov023_021f9f78* self, void* script)
{
    Struct_ov023_021fd92c steps = data_ov023_021fd92c;
    Type_ov023_021f9f78 none = __ptmf_null;
    steps.steps[0] = none;
    steps.steps[2] = none;
    for (int i = 0; i < self->count_; i++)
    {
        if (self->unknown_24_[i].kind_ != 0)
            (self->*steps.steps[self->unknown_24_[i].kind_])(script, &self->unknown_24_[i]);
    }
}
