#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* state);

struct Struct_ov017_021ce400 {
    unsigned char tag;
    unsigned char pad0[3];
    short field4;
    short field6;
    unsigned char pad1[12];
};

// USA: func_ov017_021ce400
extern "C" ARM void func_ov017_021ce400(int a, int b) {
    void* p = LinkMessageQueue_GetInstance();
    if (LinkSession_IsHostOrSolo(LinkSession_GetInstance()) != 0 && a > 0) {
        Struct_ov017_021ce400 buf;
        buf.tag = 0x27;
        buf.field4 = a;
        buf.field6 = b;
        func_0205e330(p, &buf, 0);
    }
}
