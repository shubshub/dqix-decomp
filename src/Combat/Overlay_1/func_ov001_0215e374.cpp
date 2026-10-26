#include <globaldefs.h>
#include "Resource/MessageSystem.h"

extern "C" int MessageSystem_GetInstance();
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov001_0215e374
extern "C" ARM int func_ov001_0215e374(void* self) {
    MessageSystem* messages = (MessageSystem*)MessageSystem_GetInstance();
    func_ov017_021d6134(self, messages->unknown_19bd_);
    return 1;
}
