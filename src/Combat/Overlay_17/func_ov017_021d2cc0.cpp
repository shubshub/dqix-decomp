#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void func_ov017_021d2d00(void* dst, void* src);

struct Struct_ov017_021d2cc0 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char payload[16];
};

// USA: func_ov017_021d2cc0
extern "C" ARM void func_ov017_021d2cc0(void* src) {
    Struct_ov017_021d2cc0 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x25;
    func_ov017_021d2d00(&buf.payload, src);
    func_0205e330(p, &buf, 0);
}
