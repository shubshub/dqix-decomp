#include <globaldefs.h>
#include <Resource/MessageSystem.h>

extern "C" int MessageSystem_GetInstance();
extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_0215e938
extern "C" ARM int func_ov001_0215e938(void* obj) {
    MessageSystem* messages = (MessageSystem*)MessageSystem_GetInstance();
    messages->unknown_19ae_ = func_ov017_021d60f4(obj);
    return 1;
}
