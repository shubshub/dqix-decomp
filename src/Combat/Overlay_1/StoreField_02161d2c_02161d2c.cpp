#include <globaldefs.h>

extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_02161d2c
ARM int StoreField_02161d2c_02161d2c(void* obj) {
#if defined(jpn)
    enum { regionalFieldOffset = 0x78c };
#else
    enum { regionalFieldOffset = 0x74c };
#endif
    char* base = (char*)Zone3D_GetInstance();
    int v = func_ov017_021d60f4(obj);
    *(int*)(base + 0x2000 + regionalFieldOffset) = v;
    return 1;
}
