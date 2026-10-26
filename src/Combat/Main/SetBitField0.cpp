#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);

// USA: func_020e36c4
ARM void SetBitField0_020e36c4(unsigned char* obj, int bit) {
    if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
        obj[0] |= 1 << bit;
    }
}
