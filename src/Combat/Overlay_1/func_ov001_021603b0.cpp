#include <globaldefs.h>
#include "Graphics/LightingManager.h"

extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_021603b0
extern "C" ARM int func_ov001_021603b0(void* obj) {
    int* p = (int*)LightingManager::GetInstance();
    func_ov017_021d60f4(obj);
    *(int*)((char*)p + 0x90) = 0;
    return 1;
}
