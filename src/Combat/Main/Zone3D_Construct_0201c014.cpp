#include <globaldefs.h>

#include "Graphics/LightingInfo.h"
#include "Memory/SafeAllocator.h"
#include "Grotto/Main/FloorMap.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "World/ZoneFeatures.h"
#include "World/Zone3D.h"

extern "C" void __cxa_vec_ctor(void* obj, int a, int b, void* cb1, void* cb2);
extern "C" void* _ZN7Model3DC1Ev(void* obj);
extern "C" void* _ZN7Model3DD1Ev(void* obj);
extern "C" void* SprSprite_Destroy(void* obj);
extern "C" void* SprSprite_Construct(void* obj);

extern "C" void func_020982b4(void* obj);

struct InitState0208f7ecStruct;
extern "C" void func_0208f7ec(struct InitState0208f7ecStruct* s);

struct ClearThreeWords02094d00Struct;
extern "C" void GrottoChestList_Clear(struct ClearThreeWords02094d00Struct* s);

extern "C" void* ItemTable_Construct(void* obj);

extern "C" void Zone3D_Reset(void* obj);

// Main, originally InitBigStruct0201c014 (USA 0x0201c014, EUR 0x0201c024, JPN 0x0201bd8c)
extern "C" ARM void* Zone3D_Construct(void* zoneBytes) {
    Zone3D* zone = (Zone3D*)zoneBytes;
    zone->internalAllocator_.ResetAllocatorPointer();
    zone->substruct_6c_.Reset();
    zone->atmosphericEffects_.firstThing_ = 0;
    zone->lighting_.Initialize();
    __cxa_vec_ctor(zone->models_498_, 2, sizeof(Model3D), (void*)_ZN7Model3DC1Ev, (void*)_ZN7Model3DD1Ev);
    __cxa_vec_ctor(zone->lootIcons_, 4, sizeof(Foo02048004), (void*)SprSprite_Construct, (void*)SprSprite_Destroy);
    func_020982b4(zone->unk_840);
    ActiveGrottoClass* grotto = &zone->grotto_;
    grotto->floorMap_.Clear();
    grotto->Clear();
    func_0208f7ec((struct InitState0208f7ecStruct*)zone->unk_2664);
    GrottoChestList_Clear((struct ClearThreeWords02094d00Struct*)zone->grottoChestList_);
    ((SafeAllocator*)zone->unk_2730)->ResetAllocatorPointer();
    ItemTable_Construct(zone->containerItems_);
    Zone3D_Reset(zone);
    return zone;
}
