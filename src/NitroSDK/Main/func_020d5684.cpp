#include <globaldefs.h>
#include "NitroSDK/Cache.h"


#if defined(jpn)
#define func_020ca408 func_020cbed4
#endif

typedef void (*Type_020d42e0)(void* arg);

struct Struct_020d424c
{
    unsigned short state;
    char unk_2[0xc - 0x2];
    unsigned long unknown_c_;
    char unk_10[0x9c - 0x10];
    unsigned short unknown_9c_;
    char unknown_9e_[0xc6 - 0x9e];
    unsigned short unknown_c6_;
    char unknown_c8_[0x188 - 0xc8];
    unsigned short aid;
};

struct Struct_020d424c_2
{
    void* unknown_0_;
    Struct_020d424c* status;
};

struct Struct_020d5684_3
{
    unsigned long mask;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    unsigned short unknown_14_;
    unsigned short unknown_16_;
    unsigned char unknown_18_;
    unsigned char unknown_19_;
    unsigned char unknown_1a_;
    unsigned char unknown_1b_;
};

struct Struct_020d5684
{
    unsigned long mask;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char reserved[1];
};

struct Struct_020d5684_2
{
    unsigned short unknown_0_;
    unsigned short reserved;
    unsigned long* unknown_4_;
    unsigned long unknown_8_;
    unsigned long* unknown_c_;
    unsigned long unknown_10_;
    Struct_020d5684_3 param;
    Struct_020d5684 unknown_30_;
};

extern "C" void func_020ca3ec(unsigned long value, void* dst, unsigned long size);
extern "C" void func_020ca408(const void* src, void* dst, unsigned long size);
extern "C" int func_020d424c(int arg0, ...);
extern "C" Struct_020d424c_2* func_020d41d8();
extern "C" int func_020d4900();
extern "C" int func_020d4894();
extern "C" void func_020d404c(int id, int callback);
extern "C" int func_020d4168(void* data, unsigned int length);

// USA: func_020d5684
extern "C" ARM int func_020d5684(Type_020d42e0 callback, unsigned short* arg1, unsigned short arg2,
                                 unsigned short* arg3, unsigned short arg4, const Struct_020d5684* arg5)
{
    int result;
    Struct_020d424c_2* const p = func_020d41d8();
    Struct_020d424c* const status = p->status;
    result = func_020d424c(2, 7, 8);
    if (result != 0)
        return result;
    InvalidateDataCacheRange(&status->aid, 2);
    InvalidateDataCacheRange(&status->unknown_c6_, 2);
    if (status->aid != 0 && status->unknown_c6_ != 1)
        return 3;
    InvalidateDataCacheRange(&status->unknown_c_, 4);
    if (status->unknown_c_ == true)
        return 3;
    if ((arg2 & 0x3f) != 0)
        return 6;
    if ((arg4 & 0x1f) != 0)
        return 6;
    InvalidateDataCacheRange(&status->unknown_9c_, 2);
    if (status->unknown_9c_ == false)
    {
        if (arg2 < func_020d4900())
            return 6;
        if (arg4 < func_020d4894())
            return 6;
    }
    func_020d404c(0xe, (int)callback);
    {
        Struct_020d5684_2 req;
        func_020ca3ec(0, &req, sizeof(Struct_020d5684_2));
        req.unknown_0_ = 0xe;
        req.unknown_4_ = (unsigned long*)arg1;
        req.unknown_8_ = arg2 / 2;
        req.unknown_c_ = (unsigned long*)arg3;
        req.unknown_10_ = arg4;
        func_020ca3ec(0, &req.param, sizeof(Struct_020d5684_3));
        func_020ca408(arg5, &req.unknown_30_, sizeof(Struct_020d5684));
        result = func_020d4168(&req, sizeof(Struct_020d5684_2));
    }
    if (result != 0)
        return result;
    return 2;
}
