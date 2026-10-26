#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);

// USA: func_ov011_02187460
extern "C" ARM int func_ov011_02187460(void) {
    char* obj = (char*)MessageSystem_GetInstance();
    MessageSystem_Reset(obj);
    MessageSystem_Stop(obj);
    return 1;
}
