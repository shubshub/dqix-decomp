#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cea8c {
    unsigned char tag;
    unsigned char pad[0x13];
};

// USA: func_ov017_021cea8c
extern "C" ARM void func_ov017_021cea8c(void) {
    Struct_ov017_021cea8c buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x32;
    func_0205e330(p, &buf, 0);
}
