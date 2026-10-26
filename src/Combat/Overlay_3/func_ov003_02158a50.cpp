// USA: func_ov003_02158a50
#include <globaldefs.h>
#include "World/Object3D.h"
#if defined(jpn)
enum { kRegion280 = 0x27c };
enum { Enum_ov003_02158a50_812 = 0x328 };
#else
enum { kRegion280 = 0x280 };
enum { Enum_ov003_02158a50_812 = 0x32c };
#endif

extern unsigned char data_ov003_0217fe16;

extern "C" ARM void func_ov003_02158a50(unsigned char* obj) {
    ((Object3D*)(obj + kRegion280))->SetAnimationByName((char const*)&data_ov003_0217fe16, 9);
    ((Object3D*)(obj + kRegion280))->DisableFlag(0x40000);
    *(int*)(obj + Enum_ov003_02158a50_812) = 1;
}
