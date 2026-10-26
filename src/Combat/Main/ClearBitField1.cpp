#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);

// USA: func_020e3748
ARM void ClearBitField1_020e3748(unsigned char* obj, int bit) {
    if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
        obj[1] &= ~(1 << bit);
    }
}
