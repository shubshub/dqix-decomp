#include <globaldefs.h>

int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Stop(char* obj);
void MessageSystem_Reset(char* obj);

// USA: func_ov001_0215e398
ARM int Function_0215e398(void) {
	int v = MessageSystem_GetInstance();
	MessageSystem_Stop((char*)v);
	MessageSystem_Reset((char*)v);
	return 1;
}
