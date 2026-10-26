#include <globaldefs.h>

struct Struct_ov031_02208f50_2 {
    unsigned long state[4];
    unsigned long count[2];
    unsigned char buffer[64];
};
struct Struct_ov031_02208f50 {
    unsigned long state[5];
    unsigned long count[2];
    unsigned char buffer[64];
};
struct Struct_0205faf4_21 {
    unsigned char x;
    unsigned char y;
    unsigned char m[256];
    unsigned short padding;
};
struct Struct_0205faf4_22 {
    char* unknown_0_;
    int unknown_4_;
    unsigned char* unknown_8_;
    int unknown_c_;
    unsigned char* unknown_10_;
};
union Struct_0205faf4_23 { Struct_0205faf4_21 unknown_0_; };
struct Struct_0205faf4_24;
struct Struct_0205faf4_25;
struct Struct_ov031_0220871c_2 {
    unsigned char unknown_0_[48];
    unsigned char unknown_30_;
    unsigned char unknown_31_;
    unsigned short method;
    unsigned char unknown_34_[32];
    unsigned char unknown_54_[32];
    union {
        unsigned char unknown_0_[32];
        unsigned char unknown1_0_[72];
    } unknown_74_;
    unsigned char* unknown_bc_;
    unsigned char* unknown_c0_;
    unsigned char* unknown_c4_;
    Struct_0205faf4_23 unknown_c8_;
    unsigned char unknown_1cc_[8];
    unsigned char* unknown_1d4_;
    unsigned char* unknown_1d8_;
    unsigned char* unknown_1dc_;
    Struct_0205faf4_23 unknown_1e0_;
    unsigned char unknown_2e4_[8];
    Struct_ov031_02208f50 unknown_2ec_;
    Struct_ov031_02208f50 unknown_348_;
    Struct_ov031_02208f50_2 unknown_3a4_;
    Struct_ov031_02208f50_2 unknown_3fc_;
    unsigned char unknown_454_;
    unsigned char state;
    unsigned char unknown_456_;
    unsigned char padding2;
    int unknown_458_;
    int unknown_45c_;
    unsigned char* unknown_460_;
    unsigned char* unknown_464_;
    unsigned char unknown_468_[20];
    int unknown_47c_;
    Struct_0205faf4_22 unknown_480_;
    unsigned char unknown_494_[256];
    unsigned long unknown_594_;
    unsigned char unknown_598_[8];
    int unknown_5a0_;
    unsigned char* signature;
    int unknown_5a8_;
    unsigned char unknown_5ac_;
    unsigned char unknown_5ad_;
    unsigned char unknown_5ae_;
    unsigned char unknown_5af_;
    char unknown_5b0_[256];
    char unknown_6b0_[256];
    char unknown_7b0_[80];
    char* unknown_800_;
    unsigned char* unknown_804_;
    int unknown_808_;
    unsigned long unknown_80c_;
    int (*unknown_810_)(int, Struct_ov031_0220871c_2*, int);
    Struct_0205faf4_22** unknown_814_;
    int unknown_818_;
    Struct_0205faf4_24* unknown_81c_;
    Struct_0205faf4_25* unknown_820_;
    unsigned char* unknown_824_;
    long unknown_828_;
    long unknown_82c_;
};

struct Struct_ov031_0220871c {
    unsigned long year;
    unsigned long month;
    unsigned long day;
    int unknown_c_;
};
extern "C" int func_020cf0fc(int);
extern "C" int func_ov031_02207f10(Struct_ov031_0220871c_2*, unsigned char**, int, int, int);
extern "C" int func_ov031_022085a8(Struct_ov031_0220871c_2*);
extern "C" int func_ov031_022086b0(const char*, const char*);
extern "C" int func_ov031_02208400(Struct_ov031_0220871c_2*, Struct_0205faf4_22*);

// USA: func_ov031_0220871c
extern "C" ARM void func_ov031_0220871c(Struct_ov031_0220871c_2* context, unsigned char* data) {
    Struct_ov031_0220871c date;
    unsigned long code;
    unsigned long result;
    unsigned long length;
    unsigned long remaining;
    int index;
    remaining = data[2] + (((data[0] << 8) + data[1]) << 8);
    data += 3;
    context->unknown_45c_ = -1;
    func_020cf0fc((int)&date);
    context->unknown_80c_ = ((date.year + 2000) << 16) + (date.month << 8) + date.day;
    code = 0;
    context->unknown_6b0_[0] = 0;
    context->unknown_5a0_ = 0;
    context->unknown_594_ = 0;
    index = 0;
    do {
        length = data[2] + (((data[0] << 8) + data[1]) << 8);
        data += 3;
        remaining -= length + 3;
        context->unknown_458_ = -1;
        context->unknown_5ad_ = 0;
        context->unknown_5ac_ = 0;
        context->unknown_5af_ = 0;
        context->unknown_6b0_[0] = 0;
        context->unknown_5b0_[0] = 0;
        context->unknown_7b0_[0] = 0;
        context->unknown_804_ = data;
        context->unknown_808_ = length;
        int var6 = func_ov031_02207f10(context, &data, 0, 0, code);
        if (var6 || context->unknown_594_ < 51 || !context->unknown_5a0_) {
            context->state = 9;
            return;
        }
        result = func_ov031_022085a8(context);
        if (!index && context->unknown_800_ && func_ov031_022086b0(context->unknown_800_, context->unknown_7b0_)) result |= 0x4000;
        code = result & 0xff;
        if (code == 1 && remaining) {
            unsigned char* next = data + 3;
            context->unknown_5ad_ = 0;
            if (func_ov031_02207f10(context, &next, 0, 0, 2)) {
                context->state = 9;
                return;
            }
            result = (result & ~0xff) | func_ov031_02208400(context, &context->unknown_480_);
        }
        if (context->unknown_810_) result = context->unknown_810_(result, context, index);
        index++;
        if (!code || result || !remaining) break;
        code = 1;
    } while (true);
    if (!result) context->state = 3;
    else context->state = 9;
}
