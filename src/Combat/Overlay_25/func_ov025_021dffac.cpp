#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov025_021dffac { char field_0[0x20]; unsigned short actorIndex; };
struct Struct_ov025_021dffac_2 { char field_0[0xe]; short actorIndex; };
struct Struct_ov025_021dffac_3 {
    unsigned short id; char unknown_2_[0xe]; Struct_ov025_021dffac* source; Struct_ov025_021dffac_2* target; char field_18[0x10];
};
struct Struct_ov025_021dffac_4 { char field_0[0x821c]; Struct_ov025_021dffac_3 actions[77]; int count; };
#if defined(jpn)
struct Struct_ov025_021dffac_5 { char field_0[0x218]; Struct_ov025_021dffac_4* battle; char unknown_21c_[0x57c8-0x21c]; int unknown_55d8_; };
#else
struct Struct_ov025_021dffac_5 { char field_0[0x29c]; Struct_ov025_021dffac_4* battle; char unknown_2a0_[0x5338]; int unknown_55d8_; };
#endif
union Struct_ov025_021dffac_6 { Vector3fix vector; int coordinates[3]; };
struct Struct_ov025_021dffac_7 { unsigned char index; char unknown_1_[3]; int flag; GameObject* actor; };
struct Struct_ov025_021dffac_8 { int x, z; };
extern "C" int func_ov000_02163690(int);
extern "C" void* func_02079e2c(char*, int);
extern "C" int func_ov000_021627fc(void*);
extern "C" int func_ov025_021e1048(Struct_ov025_021dffac_4*, Struct_ov025_021dffac_7*);
extern "C" unsigned char func_020493a4(unsigned char*);
extern "C" unsigned char func_020493c8(unsigned char*);
extern "C" unsigned char func_020493ec(unsigned char*);
extern "C" void func_02049390(unsigned char*, unsigned char);
extern "C" void func_020493b8(unsigned char*, unsigned char);
extern "C" void func_020493dc(unsigned char*, unsigned char);
extern "C" void func_02049400(unsigned char*, unsigned char);
extern "C" int func_ov025_021e1540(int);
extern "C" Struct_ov025_021dffac_7* func_ov025_021e1010(unsigned char*, int, int);
extern "C" void func_ov025_021e110c(unsigned char*, Struct_ov025_021dffac_7*, int);
extern "C" int func_02048bd0(unsigned char*);
extern "C" Struct_ov025_021dffac_8 func_ov000_0216f74c(int*);
extern "C" void __clear(void*, int);
extern "C" int Vector3fix_DistanceToSegment(const Vector3fix*, const Vector3fix*, const Vector3fix*, Vector3fix*);
extern "C" void func_ov025_021e1ff4(unsigned char*, unsigned char, unsigned char*, GameObject*, GameObject*, Struct_ov025_021dffac_7*, int);
extern "C" int func_ov025_021e1f40(GameObject*, int);
extern "C" void func_ov025_021e16c8(Struct_ov025_021dffac_7*, Struct_ov025_021dffac_7*, unsigned char*, Struct_ov025_021dffac_3*, void*, Struct_ov025_021dffac_7*, int);
extern "C" void func_ov025_021e1d54(Struct_ov025_021dffac_7*, unsigned char*);
extern "C" int func_ov025_021e1f08(unsigned char*, unsigned char*);
extern "C" int func_ov000_021628c8(void*, int, int*);
extern "C" int func_ov025_021dfbd4(int);

inline int inline_ov025_021dffac(unsigned char index) {
    return index >= 0xc0 && index <= 0xc7;
}
inline int IsOccupied021dffac(unsigned char cell) {
    return cell >= 0xf2;
}

inline Struct_ov025_021dffac_3* inline_ov025_021dffac_3(Struct_ov025_021dffac_4* battle, int index) { return &battle->actions[index]; }

