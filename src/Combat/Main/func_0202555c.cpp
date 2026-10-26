#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Bcb8Params;
struct Entry_02027878 {
    char padding0[8];
    Bcb8Params* forwarding;
};
struct List_02027878;
struct BattleTimer0202441c;
struct Actor02024d48;
struct Struct_0202555c {
    int field_0x0;
    int entryIndex;
    int x;
    int y;
};
struct Struct_02000c9c_20 {
    char data[0x28];
};
struct Struct_0202555c_2 {
    char padding0[0x18];
    int forwardingX;
    int forwardingY;
    char unknown_20_[0xc];
    Struct_0202555c* forwarding;
    int forwardingCount;
    char unknown_34_[4];
    fix32_t scale;
    int tileX;
    int tileY;
    int screenX;
    int screenY;
    char unknown_4c_[0x74 - 0x4c];
    int forwardingFill;
    char unknown_78_[0x94 - 0x78];
    int bits94;
    char unknown_98_[0xe8 - 0x98];
    Struct_02000c9c_20 slots[1];
    char unknown_110_[0x55c - 0x110];
    unsigned char forwardingPending;
    char unknown_55d_[0x5b0 - 0x55d];
    fix32_t unknown_5b0_;
#if defined(jpn)
    char unknown_5b4_[0x914 - 0x5b4];
#else
    char unknown1_5b4_[0x9c0 - 0x5b4];
#endif
    unsigned char actionState;
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
extern "C" void SpriteContext_SetSpriteObjMode(int, void*, int);

// USA: func_0202555c
extern "C" ARM void func_0202555c(Struct_0202555c_2* self) {
    char* slotData;
    GameObject* object;
    void* displayState;
    int count;
    int screenX;
    fix32_t var5;
    int var6;
    int var7;
    int below;
    int above;
    fix32_t var10;
    int tileX;
    int tileY;
    int i;
    Entry_02027878* forwardEntry;
    int j;
    CombatActionPosition* entry;
    int x;
    int y;
    int group;
    int var20;
    fix32_t scale;
    object = GameState::GetInstance()->GetLeader();
    displayState = BgVram_GetInstance();
    Zone3D_GetInstance();
    Vector3i position = object->obj3D_.position_;
    CombatActionPosition entries[17];
    unsigned char groups[32];
    memset(groups, 0, sizeof(groups));
    count = MapDisplay_CollectIcons(entries, groups, &position);
    scale = self->scale;
    screenX = (int)((float)FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    var5 = self->unknown_5b0_;
    var6 = (int)((float)FIX32_MULTIPLY(self->unknown_5b0_, scale) / 4096.0f);
    var7 = (int)((float)FIX32_MULTIPLY(position.z, scale) / 4096.0f);
    below = var6 - var7;
    above = var7 - var6;
    if (above > 0x1e) {
        self->unknown_5b0_ += fix32_Divide((above - 0x1e) << 12, scale);
    } else if (below > 0x37) {
        self->unknown_5b0_ -= fix32_Divide((below - 0x37) << 12, scale);
    }
    var10 = FIX32_MULTIPLY(var5, self->unknown_5b0_);
    if (var10 < 0) {
        self->unknown_5b0_ = 0;
    }
    scale = self->scale;
    var6 = (int)((float)FIX32_MULTIPLY(self->unknown_5b0_, scale) / 4096.0f);
    tileX = screenX < 0 ? screenX / 8 - 1 : screenX / 8;
    tileY = var6 < 0 ? var6 / 8 - 1 : var6 / 8;
    if (self->forwardingY - tileY + 14 != 0 || var6 % 8 != 0) {
        if (above > 0) {
            self->unknown_5b0_ = fix32_Divide((var7 - 0x1e) << 12, scale);
        } else if (below > 0) {
            self->unknown_5b0_ = fix32_Divide((var7 + 0x37) << 12, scale);
        }
    }
    var6 = (int)((float)FIX32_MULTIPLY(self->unknown_5b0_, self->scale) / 4096.0f);
    tileY = var6 < 0 ? var6 / 8 - 1 : var6 / 8;
    self->screenX = screenX;
    self->screenY = var6;
    if (self->tileY != tileY) {
        self->forwardingPending = 1;
    }
    self->tileX = tileX;
    self->tileY = tileY;
    if (self->forwardingPending) {
        self->forwardingPending = 0;
        BgVram_FillMap(displayState, 1, 0, self->forwardingFill);
        for (i = 0; i < self->forwardingCount; ++i) {
            forwardEntry = MapDisplay_GetMapPiece((List_02027878*)self, self->forwarding[i].entryIndex);
            if (forwardEntry) {
                BgImage_Place((Bcb8Params*)((char*)forwardEntry + 8), self->forwarding[i].x,
                                    self->forwardingY + self->forwarding[i].y - tileY + 16);
            }
        }
    }
    MapDisplay_UpdateBlink((BattleTimer0202441c*)self);
    for (j = 0; j < count; ++j) {
        entry = &entries[j];
        if (!MapDisplay_IsMemberVisible(self, entry->combatantId)) {
            continue;
        }
        scale = self->scale;
        x = (int)((float)FIX32_MULTIPLY(entry->position.x, scale) / 4096.0f) - (self->forwardingX << 3);
        y = (int)((float)FIX32_MULTIPLY(entry->position.z, scale) / 4096.0f) - self->screenY;
        if (entry->variant >= 0) {
            group = groups[entry->group] - 1;
            x += data_020e70f0[group][entry->variant][0];
            y += data_020e70f4[group][entry->variant][0];
        }
        var20 = entry->type == 0x74;
        if (var20) {
            MapDisplay_DrawSprite(self, (x - 4) << 12, (y + 0x5c) << 12, entry->elementId, entry->type, 0,
                                     entry->palette, 0xff, 0x1000, 0x1000);
            continue;
        }
        if (!MapIcon_IsShownInBlinkPhase(entry, self->actionState)) {
            continue;
        }
        slotData = (char*)self->slots + (short)entry->elementId * (short)40;
        if (entry->flag13) {
            ColorEffect_ConfigureAlphaBlend(0x04001050, 0, 3, 8, 8);
            SpriteContext_SetSpriteObjMode((int)&self->bits94, slotData, 1);
        } else {
            SpriteContext_SetSpriteObjMode((int)&self->bits94, slotData, 0);
        }
        MapDisplay_DrawSprite(self, (x - 4) << 12, (y + 0x5c) << 12, entry->elementId, entry->type, 0,
                                 entry->palette, 0xff, 0x1000, 0x1000);
    }
    MapDisplay_DrawRedChestMarkers(self, self->forwardingX << 3, self->screenY, -4, 0x5c, 0);
    MapDisplay_DrawBattleMarkers(self, entries, count, self->forwardingX << 3, self->screenY, -4, 0x5c, 0);
}
