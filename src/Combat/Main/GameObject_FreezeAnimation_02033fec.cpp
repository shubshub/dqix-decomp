#include <globaldefs.h>
#include "World/Object3D.h"
#include "Combat/ObjectStateInitialization.h"
struct ObjectStatePrefix;

// Main, originally SetBits0x40000AndFlag0x2_02033fec (USA 0x02033fec, EUR 0x02033ffc, JPN 0x02033b24)
extern "C" ARM void GameObject_FreezeAnimation(ObjectStatePrefix* arg0) {
    unsigned char* obj = (unsigned char*)arg0;
    arg0->object.EnableFlag(0x40000);
    obj[0xe0] |= 0x2;
}
