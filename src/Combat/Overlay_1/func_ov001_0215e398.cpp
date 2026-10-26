#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Stop(char* obj);
extern "C" void MessageSystem_Reset(char* obj);

// USA: func_ov001_0215e398
extern "C" ARM int func_ov001_0215e398(void) {
	int v = MessageSystem_GetInstance();
	MessageSystem_Stop((char*)v);
	MessageSystem_Reset((char*)v);
	return 1;
}
