#include <globaldefs.h>

#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_02024e78_2496 = 0x914 };
#else
enum { Enum_02024e78_2496 = 0x9c0 };
#endif

struct Struct_02024e78 {
    int unknown0;
    int index;
    int parameter1;
    int unknown_c_;
};

struct Struct_02024e78_2 {
    unsigned char unknown0[0x18];
    int tileX;
    int tileY;
    unsigned char unknown20[0xc];
    Struct_02024e78 *forwardingEntries;
    int forwardingCount;
    unsigned char unknown34[4];
    fix32_t scale;
    unsigned char unknown_3c_[8];
    int originX;
    int originY;
    unsigned char unknown4c[0x510];
    unsigned char unknown_55c_;
    unsigned char unknown_55d_[0x47];
    int flags;
    unsigned char unknown_5a8_[Enum_02024e78_2496 - 0x5a8];
    unsigned char actionState;
};

struct List_02027878;
struct Entry_02027878;
struct Bcb8Params;
struct BattleTimer0202441c;
struct Actor02024d48;

extern "C" void *BgVram_GetInstance();
extern "C" void *Zone3D_GetInstance();
extern "C" void BgVram_FillMap(void *owner, int mode, int index, int value);
extern "C" Entry_02027878 *MapDisplay_GetMapPiece(List_02027878 *list, int index);
extern "C" void BgImage_Place(Bcb8Params *params, int a, int b);
extern "C" void MapDisplay_UpdateBlink(BattleTimer0202441c *receiver);
extern "C" int MapDisplay_IsMemberVisible(void *receiver, int combatantId);
extern "C" int MapIcon_IsShownInBlinkPhase(CombatActionPosition* entry, int state);
extern "C" void MapDisplay_DrawSprite(void *receiver, int x, int y, int index, unsigned char type, unsigned char flags,
                              unsigned short palette, unsigned char arg7, int scaleX, int scaleY);

