#include <globaldefs.h>

#if defined(jpn)
enum { kMetadataOffset = 0x4c };
#else
enum { kMetadataOffset = 0x6c };
#endif

#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Resource/GameResources.h"

struct HeadNode02046b24;
int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);

extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_0208f68c(void* obj);

// USA: func_0208f4e4
ARM void ProcessGrottoTurnEvent0208f4e4(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    void* miscPtr;
    void* headList;
    GameResources* res = GetGameResources();
    headList = res->fieldTaskQueue_;
    miscPtr = Zone3D_GetInstance();
    if (obj[0xb5]) {
        func_0208f68c(obj);
    }
    if (FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)headList) == 10) return;
    GrottoStruct* grotto = battle->GetGrottoStruct();
    TreasureMapMetadata* meta = (TreasureMapMetadata*)((char*)grotto + kMetadataOffset);
    unsigned short zoneId = *(unsigned short*)miscPtr;
    unsigned char state = meta->GetDiscoveryState();
    if (zoneId == *(int*)((char*)battle->GetGrottoStruct() + 0xc)) {
        ((Object3D*)(obj + 8))->AdvanceEffects();
    }
    if (grotto->unknown_0[0] != 0) {
        switch (state) {
            case 2:
            case 3:
                return;
        }
    }
    ((Object3D*)(obj + 8))->MakeHidden();
}
