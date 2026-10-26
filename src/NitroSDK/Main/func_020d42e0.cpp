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
    unsigned short state;
    char unk_2[0x72 - 0x2];
    unsigned short unknown_72_;
    char unknown_74_[0x800 - 0x74];
};

struct Struct_020d424c_2
{
    void* unknown_0_;
    Struct_020d424c* status;
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
    unsigned short myAid;
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
    unsigned short state;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    const unsigned short* data;
    unsigned short length;
    unsigned short unknown_1a_;
    Type_020d42e0 callback;
    void* arg;
    unsigned short unknown_24_;
    unsigned short unknown_26_;
};

struct Struct_02114330
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short state;
    unsigned short unknown_6_;
    void* unknown_8_;
    void* data;
    unsigned short length;
    unsigned short aid;
    unsigned char macAddress[6];
    unsigned short unknown_1a_;
    void* arg;
    unsigned short myAid;
    unsigned short unknown_22_;
    unsigned char ssid[24];
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
    unsigned short state;
    unsigned char macAddress[6];
    unsigned short aid;
    unsigned short unknown_12_;
    unsigned char ssid[24];
    unsigned short unknown_2c_;
    unsigned short unknown_2e_;
};

struct Struct_020d42e0_4
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short state;
    unsigned short aid;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned char macAddress[6];
    unsigned short unknown_16_;
    unsigned short unknown_18_;
};

struct Struct_020d42e0_5
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short state;
    unsigned char reserved[2];
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
extern "C" ARM void func_020d42e0(unsigned int command, unsigned int data, unsigned int error)
{
    Struct_020d42e0* const callback = (Struct_020d42e0*)data;
    Struct_020d424c_2* const var1 = data_021142e0.unknown_4_;
    if (error)
        return;
    InvalidateDataCacheRange(var1->unknown_10_, 0x100);
    if (!var1->unknown_16_)
        InvalidateDataCacheRange(var1->status, sizeof(Struct_020d424c));
    if ((unsigned long)callback != (unsigned long)var1->unknown_10_)
        InvalidateDataCacheRange(callback, 0x100);
    if (callback->unknown_0_ >= 0x2c)
    {
        if (callback->unknown_0_ == 0x80)
        {
            if (callback->unknown_2_ == 19)
                HaltSystem();
            if (var1->unknown_c8_ != NULL)
                var1->unknown_c8_(callback);
        }
        else if (callback->unknown_0_ == 0x82)
        {
            Struct_02114330* const var2 = (Struct_02114330*)callback;
            if (var1->unknown_cc_[var2->unknown_6_] != NULL)
            {
                var2->arg = var1->unknown_10c_[var2->unknown_6_];
                var2->unknown_22_ = var1->unknown_14c_;
                InvalidateDataCacheRange(var2->unknown_8_, var1->status->unknown_72_);
                var1->unknown_cc_[var2->unknown_6_](var2);
            }
        }
        else if (callback->unknown_0_ == 0x81)
        {
            Struct_020d42e0_2* const var3 = (Struct_020d42e0_2*)callback;
            callback->unknown_0_ = 0xf;
            if (var3->callback != NULL)
                var3->callback(var3);
        }
    }
    else
    {
        if (callback->unknown_0_ == 0xe)
        {
            Struct_020d42e0_5* const mp = (Struct_020d42e0_5*)callback;
            if ((mp->state == 11 || mp->state == 12) && mp->unknown_2_ == 0)
                InvalidateDataCacheRange(mp->unknown_8_, var1->status->unknown_72_);
        }
        if (callback->unknown_0_ == 2 && callback->unknown_2_ == 0)
        {
            const Type_020d42e0 func = var1->unknown_18_[callback->unknown_0_];
            func_020d3fdc();
            if (func != NULL)
                func(callback);
            return;
        }
        if (var1->unknown_18_[callback->unknown_0_] != NULL)
        {
            var1->unknown_18_[callback->unknown_0_](callback);
            if (!data_021142e0.unknown_0_)
                return;
        }
        if (callback->unknown_0_ == 8 || callback->unknown_0_ == 0xc)
        {
            unsigned short state;
            unsigned short aid;
            unsigned short myAid;
            unsigned short var9;
            const unsigned char* macAddress;
            const unsigned char* ssid;
            unsigned short var12;
            unsigned short var13;
            if (callback->unknown_0_ == 8)
            {
                Struct_020d42e0_3* const parent = (Struct_020d42e0_3*)callback;
                state = parent->state;
                aid = parent->aid;
                myAid = 0;
                macAddress = parent->macAddress;
                ssid = parent->ssid;
                var9 = parent->unknown_12_;
                var12 = parent->unknown_2c_;
                var13 = parent->unknown_2e_;
            }
            else if (callback->unknown_0_ == 0xc)
            {
                Struct_020d42e0_4* const var15 = (Struct_020d42e0_4*)callback;
                state = var15->state;
                aid = 0;
                myAid = var15->aid;
                macAddress = var15->macAddress;
                ssid = NULL;
                var9 = var15->unknown_c_;
                var12 = var15->unknown_16_;
                var13 = var15->unknown_18_;
            }
            if (state == 7 || state == 9 || state == 26)
            {
                if (state == 7)
                    var1->unknown_14c_ |= 1 << aid;
                else
                    var1->unknown_14c_ &= ~(1 << aid);
                var1->myAid = myAid;
                VectorizedMemset(&data_02114330, 0, sizeof(Struct_02114330));
                data_021142e0.unknown_50_.unknown_0_ = 0x82;
                data_021142e0.unknown_50_.unknown_2_ = 0;
                data_021142e0.unknown_50_.state = state;
                data_021142e0.unknown_50_.unknown_8_ = NULL;
                data_021142e0.unknown_50_.data = NULL;
                data_021142e0.unknown_50_.length = 0;
                data_021142e0.unknown_50_.aid = aid;
                data_021142e0.unknown_50_.myAid = myAid;
                data_021142e0.unknown_50_.unknown_22_ = var1->unknown_14c_;
                data_021142e0.unknown_50_.unknown_1a_ = 0xffff;
                data_021142e0.unknown_50_.unknown_3c_ = var9;
                VectorizedInvertedMemcpy(macAddress, data_02114344, sizeof(data_02114344));
                if (ssid != NULL)
                    func_020ca3b8(ssid, data_02114354, sizeof(data_02114354));
                else
                    func_020ca390(0, data_02114354, sizeof(data_02114354));
                data_021142e0.unknown_50_.unknown_40_ = myAid == 0 ? var12 : var13;
                data_021142e0.unknown_50_.unknown_42_ = myAid == 0 ? var13 : var12;
                for (unsigned short i = 0; i < 16; i++)
                {
                    data_021142e0.unknown_50_.unknown_6_ = i;
                    if (var1->unknown_cc_[i] != NULL)
                    {
                        data_021142e0.unknown_50_.arg = var1->unknown_10c_[i];
                        var1->unknown_cc_[i](&data_02114330);
                    }
                }
            }
        }
    }
    InvalidateDataCacheRange(var1->unknown_10_, 0x100);
    func_020d468c();
    if ((unsigned long)callback != (unsigned long)var1->unknown_10_)
    {
        callback->unknown_0_ |= 0x8000;
        CleanCacheRange(callback, 0x100);
    }
}
