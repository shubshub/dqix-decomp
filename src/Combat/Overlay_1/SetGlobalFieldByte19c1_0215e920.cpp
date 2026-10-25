#include <globaldefs.h>
#include <Resource/MessageSystem.h>

int MessageSystem_GetInstance();

// KEEP-NAME
// USA: func_ov001_0215e920
ARM int SetGlobalFieldByte19c1_0215e920() {
    ((MessageSystem*)MessageSystem_GetInstance())->b19c1 = 1;
    return 1;
}
