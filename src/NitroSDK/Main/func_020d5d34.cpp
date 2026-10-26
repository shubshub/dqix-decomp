#include <globaldefs.h>

typedef void (*Type_020d42e0)(void* arg);

struct Struct_020d5d34_2
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_[254];
};

struct Struct_020d5d34
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
    unsigned short unknown_81c_;
    unsigned short unknown_81e_[1];
};

extern "C" int func_020d424c(int paramNum, ...);
extern "C" void MIi_CpuClearFast(unsigned long value, void* dst, unsigned long size);
extern "C" int func_020d4770(unsigned short port, WMCallbackFunc callback, void* arg);
extern "C" int func_020d59bc(WMCallbackFunc callback, void* arg, const unsigned short* sendData,
                             unsigned short sendDataSize, unsigned short destBitmap, unsigned short port,
                             unsigned short prio);
extern "C" void func_020d6318(void* callback);
extern "C" void func_020d63f0(void* callback);
extern "C" void func_020d651c(void* callback);
unsigned short GetBattleContextField0x150_020d46cc();
unsigned short GetBattleContextField0x14cLow16_020d46fc();
unsigned char PopCount32_020d1ae4(unsigned int x);

// USA: func_020d5d34
extern "C" ARM int func_020d5d34(Struct_020d5d34* arg0, unsigned short arg1, unsigned short arg2,
                                 unsigned short arg3, int arg4)
{
    int var0;
    int var1;
    unsigned short var2 = 1;
    var0 = func_020d424c(2, 9, 10);
    if (var0 != 0)
        return var0;
    if (arg0 == NULL)
        return 6;
    if (arg1 >= 16)
        return 6;
    if (arg2 == 0)
        return 6;
    aid = GetBattleContextField0x150_020d46cc();
    if (aid == 0)
        connectedAIDs = GetBattleContextField0x14cLow16_020d46fc();
    MIi_CpuClearFast(0, dsInfo, sizeof(WMDataSharingInfo));
    dsInfo->writeIndex = 0;
    dsInfo->sendIndex = 0;
    dsInfo->readIndex = 0;
    dsInfo->dataLength = dataLength;
    dsInfo->port = port;
    dsInfo->aidBitmap = 0;
    dsInfo->doubleMode = doubleMode ? true : false;
    aidBitmap |= 1 << aid;
    dsInfo->aidBitmap = aidBitmap;
    {
        const unsigned char var3 = func_020d1ae4(arg2);
        arg0->unknown_812_ = var3;
        arg0->unknown_814_ = arg3 * var3;
    }
    if (arg0->unknown_814_ > 508)
    {
        arg0->unknown_80e_ = 0;
        return 6;
    }
    arg0->unknown_814_ += 4;
    arg0->unknown_81c_ = 1;
    if (var1 == 0)
    {
        int var4;
        for (var4 = 0; var4 < 4; var4++)
            arg0->unknown_0_[var4].unknown_0_ = arg0->unknown_80e_ & (var2 | 1);
        func_020d4770(arg1, func_020d63f0, arg0);
        for (var4 = 0; var4 < (arg0->unknown_818_ == true ? 2 : 1); var4++)
        {
            int var5;
            arg0->unknown_808_ = (arg0->unknown_808_ + 1) & 3;
            var5 = func_020d59bc(func_020d6318, arg0, (unsigned short*)&arg0->unknown_0_[var4], arg0->unknown_814_,
                                arg0->unknown_80e_ & var2, arg0->unknown_816_, 1);
            if (var5 == 7)
            {
                arg0->unknown_800_[var4] = 0xffff;
                arg0->unknown_80a_ = (arg0->unknown_80a_ + 1) & 3;
            }
            else if (var5 != 0 && var5 != 2)
            {
                arg0->unknown_81c_ = 5;
                return 1;
            }
        }
    }
    else
    {
        arg0->unknown_80a_ = 3;
        func_020d4770(arg1, func_020d651c, arg0);
    }
    return 0;
}
