#include <globaldefs.h>

class Struct_ov023_021fa2f4
{
public:
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned char unknown_c_;
    char unknown_d_[3];
    const char* unknown_10_;
    void* unknown_14_;
    void* unknown_18_;
    int unknown_1c_;

    virtual void inline_ov023_021fa2f4(void* arg0);
};

typedef int (Struct_ov023_021fa2f4::*Type_ov023_021fa2f4)(void* script);

extern unsigned int data_ov023_021fff28;
extern TextsState_021fa2f4 __ptmf_null;
extern TextsState_021fa2f4 data_ov023_021fea0c[4];
extern TextsState_021fa2f4 data_ov023_021fea0c_dup[4];

// USA: func_ov023_021fa2f4
extern "C" ARM void func_ov023_021fa2f4(Struct_ov023_021fa2f4* arg0, void* arg1)
{
    if (!(data_ov023_021fff28 & 1))
    {
        data_ov023_021fea0c_dup[3] = __ptmf_null;
        data_ov023_021fff28 |= 1;
    }
    arg0->unknown_1c_ = (arg0->*data_ov023_021fea0c[arg0->unknown_1c_])(arg1);
}
