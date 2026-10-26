#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

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

extern "C" void OS_GetMacAddress(void* mac);
extern "C" int func_020d41e8();
extern "C" Struct_020d424c_2* func_020d41d8();
extern "C" unsigned short func_020d46fc();
extern "C" unsigned short func_020d46cc();

// USA: func_020d4770
extern "C" ARM int func_020d4770(unsigned short arg0, Type_020d42e0 callback, void* arg)
{
    int result;
    int var1;
    Struct_02114330 cb;
    if (callback != NULL)
    {
        VectorizedMemset(&cb, 0, sizeof(Struct_02114330));
        cb.unknown_0_ = 0x82;
        cb.unknown_2_ = 0;
        cb.state = 25;
        cb.unknown_6_ = arg0;
        cb.unknown_8_ = NULL;
        cb.data = NULL;
        cb.length = 0;
        cb.unknown_1a_ = 0xffff;
        cb.arg = arg;
        cb.aid = 0;
        OS_GetMacAddress(cb.macAddress);
    }
    var1 = DisableIRQInterrupts();
    result = func_020d41e8();
    if (result != 0)
    {
        SetIRQInterruptState(var1);
        return result;
    }
    {
        Struct_020d424c_2* const var3 = func_020d41d8();
        var3->unknown_cc_[arg0] = callback;
        var3->unknown_10c_[arg0] = arg;
    }
    if (callback != NULL)
    {
        cb.unknown_22_ = func_020d46fc();
        cb.myAid = func_020d46cc();
        callback(&cb);
    }
    SetIRQInterruptState(var1);
    return 0;
}
