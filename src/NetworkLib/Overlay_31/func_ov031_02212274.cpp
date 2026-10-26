#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Cache.h"

struct Struct_ov031_02212274
{
    int unknown_0_;
    int area;
    char unknown_8_[10];
    char unknown_12_[33];
    unsigned char bssid[6];
    char pad[3];
};

extern "C" int func_ov031_02211f24();
extern "C" int func_ov031_02213024();
extern "C" unsigned char* func_ov031_0220f040();
extern "C" void* func_ov031_0220f084(unsigned short* out);
extern "C" int func_ov031_02213054(void* buf);

static inline int inline_ov031_02212274(unsigned int c)
{
    return c >= '0' && c <= '9';
}

// USA: func_ov031_02212274
extern "C" ARM int func_ov031_02212274(Struct_ov031_02212274* arg0)
{
    int var0;
    unsigned char* bssid;
    unsigned short var2;
    void* var3;
    unsigned char var4[10];

    VectorizedMemset(arg0, 0, sizeof(Struct_ov031_02212274));
    arg0->area = 0xff;
    if (func_ov031_02211f24() != 4) return 0;

    arg0->unknown_0_ = func_ov031_02213024();
    if (arg0->unknown_0_ == 0xff || arg0->unknown_0_ > 99)
    {
        arg0->unknown_0_ = 99;
        return 0;
    }

    var0 = DisableIRQInterrupts();
    bssid = func_ov031_0220f040();
    InvalidateDataCacheRange(bssid, 6);
    if (bssid == NULL)
    {
        SetIRQInterruptState(var0);
        return 0;
    }
    VectorizedInvertedMemcpy(bssid, arg0->bssid, 6);

    if (arg0->unknown_0_ >= 0 && arg0->unknown_0_ < 3)
    {
        var3 = func_ov031_0220f084(&var2);
        InvalidateDataCacheRange(var3, 32);
        if (var3 == NULL)
        {
            SetIRQInterruptState(var0);
            return 0;
        }
        VectorizedInvertedMemcpy(var3, arg0->unknown_12_, var2);
    }
    SetIRQInterruptState(var0);

    if (func_ov031_02213054(var4))
    {
        arg0->area = inline_ov031_02212274(var4[0]) ? var4[0] - '0' : 0xff;
        VectorizedInvertedMemcpy(&var4[1], arg0->unknown_8_, 9);
    }
    else
    {
        arg0->area = 0xff;
    }
    return 1;
}
