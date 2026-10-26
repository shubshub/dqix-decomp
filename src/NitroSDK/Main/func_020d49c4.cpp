#include <globaldefs.h>
#include "NitroSDK/Cache.h"

typedef void (*Type_020d42e0)(void* arg);

struct Struct_020d424c
{
    char unk_0[0x182];
    unsigned short unknown_182_;
};

struct Struct_020d424c_2
{
    void* unknown_0_;
    Struct_020d424c* status;
};

struct Struct_020d49c4
{
    unsigned short length;
    unsigned short unknown_2_;
    unsigned short aid;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned char unknown_a_[2];
};

struct Struct_020d49c4_2
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short count;
    unsigned short length;
    unsigned short unknown_8_;
    Struct_020d49c4 data[1];
};

extern "C" int func_020d41e8();
extern "C" Struct_020d424c_2* func_020d41d8();

// USA: func_020d49c4
extern "C" ARM const Struct_020d49c4* func_020d49c4(const void* header, unsigned short aid)
{
    const Struct_020d49c4_2* const var0 = (const Struct_020d49c4_2*)header;
    Struct_020d49c4* var1[15];
    Struct_020d424c_2* const var2 = func_020d41d8();
    if (func_020d41e8() != 0)
        return NULL;
    if (aid < 1 || aid > 15)
        return NULL;
    InvalidateDataCacheRange(&var2->status->unknown_182_, 2);
    if (!(var2->status->unknown_182_ & (1 << aid)))
        return NULL;
    if (var0->count == 0)
        return NULL;
    var1[0] = (Struct_020d49c4*)var0->data;
    int i = 0;
    do
    {
        if (var1[i]->aid == aid)
            return var1[i];
        i++;
        var1[i] = (Struct_020d49c4*)((unsigned long)var1[i - 1] + var0->length);
    } while (i < var0->count);
    return NULL;
}
