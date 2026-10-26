#include <globaldefs.h>

#include "NitroSDK/IPC.h"

#if defined(jpn)
#define func_020d1118 func_020d2be4
#endif

void InitializeInterProcessorCommunication(void);
void SetArm9IPCCommandHandler(int, IPCCommandHandler);
extern "C" void func_020d1144(unsigned int, unsigned int, unsigned int);

struct Struct_02112140 { int done; void* callback; };
extern Struct_02112140 data_02112140;

// USA: func_020d1118
extern "C" ARM void func_020d1118(void) {
    InitializeInterProcessorCommunication();
    SetArm9IPCCommandHandler(0xe, (IPCCommandHandler)func_020d1144);
    data_02112140.callback = NULL;
}
