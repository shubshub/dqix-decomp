#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include "Resource/Brightness.h"

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short slotGroup : 2;
};

struct SpawnParams {
#if defined(jpn)
    char unknown_0_[0x58];
#else
    char unknown1_0_[0x38];
#endif
    unsigned short unknown_38_;
    unsigned int unknown_3c_;
};

struct Struct_ov017_021a1d98 {
    char unknown_0_[0x12];
    short scale;
};

struct FieldMonster : GameObject {
    char unknown_13c_[0x180 - 0x13c];
    Struct_ov017_021a1d98* unknown_180_;
};

struct Struct_ov017_021a1d98_4 {
    int distance;
    unsigned char selected;
    Struct_ov017_021a1d98_4() : distance(0x0270f000), selected(0) {}
};

extern "C" Entry_02028bd0* ZoneRecords_GetInstance();
extern "C" Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0*, int);
extern "C" SpawnParams* Zone3D_GetInstance();
extern "C" int func_02076bec(GameObject*, void*);
struct BitField0203402c;
extern "C" int GameObject_IsSinking(BitField0203402c*);
extern "C" void func_0208f87c(const void* self, int b, int c, int d, int polygonId);

// USA: func_ov017_021a1d98
extern "C" ARM void func_ov017_021a1d98(unsigned int* flags, int id) {
    GameState* state = GameState::GetInstance();
    Entry_02028bd0* entry = ZoneRecords_Find(ZoneRecords_GetInstance(), id);
    if (!entry) return;
    SpawnParams* params = Zone3D_GetInstance();
    unsigned short field38 = params->unknown_38_;
    unsigned int field3c = params->unknown_3c_;
    int arg = 1;
    if (TestFlags04((GameResources*)flags, 0x1000)) arg = 0;
    int var6 = 0;
    for (int i = 0; i < 4; i++) {
        GameObject* member = state->GetPartyMemberByIndex(i);
        if (member && id == member->obj3D_.GetField06()) var6++;
    }
    int remaining = 7 - var6;
    Vector3fix origin = state->GetLeader()->obj3D_.position_;
    Struct_ov017_021a1d98_4 slots[12];
    for (int j = 0; j < 12; j++) {
        FieldMonster* monster = (FieldMonster*)state->GetFieldMonsterByIndex(entry->slotGroup * 12 + 0x70 + j);
        if (monster && monster->obj3D_.IsVisible()) {
            Vector3fix position = monster->obj3D_.position_;
            slots[j].distance = Vector3fix_Distance(&origin, &position);
        }
    }
    int var15, k, best;
    for (k = 0; k < remaining; k++) {
        best = -1;
        var15 = 0x0270f000;
        for (int j = 0; j < 12; j++) {
            if (!slots[j].selected && slots[j].distance <= var15) {
                var15 = slots[j].distance;
                best = j;
            }
        }
        if (best != -1) slots[best].selected = 1;
    }
    for (int j = 0; j < 12; j++) {
        if (!slots[j].selected) continue;
        FieldMonster* monster = (FieldMonster*)state->GetFieldMonsterByIndex(entry->slotGroup * 12 + 0x70 + j);
        if (monster && monster->obj3D_.IsVisible()
            && func_02076bec(monster, (void*)arg)
            && !GameObject_IsSinking((BitField0203402c*)monster)) {
            int alpha = monster->obj3D_.GetCombinedAlpha();
            int value = (int)((float)field3c / 31.0f * (float)alpha);
            int var23 = monster->unknown_180_ ? monster->unknown_180_->scale : 0x1000;
            fix32_t size = FIX32_MULTIPLY(var23, monster->obj3D_.GetScale().x * 15);
            const Vector3fix& var25 = monster->obj3D_.MaybeGetShadowSource();
            func_0208f87c(&var25, field38, size, value, 8);
        }
    }
}
