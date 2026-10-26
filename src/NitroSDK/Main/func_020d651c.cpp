#include <globaldefs.h>

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

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

extern "C" void func_020ca3b8(const void* src, void* dst, unsigned long size);
extern "C" unsigned short func_020d46cc();

// USA: func_020d651c
extern "C" ARM void func_020d651c(void* callback)
{
    Struct_02114330* const cb = (Struct_02114330*)callback;
    WMDataSharingInfo* const dsInfo = (WMDataSharingInfo*)cb->arg;
    if (dsInfo == NULL)
        return;
    if (cb->unknown_2_ == 0)
    {
        switch (cb->state)
        {
        case 21:
        {
            unsigned short length;
            unsigned short var3;
            unsigned short aid;
            Struct_020d5d34_2* var5;
            var5 = (Struct_020d5d34_2*)cb->data;
            length = cb->length;
            var3 = var5->unknown_0_;
            aid = func_020d46cc();
            if (length != dsInfo->unknown_814_)
            {
                if (length > sizeof(Struct_020d5d34_2))
                    length = sizeof(Struct_020d5d34_2);
            }
            if (length < 4)
                return;
            if (!(var3 & (1 << aid)))
                return;
            func_020ca3b8(var5, &dsInfo->unknown_0_[dsInfo->unknown_808_], length);
            dsInfo->unknown_800_[dsInfo->unknown_808_] = cb->unknown_1a_ >> 1;
            dsInfo->unknown_808_ = (dsInfo->unknown_808_ + 1) & 3;
            break;
        }
        case 7:
        case 9:
        case 25:
        case 26:
            break;
        }
    }
    else
    {
        dsInfo->state = 5;
    }
}
