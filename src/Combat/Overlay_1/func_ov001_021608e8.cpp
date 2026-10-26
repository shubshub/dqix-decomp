#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance();
extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_021608e8
extern "C" ARM int func_ov001_021608e8(void* obj) {
#if defined(jpn)
    enum { fieldOffset = 0x86c };
#else
    enum { fieldOffset = 0x99c };
#endif
    int v = func_ov017_021d60f4(obj);
    *(int*)(MessageSystem_GetInstance() + fieldOffset) = v;
    return 1;
}
