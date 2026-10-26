#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

typedef void (*Type_020d42e0)(void* arg);

struct Struct_020d424c_2
{
    void* unknown_0_;
    void* unknown_4_;
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
    unsigned short unknown_150_;
};

struct Struct_02114330
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    void* unknown_8_;
    void* unknown_c_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    unsigned char unknown_14_[6];
    unsigned short unknown_1a_;
    void* unknown_1c_;
    unsigned short unknown_20_;
    unsigned short unknown_22_;
    unsigned char unknown_24_[24];
    unsigned short unknown_3c_;
    unsigned short unknown_3e_;
    unsigned short unknown_40_;
    unsigned short unknown_42_;
};

extern "C" void OS_GetMacAddress(void* mac);
int GetBattleStateCode_020d41e8();
WMArm9Buf* GetBattleContext_020d41d8();
unsigned short GetBattleContextField0x14cLow16_020d46fc();
unsigned short GetBattleContextField0x150_020d46cc();

// USA: func_020d4770
extern "C" ARM int func_020d4770(unsigned short arg0, Type_020d42e0 arg1, void* arg2)
{
    int var0;
    int var1;
    Struct_02114330 var2;
    if (arg1 != NULL)
    {
        VectorizedMemset(&cb, 0, sizeof(WMPortRecvCallback));
        cb.apiid = 0x82;
        cb.errcode = 0;
        cb.state = 25;
        cb.port = port;
        cb.recvBuf = NULL;
        cb.data = NULL;
        cb.length = 0;
        cb.seqNo = 0xffff;
        cb.arg = arg;
        cb.aid = 0;
        OS_GetMacAddress(cb.macAddress);
    }
    var1 = DisableIRQInterrupts();
    var0 = func_020d41e8();
    if (var0 != 0)
    {
        SetIRQInterruptState(var1);
        return var0;
    }
    {
        Struct_020d424c_2* const var3 = func_020d41d8();
        var3->unknown_cc_[arg0] = arg1;
        var3->unknown_10c_[arg0] = arg2;
    }
    if (arg1 != NULL)
    {
        var2.unknown_22_ = func_020d46fc();
        var2.unknown_20_ = func_020d46cc();
        arg1(&var2);
    }
    SetIRQInterruptState(var1);
    return 0;
}
