#include <globaldefs.h>

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};

extern "C" int* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021d1cb8 {
    unsigned char tag;
    char pad[19];
};

// USA: func_ov017_021d1cb8
ARM void CheckAndEnqueueTag_021d1cb8_021d1cb8(void) {
    if (!LinkSession_IsActive(LinkSession_GetInstance())) return;
    if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)LinkSession_GetInstance()) != 0) return;
    void* p = LinkMessageQueue_GetInstance();

    struct LocalEvt021d1cb8 buf;
    buf.tag = 0xb4;
    func_0205e330(p, &buf, 0);
}
