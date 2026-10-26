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

struct Struct0217f8c0;
extern "C" void* func_ov000_0217f8c0(struct Struct0217f8c0* s);
extern "C" void func_ov000_021781f8(void*, void*);
extern "C" int MessageSystem_GetInstance();
extern "C" void func_ov000_0217831c(void*, void*);
struct StructA0205d5d0;
// USA: func_ov000_0217819c
extern "C" ARM void func_ov000_0217819c(void* obj) {
    void* entry = func_ov000_0217f8c0((struct Struct0217f8c0*)obj);
    func_ov000_021781f8(obj, entry);
    void* buf = *(void**)(MessageSystem_GetInstance() + REGION_OFFSET_0);
    memset(buf, 0, REGION_OFFSET_1);
    func_ov000_0217831c(obj, buf);
#if defined(jpn)
    Window_SetPaneText((struct StructA0205d5d0*)((char*)obj + 0x188), 7, (int)buf, 1);
#else
    Window_SetPaneText((struct StructA0205d5d0*)((char*)obj + 0x188), 7, (int)buf, 1, 0);
#endif
}
