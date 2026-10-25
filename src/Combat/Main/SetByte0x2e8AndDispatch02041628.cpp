#include <globaldefs.h>
#include "World/Object3D.h"

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif

// USA: func_02041628
ARM void SetByte0x2e8AndDispatch02041628(void* obj, int v, int) {
    unsigned char* p = (unsigned char*)obj + RG(0x2e8, 0x2dc);
    *p = v;
    ((Object3D*)obj)->SetAnimationByIndex(*p, 0);
}
