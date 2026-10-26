#include <globaldefs.h>

extern "C" void LinkMessageQueue_Reset(void* p);

// USA: func_0205e324
ARM void ResetBattleSections0205e324(void* p) {
    LinkMessageQueue_Reset(p);
}
