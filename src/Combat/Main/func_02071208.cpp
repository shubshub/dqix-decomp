#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"

extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float value);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);

struct Struct_02071208 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    unsigned char f8;
    char unknown_9_[0xa - 0x9];
    short unknown_a_;
    short f0c;
    short unknown_e_;
    short f10;
    char name[0x20];
    char desc[0xc];
    short unknown_3e_;
    short f40;
    short unknown_42_;
    unsigned short unknown_44_;
    short f46;
    Vector3fix vec;
    short unknown_54_;
    char tag[0x10];
};

struct Struct_02108d70_3 {
    short h0;
    unsigned short h2;
    unsigned short h4;
    unsigned short h6;
    char pad8[0xc - 0x8];
    int unknown_c_;
    char pad10[0x18 - 0x10];
    int unknown_18_;
    char unknown_1c_[0x20 - 0x1c];
    Struct_02071208* unknown_20_;
};
extern struct Struct_02108d70_3 data_02108d70;

// USA: func_02071208
extern "C" ARM int func_02071208(Script::Parameter* params) {
    data_02108d70.h4++;
    if (data_02108d70.unknown_c_ != 0) {
        return 1;
    }

    int b0 = params[0].ToInt();
    int b1 = params[1].ToInt();
    int b2 = params[2].ToInt();
    int b3 = params[3].ToInt();
    int var4 = params[4].ToInt();
    int var5 = params[5].ToInt();

    if (var5 == data_02108d70.unknown_18_) {
        data_02108d70.unknown_20_->f0 = b0;
        data_02108d70.unknown_20_->f2 = b2;
        data_02108d70.unknown_20_->f1 = b1;
        data_02108d70.unknown_20_->f3 = b3;
        data_02108d70.unknown_20_->unknown_e_ = var4;
        data_02108d70.unknown_20_->unknown_a_ = var5;

        data_02108d70.unknown_20_->f0c = params[6].ToInt();

        const char* var6 = params[7].ToString();
        if (var6) {
            memcpy(data_02108d70.unknown_20_->name, var6, 0x20);
            data_02108d70.unknown_20_->name[0x1f] = 0;
        }

        const char* var7 = params[8].ToString();
        if (!var7) {
            return 0;
        }
        strcpy(data_02108d70.unknown_20_->desc, var7);

        data_02108d70.unknown_20_->unknown_3e_ = params[9].ToInt();
        data_02108d70.unknown_20_->f40 = params[10].ToInt();
        data_02108d70.unknown_20_->unknown_42_ = params[11].ToInt();
        params = params[12].ToVec3fix(&data_02108d70.unknown_20_->vec);
        data_02108d70.unknown_20_->unknown_54_ = _ffix(_fmul(4096.0f, params->ToFloat()));

        data_02108d70.unknown_20_->unknown_5_ = params[1].ToInt();
        data_02108d70.unknown_20_->f46 = params[2].ToInt();
        if (data_02108d70.unknown_20_->f46 >= 0) {
            data_02108d70.unknown_20_->f46 = data_02108d70.h4 - 1;
        }
        data_02108d70.unknown_20_->f4 = params[3].ToInt();
        data_02108d70.unknown_20_->unknown_6_ = params[4].ToInt();

        const char* var8 = params[5].ToString();
        if (var8) {
            memcpy(data_02108d70.unknown_20_->tag, var8, 0x10);
            data_02108d70.unknown_20_->tag[0xf] = 0;
        }

        data_02108d70.unknown_20_->unknown_44_ = params[6].ToInt();
        if (LinkSession_IsGuest(LinkSession_GetInstance())) {
            data_02108d70.unknown_20_->unknown_44_ = data_02108d70.unknown_20_->unknown_44_ & ~8;
        }

        data_02108d70.unknown_20_->f10 = params[7].ToInt();
        data_02108d70.unknown_c_ = 1;
    }
    return 1;
}