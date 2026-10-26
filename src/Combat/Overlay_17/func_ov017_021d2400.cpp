#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d2400 {
    unsigned char tag;
    unsigned char pad[19];
};

// USA: func_ov017_021d2400
extern "C" ARM void func_ov017_021d2400(void) {
    Struct_ov017_021d2400 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x1b;
    func_0205e330(p, &buf, 0);
}
