#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#endif

#include "std_library_functions.h"

int MessageSystem_GetInstance();
extern "C" void func_ov000_02176500(void* obj, void* buf, int flag);

struct StructA0205d5d0;
// USA: func_ov000_02176498
ARM void RunElemFieldsIfField_02176498_02176498(void* obj, int flag) {
    if (*(void**)((char*)obj + 0x38) != 0) {
        void* buf = *(void**)(MessageSystem_GetInstance() + REGION_OFFSET_0);
        memset(buf, 0, REGION_OFFSET_1);
        func_ov000_02176500(obj, buf, flag);
#if defined(jpn)
        Window_SetPaneText((struct StructA0205d5d0*)*(void**)((char*)obj + 0x38), 0xd, (int)buf, 1);
#else
        Window_SetPaneText((struct StructA0205d5d0*)*(void**)((char*)obj + 0x38), 0xd, (int)buf, 1, 0);
#endif
    }
}
