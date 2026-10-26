#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" int func_ov004_02164738(void* obj);

// USA: func_ov004_02165be4
extern "C" ARM int func_ov004_02165be4(void* a1) {
    MessageSystem_Reset((char*)MessageSystem_GetInstance());
    func_ov004_02164738(a1);
    return 0;
}
