#include <globaldefs.h>
#include "NitroSDK/Cache.h"

typedef char* Type_02001bdc;
#define __va_align(size) ((((unsigned long)(size)) + 3U) & ~3U)
#define va_start(ap, parm) ((ap) = (Type_02001bdc)((char*)((unsigned long)&(parm) & ~3U) + __va_align(sizeof(parm))))
#define va_arg(ap, type) (*(type*)(((ap) += __va_align(sizeof(type))) - __va_align(sizeof(type))))
#define va_end(ap) ((void)0)

extern "C" int func_020d41e8();

struct Struct_020d424c
{
    unsigned short state;
};

struct Struct_020d424c_2
{
    void* unknown_0_;
    Struct_020d424c* status;
};

struct Struct_021142e0_3
{
    unsigned short unknown_0_;
    Struct_020d424c_2* unknown_4_;
};

extern Struct_021142e0_3 data_021142e0;

// USA: func_020d424c
extern "C" ARM int func_020d424c(int arg0, ...)
{
    int result = func_020d41e8();
    unsigned short state;
    Type_02001bdc args;
    if (result != 0)
        return result;
    InvalidateDataCacheRange(&data_021142e0.unknown_4_->status->state, sizeof(unsigned short));
    state = data_021142e0.unknown_4_->status->state;
    va_start(args, arg0);
    result = 3;
    if (arg0 == 0)
        return result;
    do
    {
        if (va_arg(args, unsigned long) == state)
            result = 0;
    } while (--arg0 != 0);
    va_end(args);
    return result;
}
