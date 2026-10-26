#include <globaldefs.h>

extern "C" void* MessageSystem_GetInstance();
extern "C" void MessageSystem_Stop(void* obj);

// USA: func_ov025_021e5f40
extern "C" ARM int func_ov025_021e5f40() {
    MessageSystem_Stop(MessageSystem_GetInstance());
    return 1;
}