// USA: func_ov025_021dffac
extern "C" ARM int func_ov025_021dffac(Struct_ov025_021dffac_5* context) {
    GameState* game = GameState::GetInstance();
    Struct_ov025_021dffac_4* battle = context->battle;
    int var2;
    Struct_ov025_021dffac_3* selected = inline_ov025_021dffac_3(battle, context->unknown_55d8_);
    int id = selected->id;
    if (func_ov000_02163690(id)) id = 1;
    void* var5 = func_02079e2c((char*)func_020797dc(), (short)id);
    if (!var5) return 0;
    if (!func_ov000_021627fc(context)) return 0;
    Struct_ov025_021dffac_7 entries[12];
    int count = func_ov025_021e1048(battle, entries);
    Struct_ov025_021dffac_3* actions = battle->actions;
    int var9 = battle->count;
    int var10 = context->unknown_55d8_;
    for (int i = 0; i < count; ++i) {
        func_020493b8((unsigned char*)entries[i].actor, func_020493a4((unsigned char*)entries[i].actor));
        func_02049400((unsigned char*)entries[i].actor, 0xff);
    }
    for (int i = 0; i < count; ++i) {
        GameObject* actor = entries[i].actor;
        int current = func_020493a4((unsigned char*)actor);
        if (current == func_020493ec((unsigned char*)actor))
            func_02049390((unsigned char*)actor, (unsigned char)func_ov025_021e1540(actor->obj3D_.actorIndex_));
    }
    var2 = 0;
    if (selected->source) var2 = selected->source->actorIndex;
    Struct_ov025_021dffac_7* var15 = func_ov025_021e1010((unsigned char*)entries, count, var2);
    if (!var15) return 0;
    int targetIndex = -1;
    if (selected->target) targetIndex = selected->target->actorIndex;
    Struct_ov025_021dffac_7* var17 = func_ov025_021e1010((unsigned char*)entries, count, targetIndex);
    if (!var17) return 0;
    if (var2 == targetIndex) return 1;
    unsigned char occupied[81];
    unsigned char var19[81];
    unsigned char var20[12];
    int indices[12];
    Struct_ov025_021dffac_6 position;
    Struct_ov025_021dffac_6 projected;
    Struct_ov025_021dffac_6 targetPosition;
    Struct_ov025_021dffac_6 sourcePosition;
    memset(occupied, 0, sizeof(occupied));
    memset(var20, 0, sizeof(var20));
    Struct_ov025_021dffac_3* action;
    Struct_ov025_021dffac_3* var27;
    int var28;
    Struct_ov025_021dffac_7* var29;
    Struct_ov025_021dffac* source;
    for (int i = var10; i < var9; ++i) {
        func_ov025_021e110c(occupied, entries, count);
        action = &actions[i];
        source = action->source;
        if (!source || !action->target) continue;
        int actorIndex = source->actorIndex;
        unsigned char var33 = actorIndex;
        if (inline_ov025_021dffac(var33)) var33 -= 0xbc;
        if (var33 < 12) {
            if (var20[var33]) continue;
            var20[var33] = 1;
        }
        GameObject* actor = game->GetCombatantByIndex(actorIndex);
        if (!actor) continue;
        if (var10 == i) {
            GameObject* target = game->GetCombatantByIndex(targetIndex);
            unsigned short var36 = action->id;
            if (actor && target && func_02048bd0((unsigned char*)actor) && (unsigned int)(var36 - 9) <= 2) {
                COPY_ARRAY(sourcePosition.coordinates, ((const Struct_ov025_021dffac_6*)&actor->obj3D_.position_)->coordinates);
                COPY_ARRAY(targetPosition.coordinates, ((const Struct_ov025_021dffac_6*)&target->obj3D_.position_)->coordinates);
                int var37 = 0;
                for (int var38 = 0; var38 < 81; ++var38) {
                    if (var38 % 18 == 17) continue;
                    Struct_ov025_021dffac_8 cell = func_ov000_0216f74c(&var38);
                    __clear(&position, 12);
                    position.vector.x = cell.x;
                    position.vector.z = cell.z;
                    if (Vector3fix_DistanceToSegment(&sourcePosition.vector, &targetPosition.vector, &position.vector, &projected.vector) < 0x1800)
                        var19[var37++] = var38;
                }
                func_ov025_021e1ff4(var19, (unsigned char)var37, occupied, actor, target, entries, count);
            }
        }
        if (!func_ov025_021e1f40(actor, targetIndex)) continue;
        if (var10 == i) {
            func_ov025_021e16c8(var15, var17, occupied, &actions[var10], var5, entries, count);
            func_02049400((unsigned char*)var15->actor, func_020493c8((unsigned char*)var17->actor));
        } else {
            Struct_ov025_021dffac_7* entry = func_ov025_021e1010((unsigned char*)entries, count, source->actorIndex);
            if (entry && entry->flag) func_ov025_021e1d54(entry, occupied);
            else if (entry && func_020493a4((unsigned char*)entry->actor) != 0xff) {
                int var41 = func_ov025_021e1f08((unsigned char*)entry->actor, (unsigned char*)action);
                Struct_ov025_021dffac_7* other = func_ov025_021e1010((unsigned char*)entries, count, var41);
                if (!other) continue;
                func_ov025_021e16c8(entry, other, occupied, &actions[var10], var5, entries, count);
                func_02049400((unsigned char*)entry->actor, func_020493c8((unsigned char*)other->actor));
            }
        }
    }
    for (int i = 0; i < var10; ++i) {
        func_ov025_021e110c(occupied, entries, count);
        var27 = &actions[i];
        if (!var27->source || !var27->target) continue;
        var28 = func_ov000_021628c8(context, i, indices);
        for (int j = 0; j < var28; ++j) {
            int actorIndex = indices[j];
            unsigned char var46 = actorIndex;
            if (inline_ov025_021dffac(var46)) var46 -= 0xbc;
            if (var46 < 12) {
                if (var20[var46]) continue;
                var20[var46] = 1;
            }
            var29 = func_ov025_021e1010((unsigned char*)entries, count, actorIndex);
            GameObject* actor = game->GetCombatantByIndex(actorIndex);
            if (!actor || !var29 || !func_ov025_021e1f40(actor, targetIndex)) continue;
            unsigned char cell = func_020493ec((unsigned char*)actor);
            if (cell < 81 && (!IsOccupied021dffac(occupied[cell]) || occupied[cell] == func_ov025_021dfbd4(actor->obj3D_.actorIndex_)))
                func_020493b8((unsigned char*)actor, cell);
            else func_ov025_021e1d54(var29, occupied);
            func_020493dc((unsigned char*)actor, 0xff);
            int var49 = func_ov025_021e1f08((unsigned char*)actor, (unsigned char*)var27);
            GameObject* other = game->GetCombatantByIndex(var49);
            if (other) func_02049400((unsigned char*)actor, func_020493c8((unsigned char*)other));
        }
    }
    return 1;
}
