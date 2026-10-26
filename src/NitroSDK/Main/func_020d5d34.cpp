#include <globaldefs.h>

typedef void (*Type_020d42e0)(void* arg);

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

extern "C" int func_020d424c(int arg0, ...);
extern "C" void MIi_CpuClearFast(unsigned long value, void* dst, unsigned long size);
extern "C" int func_020d4770(unsigned short arg0, Type_020d42e0 callback, void* arg);
extern "C" int func_020d59bc(Type_020d42e0 callback, void* arg, const unsigned short* arg2,
                             unsigned short arg3, unsigned short arg4, unsigned short arg5,
                             unsigned short arg6);
extern "C" void func_020d6318(void* callback);
extern "C" void func_020d63f0(void* callback);
extern "C" void func_020d651c(void* callback);
extern "C" unsigned short func_020d46cc();
extern "C" unsigned short func_020d46fc();
extern "C" unsigned char func_020d1ae4(unsigned int x);

// USA: func_020d5d34
extern "C" ARM int func_020d5d34(WMDataSharingInfo* dsInfo, unsigned short arg1, unsigned short arg2,
                                 unsigned short arg3, int arg4)
{
    int result;
    int aid;
    unsigned short var2 = 1;
    result = func_020d424c(2, 9, 10);
    if (result != 0)
        return result;
    if (dsInfo == NULL)
        return 6;
    if (arg1 >= 16)
        return 6;
    if (arg2 == 0)
        return 6;
    aid = func_020d46cc();
    if (aid == 0)
        var2 = func_020d46fc();
    MIi_CpuClearFast(0, dsInfo, sizeof(WMDataSharingInfo));
    dsInfo->unknown_808_ = 0;
    dsInfo->unknown_80a_ = 0;
    dsInfo->unknown_80c_ = 0;
    dsInfo->unknown_810_ = arg3;
    dsInfo->unknown_816_ = arg1;
    dsInfo->unknown_80e_ = 0;
    dsInfo->unknown_818_ = arg4 ? true : false;
    arg2 |= 1 << aid;
    dsInfo->unknown_80e_ = arg2;
    {
        const unsigned char var3 = func_020d1ae4(arg2);
        dsInfo->unknown_812_ = var3;
        dsInfo->unknown_814_ = arg3 * var3;
    }
    if (dsInfo->unknown_814_ > 508)
    {
        dsInfo->unknown_80e_ = 0;
        return 6;
    }
    dsInfo->unknown_814_ += 4;
    dsInfo->state = 1;
    if (aid == 0)
    {
        int i;
        for (i = 0; i < 4; i++)
            dsInfo->unknown_0_[i].unknown_0_ = dsInfo->unknown_80e_ & (var2 | 1);
        func_020d4770(arg1, func_020d63f0, dsInfo);
        for (i = 0; i < (dsInfo->unknown_818_ == true ? 2 : 1); i++)
        {
            int res;
            dsInfo->unknown_808_ = (dsInfo->unknown_808_ + 1) & 3;
            res = func_020d59bc(func_020d6318, dsInfo, (unsigned short*)&dsInfo->unknown_0_[i], dsInfo->unknown_814_,
                                dsInfo->unknown_80e_ & var2, dsInfo->unknown_816_, 1);
            if (res == 7)
            {
                dsInfo->unknown_800_[i] = 0xffff;
                dsInfo->unknown_80a_ = (dsInfo->unknown_80a_ + 1) & 3;
            }
            else if (res != 0 && res != 2)
            {
                dsInfo->state = 5;
                return 1;
            }
        }
    }
    else
    {
        dsInfo->unknown_80a_ = 3;
        func_020d4770(arg1, func_020d651c, dsInfo);
    }
    return 0;
}
