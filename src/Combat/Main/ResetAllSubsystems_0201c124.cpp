#include <globaldefs.h>

#if defined(jpn)
enum { threeWordsOffset = 0x2764, stateOffset = 0x26a4, blankTargetOffset = 0x860, nameTablesOffset = 0x620 };
#else
enum { threeWordsOffset = 0x2724, stateOffset = 0x2664, blankTargetOffset = 0x840, nameTablesOffset = 0x600 };
#endif
#include "Grotto/Main/FloorMap.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "World/Zone3D.h"

struct ClearThreeWords02094d00Struct;
struct InitState0208f7ecStruct;

void Zone3D_Unload(void* p, int n);
void GrottoChestList_Clear(ClearThreeWords02094d00Struct* p);
void InitState0208f7ec(InitState0208f7ecStruct* p);
void BlankFunction020984ac(void* p);
void SprSprite_Destroy(void* p);
extern "C" void* _ZN7Model3DD1Ev(void* obj);

extern "C" void func_0200ef44(void* p, int count, int size, void* fn);

// USA: func_0201c124  (semantic: ResetAllSubsystems_0201c124)
extern "C" ARM void* func_0201c124(Zone3D* self) {
    Zone3D_Unload(self, 1);
    GrottoChestList_Clear((ClearThreeWords02094d00Struct*)((char*)self + threeWordsOffset));
    InitState0208f7ec((InitState0208f7ecStruct*)((char*)self + stateOffset));
    self->grotto_.BlankFunction2();
    self->grotto_.floorMap_.Clear2();
    BlankFunction020984ac((char*)self + blankTargetOffset);
    func_0200ef44((char*)self + nameTablesOffset, 4, 0x88, (void*)SprSprite_Destroy);
    func_0200ef44(self->models_498_, 2, 0xac, (void*)_ZN7Model3DD1Ev);
    self->lighting_.Initialize();
    self->substruct_6c_.Reset();
    return self;
}
