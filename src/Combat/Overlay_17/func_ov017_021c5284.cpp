#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void);
extern "C" void func_ov017_021cdaa0(void);

struct Struct_ov017_021b7284_10 {
    unsigned short field0;
    unsigned short field2;
    unsigned char field4;
    unsigned char field5;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
    unsigned short fielda;
    unsigned char fieldc;
};

struct Struct_ov017_021c5284 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned short field4;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
    unsigned short fielda;
    unsigned char fieldc;
    unsigned char unknown_d_;
    unsigned short unknown_e_;
    unsigned char field10;
};

// USA: func_ov017_021c5284
extern "C" ARM void func_ov017_021c5284(Struct_ov017_021b7284_10* src) {
    void* p = LinkMessageQueue_GetInstance();

    Struct_ov017_021c5284 buf;
    buf.tag = 0x3d;
    buf.field4 = src->field0;
    buf.field6 = src->field2;
    buf.field8 = src->field4;
    buf.field9 = src->field5;
    buf.fielda = src->field6;
    buf.fieldc = src->field8;
    buf.unknown_d_ = src->field9;
    buf.unknown_e_ = src->fielda;
    buf.field10 = src->fieldc;
    func_0205e330(p, &buf, 0);

    LinkSession_GetInstance();
    if (LinkSession_IsHostOrSolo()) {
        func_ov017_021cdaa0();
    }
}
