#include <globaldefs.h>

extern "C" int OamManager_GetInstance(int a);
extern "C" int OamManager_GetSubOamBuffer(int obj);
extern "C" int OamManager_GetMainOamBuffer(int obj);

// USA: func_020db2dc
extern "C" ARM int func_020db2dc(int a, int b) {
    int obj = OamManager_GetInstance(a);
    int v = OamManager_GetSubOamBuffer(obj);
    if (b != 0) return v;
    return OamManager_GetMainOamBuffer(obj);
}
