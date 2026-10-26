#include <globaldefs.h>

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

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

struct Struct_020d5fd0;
struct Struct_020d5fd0_2;

extern "C" int func_020d424c(int arg0, ...);
extern "C" void func_020ca3b8(const void* src, void* dst, unsigned long size);
extern "C" int func_020d59bc(Type_020d42e0 callback, void* arg, const unsigned short* arg2,
                             unsigned short arg3, unsigned short arg4, unsigned short arg5,
                             unsigned short arg6);
extern "C" void func_020d6318(void* callback);
extern "C" unsigned short func_020d46cc();
extern "C" unsigned short func_020d46fc();
extern "C" void func_020d6610(Struct_020d5fd0* dsInfo, int aid, int data);
extern "C" void func_020d66dc(Struct_020d5fd0_2* dsInfo, int arg1);

// USA: func_020d5fd0
extern "C" ARM int func_020d5fd0(WMDataSharingInfo* dsInfo, const unsigned short* arg1, Struct_020d5d34_2* arg2)
{
    int result;
    unsigned short aid;
    unsigned short var2;
    unsigned short state;
    result = func_020d424c(2, 9, 10);
    if (result != 0)
        return result;
    if (dsInfo == NULL)
        return 6;
    if (arg1 == NULL)
        return 6;
    if (arg2 == NULL)
        return 6;
    aid = func_020d46cc();
    if (aid == 0)
        var2 = func_020d46fc();
    state = dsInfo->state;
    if (state == 5)
        return 1;
    if (state != 1 && state != 4)
        return 3;
    result = 5;
    if (aid == 0)
    {
        int var4 = false;
        int var5 = false;
        if (state == 4)
        {
            int res;
            int var7;
            dsInfo->state = 1;
            var7 = (dsInfo->unknown_808_ + 4 - 1) & 3;
            res = func_020d59bc(func_020d6318, dsInfo, (unsigned short*)&dsInfo->unknown_0_[var7],
                                dsInfo->unknown_814_, dsInfo->unknown_80e_ & var2, dsInfo->unknown_816_, 1);
            if (res == 7)
            {
                dsInfo->unknown_800_[var7] = 0xffff;
                dsInfo->unknown_80a_ = (dsInfo->unknown_80a_ + 1) & 3;
            }
            else if (res != 0 && res != 2)
            {
                dsInfo->state = 5;
                return 1;
            }
        }
        if (dsInfo->unknown_80c_ != dsInfo->unknown_80a_)
        {
            dsInfo->unknown_0_[dsInfo->unknown_80c_].unknown_0_ |= 1;
            func_020ca3b8(&dsInfo->unknown_0_[dsInfo->unknown_80c_], arg2, sizeof(Struct_020d5d34_2));
            dsInfo->unknown_81a_ = dsInfo->unknown_800_[dsInfo->unknown_80c_];
            dsInfo->unknown_80c_ = (dsInfo->unknown_80c_ + 1) & 3;
            var4 = true;
            result = 0;
            if (dsInfo->unknown_818_ == false && var2 != 0 && dsInfo->unknown_0_[dsInfo->unknown_808_].unknown_0_ == 1)
                var5 = true;
            else
                var5 = false;
        }
        func_020d66dc((Struct_020d5fd0_2*)dsInfo, false);
        if (var4)
        {
            func_020d6610((Struct_020d5fd0*)dsInfo, 0, (int)arg1);
            if (dsInfo->unknown_818_ == false)
                func_020d66dc((Struct_020d5fd0_2*)dsInfo, var5);
        }
    }
    else
    {
        int var8 = false;
        if (state == 4)
        {
            var8 = true;
            dsInfo->state = 1;
        }
        else if (dsInfo->unknown_80c_ != dsInfo->unknown_808_)
        {
            if (!(dsInfo->unknown_0_[dsInfo->unknown_80c_].unknown_0_ & 1))
            {
                dsInfo->unknown_0_[dsInfo->unknown_80c_].unknown_0_ |= 1;
            }
            else
            {
                func_020ca3b8(&dsInfo->unknown_0_[dsInfo->unknown_80c_], arg2, sizeof(Struct_020d5d34_2));
                dsInfo->unknown_81a_ = dsInfo->unknown_800_[dsInfo->unknown_80c_];
                dsInfo->unknown_80c_ = (dsInfo->unknown_80c_ + 1) & 3;
                var8 = true;
                result = 0;
            }
        }
        if (var8)
        {
            unsigned short* const buf = (unsigned short*)((unsigned char*)&dsInfo->unknown_0_[dsInfo->unknown_80a_] + 32);
            int res;
            func_020ca3b8(arg1, buf, dsInfo->unknown_810_);
            res = func_020d59bc(func_020d6318, dsInfo, buf, dsInfo->unknown_810_, dsInfo->unknown_80e_, dsInfo->unknown_816_, 1);
            dsInfo->unknown_80a_ = (dsInfo->unknown_80a_ + 1) & 3;
            if (res != 2 && res != 0)
            {
                dsInfo->state = 5;
                result = 1;
            }
        }
    }
    return result;
}
