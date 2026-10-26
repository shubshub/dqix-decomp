#include <globaldefs.h>
#include "World/ZoneLifecycle.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Resource/GameResources.h"
#include "World/Zone3D.h"
#include "World/FieldTask.h"

struct HeadNode02046b24;
struct EntryList0217208;
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
extern "C" void Zone3D_UpdateScriptNode(void* a, char* list);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void Zone3D_UpdateLoading(Zone3D* self);
extern "C" void Zone3D_UpdateLootables(struct EntryList0217208* self);
extern "C" void Zone3D_UpdateChests(Zone3D* self);
extern "C" void func_020a84e0();
extern "C" void Zone3D_SetVisitedFlag(void*);
extern "C" void Zone3D_StartPendingFieldTask(unsigned char*);

// Main, originally func_02015438 (USA 0x02015438, EUR 0x02015448, JPN 0x02015204)
extern "C" ARM void Zone3D_Update(Zone3D* self) {
    GameState* gameState = GameState::GetInstance();
    if (*(int*)&self->unk_428[0] == 0)
        return;

    if (self->unknown_424_ != 0) {
        Zone3D_UpdateLoading(self);
        return;
    }

    BmdjScriptNode* node = self->firstBMDJStruct_41c_;
    while (node != 0) {
        Zone3D_UpdateScriptNode(self, (char*)node);
        node = node->next;
    }

    unsigned char controlDelay = self->unk_830[0];
    if (controlDelay != 0) {
        controlDelay--;
        self->unk_830[0] = controlDelay;
        if ((self->unk_830[0] & 0xff) == 0) {
            void* protagonist = gameState->GetProtagonist();
            if (protagonist != 0) {
                if (FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)GetGameResources()->fieldTaskQueue_)
                        != FieldTaskKind_ScriptedEvent) {
                    GameObject_EnableControl(protagonist);
                }
            }
            self->unk_830[0] = 0;
        }
    }

    Zone3D_UpdateLootables((struct EntryList0217208*)self);
    Zone3D_UpdateChests(self);
    LightingManager::GetInstance()->RecomputeAdvancedLighting();
    func_020a84e0();
    Zone3D_SetVisitedFlag(self);
    Zone3D_StartPendingFieldTask((unsigned char*)self);
    func_0201bfd4(self);
}
