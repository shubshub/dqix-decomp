#include <globaldefs.h>
#include "World/Object3D.h"

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif

// USA: func_02041640
extern "C" ARM void func_02041640(void* obj, int v, int) {
    int* p = (int*)((char*)obj + RG(0x2f4, 0x2e8));
    *p = v;
    ((Object3D*)obj)->SetAnimationByName((char const*)(*p), 0);
}
