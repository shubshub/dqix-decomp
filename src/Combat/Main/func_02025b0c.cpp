#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "Combat/MapDisplay.h"
#include "GameState/GameState.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Bcb8Params;
struct Entry_02027878;
struct List_02027878;
struct BattleTimer0202441c;
struct Actor02024d48;
struct ForwardingRecord02024518 {
    int unknown0;
    int entryIndex;
    int x;
    int y;
};
extern "C" void* BgVram_GetInstance();
extern "C" void* Zone3D_GetInstance();
extern "C" void BgVram_FillMap(void*, int, int, int);
extern "C" Entry_02027878* MapDisplay_GetMapPiece(List_02027878*, int);
extern "C" void BgImage_Place(Bcb8Params*, int, int);
extern "C" void MapDisplay_UpdateBlink(BattleTimer0202441c*);
extern "C" int MapDisplay_IsMemberVisible(void*, int);
extern "C" int MapIcon_IsShownInBlinkPhase(CombatActionPosition*, int);
extern "C" void MapDisplay_DrawSprite(void*, int, int, int, unsigned char, unsigned char, unsigned short, unsigned char, int, int);

// USA: func_02025b0c
extern "C" ARM void func_02025b0c(MapDisplay* self) {
    GameObject* object = GameState::GetInstance()->GetLeader();
    void* displayState = BgVram_GetInstance();
    Zone3D_GetInstance();
    Vector3i position = object->obj3D_.position_;
    CombatActionPosition entries[17];
    unsigned char groups[32];
    memset(groups, 0, sizeof(groups));
    int count = MapDisplay_CollectIcons(entries, groups, &position);
    int screenX;
    int var7;
    fix32_t scale;
    scale = self->scale;
    screenX = (int)((float)FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    var7 = (int)((float)FIX32_MULTIPLY(self->cameraZ, scale) / 4096.0f);
    int var9 = (int)((float)FIX32_MULTIPLY(position.y, scale) / 4096.0f);
    if (var7 - var9 > 5 || var9 - var7 > 5) {
        if (var9 < var7) {
            self->cameraZ -= fix32_Divide((var7 - var9 - 5) << 12, scale);
        } else {
            self->cameraZ += fix32_Divide((var9 - var7 - 5) << 12, scale);
        }
    }
    var7 = (int)((float)FIX32_MULTIPLY(self->cameraZ, self->scale) / 4096.0f);
    self->screenX = screenX;
    self->screenY = var7;
    int tileY = var7 < 0 ? var7 / 8 - 1 : var7 / 8;
    self->forwardingPending = 0;
    BgVram_FillMap(displayState, 1, 0, self->forwardingFill);
    for (int i = 0; i < self->forwardingCount; ++i) {
        Entry_02027878* entry = MapDisplay_GetMapPiece((List_02027878*)self, self->forwarding[i].entryIndex);
        if (entry) {
            int forwardY = self->forwardingY + self->forwarding[i].y;
            int forwardX = self->forwardingX + self->forwarding[i].x;
            BgImage_Place(reinterpret_cast<Bcb8Params*>(reinterpret_cast<unsigned char*>(entry) + 8), forwardX + 16, tileY + forwardY + 16);
        }
    }
    MapDisplay_UpdateBlink((BattleTimer0202441c*)self);
    for (int i = 0; i < count; ++i) {
        CombatActionPosition* entry = &entries[i];
        if (!MapDisplay_IsMemberVisible(self, entry->combatantId)) {
            continue;
        }
        fix32_t var17 = self->scale;
        int x = (int)((float)FIX32_MULTIPLY(entry->position.x, var17) / 4096.0f);
        int y = -((int)((float)FIX32_MULTIPLY(entry->position.y, var17) / 4096.0f) - self->screenY);
        if (entry->variant >= 0) {
            int group = groups[entry->group] - 1;
            x += data_020e70f0[group][entry->variant][0];
            y -= data_020e70f4[group][entry->variant][0];
        }
        if (self->flags & 1) {
            if (inline_02024518(entry->type)) {
                continue;
            }
        }
        if (!MapIcon_IsShownInBlinkPhase(entry, self->actionState)) {
            continue;
        }
        MapDisplay_DrawSprite(self, (x + 0x7c) << 12, (y + 0x5c) << 12,
            entry->elementId, entry->type, 0, entry->palette, 0xff, 0x1000, 0x1000);
    }
    MapDisplay_DrawRedChestMarkers(self, 0, self->screenY, 0x7c, 0x5c, 1);
    MapDisplay_DrawBattleMarkers(self, entries, count, 0, self->screenY, 0x7c, 0x5c, 1);
}
