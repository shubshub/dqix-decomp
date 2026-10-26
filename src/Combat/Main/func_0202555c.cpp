#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Struct_02020fc4_3;
struct Struct_02024518_3 {
    char unknown_0_[8];
    Struct_02020fc4_3* unknown_8_;
};
struct Struct_02024518_2;
struct Struct_0202441c;
struct Struct_02024d48;
struct Struct_0202555c {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
};
struct Struct_02000c9c_20 {
    char unknown_0_[0x28];
};
struct Struct_0202555c_2 {
    char unknown_0_[0x18];
    int unknown_18_;
    int unknown_1c_;
    char unknown_20_[0xc];
    Struct_0202555c* unknown_2c_;
    int unknown_30_;
    char unknown_34_[4];
    fix32_t unknown_38_;
    int unknown_3c_;
    int unknown_40_;
    int unknown_44_;
    int unknown_48_;
    char unknown_4c_[0x74 - 0x4c];
    int unknown_74_;
    char unknown_78_[0x94 - 0x78];
    int unknown_94_;
    char unknown_98_[0xe8 - 0x98];
    Struct_02000c9c_20 unknown_e8_[1];
    char unknown_110_[0x55c - 0x110];
    unsigned char unknown_55c_;
    char unknown_55d_[0x5b0 - 0x55d];
    fix32_t unknown_5b0_;
#if defined(jpn)
    char unknown_5b4_[0x914 - 0x5b4];
#else
    char unknown1_5b4_[0x9c0 - 0x5b4];
#endif
    unsigned char unknown_9c0_;
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
void SpriteContext_SetSpriteObjMode(int, void*, int);

// USA: func_0202555c
extern "C" ARM void func_0202555c(Receiver0202555c* self) {
    char* slotData;
    GameObject* object;
    void* displayState;
    int count;
    int screenX;
    fix32_t oldHeight;
    int cameraY;
    int objectY;
    int below;
    int above;
    fix32_t product;
    int tileX;
    int tileY;
    int i;
    Entry_02027878* forwardEntry;
    int j;
    CombatActionPosition* entry;
    int x;
    int y;
    int group;
    int isSpecial;
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
    oldHeight = self->cameraHeight;
    cameraY = (int)((float)FIX32_MULTIPLY(self->cameraHeight, scale) / 4096.0f);
    objectY = (int)((float)FIX32_MULTIPLY(position.z, scale) / 4096.0f);
    below = cameraY - objectY;
    above = objectY - cameraY;
    if (above > 0x1e) {
        self->cameraHeight += fix32_Divide((above - 0x1e) << 12, scale);
    } else if (below > 0x37) {
        self->cameraHeight -= fix32_Divide((below - 0x37) << 12, scale);
    }
    var10 = FIX32_MULTIPLY(var5, arg0->unknown_5b0_);
    if (var10 < 0) {
        arg0->unknown_5b0_ = 0;
    }
    var21 = arg0->unknown_38_;
    var6 = (int)((float)FIX32_MULTIPLY(arg0->unknown_5b0_, var21) / 4096.0f);
    var11 = var4 < 0 ? var4 / 8 - 1 : var4 / 8;
    var12 = var6 < 0 ? var6 / 8 - 1 : var6 / 8;
    if (arg0->unknown_1c_ - var12 + 14 != 0 || var6 % 8 != 0) {
        if (var9 > 0) {
            arg0->unknown_5b0_ = fix32_Divide((var7 - 0x1e) << 12, var21);
        } else if (var8 > 0) {
            arg0->unknown_5b0_ = fix32_Divide((var7 + 0x37) << 12, var21);
        }
    }
    var6 = (int)((float)FIX32_MULTIPLY(arg0->unknown_5b0_, arg0->unknown_38_) / 4096.0f);
    var12 = var6 < 0 ? var6 / 8 - 1 : var6 / 8;
    arg0->unknown_44_ = var4;
    arg0->unknown_48_ = var6;
    if (arg0->unknown_40_ != var12) {
        arg0->unknown_55c_ = 1;
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
        var21 = arg0->unknown_38_;
        var17 = (int)((float)FIX32_MULTIPLY(var16->unknown_0_.x, var21) / 4096.0f) - (arg0->unknown_18_ << 3);
        var18 = (int)((float)FIX32_MULTIPLY(var16->unknown_0_.z, var21) / 4096.0f) - arg0->unknown_48_;
        if (var16->unknown_f_ >= 0) {
            var19 = var24[var16->unknown_10_] - 1;
            var17 += data_020e70f0[var19][var16->unknown_f_][0];
            var18 += data_020e70f4[var19][var16->unknown_f_][0];
        }
        isSpecial = entry->type == 0x74;
        if (isSpecial) {
            MapDisplay_DrawSprite(self, (x - 4) << 12, (y + 0x5c) << 12, entry->elementId, entry->type, 0,
                                     entry->palette, 0xff, 0x1000, 0x1000);
            continue;
        }
        if (!MapIcon_IsShownInBlinkPhase(entry, self->actionState)) {
            continue;
        }
        var0 = (char*)arg0->unknown_e8_ + (short)var16->unknown_c_ * (short)40;
        if (var16->unknown_13_) {
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
