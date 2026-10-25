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
extern "C" void func_ov000_02179a70(void*, int, int, void*);
struct StructA0205d5d0;
// USA: func_ov000_02179a14
ARM void ApplyElemFieldsSlot18_02179a14(void* obj, int a, int b) {
    void* buf = *(void**)(MessageSystem_GetInstance() + REGION_OFFSET_0);
    memset(buf, 0, REGION_OFFSET_1);
    func_ov000_02179a70(obj, a, b, buf);
#if defined(jpn)
    Window_SetPaneText((struct StructA0205d5d0*)((char*)obj + 0x188), 0x12, (int)buf, 1);
#else
    Window_SetPaneText((struct StructA0205d5d0*)((char*)obj + 0x188), 0x12, (int)buf, 1, 0);
#endif
}
