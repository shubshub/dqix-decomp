#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cd218 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned short unknown_4_0_ : 16;
    unsigned short unknown_6_0_ : 16;
    unsigned short unknown_8_0_ : 16;
    unsigned short unknown_a_0_ : 4;
    unsigned short unknown_a_4_ : 12;
    unsigned short unknown_c_0_ : 4;
    unsigned short unknown_c_4_ : 12;
    unsigned char unknown_e_[6];
};

// USA: func_ov017_021cd218
extern "C" ARM void func_ov017_021cd218(unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short e, unsigned short f) {
    void* data = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021cd218 var1;
    var1.unknown_0_ = 0x66;
    var1.unknown_4_0_ = arg0;
    var1.unknown_6_0_ = arg1;
    var1.unknown_8_0_ = arg2;
    var1.unknown_a_0_ = arg3;
    var1.unknown_c_0_ = arg4;
    var1.unknown_a_4_ = arg5;

    func_0205e330(var0, &var1, 0);
}
