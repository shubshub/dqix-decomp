#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c530c_2 { unsigned short unknown_0_; unsigned short w2; unsigned char unknown_4_; unsigned char unknown_5_; unsigned char unknown_6_; };

struct Struct_ov017_021c5f00 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned short field4;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
    unsigned char fielda;
    unsigned char pad2[9];
};

// USA: func_ov017_021c5f00
extern "C" ARM void func_ov017_021c5f00(Struct_ov017_021c530c_2* src) {
    Struct_ov017_021c5f00 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x3f;
    buf.field4 = src->unknown_0_;
    buf.field6 = src->w2;
    buf.field8 = src->unknown_4_;
    buf.field9 = src->unknown_5_;
    buf.fielda = src->unknown_6_;
    func_0205e330(p, &buf, 0);
}
