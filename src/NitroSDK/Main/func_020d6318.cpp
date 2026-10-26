#include <globaldefs.h>

typedef void (*Type_020d42e0)(void* arg);

struct Struct_020d424c_2
{
    void* unknown_0_;
    void* status;
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

struct Struct_020d5d34_2
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short data[254];
};

struct WMDataSharingInfo
{
    Struct_020d5d34_2 unknown_0_[4];
    unsigned short unknown_800_[4];
    unsigned short unknown_808_;
    unsigned short unknown_80a_;
    unsigned short unknown_80c_;
    unsigned short unknown_80e_;
    unsigned short unknown_810_;
    unsigned short unknown_812_;
    unsigned short unknown_814_;
    unsigned short unknown_816_;
    unsigned short unknown_818_;
    unsigned short unknown_81a_;
    unsigned short state;
    unsigned short reserved[1];
};

extern "C" void func_020d63f0(void* callback);
extern "C" void func_020d651c(void* callback);
extern "C" Struct_020d424c_2* func_020d41d8();
extern "C" unsigned short func_020d46cc();

// USA: func_020d6318
extern "C" ARM void func_020d6318(void* callback)
{
    Struct_020d424c_2* const p = func_020d41d8();
    Struct_020d42e0_2* const cb = (Struct_020d42e0_2*)callback;
    const Type_020d42e0 var2 = p->unknown_cc_[cb->unknown_a_];
    WMDataSharingInfo* const dsInfo = (WMDataSharingInfo*)p->unknown_10c_[cb->unknown_a_];
    unsigned short aid;
    if (var2 != func_020d63f0 && var2 != func_020d651c)
        return;
    if (dsInfo == NULL)
        return;
    if (dsInfo != cb->arg)
        return;
    aid = func_020d46cc();
    if (cb->unknown_2_ == 0)
    {
        if (aid == 0)
        {
            dsInfo->unknown_800_[dsInfo->unknown_80a_] = cb->unknown_1a_ >> 1;
            dsInfo->unknown_80a_ = (dsInfo->unknown_80a_ + 1) & 3;
        }
    }
    else if (cb->unknown_2_ == 10)
    {
        if (aid != 0)
            dsInfo->unknown_80a_ = (dsInfo->unknown_80a_ + 4 - 1) & 3;
        dsInfo->state = 4;
    }
    else
    {
        dsInfo->state = 5;
    }
}
