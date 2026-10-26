#include <globaldefs.h>

extern "C" void* OamManager_GetInstance(void);
extern "C" void OamManager_GetSubOamBuffer(void* x);
extern "C" void OamManager_GetMainOamBuffer(void* x);

// USA: func_02093704
ARM void TeardownUnlessFlag02093704(int keepAlive) {
    void* x = OamManager_GetInstance();
    OamManager_GetSubOamBuffer(x);
    if (keepAlive != 0) return;
    OamManager_GetMainOamBuffer(x);
}
