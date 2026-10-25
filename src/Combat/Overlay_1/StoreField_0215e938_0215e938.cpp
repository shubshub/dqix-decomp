#include <globaldefs.h>
#include <Resource/MessageSystem.h>

int MessageSystem_GetInstance();
extern "C" int func_ov017_021d60f4(void*);

// KEEP-NAME
// USA: func_ov001_0215e938
ARM int StoreField_0215e938_0215e938(void* obj) {
    MessageSystem* messages = (MessageSystem*)MessageSystem_GetInstance();
    messages->b19ae = func_ov017_021d60f4(obj);
    return 1;
}