// USA: func_02024e78
extern "C" ARM void func_02024e78(void *receiver) {
    Struct_02024e78_2 *obj = static_cast<Struct_02024e78_2 *>(receiver);
    GameObject *actor             = GameState::GetInstance()->GetLeader();
    void *resourceData            = BgVram_GetInstance();
    Zone3D_GetInstance();
    Vector3i position = actor->obj3D_.position_;
    CombatActionPosition entries[17];
    unsigned char groups[32];
    memset(groups, 0, sizeof(groups));
    int count     = MapDisplay_CollectIcons(entries, groups, &position);
    fix32_t scale = obj->scale;
    int originX   = (int) ((float) FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    int originY   = (int) ((float) FIX32_MULTIPLY(position.z, scale) / 4096.0f);
    obj->originX  = originX;
    obj->originY  = originY;

    if (obj->unknown_55c_) {
        obj->unknown_55c_ = 0;
        BgVram_FillMap(resourceData, 1, 0, 0);
        for (int i = 0; i < obj->forwardingCount; i++) {
            Entry_02027878 *entry = MapDisplay_GetMapPiece(static_cast<List_02027878 *>(receiver), obj->forwardingEntries[i].index);
            if (entry) {
                BgImage_Place(reinterpret_cast<Bcb8Params *>((char *) entry + 8), obj->forwardingEntries[i].parameter1,
                                    obj->forwardingEntries[i].unknown_c_);
            }
        }
    }
    MapDisplay_UpdateBlink(static_cast<BattleTimer0202441c *>(receiver));
    for (int i = 0; i < count; i++) {
        CombatActionPosition *entry = &entries[i];
        if (!MapDisplay_IsMemberVisible(receiver, entry->combatantId)) continue;
        fix32_t scale = obj->scale;
        int x         = (int) ((float) FIX32_MULTIPLY(entry->position.x, scale) / 4096.0f) - (obj->tileX << 3);
        int y         = (int) ((float) FIX32_MULTIPLY(entry->position.z, scale) / 4096.0f) - (obj->tileY << 3);
        if (entry->variant >= 0) {
            int group = groups[entry->group] - 1;
            x += data_020e70f0[group][entry->variant][0];
            y += data_020e70f4[group][entry->variant][0];
        }
        if (obj->flags & 1) {
            if (inline_02024518(entry->type)) continue;
        }
        if (!MapIcon_IsShownInBlinkPhase(entry, obj->actionState)) continue;
        MapDisplay_DrawSprite(receiver, (x - 4) << 12, (y - 4) << 12, entry->elementId, entry->type, 0, entry->palette,
                                 0xff, 0x1000, 0x1000);
    }
    MapDisplay_DrawRedChestMarkers(receiver, obj->tileX << 3, obj->tileY << 3, -4, -4, 0);
    MapDisplay_DrawBattleMarkers(receiver, entries, count, obj->tileX << 3, obj->tileY << 3, -4, -4, 0);
}

struct Struct_020251bc {
    int unknown0;
    int entryIndex;
    int x;
    int z;
};

struct Struct_020251bc_2 {
    unsigned char unknown0[0x18];
    int xOrigin;
    int unknown_1c_;
    unsigned char unknown20[0xc];
    Struct_020251bc *forwarding;
    int forwardingCount;
    unsigned char unknown34[4];
    fix32_t scale;
    int tileX;
    int tileZ;
    int screenX;
    int screenZ;
    unsigned char unknown4c[0x74 - 0x4c];
    int forwardingFill;
    unsigned char unknown78[0x55c - 0x78];
    unsigned char forwardingPending;
    unsigned char unknown_55d_[0x5a4 - 0x55d];
    int unknown_5a4_;
    unsigned char unknown_5a8_[Enum_02024e78_2496 - 0x5a8];
    unsigned char actionFlag;
};

// USA: func_020251bc
extern "C" ARM void func_020251bc(void *receiver) {
    Struct_020251bc_2 *state = static_cast<Struct_020251bc_2 *>(receiver);
    GameObject *object                  = GameState::GetInstance()->GetLeader();
    void *displayState                  = BgVram_GetInstance();
    Zone3D_GetInstance();
    Vector3fix position = object->obj3D_.position_;
    CombatActionPosition records[17];
    unsigned char groupCounts[32];
    memset(groupCounts, 0, sizeof(groupCounts));
    int count = MapDisplay_CollectIcons(records, groupCounts, &position);

    fix32_t scale  = state->scale;
    int screenX    = (int) ((float) FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    int screenZ    = (int) ((float) FIX32_MULTIPLY(position.z, scale) / 4096.0f);
    state->screenX = screenX;
    int tileX      = screenX < 0 ? screenX / 8 - 1 : screenX / 8;
    state->screenZ = screenZ;
    int tileZ      = screenZ < 0 ? screenZ / 8 - 1 : screenZ / 8;
    if (state->tileZ != tileZ) state->forwardingPending = 1;
    state->tileX = tileX;
    state->tileZ = tileZ;

    if (state->forwardingPending) {
        state->forwardingPending = 0;
        BgVram_FillMap(displayState, 1, 0, state->forwardingFill);
        for (int i = 0; i < state->forwardingCount; i++) {
            Entry_02027878 *entry =
                MapDisplay_GetMapPiece(reinterpret_cast<List_02027878 *>(receiver), state->forwarding[i].entryIndex);
            if (entry) {
                BgImage_Place(reinterpret_cast<Bcb8Params *>(reinterpret_cast<unsigned char *>(entry) + 8),
                                    state->forwarding[i].x, state->unknown_1c_ + state->forwarding[i].z - tileZ + 16);
            }
        }
    }
    MapDisplay_UpdateBlink(reinterpret_cast<BattleTimer0202441c *>(receiver));
    for (int i = 0; i < count; i++) {
        CombatActionPosition *record = &records[i];
        if (!MapDisplay_IsMemberVisible(receiver, record->combatantId)) continue;
        fix32_t var16 = state->scale;
        int x               = (int) ((float) FIX32_MULTIPLY(record->position.x, var16) / 4096.0f) - state->xOrigin * 8;
        int z               = (int) ((float) FIX32_MULTIPLY(record->position.z, var16) / 4096.0f) - state->screenZ;
        if (record->variant >= 0) {
            int group = groupCounts[record->group] - 1;
            x += data_020e70f0[group][record->variant][0];
            z += data_020e70f4[group][record->variant][0];
        }
        if (state->unknown_5a4_ & 1) {
            if (inline_02024518(record->type)) continue;
        }
        if (!MapIcon_IsShownInBlinkPhase(record, state->actionFlag)) continue;
        MapDisplay_DrawSprite(receiver, (x - 4) * 0x1000, (z + 0x5c) * 0x1000, record->elementId, record->type, 0,
                                 record->palette, 0xff, 0x1000, 0x1000);
    }
    MapDisplay_DrawRedChestMarkers(receiver, state->xOrigin * 8, state->screenZ, -4, 0x5c, 0);
    MapDisplay_DrawBattleMarkers(receiver, records, count, state->xOrigin * 8, state->screenZ, -4, 0x5c, 0);
}
