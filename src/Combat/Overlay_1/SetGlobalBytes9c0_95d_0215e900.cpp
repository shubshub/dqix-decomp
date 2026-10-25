#include <globaldefs.h>
#include <Resource/MessageSystem.h>

int MessageSystem_GetInstance();

// USA: func_ov001_0215e900  (semantic: SetGlobalBytes9c0_95d_0215e900)
extern "C" ARM int func_ov001_0215e900(void) {
    MessageSystem* messages = (MessageSystem*)MessageSystem_GetInstance();
    messages->b19c0 = 1;
    messages->b195d = 30;
    return 1;
}
