#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);

// USA: func_020e3368
ARM void StoreInFirstEmptySlot_020e3368(unsigned char* base, unsigned char val) {
    unsigned char* p;
    int i;
    if (!LinkSession_IsActive((int*)LinkSession_GetInstance())) return;
    p = base + 0x20;
    for (i = 0; i < 8; i++, p++) {
        if (*p == 0) {
            *p = val;
            return;
        }
    }
}
