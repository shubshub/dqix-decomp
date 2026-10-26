#include <globaldefs.h>
#include "GameState/GameState.h"

// Per party member status records (0x20 bytes): hp at +0, maxHp at +8
extern int data_020fdcb0[][8];
extern int data_020fdcb8[][8];

enum {
    HpTier_Normal = 1,
    HpTier_Down = 2,
    HpTier_Critical = 3,
    HpTier_Low = 4,
};

// Main, originally ClassifyFlag0x800RatioTier02027bd0 (USA 0x02027bd0, EUR 0x02027be0, JPN 0x0202743c)
ARM int MapDisplay_GetMemberHpTier(int memberId) {
    int hp, maxHp;
    GameState* gameState;
    GameObject* member;
    float hpRatio;
    int isPartySlot;

    isPartySlot = (memberId >= 0) && (memberId <= 3);
    if (!isPartySlot) {
        return HpTier_Normal;
    }

    hp = data_020fdcb0[memberId][0];
    maxHp = data_020fdcb8[memberId][0];
    if (hp < 0) {
        return HpTier_Normal;
    }
    if (maxHp <= 0) {
        return HpTier_Normal;
    }

    gameState = GameState::GetInstance();
    member = gameState->GetPartyMemberByIndex(memberId);
    if (member == NULL) {
        return HpTier_Normal;
    }

    hpRatio = (float)hp / (float)maxHp;
    if (hpRatio <= 0.0f) {
        return HpTier_Down;
    }
    if (hpRatio <= 0.08f) {
        return HpTier_Critical;
    }
    if (hpRatio <= 0.25f) {
        return HpTier_Low;
    }
    return HpTier_Normal;
}
