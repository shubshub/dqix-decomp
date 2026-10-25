#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "Combat/CombatantRecovery.h"
#include "Combat/MapDisplay.h"
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "Resource/GameResources.h"


struct Struct_020236dc_5 : Struct_020236dc_2 {
    unsigned char unknown_190_[0x1b2 - 0x190];
    unsigned short unknown_1b2_;
};
struct Struct_02021f88 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    short* unknown_4_;
    int unknown_8_;
    int unknown_c_;
    Struct_02021f88* unknown_10_;
};
struct Struct_02021394_2;
struct Struct_020236dc_6 {
    unsigned char unknown_0_[0x8c];
    unsigned char unknown_8c_[1];
};
struct FlagWord02046708;
struct S3f58;
extern "C" void* Zone3D_GetInstance();
extern "C" void* func_0202ae18();
extern "C" void* Scenario_GetInstance();
void* GlobalFlags_GetInstance();
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState*, int);
int TestFlags02046708(FlagWord02046708*, unsigned int);
void GetFields1a8And1ac_02053f58(S3f58*, int*, int*);
unsigned char GetField0x1b0_02053f74(void*);
int GameState_GetProtagonistIndex(GameState*);
int GetSignedByte0x1c9_02039874(void*);
int Scenario_TestFlag(int, unsigned char*, int);
int FindEntryByKeyPair02021394(Container02021394*, int, int, short*, short*);
#if defined(jpn)
#define data_020e704c data_020e78e8
#endif
extern unsigned short data_020e704c[];

struct Struct_020236dc_4 {
    Struct_020236dc* unknown_0_;
    int unknown_4_;
};

// USA: func_020236dc
extern "C" ARM int func_020236dc(CombatActionPosition* entries, unsigned char* groups, Vector3i* position) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    GameObject* protagonist = game->GetProtagonist();
    Zone3D* zone = (Zone3D*)Zone3D_GetInstance();
    func_0202ae18();
    SaveFlags020236dc* saved = (SaveFlags020236dc*)Scenario_GetInstance();
    FlagWord02046708* flags = (FlagWord02046708*)GlobalFlags_GetInstance();
    Container02021394* container = (Container02021394*)resources->unknown_ptr_36d0;
    ActionOutputState020236dc output;
    output.entries = entries;
    output.count = 0;
    for (int i = 0; i < 4; ++i) {
        Member020236dc* member = (Member020236dc*)GetCombatantWithFlag0x100_0200ff1c(game, i);
        if (!member || !(member->recoveryFlags & 8)) continue;
        if (GetCombatantWithFlag0x1000_0200ff58(game, i)) {
            unsigned char index = 0;
            unsigned short zoneId = zone->unknown_4_;
            int excluded = 0;
            for (; data_020e704c[index]; ++index) {
                if (zoneId == data_020e704c[index]) {
                    excluded = 1;
                    break;
                }
            }
            if (var12) continue;
        }
        CombatActionPosition* entry = &output.entries[output.count];
        entry->combatantId = i;
        ++output.count;
        entry->flag11 = member->field1b2 && !TestFlags02046708(flags, 0x80000) ? 1 : 0;
        entry->flag12 = protagonist ? protagonist->obj3D_.GetField06() == member->obj3D_.GetField06() : 0;
        if (member->recoveryFlags & 0x10) {
            GetFields1a8And1ac_02053f58((S3f58*)member, &entry->position.x, &entry->position.z);
            entry->group = GetField0x1b0_02053f74(member);
            entry->variant = groups[entry->group];
            ++groups[entry->group];
            if (i == GameState_GetProtagonistIndex(game)) {
                position->x = entry->position.x;
                position->z = entry->position.z;
            }
        } else {
            Vector3i var14 = var9->obj3D_.position_;
            var13->unknown_0_.x = var14.x;
            var13->unknown_0_.y = var14.y;
            var13->unknown_0_.z = var14.z;
            var13->unknown_f_ = -1;
        }
        entry->elementId = 5;
        entry->palette = member->obj3D_.actorIndex_ + 4;
        GameObject* party = game->GetPartyMemberByIndex(i);
        GameObject* active = GetCombatantWithFlag0x1000_0200ff58(game, i);
        if (party && (member->obj3D_.actorIndex_ == 0 || active)) entry->type = GetSignedByte0x1c9_02039874(party) + 0x58;
        else entry->type = member->obj3D_.actorIndex_ + 0x5b;
        if (party) entry->flag13 = GetSignedByte0x1c9_02039874(party);
        if (member->combatFields_.savedState_130_->flags & 1) {
            entry->elementId = 6;
            entry->palette = 6;
        }
    }
    int var17 = 0;
    Struct_02020554* var18 = GetGameResources()->unknown_ptr_36d0;
    if (var18) {
        for (Struct_02021f88* var19 = var18->unknown_754_; var19; var19 = var19->unknown_10_) {
            for (int var20 = 0; var20 < var19->unknown_2_; ++var20) {
                int var21 = (unsigned short)var19->unknown_4_[var20];
                int var22 = var3->unknown_2774_.unknown_12_;
                if (var21 == var22) {
                    var17 = 1;
                    break;
                }
            }
        }
    }
    if (found && Scenario_TestFlag((int)saved, saved->flags, 0x2b)) {
        short x = 0;
        short z = 0;
        if (FindEntryByKeyPair02021394(container, zone->savedActor_.zoneId, (unsigned char)zone->savedActor_.nodeId, &x, &z)) {
            CombatActionPosition* entry = &output.entries[output.count];
            ++output.count;
            VectorizedMemset(entry, 0, sizeof(*entry));
            entry->variant = -1;
            entry->combatantId = 0xff;
            entry->position.x = x << 12;
            entry->position.z = z << 12;
            entry->elementId = 0x1b;
            entry->palette = 7;
            entry->type = 0x74;
        }
    }
    return var7.unknown_4_;
}
