#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c9b20 {
    unsigned char tag;
    unsigned char pad[5];
    unsigned short field6;
    unsigned char pad2[2];
    unsigned char unknown_a_;
    unsigned char pad3[9];
};

// USA: func_ov017_021c9b20
extern "C" ARM void func_ov017_021c9b20(int a, int b) {
    Struct_ov017_021c9b20 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x57;
    buf.field6 = (unsigned short)a;
    buf.unknown_a_ = (unsigned char)b;
    func_0205e330(p, &buf, 0);
}
