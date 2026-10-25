#include <globaldefs.h>

struct Struct_02098630
{
    unsigned char unknown_0_[11];
    unsigned char unknown_b_0_ : 7;
    unsigned char unknown_b_7_ : 1;
    unsigned int unknown_c_0_ : 4;
    unsigned int unknown_c_4_ : 4;
    unsigned int unknown_d_0_ : 7;
    unsigned int unknown_d_7_ : 4;
    unsigned int unknown_e_3_ : 5;
    unsigned int unknown_f_0_ : 6;
    unsigned int unknown_f_6_ : 1;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 2;
    unsigned int unknown_10_2_ : 30;
    unsigned char unknown_14_[6];
    unsigned char unknown_1a_[0x6c - 0x1a];
    unsigned int unknown_6c_0_ : 26;
    unsigned int unknown_6f_2_ : 1;
    unsigned int unknown_6f_3_ : 5;
    unsigned char unknown_70_[0xe8 - 0x70];
};

struct Struct_02097cac_2
{
    Struct_02098630 unknown_0_[30];
    int unknown_1b30_;
    unsigned int unknown_1b34_;
    unsigned int unknown_1b38_;
    unsigned char unknown_1b3c_[0x1b68 - 0x1b3c];
    unsigned int unknown_1b68_[3];
    int unknown_1b74_;
};

struct Struct_02098630_2
{
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
};

extern "C" int memcmp(const void*, const void*, int);
extern "C" int func_02098a84(Base020989cc*);
S02098834* CopyStruct02098834(S02098834*, S02098834*);
void UpdateRankLevel020989cc(Base020989cc*);
int RegisterSlotA020cf0fc(int);

// USA: func_02098630
extern "C" ARM int func_02098630(Struct_02097cac_2* arg0, Struct_02098630* arg1, int arg2, int arg3)
{
    if (!arg1->unknown_6f_2_)
        return 0;
    for (int var0 = 0; var0 < 30; var0++)
    {
        if (memcmp(self->records[i].key, source->key, 6) == 0)
            return 0;
    }
    int var1 = func_02098a84(arg0);
    if (arg2)
        arg0->unknown_1b34_++;
    arg0->unknown_1b38_ = 0;
    Struct_02098630* var2 = arg0->unknown_0_;
    for (int var3 = 0; var3 < 30; var3++, var2++)
    {
        if (var2->unknown_10_2_)
            arg0->unknown_1b38_++;
    }
    if (++arg0->unknown_1b38_ > 30)
        arg0->unknown_1b38_ = 30;
    Struct_02098630* var4 = &arg0->unknown_0_[var1];
    func_02098834(var4, arg1);
    var4->unknown_c_4_ = 2;
    var4->unknown_10_0_ = 2;
    var4->unknown_f_6_ = 1;
    var4->unknown_10_2_ = arg0->unknown_1b34_;
    Struct_02098630_2 var5;
    if (func_020cf0fc((int)&var5) == 0)
    {
        arg0->unknown_0_[var1].unknown_b_0_ = (unsigned char)var5.unknown_0_;
        arg0->unknown_0_[var1].unknown_d_7_ = var5.unknown_4_;
        arg0->unknown_0_[var1].unknown_e_3_ = var5.unknown_8_;
    }
    if (arg3)
        func_020989cc(arg0);
    unsigned int var6 = var4->unknown_10_2_;
    for (int var7 = 0; var7 < 3; var7++)
    {
        if (arg0->unknown_1b68_[var7] == 0xffffffff)
        {
            arg0->unknown_1b68_[var7] = var6;
            arg0->unknown_1b74_++;
            break;
        }
    }
    return 1;
}
