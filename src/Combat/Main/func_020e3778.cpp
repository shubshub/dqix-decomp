#include <globaldefs.h>

extern "C" int* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);

// USA: func_020e3778
extern "C" ARM void func_020e3778(unsigned char* p) {
    if (LinkSession_IsActive(LinkSession_GetInstance())) {
        p[2] = 1;
    }
}
