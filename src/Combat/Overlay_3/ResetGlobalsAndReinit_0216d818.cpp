// USA: func_ov003_0216d818
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

int MessageSystem_GetInstance();
void MessageSystem_Reset(char* obj);

struct Entry_0205d6a0;
void Window_ClosePane(struct Entry_0205d6a0* a, int flag);

extern "C" void func_ov003_0216d77c(void* obj);

ARM void ResetGlobalsAndReinit_0216d818(char* obj) {
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    MessageSystem_Reset((char*)MessageSystem_GetInstance());
#if defined(jpn)
    enum { entriesOffset = 0x1150 };
#else
    enum { entriesOffset = 0x12c0 };
#endif
    Window_ClosePane(*(struct Entry_0205d6a0**)(obj + entriesOffset), 0);
    func_ov003_0216d77c(obj);
}
