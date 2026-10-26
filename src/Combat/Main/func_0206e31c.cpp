#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);

// USA: func_0206e31c
extern "C" ARM int func_0206e31c(int unused, int index) {
    if (LinkSession_IsGuest(LinkSession_GetInstance())) {
        if (index < 0xae) return 0;
    }
    return 1;
}
