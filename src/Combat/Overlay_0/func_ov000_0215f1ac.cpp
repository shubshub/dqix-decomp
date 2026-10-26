#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov000_0215f1ac_2 { char unknown_0_[0x20]; unsigned short combatant; };
struct Struct_ov000_0215f1ac_3 { short key; char unknown_2_[0x10 - 2]; Struct_ov000_0215f1ac_2* head; char unknown_14_[0x28 - 0x14]; };
struct Struct_ov000_0215f1ac_4 { char unknown_0_[0x8e20]; int unknown_8e20_; char unknown_8e24_[0x8e78 - 0x8e24]; Struct_ov000_0215f1ac_3* records; int count; };
struct Struct_ov000_0215f1ac_5 { char unknown_0_[0x10]; unsigned int flags; char unknown_14_[0x2c - 0x14]; unsigned int field_0 : 14; unsigned int category : 6; unsigned int field_20 : 12; };
struct Struct_ov000_0215440c_2;

extern "C" Struct_ov000_0215f1ac_5* func_02079e2c(char*, int);
extern "C" int func_02085180(unsigned char*);
extern "C" int func_ov000_0215fc60(char*);
extern "C" Struct_ov000_0215f1ac_2* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" void func_ov000_0215f500(Struct_ov000_0215f1ac_3*, Struct_ov000_0215f1ac_3*);
extern const int data_ov000_02182aac[3];
extern int data_ov000_02182a58[2];
#if defined(jpn)
struct Struct_ov000_0215f1ac { char unknown_0_[0x144]; unsigned char* status; };
#else
struct Struct_ov000_0215f1ac { char unknown_0_[0x150]; unsigned char* status; };
#endif

// USA: func_ov000_0215f1ac
extern "C" ARM void func_ov000_0215f1ac(Struct_ov000_0215f1ac_4* events) {
    GameState* state = GameState::GetInstance();
    ActionDataTables* data = func_020797dc();
    int moved = 0;
    for (int i = events->count - 1; i >= moved; i--) {
        Struct_ov000_0215f1ac_3* record = &events->records[i];
        Struct_ov000_0215f1ac_5* rule = func_02079e2c((char*)data, record->key);
        if (!rule || !(rule->flags & 0x80000)) continue;
        unsigned short id = record->head->combatant;
        unsigned char partyMember = id <= 3;
        if (!partyMember) continue;
        GameObject* combatant = func_0200ff1c(state, id);
        if (!combatant || !func_02085180(((Struct_ov000_0215f1ac*)combatant)->status)) continue;
        Struct_ov000_0215f1ac_3 saved;
        memcpy(&saved, record, 0x28);
        memmove(events->records + 1, events->records, i * 0x28);
        moved++;
        i++;
        memcpy(events->records, &saved, 0x28);
    }
    for (int var10 = 0; var10 < 3; var10++) {
        int moved = 0;
        for (int i = events->count - 1; i >= moved; i--) {
            Struct_ov000_0215f1ac_3* records = events->records;
            Struct_ov000_0215f1ac_5* rule = func_02079e2c((char*)data, records[i].key);
            if (!rule || rule->category != data_ov000_02182aac[var10]) continue;
            Struct_ov000_0215f1ac_3 saved;
            memcpy(&saved, &records[i], 0x28);
            memmove(events->records + 1, events->records, i * 0x28);
            moved++;
            i++;
            memcpy(events->records, &saved, 0x28);
        }
    }
    int var16[1] = { data_ov000_02182a58[1] };
    for (int var17 = 0; var17 < 1; var17++) {
        int category;
        int remaining = events->count;
        int i = 0;
        for (; i < remaining; i++) {
            category = var16[var17];
            Struct_ov000_0215f1ac_3* records = events->records;
            Struct_ov000_0215f1ac_5* rule = func_02079e2c((char*)data, records[i].key);
            if (!rule || rule->category != category) continue;
            Struct_ov000_0215f1ac_3 saved;
            memcpy(&saved, &records[i], 0x28);
            int recordCount = events->count;
            if (i < recordCount - 1) {
                memmove(&events->records[i], &events->records[i + 1], (recordCount - i - 1) * 0x28);
                remaining--;
                i--;
            }
            memcpy(&events->records[events->count - 1], &saved, 0x28);
        }
    }
    if (func_ov000_0215fc60((char*)events)) {
        Struct_ov000_0215f1ac_3* first = events->records;
        Struct_ov000_0215f1ac_3* second = first + 1;
        Struct_ov000_0215f1ac_2* node = func_ov000_02160094((Struct_ov000_0215440c_2*)first, 0);
        if (events->count == 1) {
            second = events->records;
            first = 0;
        } else if (node && node->combatant) {
            Struct_ov000_0215f1ac_3 saved = *first;
            func_ov000_0215f500(first, second);
            func_ov000_0215f500(second, &saved);
        }
        int var29 = events->unknown_8e20_;
        node = func_ov000_02160094((Struct_ov000_0215440c_2*)second, 0);
        if (node && var29 <= 1) second->key = var29 == 0 ? 0x16e : 1;
        if (first) first->key = 0x1f7;
    }
}
