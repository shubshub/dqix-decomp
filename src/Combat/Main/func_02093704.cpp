#include <globaldefs.h>

extern "C" void* OamManager_GetInstance(void);
extern "C" void OamManager_GetSubOamBuffer(void* x);
extern "C" void OamManager_GetMainOamBuffer(void* x);

// USA: func_02093704
extern "C" ARM void func_02093704(int arg0) {
    void* x = OamManager_GetInstance();
    OamManager_GetSubOamBuffer(x);
    if (arg0 != 0) return;
    OamManager_GetMainOamBuffer(x);
}
