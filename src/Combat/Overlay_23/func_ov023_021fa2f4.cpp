#include <globaldefs.h>

class Struct_ov023_021fa2f4
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

    virtual void inline_ov023_021fa2f4(void* script);
};

typedef int (Struct_ov023_021fa2f4::*Type_ov023_021fa2f4)(void* script);

extern unsigned int data_ov023_021fff28;
extern Type_ov023_021fa2f4 __ptmf_null;
extern Type_ov023_021fa2f4 data_ov023_021fea0c[4];
extern Type_ov023_021fa2f4 data_ov023_021fea0c_dup[4];

// USA: func_ov023_021fa2f4
extern "C" ARM void func_ov023_021fa2f4(Struct_ov023_021fa2f4* self, void* script)
{
    if (!(data_ov023_021fff28 & 1))
    {
        data_ov023_021fea0c_dup[3] = __ptmf_null;
        data_ov023_021fff28 |= 1;
    }
    self->state_ = (self->*data_ov023_021fea0c[self->state_])(script);
}
