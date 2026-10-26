#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Struct_020bc180_2
{
    int origin;
    int target;
    int counter;
    int frame;
};

struct Struct_020bc2f0;
struct Struct_020bc2f0_2;

struct Struct_020bc2f0_3
{
    SignedAllocatorList unknown_0_;
    SignedAllocatorList unknown_c_;
    unsigned long unknown_18_;
    unsigned long unknown_1c_;
    unsigned char volume;
    unsigned char pad;
    unsigned short pad2;
};

struct Struct_0201099c_24
{
    void* unknown_0_;
    void* nextObject;
};

struct Struct_020bc2f0_4
{
    void* handle;
    Struct_020bc2f0_3* player;
    void* heap;
    Struct_0201099c_24 unknown_c_;
    Struct_0201099c_24 unknown_14_;
    Struct_020bc180_2 unknown_1c_;
    unsigned char status;
    unsigned char unknown_2d_;
    unsigned char unknown_2e_;
    unsigned char unknown_2f_;
    unsigned long unknown_30_;
    unsigned short unknown_34_;
    unsigned short pad2;
    unsigned short unknown_38_;
    unsigned short unknown_3a_;
    unsigned char unknown_3c_;
    unsigned char unknown_3d_;
    short volume;
    unsigned char unknown_40_;
    unsigned char unknown_41_;
    unsigned short pad3;
};

extern "C" unsigned long func_020d29f4();
extern "C" int func_020d2718(unsigned int tag);
extern "C" void func_020bc79c(Struct_020bc2f0_4* arg0);
extern "C" void func_020c0260(Struct_020bc180_2* arg0);
extern "C" int func_020c022c(Struct_020bc180_2* arg0);
extern "C" void func_020d1e70(int arg0, int volume);
extern "C" int func_020c0278(Struct_020bc2f0* arg0);
extern "C" void func_020bc6fc(Struct_020bc2f0_2* arg0);
extern "C" void func_020d1e30(int arg0);

extern "C" SignedAllocatorList data_0210f3d8;
extern "C" const short data_020ed82c[];

static inline short inline_020bc2f0(int scale)
{
    return data_020ed82c[scale];
}

static inline Struct_020bc2f0_4* inline_020bc2f0_2(Struct_020bc2f0_4* arg0)
{
    return (Struct_020bc2f0_4*)data_0210f3d8.ElementAfter((SignedAllocatorHeader*)arg0);
}

// USA: func_020bc2f0
extern "C" ARM void func_020bc2f0()
{
    Struct_020bc2f0_4* var0;
    Struct_020bc2f0_4* next;
    unsigned long status;
    int var3;

    status = func_020d29f4();

    var0 = inline_020bc2f0_2(NULL);
    if (var0 == NULL)
        return;

    do
    {
        next = inline_020bc2f0_2(var0);

        if (!var0->unknown_2d_)
        {
            if (func_020d2718(var0->unknown_30_))
                var0->unknown_2d_ = 1;
        }

        if (var0->unknown_2d_)
        {
            if ((status & (1 << var0->unknown_3c_)) == 0)
            {
                func_020bc79c(var0);
                continue;
            }
        }

        func_020c0260(&var0->unknown_1c_);

        var3 = inline_020bc2f0(var0->unknown_40_) + inline_020bc2f0(var0->unknown_41_)
            + inline_020bc2f0(var0->player->volume)
            + inline_020bc2f0(func_020c022c(&var0->unknown_1c_) >> 8);

        if (var3 < -32768)
            var3 = -32768;
        else if (var3 > 32767)
            var3 = 32767;

        if (var3 != var0->volume)
        {
            func_020d1e70(var0->unknown_3c_, var3);
            var0->volume = (short)var3;
        }

        if (var0->status == 2)
        {
            if (func_020c0278((Struct_020bc2f0*)&var0->unknown_1c_))
                func_020bc6fc((Struct_020bc2f0_2*)var0);
        }

        if (var0->unknown_2f_)
        {
            func_020d1e30(var0->unknown_3c_);
            var0->unknown_2f_ = 0;
        }
    } while ((var0 = next) != NULL);
}
