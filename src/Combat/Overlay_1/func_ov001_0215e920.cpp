#include <globaldefs.h>
#include <Resource/MessageSystem.h>

extern "C" int MessageSystem_GetInstance();

// USA: func_ov001_0215e920
extern "C" ARM int func_ov001_0215e920() {
    ((MessageSystem*)MessageSystem_GetInstance())->b19c1 = 1;
    return 1;
}
