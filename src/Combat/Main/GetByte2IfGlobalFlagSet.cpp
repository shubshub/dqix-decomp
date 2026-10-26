#include <globaldefs.h>

extern "C" int* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);

// USA: func_020e37e8
ARM int GetByte2IfGlobalFlagSet_020e37e8(unsigned char* p) {
    if (LinkSession_IsActive(LinkSession_GetInstance())) {
        return p[2];
    }
    return 1;
}
