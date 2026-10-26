#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d3ec8 {
    unsigned char tag;
    unsigned char pad[0x13];
};

// USA: func_ov017_021d3ec8
extern "C" ARM void func_ov017_021d3ec8(void) {
    Struct_ov017_021d3ec8 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0xa7;
    func_0205e330(p, &buf, 0);
}
