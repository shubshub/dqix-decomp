#include <globaldefs.h>
#include <Resource/MessageSystem.h>

extern "C" int MessageSystem_GetInstance();

// USA: func_ov001_0215e900
extern "C" ARM int func_ov001_0215e900(void) {
    MessageSystem* messages = (MessageSystem*)MessageSystem_GetInstance();
    messages->unknown_19c0_ = 1;
    messages->unknown_195d_ = 30;
    return 1;
}
