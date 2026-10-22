#include <globaldefs.h>

#if defined(jpn)
#define data_ov003_02180cc8 data_ov003_0217ef40
#define data_ov003_02180aa4 data_ov003_0217ed08
#endif

struct Struct_020e28dc;
struct Struct_020e263c_2;
struct Struct_0207fc6c;

struct Struct_ov003_021745fc {
#if defined(jpn)
    char unknown_0_[0x2a];
#else
    char unknown1_0_[0x36];
#endif
    short unknown_36_;
};

class Struct_ov003_021745fc_2 {
public:
    Struct_020e28dc* unknown_0_;
#if defined(jpn)
    char unknown_4_[0x808 - 0x4];
#else
    char unknown1_4_[0x88c - 0x4];
#endif
    char unknown_88c_[0xc];
    unsigned short unknown_898_;
    unsigned char unknown_89a_;
    char unknown_89b_;
    Struct_ov003_021745fc* unknown_89c_;
    char unknown_8a0_[0xfe0 - 0x8a0];
    int unknown_fe0_;
    int unknown_fe4_;
    char unknown_fe8_[0xff8 - 0xfe8];
    short* unknown_ff8_;
    short unknown_ffc_;
    short unknown_ffe_;
    short unknown_1000_;
    char unknown_1002_[0x1036 - 0x1002];
    short unknown_1036_;
    char unknown_1038_[0x103e - 0x1038];
    unsigned char unknown_103e_;
    char unknown_103f_[0x1046 - 0x103f];
    unsigned short unknown_1046_;
};

typedef void (Struct_ov003_021745fc_2::*Type_020200c0)();

extern "C" {
bool func_ov017_021959b4();
void func_ov003_02174550(Struct_ov003_021745fc_2* arg0);
void func_ov003_021749f0(Struct_ov003_021745fc_2* arg0);
void func_ov003_021760cc(Struct_ov003_021745fc_2* arg0);
void func_02081f20(void* arg0, int arg1);
int func_020800fc(Struct_ov003_021745fc* arg0, short* arg1, short arg2, unsigned short arg3, unsigned char, bool);
void func_020813ec(Struct_ov003_021745fc* arg0, short arg1);
}

extern "C" void func_ov003_02174988(char* arg0);
extern "C" void func_ov003_0217451c(char* arg0);
extern "C" int func_020421a0();
extern "C" void func_02043204(char* arg0);
extern "C" void func_0207fc6c(Struct_0207fc6c* arg0, int arg1);
extern "C" void func_020804fc(void* arg0, int arg1);
extern "C" int func_020e28dc(Struct_020e28dc* arg0);
extern "C" void func_020e263c(Struct_020e263c_2* arg0, int arg1);

extern unsigned int data_ov003_02180cc8[2];
extern StateFn021745fc __ptmf_null;
extern StateFn021745fc data_ov003_02180aa4[10];

// USA: func_ov003_021745fc
extern "C" ARM bool func_ov003_021745fc(Struct_ov003_021745fc_2* arg0, int arg1) {
    arg0->unknown_fe0_ = arg1;
    if (func_ov017_021959b4())
        func_ov003_02174550(arg0);
    func_ov003_021749f0(arg0);
    func_ov003_02174988((char*)arg0);
    func_ov003_0217451c((char*)arg0);

    if (arg0->unknown_103e_ != 0) {
        if (arg0->unknown_1036_ >= 0) {
            func_ov003_021760cc(arg0);
            return false;
        }
#if defined(jpn)
        ((unsigned char*)func_020421a0())[0x17de] = 0;
#else
        ((unsigned char*)func_020421a0())[0x19ae] = 0;
#endif
        Struct_ov003_021745fc* var0 = arg0->unknown_89c_;
        if (var0 != NULL)
            func_0207fc6c((Struct_0207fc6c*)var0, arg1);
        if (arg0->unknown_ff8_ != NULL) {
            func_02081f20(arg0->unknown_88c_, arg1);
            arg0->unknown_1000_ = *arg0->unknown_ff8_;
            arg0->unknown_fe4_ = func_020800fc(var0, arg0->unknown_ff8_, arg0->unknown_1000_, arg0->unknown_898_, arg0->unknown_89a_, (arg0->unknown_1046_ & 0x400) != 0);
            var0->unknown_36_ = *arg0->unknown_ff8_;
            if (arg0->unknown_fe4_ != 0)
                func_020804fc(var0, arg0->unknown_ffe_);
            if (arg0->unknown_1000_ != *arg0->unknown_ff8_)
                func_020813ec(var0, arg0->unknown_ffe_);
        }
    }

    if (arg0->unknown_0_ != NULL && func_020e28dc(arg0->unknown_0_))
        func_020e263c((Struct_020e263c_2*)arg0->unknown_0_, arg0->unknown_fe0_);

    if (!(data_ov003_02180cc8[0] & 1)) {
        data_ov003_02180aa4[9] = __ptmf_null;
        data_ov003_02180cc8[0] |= 1;
    }
    if (data_ov003_02180aa4[arg0->unknown_103e_] == NULL) {
        func_02043204((char*)func_020421a0());
        return !(arg0->unknown_1046_ & 0x80);
    }
    (arg0->*data_ov003_02180aa4[arg0->unknown_103e_])();
    return false;
}
