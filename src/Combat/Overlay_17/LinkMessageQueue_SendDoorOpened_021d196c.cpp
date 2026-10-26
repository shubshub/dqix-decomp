#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d196c {
    unsigned short v0;
    unsigned short v2;
    int v4;
};

struct LocalEvt021d196c {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021d196c sub;
    unsigned char pad2[8];
};

// Overlay 17, originally EnqueueEventTag175_021d196c (USA/EUR 0x021d196c, JPN 0x021d1df0)
ARM void LinkMessageQueue_SendDoorOpened(unsigned short a, unsigned short b, int c) {
    LocalEvt021d196c buf;
    void* p = LinkMessageQueue_GetInstance();
    Sub021d196c* s = &buf.sub;
    buf.tag = 0xaf;
    s->v0 = a;
    s->v2 = b;
    s->v4 = c;
    func_0205e330(p, &buf, 0);
}
