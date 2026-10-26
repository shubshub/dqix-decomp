#include <globaldefs.h>

extern "C" void VCountIrq_PushDisable(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int func_0205e218(void** p);
extern "C" void* LinkSession_GetOwnRecord(void* base);
extern "C" void VCountIrq_PopDisable(void);

struct Elem0205e488 {
    unsigned char pad[0x10];
    unsigned char field10;
    unsigned char pad2[0x14 - 0x11];
};

// USA: func_0205e488
extern "C" ARM int func_0205e488(void* obj) {
    VCountIrq_PushDisable();
    int result = 0;
    void* base = LinkSession_GetInstance();
    if (func_0205e218((void**)((char*)obj + 0x150c))) {
        result = 1;
        struct Elem0205e488* arr = (struct Elem0205e488*)LinkSession_GetOwnRecord(base);
        for (int i = 0; i < 5; i++) {
            if (arr[i].field10 != 0xff) {
                result = 0;
                break;
            }
        }
    }
    VCountIrq_PopDisable();
    return result;
}
