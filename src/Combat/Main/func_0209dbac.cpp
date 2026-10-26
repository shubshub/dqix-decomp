#include "Grotto/Main/ActiveGrottoClass.h"
#include <globaldefs.h>

#if defined(jpn)
enum { activeGrottoOffset = 0x240c };
#else
enum { activeGrottoOffset = 0x23EC };
#endif

extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov017_021d6134(void*, int);

// USA: func_0209dbac
extern "C" ARM int func_0209dbac(void* arg) {
    ActiveGrottoClass* g = (ActiveGrottoClass*)((char*)Zone3D_GetInstance() + activeGrottoOffset);
    if (g == NULL) return 0;
    DetailedTreasureMapData* r = g->GetDetailedData();
    if (r == NULL) return 0;
    if (r->mapType_ != 1) return 0;
    func_ov017_021d6134(arg, r->regular_.environ_);
    return 1;
}
