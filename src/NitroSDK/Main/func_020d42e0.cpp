#include <globaldefs.h>
#include "NitroSDK/Cache.h"
#include "NitroSDK/Memory.h"

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif


extern "C" void HaltSystem();
extern "C" void func_020ca390(unsigned short value, void* dst, unsigned long size);
extern "C" void func_020ca3b8(const void* src, void* dst, unsigned long size);
extern "C" int func_020d3fdc();
extern "C" void func_020d468c();

typedef void (*Type_020d42e0)(void* arg);

struct Struct_020d424c
{
    unsigned short unknown_0_;
    char unknown_2_[0x72 - 0x2];
    unsigned short unknown_72_;
    char unknown_74_[0x800 - 0x74];
};

struct Struct_020d424c_2
{
    void* unknown_0_;
    Struct_020d424c* unknown_4_;
    unsigned long* unknown_8_;
    unsigned long* unknown_c_;
    unsigned long* unknown_10_;
    unsigned short unknown_14_;
    unsigned short unknown_16_;
    Type_020d42e0 unknown_18_[0x2c];
    Type_020d42e0 unknown_c8_;
    Type_020d42e0 unknown_cc_[16];
    void* unknown_10c_[16];
    unsigned long unknown_14c_;
    unsigned short unknown_150_;
};

struct Struct_020d42e0
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_020d42e0_2
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    const unsigned short* unknown_14_;
    unsigned short unknown_18_;
    unsigned short unknown_1a_;
    Type_020d42e0 unknown_1c_;
    void* unknown_20_;
    unsigned short unknown_24_;
    unsigned short unknown_26_;
};

struct Struct_02114330
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    void* unknown_8_;
    void* unknown_c_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    unsigned char unknown_14_[6];
    unsigned short unknown_1a_;
    void* unknown_1c_;
    unsigned short unknown_20_;
    unsigned short unknown_22_;
    unsigned char unknown_24_[24];
    unsigned short unknown_3c_;
    unsigned short unknown_3e_;
    unsigned short unknown_40_;
    unsigned short unknown_42_;
};

struct Struct_020d42e0_3
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned char unknown_a_[6];
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    unsigned char unknown_14_[24];
    unsigned short unknown_2c_;
    unsigned short unknown_2e_;
};

struct Struct_020d42e0_4
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned char unknown_10_[6];
    unsigned short unknown_16_;
    unsigned short unknown_18_;
};

struct Struct_020d42e0_5
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned char unknown_6_[2];
    void* unknown_8_;
};

struct Struct_021142e0_3
{
    unsigned short unknown_0_;
    Struct_020d424c_2* unknown_4_;
    char unknown_8_[0x20];
    void* unknown_28_[10];
    Struct_02114330 unknown_50_;
};

extern Struct_021142e0_3 data_021142e0;
extern Struct_02114330 data_02114330;
extern unsigned char data_02114344[6];
extern unsigned char data_02114354[24];

