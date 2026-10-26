#include <globaldefs.h>
#include <Resource/MessageSystem.h>

extern "C" int MessageSystem_GetInstance();

// USA: func_ov001_0215e960
extern "C" ARM int func_ov001_0215e960(void) {
    ((MessageSystem*)MessageSystem_GetInstance())->b19ca = 0;
    return 1;
}
