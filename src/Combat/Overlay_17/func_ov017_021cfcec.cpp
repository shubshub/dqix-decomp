#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cfcec {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char id;
    unsigned char pad1[14];
};

// USA: func_ov017_021cfcec
extern "C" ARM void func_ov017_021cfcec(unsigned char id) {
    if (LinkSession_IsGuest(LinkSession_GetInstance())) return;
    Struct_ov017_021cfcec buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0xa3;
    buf.id = id;
    func_0205e330(p, &buf, 0);
}
