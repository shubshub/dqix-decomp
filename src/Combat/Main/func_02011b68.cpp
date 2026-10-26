#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Struct_02011b68 {
    unsigned char unknown_0_[6];
};
struct KeyTimerFlags {
    unsigned char active : 1;
    unsigned char flags : 7;
};
struct State0200fad4 {
    SixBytes key;
    KeyTimerFlags state;
    unsigned char pad_07;
    float elapsed;
};
struct MemberKey {
    SixBytes key;
    signed char objectIndex;
    char pad_07[3];
};
struct KeyRecord {
    SixBytes key;
    char pad_06[0xb];
    unsigned char timer;
    unsigned short count : 14;
    unsigned short active : 1;
    unsigned short flag : 1;
    char pad_14[0x18];
};
struct GameStateKeys {
    char pad_00[0x3ac];
    int protagonistObjectIndex_;
    char pad_3b0[0x14];
    unsigned int numTicks_;
    char pad_3c8[0xc];
    float daySpeed_;
#if defined(jpn)
    char unknown_3d8_[0x50e5];
#else
    char unknown1_3d8_[0x5345];
#endif
    unsigned char partyOrder[4];
    signed char partyOrderCount;
#if defined(jpn)
    char unknown_54c2_[0x1afe];
#else
    char unknown_5722_[0x1ade];
#endif
    KeyRecord keyRecords[16];
    MemberKey memberKeys[3];
#if defined(jpn)
    char unknown_729e_[0xa1a];
#else
    char unknown_74de_[0xaae];
#endif
    State0200fad4 keyTimers[3];
};
extern "C" int func_02011fb4(unsigned char*, Struct_02011b68);
extern "C" void func_0200fad4(Struct_0200f3a4_11*);

// USA: func_02011b68
extern "C" ARM void func_02011b68(GameStateKeys* gameState) {
    unsigned char partyOrder[4] = {0};
    memcpy(partyOrder, gameState->partyOrder, (unsigned char)gameState->partyOrderCount);
    int partyOrderCount = gameState->partyOrderCount;
    signed char newKeyCount = 0;
    SixBytes newKeys[4];
    memset(newKeys, 0, sizeof(newKeys));
    MemberKey* memberKey = gameState->memberKeys;
    for (int i = 0; i < 3; i++) gameState->keyTimers[i].state.active = 0;
    for (int i = 0; i < 3; i++, memberKey++) {
        int isNew = 0;
        SixBytes key;
        VectorizedMemset(&key, isNew, sizeof(key));
        for (int j = 0; j < partyOrderCount; j++) {
            if (memberKey->objectIndex == partyOrder[j]) {
                key = memberKey->key;
                if (memberKey->objectIndex >= 0 && memberKey->objectIndex != gameState->protagonistObjectIndex_) {
                    isNew = 1;
                    for (int k = 0; k < 3; k++) {
                        if (CompareSixBytes_02011fb4(gameState->keyTimers[k].key.b, key)) {
                            gameState->keyTimers[k].state.active = 1;
                            isNew = 0;
                            break;
                        }
                    }
                }
            }
        }
        if (isNew) {
            newKeys[newKeyCount] = key;
            newKeyCount++;
        }
    }
    for (int i = 0; i < newKeyCount; i++) {
        int empty;
        for (int k = 0; k < 6; k++) {
            if (newKeys[i].b[k] != 0) {
                empty = 0;
                goto checkedKey;
            }
        }
        var12 = 1;
checkedKey:
        if (!empty) {
            for (int j = 0; j < 3; j++) {
                if (!gameState->keyTimers[j].state.active) {
                    State0200fad4* timer = &gameState->keyTimers[j];
                    ClearFlagsAndValue0200fad4(timer);
                    gameState->keyTimers[j].state.active = 1;
                    timer->key = newKeys[i];
                    break;
                }
            }
        }
    }
    float elapsed = (float)gameState->numTicks_ * gameState->daySpeed_;
    for (int i = 0; i < 3; i++) {
        if (gameState->keyTimers[i].state.active) {
            gameState->keyTimers[i].elapsed += elapsed;
            if (gameState->keyTimers[i].elapsed >= 60.0f) {
                KeyRecord* record = gameState->keyRecords;
                for (int j = 0; j < 16; j++, record++) {
                    if (record->active && CompareSixBytes_02011fb4(record->key.b, gameState->keyTimers[i].key)) {
                        if (++record->timer >= 60) {
                            if (record->count >= 9999) record->timer = 59;
                            else {
                                record->count++;
                                record->timer = 0;
                            }
                        }
                        break;
                    }
                }
                gameState->keyTimers[i].elapsed -= 60.0f;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (!gameState->keyTimers[i].state.active) ClearFlagsAndValue0200fad4(&gameState->keyTimers[i]);
    }
}
