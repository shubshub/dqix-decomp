#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021d3e3c {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char id;
    unsigned char pad1[14];
};

// USA: func_ov017_021d3e3c
ARM void EnqueueEventTag186_021d3e3c(unsigned char id) {
    if (LinkSession_IsGuest(LinkSession_GetInstance())) return;
    LocalEvt021d3e3c buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0xba;
    buf.id = id;
    func_0205e330(p, &buf, 0);
}
