#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"

extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float value);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);

struct Struct_02071208 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    char unknown_9_[0xa - 0x9];
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
    short unknown_10_;
    char unknown_12_[0x20];
    char unknown_32_[0xc];
    short unknown_3e_;
    short unknown_40_;
    short unknown_42_;
    unsigned short unknown_44_;
    short unknown_46_;
    Vector3fix unknown_48_;
    short unknown_54_;
    char unknown_56_[0x10];
};

struct Struct_02108d70_3 {
    short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    char unknown_8_[0xc - 0x8];
    int unknown_c_;
    char unknown_10_[0x18 - 0x10];
    int unknown_18_;
    char unknown_1c_[0x20 - 0x1c];
    Struct_02071208* unknown_20_;
};
extern struct Struct_02108d70_3 data_02108d70;

// USA: func_02071208
extern "C" ARM int func_02071208(Script::Parameter* arg0) {
    data_02108d70.unknown_4_++;
    if (data_02108d70.unknown_c_ != 0) {
        return 1;
    }

    int var0 = arg0[0].ToInt();
    int var1 = arg0[1].ToInt();
    int var2 = arg0[2].ToInt();
    int var3 = arg0[3].ToInt();
    int var4 = arg0[4].ToInt();
    int var5 = arg0[5].ToInt();

    if (var5 == data_02108d70.unknown_18_) {
        data_02108d70.unknown_20_->unknown_0_ = var0;
        data_02108d70.unknown_20_->unknown_2_ = var2;
        data_02108d70.unknown_20_->unknown_1_ = var1;
        data_02108d70.unknown_20_->unknown_3_ = var3;
        data_02108d70.unknown_20_->unknown_e_ = var4;
        data_02108d70.unknown_20_->unknown_a_ = var5;

        data_02108d70.unknown_20_->unknown_c_ = arg0[6].ToInt();

        const char* var6 = arg0[7].ToString();
        if (var6) {
            memcpy(data_02108d70.unknown_20_->unknown_12_, var6, 0x20);
            data_02108d70.unknown_20_->unknown_12_[0x1f] = 0;
        }

        const char* var7 = arg0[8].ToString();
        if (!var7) {
            return 0;
        }
        strcpy(data_02108d70.unknown_20_->unknown_32_, var7);

        data_02108d70.unknown_20_->unknown_3e_ = arg0[9].ToInt();
        data_02108d70.unknown_20_->unknown_40_ = arg0[10].ToInt();
        data_02108d70.unknown_20_->unknown_42_ = arg0[11].ToInt();
        arg0 = arg0[12].ToVec3fix(&data_02108d70.unknown_20_->unknown_48_);
        data_02108d70.unknown_20_->unknown_54_ = _ffix(_fmul(4096.0f, arg0->ToFloat()));

        data_02108d70.unknown_20_->unknown_5_ = arg0[1].ToInt();
        data_02108d70.unknown_20_->unknown_46_ = arg0[2].ToInt();
        if (data_02108d70.unknown_20_->unknown_46_ >= 0) {
            data_02108d70.unknown_20_->unknown_46_ = data_02108d70.unknown_4_ - 1;
        }
        data_02108d70.unknown_20_->unknown_4_ = arg0[3].ToInt();
        data_02108d70.unknown_20_->unknown_6_ = arg0[4].ToInt();

        const char* var8 = arg0[5].ToString();
        if (var8) {
            memcpy(data_02108d70.unknown_20_->unknown_56_, var8, 0x10);
            data_02108d70.unknown_20_->unknown_56_[0xf] = 0;
        }

        data_02108d70.w0x20->f44 = params[6].ToInt();
        if (LinkSession_IsGuest(LinkSession_GetInstance())) {
            data_02108d70.w0x20->f44 = data_02108d70.w0x20->f44 & ~8;
        }

        data_02108d70.unknown_20_->unknown_10_ = arg0[7].ToInt();
        data_02108d70.unknown_c_ = 1;
    }
    return 1;
}