#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance();
extern "C" void func_0205e330(void* p, void* buf, int flag);

struct Struct_ov017_021d1014 {
    unsigned char low7 : 7;
    unsigned char unknown_0_7_ : 1;
    unsigned char unknown_1_;
};

struct Struct_ov017_021d1014_2 {
    unsigned char b0;
    unsigned char pad1[3];
    struct Struct_ov017_021d1014 sub;
    unsigned char pad2[0x14 - 6];
};

// USA: func_ov017_021d1014
extern "C" ARM void func_ov017_021d1014(int arg0, unsigned char arg1, int arg2) {
    void* g = LinkMessageQueue_GetInstance();
    struct Struct_ov017_021d1014_2 buf;
    struct Struct_ov017_021d1014* sub = &buf.sub;
    sub->low7 = arg0;
    buf.b0 = 0x19;
    sub->unknown_0_7_ = arg1;
    sub->unknown_1_ = arg2;
    func_0205e330(g, &buf, 0);
}
