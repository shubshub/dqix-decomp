#include <globaldefs.h>

struct Struct_ov031_0221bfe8 {
    unsigned long long unknown_0_;
    unsigned long long unknown_8_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
};
struct Struct_020cf294 { unsigned int unknown_0_; unsigned int unknown_4_; unsigned int unknown_8_; unsigned int unknown_c_; };
struct Struct_020cf294_2 { unsigned int unknown_0_; unsigned int unknown_4_; unsigned int unknown_8_; };

extern "C" void func_ov031_0221ae00(DWCAuthWiFiId* id);
void InitSlotSystem020cf020(void);
int RegisterSlotA020cf0fc(int a);
int RTC_GetTime(int a);
long long ComputeEntryByteOffset_020cf990(int arg0, unsigned char* arg1);
int Is64BitTimerInitialized();
unsigned long long GetCurrentTimestamp(void);
extern "C" void OS_GetMacAddress(void* dst);
extern "C" unsigned long long func_ov031_0221be64(unsigned int rand, unsigned int mac, unsigned int flag, unsigned int kind);

struct Struct_ov031_0221bfe8_2 { unsigned int unknown_0_; unsigned int unknown_4_; unsigned int unknown_8_; };

static inline void inline_ov031_0221bfe8_5(Struct_ov031_0221bfe8_2* arg0, unsigned int arg1) {
    arg0->unknown_0_ = arg1;
    arg0->unknown_4_ = 1566083941;
    arg0->unknown_8_ = 2531011;
}
static inline unsigned short inline_ov031_0221bfe8(Struct_ov031_0221bfe8_2* arg0, unsigned short arg1) {
    arg0->unknown_0_ = arg0->unknown_4_ * arg0->unknown_0_ + arg0->unknown_8_;
    if (arg1) {
        return (unsigned short)(((arg0->unknown_0_ >> 16) * arg1) >> 16);
    } else {
        return (unsigned short)(arg0->unknown_0_ >> 16);
    }
}

static inline int RTC_GetDate(RTCDate* date) { return RegisterSlotA020cf0fc((int)date); }
static inline int RTC_GetTime(RTCTime* time) { return RTC_GetTime((int)time); }
static inline long long RTC_ConvertDateTimeToSecond(const RTCDate* date, const RTCTime* time) {
    return ComputeEntryByteOffset_020cf990((int)date, (unsigned char*)time);
}

// USA: func_ov031_0221bfe8
extern "C" ARM int func_ov031_0221bfe8(Struct_ov031_0221bfe8* arg0) {
    unsigned char var0[6];
    Struct_020cf294 var1;
    Struct_020cf294_2 var2;
    long long var3;
    Struct_ov031_0221bfe8_2 var4;
    unsigned char var5;
    int var6;

    func_ov031_0221ae00(id);
    InitSlotSystem020cf020();
    if (RTC_GetDate(&date) != 0) return 0;
    if (RTC_GetTime(&time) != 0) return 0;
    sec = RTC_ConvertDateTimeToSecond(&date, &time);
    if (sec < 0) return 0;
    if (Is64BitTimerInitialized()) sec += (unsigned int)GetCurrentTimestamp;
    OS_GetMacAddress(mac);
    flag = (unsigned int)(mac[0] << 16 | mac[1] << 8 | mac[2]) != 0x9bf ? 1 : 0;
    macLow = mac[3] << 16 | mac[4] << 8 | mac[5];
    MATH_InitRand16(&rand, (unsigned int)sec);
    id->pass = MATH_Rand16(&rand, 1000);
    id->uId = 0;
    if (id->randomHistory == 0) {
        id->notAttestedId = 0;
        if (id->notAttestedId == 0) {
            do {
                inline_ov031_0221bfe8(&var4, 0);
                if (var4.unknown_0_ == 0) {
                    do {
                        inline_ov031_0221bfe8(&var4, 0);
                    } while (var4.unknown_0_ == 0);
                }
                arg0->unknown_12_ = (unsigned short)var4.unknown_0_;
                arg0->unknown_8_ = func_ov031_0221be64(arg0->unknown_12_, var6, var5, 0);
            } while (arg0->unknown_8_ == 0);
        }
    } else {
        arg0->unknown_8_ = 0;
        if (arg0->unknown_8_ == 0) {
            do {
                arg0->unknown_12_++;
                arg0->unknown_8_ = func_ov031_0221be64(arg0->unknown_12_, var6, var5, 0);
            } while (arg0->unknown_8_ == 0);
        }
    }
    return 1;
}
