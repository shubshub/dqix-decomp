#include <globaldefs.h>

typedef void (*Type_020cf294)(int result, void* arg);
typedef void (*Type_020cf020)(void);

struct Struct_020cf294 {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    int unknown_c_;
};
struct RTCTime {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int second;
};
struct Struct_020cf294_8 {
    int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    unsigned int enable;
};

struct Struct_020cf294_9 {
    unsigned int year : 8;
    unsigned int month : 5;
    unsigned int unknown_1_5_ : 3;
    unsigned int day : 6;
    unsigned int unknown_2_6_ : 2;
    unsigned int unknown_3_0_ : 3;
    unsigned int unknown_3_3_ : 5;
};
struct Struct_020cf294_10 {
    unsigned int unknown_0_0_ : 6;
    unsigned int unknown_0_6_ : 1;
    unsigned int unknown_0_7_ : 1;
    unsigned int unknown_1_0_ : 7;
    unsigned int unknown_1_7_ : 1;
    unsigned int second : 7;
    unsigned int unknown_2_7_ : 9;
};
struct Struct_020cf020 {
    unsigned short reset : 1;
    unsigned short format : 1;
    unsigned short unknown_0_2_ : 2;
    unsigned short unknown_0_4_ : 1;
    unsigned short unknown_0_5_ : 1;
    unsigned short unknown_0_6_ : 1;
    unsigned short unknown_0_7_ : 1;
    unsigned short unknown_1_0_ : 8;
};
struct Struct_020cf294_3 {
    unsigned short unknown_0_0_ : 4;
    unsigned short unknown_0_4_ : 2;
    unsigned short unknown_0_6_ : 1;
    unsigned short unknown_0_7_ : 1;
    unsigned short unknown_1_0_ : 8;
};
struct Struct_020cf294_4 {
    unsigned int unknown_0_0_ : 3;
    unsigned int unknown_0_3_ : 4;
    unsigned int unknown_0_7_ : 1;
    unsigned int unknown_1_0_ : 6;
    unsigned int unknown_1_6_ : 1;
    unsigned int he : 1;
    unsigned int unknown_2_0_ : 7;
    unsigned int me : 1;
    unsigned int unknown_3_0_ : 8;
};
union Struct_020cf294_5 {
    struct {
        Struct_020cf294_9 date;
        Struct_020cf294_10 time;
    } t;
    struct {
        Struct_020cf020 unknown_0_;
        Struct_020cf294_3 unknown_2_;
        Struct_020cf294_4 unknown_4_;
    } a;
};

union Struct_020cf294_6 {
    Struct_020cf294* date;
    RTCTime* time;
    Struct_020cf294_8* unknown2_0_;
    int* status;
};

struct Struct_020cf294_7 {
    unsigned int lock;
    Type_020cf294 callback;
    Struct_020cf294_6 buffer[2];
    void* unknown_10_;
    unsigned int unknown_14_;
    unsigned int index;
    Type_020cf020 interrupt;
    int unknown_20_;
};

struct Struct_02111818_4 {
    unsigned char pad0[0xc];
    Struct_020cf294_7 work;
};
extern Struct_02111818_4 data_02111818;

extern "C" int func_020cf7e4(unsigned int bcd);
extern "C" int func_020cfc00(Struct_020cf294* date);
extern "C" int func_020cf8ac(void);

#define RTC_BUF ((Struct_020cf294_5*)0x027ffde8)

