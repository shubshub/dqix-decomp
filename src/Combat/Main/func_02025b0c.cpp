#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "Combat/MapDisplay.h"
#include "GameState/GameState.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Struct_02020fc4_3;
struct Struct_02024518_3;
struct Struct_02024518_2;
struct Struct_0202441c;
struct Struct_02024d48;
struct Struct_02024518 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
};
void* BgVram_GetInstance();
extern "C" void* Zone3D_GetInstance();
void BgVram_FillMap(void*, int, int, int);
Entry_02027878* MapDisplay_GetMapPiece(List_02027878*, int);
void BgImage_Place(Bcb8Params*, int, int);
void MapDisplay_UpdateBlink(BattleTimer0202441c*);
int MapDisplay_IsMemberVisible(void*, int);
int MapIcon_IsShownInBlinkPhase(CombatActionPosition*, int);
void MapDisplay_DrawSprite(void*, int, int, int, unsigned char, unsigned char, unsigned short, unsigned char, int, int);

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
    int cameraY;
    fix32_t scale;
    scale = self->scale;
    screenX = (int)((float)FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    cameraY = (int)((float)FIX32_MULTIPLY(self->cameraZ, scale) / 4096.0f);
    int objectY = (int)((float)FIX32_MULTIPLY(position.y, scale) / 4096.0f);
    if (cameraY - objectY > 5 || objectY - cameraY > 5) {
        if (objectY < cameraY) {
            self->cameraZ -= fix32_Divide((cameraY - objectY - 5) << 12, scale);
        } else {
            arg0->unknown_5b0_ += fix32_Divide((var9 - var7 - 5) << 12, var8);
        }
    }
    cameraY = (int)((float)FIX32_MULTIPLY(self->cameraZ, self->scale) / 4096.0f);
    self->screenX = screenX;
    self->screenY = cameraY;
    int tileY = cameraY < 0 ? cameraY / 8 - 1 : cameraY / 8;
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
        fix32_t var17 = arg0->unknown_38_;
        int var18 = (int)((float)FIX32_MULTIPLY(var16->unknown_0_.x, var17) / 4096.0f);
        int var19 = -((int)((float)FIX32_MULTIPLY(var16->unknown_0_.y, var17) / 4096.0f) - arg0->unknown_48_);
        if (var16->unknown_f_ >= 0) {
            int var20 = var4[var16->unknown_10_] - 1;
            var18 += data_020e70f0[var20][var16->unknown_f_][0];
            var19 -= data_020e70f4[var20][var16->unknown_f_][0];
        }
        if (arg0->unknown_5a4_ & 1) {
            if (inline_02024518(var16->unknown_e_)) {
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
