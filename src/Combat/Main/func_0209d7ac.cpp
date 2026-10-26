#include <globaldefs.h>
#include "Grotto/Main/ActiveGrottoClass.h"

#if defined(jpn)
enum { activeGrottoOffset = 0x240c };
#else
enum { activeGrottoOffset = 0x23ec };
#endif

extern "C" void* Zone3D_GetInstance();
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_0209d7ac
extern "C" ARM int func_0209d7ac(void* arg) {
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)Zone3D_GetInstance() + activeGrottoOffset);
    if (grotto == NULL) return 0;
    DetailedTreasureMapData* p = grotto->GetDetailedData();
    if (p == NULL) return 0;
    func_ov017_021d6134(arg, p->mapType_);
    return 1;
}
