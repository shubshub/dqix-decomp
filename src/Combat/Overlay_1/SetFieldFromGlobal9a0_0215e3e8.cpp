#include <globaldefs.h>

int MessageSystem_GetInstance();
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_0215e3e8  (semantic: SetFieldFromGlobal9a0_0215e3e8)
extern "C" ARM int func_ov001_0215e3e8(void* obj) {
#if defined(jpn)
    enum { fieldOffset = 0x870 };
#else
    enum { fieldOffset = 0x9a0 };
#endif
    int p = MessageSystem_GetInstance();
    if (p == 0) return 0;
    int v = *(int*)(p + fieldOffset);
    func_ov017_021d6134(obj, v);
    return 1;
}