// USA: func_020cf294
extern "C" ARM void func_020cf294(int tag, unsigned int data, int arg2) {
    int result;
    int var1;
    unsigned char command;
    Type_020cf294 cb;

    if (arg2) {
        if (data_02111818.work.index) {
            data_02111818.work.index = 0;
        }
        if (data_02111818.work.lock != 0) {
            data_02111818.work.lock = 0;
        }
        if (data_02111818.work.callback) {
            cb = data_02111818.work.callback;
            data_02111818.work.callback = 0;
            cb(6, data_02111818.work.unknown_10_);
        }
        return;
    }

    command = (unsigned char)((data & 0x7f00) >> 8);
    var1 = (int)(data & 0xff);

    if (command == 0x30) {
        if (data_02111818.work.interrupt) {
            data_02111818.work.interrupt();
        }
        return;
    }

    if (var1 == 0) {
        result = 0;
        switch (data_02111818.work.unknown_14_) {
        case 0: {
            Struct_020cf294* var4 = data_02111818.work.buffer[0].date;
            Struct_020cf294_9* pSrc = &RTC_BUF->t.date;

            var4->year = func_020cf7e4(pSrc->year);
            var4->month = func_020cf7e4(pSrc->month);
            var4->day = func_020cf7e4(pSrc->day);
            var4->unknown_c_ = func_020cfc00(var4);
        } break;
        case 1: {
            RTCTime* var6 = data_02111818.work.buffer[0].time;
            Struct_020cf294_10* pSrc = &RTC_BUF->t.time;

            var6->unknown_0_ = func_020cf7e4(pSrc->unknown_0_0_);
            var6->unknown_4_ = func_020cf7e4(pSrc->unknown_1_0_);
            var6->second = func_020cf7e4(pSrc->second);
        } break;
        case 2: {
            Struct_020cf294* var8 = data_02111818.work.buffer[0].date;
            Struct_020cf294_9* pSrc = &RTC_BUF->t.date;

            var8->year = func_020cf7e4(*(unsigned int*)pSrc & 0xff);
            var8->month = func_020cf7e4(pSrc->month);
            var8->day = func_020cf7e4(pSrc->day);
            var8->unknown_c_ = func_020cfc00(var8);
        }
            {
                RTCTime* var10 = data_02111818.work.buffer[1].time;
                Struct_020cf294_10* pSrc = &RTC_BUF->t.time;

                var10->unknown_0_ = func_020cf7e4(pSrc->unknown_0_0_);
                var10->unknown_4_ = func_020cf7e4(pSrc->unknown_1_0_);
                var10->second = func_020cf7e4(pSrc->second);
            }
            break;
        case 3:
        case 4:
        case 5:
            break;
        case 6: {
            int* var12 = data_02111818.work.buffer[0].status;
            Struct_020cf294_3* pSrc = &RTC_BUF->a.unknown_2_;

            switch (pSrc->unknown_0_0_) {
            case 4:
                *var12 = 1;
                break;
            default:
                *var12 = 0;
            }
        } break;
        case 7: {
            int* var14 = data_02111818.work.buffer[0].status;
            Struct_020cf294_3* pSrc = &RTC_BUF->a.unknown_2_;

            if (pSrc->unknown_0_6_) {
                *var14 = 1;
            } else {
                *var14 = 0;
            }
        } break;
        case 8: {
            Struct_020cf294_8* var16 = data_02111818.work.buffer[0].unknown2_0_;
            Struct_020cf294_4* pSrc = &RTC_BUF->a.unknown_4_;

            var16->unknown_0_ = (int)pSrc->unknown_0_0_;
            var16->unknown_4_ = func_020cf7e4(pSrc->unknown_1_0_);
            var16->unknown_8_ = func_020cf7e4(pSrc->unknown_2_0_);
            var16->enable = 0;
            if (pSrc->unknown_0_7_)
                var16->enable += 1;
            if (pSrc->he)
                var16->enable += 2;
            if (pSrc->me)
                var16->enable += 4;
        } break;
        case 9:
            if (data_02111818.work.index == 0) {
                Struct_020cf294_3* pSrc = &RTC_BUF->a.unknown_2_;

                if (*data_02111818.work.buffer[0].status == 1) {
                    if (pSrc->unknown_0_0_ != 4) {
                        data_02111818.work.index++;
                        pSrc->unknown_0_0_ = 4;
                        if (!func_020cf8ac()) {
                            data_02111818.work.index = 0;
                            result = 3;
                        }
                    }
                } else {
                    if (pSrc->unknown_0_0_ != 0) {
                        data_02111818.work.index++;
                        pSrc->unknown_0_0_ = 0;
                        if (!func_020cf8ac()) {
                            data_02111818.work.index = 0;
                            result = 3;
                        }
                    }
                }
            } else {
                data_02111818.work.index = 0;
            }
            break;
        case 10:
            if (data_02111818.work.index == 0) {
                Struct_020cf294_3* pSrc = &RTC_BUF->a.unknown_2_;

                if (*data_02111818.work.buffer[0].status == 1) {
                    if (!pSrc->unknown_0_6_) {
                        data_02111818.work.index++;
                        pSrc->unknown_0_6_ = 1;
                        if (!func_020cf8ac()) {
                            data_02111818.work.index = 0;
                            result = 3;
                        }
                    }
                } else {
                    if (pSrc->unknown_0_6_) {
                        data_02111818.work.index++;
                        pSrc->unknown_0_6_ = 0;
                        if (!func_020cf8ac()) {
                            data_02111818.work.index = 0;
                            result = 3;
                        }
                    }
                }
            } else {
                data_02111818.work.index = 0;
            }
            break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            break;
        default:
            result = 4;
            data_02111818.work.index = 0;
        }
    } else {
        data_02111818.work.index = 0;

        switch (var1) {
        case 1:
            result = 4;
            break;
        case 2:
            result = 5;
            break;
        case 3:
            result = 1;
            break;
        case 4:
        default:
            result = 6;
        }
    }

    if (data_02111818.work.index == 0) {
        if (data_02111818.work.lock != 0) {
            data_02111818.work.lock = 0;
        }
        if (data_02111818.work.callback) {
            cb = data_02111818.work.callback;
            data_02111818.work.callback = 0;
            cb(result, data_02111818.work.unknown_10_);
        }
    }
}
