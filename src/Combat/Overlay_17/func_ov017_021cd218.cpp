#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cd218 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short field4 : 16;
    unsigned short field6 : 16;
    unsigned short field8 : 16;
    unsigned short unknown_a_0_ : 4;
    unsigned short unknown_a_4_ : 12;
    unsigned short unknown_c_0_ : 4;
    unsigned short unknown_c_4_ : 12;
    unsigned char pad2[6];
};

// USA: func_ov017_021cd218
extern "C" ARM void func_ov017_021cd218(unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short e, unsigned short f) {
    void* data = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021cd218 evt;
    evt.tag = 0x66;
    evt.field4 = a;
    evt.field6 = b;
    evt.field8 = c;
    evt.unknown_a_0_ = d;
    evt.unknown_c_0_ = e;
    evt.unknown_a_4_ = f;

    func_0205e330(data, &evt, 0);
}