// USA: func_020d42e0
extern "C" ARM void func_020d42e0(unsigned int arg0, unsigned int arg1, unsigned int arg2)
{
    Struct_020d42e0* const var0 = (Struct_020d42e0*)arg1;
    Struct_020d424c_2* const var1 = data_021142e0.unknown_4_;
    if (arg2)
        return;
    InvalidateDataCacheRange(var1->unknown_10_, 0x100);
    if (!var1->unknown_16_)
        InvalidateDataCacheRange(var1->unknown_4_, sizeof(Struct_020d424c));
    if ((unsigned long)var0 != (unsigned long)var1->unknown_10_)
        InvalidateDataCacheRange(var0, 0x100);
    if (var0->unknown_0_ >= 0x2c)
    {
        if (var0->unknown_0_ == 0x80)
        {
            if (callback->errcode == 19)
                HaltSystem();
            if (w9b->indCallback != NULL)
                w9b->indCallback(callback);
        }
        else if (var0->unknown_0_ == 0x82)
        {
            Struct_02114330* const var2 = (Struct_02114330*)var0;
            if (var1->unknown_cc_[var2->unknown_6_] != NULL)
            {
                var2->unknown_1c_ = var1->unknown_10c_[var2->unknown_6_];
                var2->unknown_22_ = var1->unknown_14c_;
                InvalidateDataCacheRange(var2->unknown_8_, var1->unknown_4_->unknown_72_);
                var1->unknown_cc_[var2->unknown_6_](var2);
            }
        }
        else if (var0->unknown_0_ == 0x81)
        {
            Struct_020d42e0_2* const var3 = (Struct_020d42e0_2*)var0;
            var0->unknown_0_ = 0xf;
            if (var3->unknown_1c_ != NULL)
                var3->unknown_1c_(var3);
        }
    }
    else
    {
        if (var0->unknown_0_ == 0xe)
        {
            Struct_020d42e0_5* const var4 = (Struct_020d42e0_5*)var0;
            if ((var4->unknown_4_ == 11 || var4->unknown_4_ == 12) && var4->unknown_2_ == 0)
                InvalidateDataCacheRange(var4->unknown_8_, var1->unknown_4_->unknown_72_);
        }
        if (var0->unknown_0_ == 2 && var0->unknown_2_ == 0)
        {
            const Type_020d42e0 var5 = var1->unknown_18_[var0->unknown_0_];
            func_020d3fdc();
            if (var5 != NULL)
                var5(var0);
            return;
        }
        if (var1->unknown_18_[var0->unknown_0_] != NULL)
        {
            var1->unknown_18_[var0->unknown_0_](var0);
            if (!data_021142e0.unknown_0_)
                return;
        }
        if (var0->unknown_0_ == 8 || var0->unknown_0_ == 0xc)
        {
            unsigned short var6;
            unsigned short var7;
            unsigned short var8;
            unsigned short var9;
            const unsigned char* var10;
            const unsigned char* var11;
            unsigned short var12;
            unsigned short var13;
            if (var0->unknown_0_ == 8)
            {
                Struct_020d42e0_3* const var14 = (Struct_020d42e0_3*)var0;
                var6 = var14->unknown_8_;
                var7 = var14->unknown_10_;
                var8 = 0;
                var10 = var14->unknown_a_;
                var11 = var14->unknown_14_;
                var9 = var14->unknown_12_;
                var12 = var14->unknown_2c_;
                var13 = var14->unknown_2e_;
            }
            else if (var0->unknown_0_ == 0xc)
            {
                Struct_020d42e0_4* const var15 = (Struct_020d42e0_4*)var0;
                var6 = var15->unknown_8_;
                var7 = 0;
                var8 = var15->unknown_a_;
                var10 = var15->unknown_10_;
                var11 = NULL;
                var9 = var15->unknown_c_;
                var12 = var15->unknown_16_;
                var13 = var15->unknown_18_;
            }
            if (var6 == 7 || var6 == 9 || var6 == 26)
            {
                if (var6 == 7)
                    var1->unknown_14c_ |= 1 << var7;
                else
                    var1->unknown_14c_ &= ~(1 << var7);
                var1->unknown_150_ = var8;
                VectorizedMemset(&data_02114330, 0, sizeof(Struct_02114330));
                data_021142e0.unknown_50_.unknown_0_ = 0x82;
                data_021142e0.unknown_50_.unknown_2_ = 0;
                data_021142e0.unknown_50_.unknown_4_ = var6;
                data_021142e0.unknown_50_.unknown_8_ = NULL;
                data_021142e0.unknown_50_.unknown_c_ = NULL;
                data_021142e0.unknown_50_.unknown_10_ = 0;
                data_021142e0.unknown_50_.unknown_12_ = var7;
                data_021142e0.unknown_50_.unknown_20_ = var8;
                data_021142e0.unknown_50_.unknown_22_ = var1->unknown_14c_;
                data_021142e0.unknown_50_.unknown_1a_ = 0xffff;
                data_021142e0.unknown_50_.unknown_3c_ = var9;
                VectorizedInvertedMemcpy(var10, data_02114344, sizeof(data_02114344));
                if (var11 != NULL)
                    func_020ca3b8(var11, data_02114354, sizeof(data_02114354));
                else
                    func_020ca390(0, data_02114354, sizeof(data_02114354));
                data_021142e0.unknown_50_.unknown_40_ = var8 == 0 ? var12 : var13;
                data_021142e0.unknown_50_.unknown_42_ = var8 == 0 ? var13 : var12;
                for (unsigned short var16 = 0; var16 < 16; var16++)
                {
                    data_021142e0.unknown_50_.unknown_6_ = var16;
                    if (var1->unknown_cc_[var16] != NULL)
                    {
                        data_021142e0.unknown_50_.unknown_1c_ = var1->unknown_10c_[var16];
                        var1->unknown_cc_[var16](&data_02114330);
                    }
                }
            }
        }
    }
    InvalidateDataCacheRange(var1->unknown_10_, 0x100);
    func_020d468c();
    if ((unsigned long)var0 != (unsigned long)var1->unknown_10_)
    {
        var0->unknown_0_ |= 0x8000;
        CleanCacheRange(var0, 0x100);
    }
}
