#include <globaldefs.h>

struct Struct_ov031_0221bfe8 {
    unsigned long long unknown_0_;
    unsigned long long unknown_8_;
    unsigned short pass;
    unsigned short unknown_12_;
};
struct Struct_020cf294 { unsigned int year; unsigned int month; unsigned int day; unsigned int unknown_c_; };
struct RTCTime { unsigned int unknown_0_; unsigned int unknown_4_; unsigned int second; };

extern "C" void func_ov031_0221ae00(Struct_ov031_0221bfe8* id);
extern "C" void func_020cf020(void);
extern "C" int func_020cf0fc(int a);
extern "C" int RTC_GetTime(int a);
extern "C" long long func_020cf990(int arg0, unsigned char* arg1);
int Is64BitTimerInitialized();
unsigned long long GetCurrentTimestamp(void);
extern "C" void OS_GetMacAddress(void* dst);
extern "C" unsigned long long func_ov031_0221be64(unsigned int arg0, unsigned int mac, unsigned char flag, unsigned int kind);

struct Struct_ov031_0221bfe8_2 { unsigned int x; unsigned int mul; unsigned int unknown_8_; };

static inline void inline_ov031_0221bfe8_5(Struct_ov031_0221bfe8_2* context, unsigned int seed) {
    context->x = seed;
    context->mul = 1566083941;
    context->unknown_8_ = 2531011;
}
static inline unsigned short inline_ov031_0221bfe8(Struct_ov031_0221bfe8_2* context, unsigned short max) {
    context->x = context->mul * context->x + context->unknown_8_;
    if (max) {
        return (unsigned short)(((context->x >> 16) * max) >> 16);
    } else {
        return (unsigned short)(context->x >> 16);
    }
}

static inline int inline_ov031_0221bfe8_2(Struct_020cf294* date) { return func_020cf0fc((int)date); }
static inline int RTC_GetTime(RTCTime* time) { return RTC_GetTime((int)time); }
static inline long long inline_ov031_0221bfe8_4(const Struct_020cf294* date, const RTCTime* time) {
    return func_020cf990((int)date, (unsigned char*)time);
}

// USA: func_ov031_0221c258
extern "C" ARM int func_ov031_0221c258(Struct_ov031_0221bfe8* id) {
    unsigned char mac[6] = {0, 0, 0, 0, 0, 0};
    Struct_020cf294 date;
    RTCTime time;
    long long var3;
    Struct_ov031_0221bfe8_2 var4;
    unsigned char flag;
    unsigned int var6;

    func_ov031_0221ae00(id);
    func_020cf020();
    if (inline_ov031_0221bfe8_2(&date) != 0) return 0;
    if (RTC_GetTime(&time) != 0) return 0;
    var3 = inline_ov031_0221bfe8_4(&date, &time);
    if (var3 < 0) return 0;
    if (Is64BitTimerInitialized()) var3 += (unsigned int)GetCurrentTimestamp;
    OS_GetMacAddress(mac);
    flag = (unsigned int)(mac[0] << 16 | mac[1] << 8 | mac[2]) != 0x9bf ? 1 : 0;
    var6 = mac[3] << 16 | mac[4] << 8 | mac[5];
    inline_ov031_0221bfe8_5(&var4, (unsigned int)var3);
    id->pass = inline_ov031_0221bfe8(&var4, 1000);
    id->unknown_8_ = 0;
    while (id->unknown_8_ == 0) {
        inline_ov031_0221bfe8(&var4, 0);
        while (var4.x == 0 || id->unknown_12_ == (unsigned short)var4.x) inline_ov031_0221bfe8(&var4, 0);
        id->unknown_12_ = (unsigned short)var4.x;
        id->unknown_8_ = func_ov031_0221be64(id->unknown_12_, var6, flag, 0);
    }
    return 1;
}
