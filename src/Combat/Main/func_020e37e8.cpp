#include <globaldefs.h>

extern "C" int* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);

// USA: func_020e37e8
extern "C" ARM int func_020e37e8(unsigned char* p) {
    if (LinkSession_IsActive(LinkSession_GetInstance())) {
        return p[2];
    }
    return 1;
}
