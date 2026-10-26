#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include "Graphics/Vector.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define data_020e88a8 data_020e89bc
struct Struct_020733d8_2;
enum { regionalOffsetList = 0x14, Enum_020733d8_96 = 0x5c };
#else
enum { regionalOffsetList = 0x18, Enum_020733d8_96 = 0x60 };
#endif

extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" int func_ov017_021a20c0(int unused, int mult, int limit);
extern "C" void* __clear(void* dst, int count);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void VectorizedInvertedMemcpy(const void* src, void* dst, unsigned int length);
extern "C" int LinkSession_IsActive(int* obj);

struct SearchStruct;
extern "C" int LinkSession_IsSlotMember(struct SearchStruct* obj, int value);
extern "C" int GameObject_GetLineLeader(void* obj);

extern "C" void func_02034104(void* out, GameObject* obj);

struct ListEntry_02028430 { unsigned char id; unsigned char unk[0xF]; };
struct List_02028430 { unsigned char unk0[2]; unsigned char count; unsigned char unknown_3_; struct ListEntry_02028430* entries; };
extern "C" struct ListEntry_02028430* NodeGraph_GetNode(struct List_02028430* list, int index);

struct Struct_020283c0 { unsigned char id; unsigned char unk[0xF]; };
struct Struct_0201a300_11 { unsigned char unk0[2]; unsigned char count; unsigned char unknown_3_; struct Struct_020283c0* entries; };
extern "C" struct Struct_020283c0* func_020283c0(struct Struct_0201a300_11* list, int id);

struct SearchCtx_02028460 { unsigned char pad0[2]; unsigned char count; unsigned char pad1[1]; void* nodes; };
extern "C" int NodeGraph_FindClosestNode(struct SearchCtx_02028460* ctx, Vector3i* pos);

struct Bounds02031118 { Vector3i unknown_0_; Vector3i max; };
extern "C" int Bounds3D_ContainsPoint(Vector3i* p, struct Bounds02031118* b);
extern "C" int Vector3fix_DistanceToSegment(Vector3i* a, Vector3i* b, Vector3i* p, Vector3i* out);

extern "C" void func_02073d50(struct Struct_020733d8_2* obj, int x, int y, int z);
extern "C" int func_02073d58(int a, void* b, int c);
extern "C" int func_02073dfc(unsigned char* self, Vector3i* pos);
extern "C" void* func_02073ec4(int mask, void* list);
extern "C" int func_02073fdc(void* p);
extern "C" int func_ov017_021a2128(void* a, int b, int c, int d, Vector3i* e, int f, int g, int h);

extern "C" int rand(void);

struct Struct_020e88a8 { int v[4]; };
extern struct Struct_020e88a8 data_020e88a8;

struct Struct_020733d8_3 { int v[3]; };

struct Struct_020733d8_4 {
    unsigned short mode : 2;
    unsigned short rest : 14;
};

struct Struct_020733d8_5 {
    unsigned char pad : 6;
    unsigned char unknown_0_6_ : 1;
    unsigned char pad2 : 1;
};

struct Struct_020733d8_6 {
    unsigned int unknown_0_0_ : 21;
    unsigned int level : 4;
    unsigned int unknown_3_1_ : 7;
};

struct ZoneNode020733d8 {
    unsigned char id;
    unsigned char mask;
    unsigned char count;
    unsigned char flags;
    short x;
    short y;
    short z;
    unsigned char pad[2];
    struct ZoneNode020733d8** unknown_c_;
};

static inline int inline_020733d8(unsigned char* self) {
    return ((struct Struct_0201a300_11*)(self + regionalOffsetList))->count;
}

#define SELF_MODE(self) (((struct Struct_020733d8_4*)((self) + 2))->mode)
#define SET_VEC3(v, x, y, z) func_02073d50((struct Struct_020733d8_2*)(v), x, y, z)

// USA: func_020733d8
extern "C" ARM void func_020733d8(unsigned char* self, int unused) {
    if (self == 0 || self[0xc] == 0) {
        return;
    }

    void* dataBase = Scenario_GetInstance();
    if (Scenario_TestFlag((int)dataBase, (unsigned char*)dataBase + 0x8c, 0x79a) != 0 &&
        *(unsigned short*)self >= 0x190 && *(unsigned short*)self <= 0x199) {
        return;
    }

    GameState* gameState = GameState::GetInstance();
    GameResources* var2 = GetGameResources();
    unsigned short var3 = *(unsigned short*)self;
    int timer = *(int*)(self + 8) + gameState->GetTrueDeltaTime();
    *(int*)(self + 8) = timer;
    if (timer < 0x3e8) {
        return;
    }

    if (func_ov017_021a20c0((int)var2, SELF_MODE(self), 0xc) < 0) {
        return;
    }

    Vector3i var5;
    void* var6 = 0;
    __clear(&var5, sizeof(var5));

    struct Struct_020e88a8 weights = data_020e88a8;
    int var8;
    int var9 = -1;
    int status = -1;
    var8 = 0;
    int var11;
    struct ZoneNode020733d8* dest;
    int level;
    int wait;
    int var15;
    GameObject* combatant;
    int angle;
    struct Struct_020733d8_3 var18;
    Vector3i var19;
    struct Struct_020733d8_3 var20;

    for (var11 = 0; var11 < 4; var11++) {
#if !defined(jpn)
        var6 = 0;
#endif

        do {
            struct Struct_020733d8_3 var21;
            int d;
            int best;
            int var24;
            int count;
            int c;
            int outCount;
            int var28[4];
            int ids[4];
            GameObject* obj;
            int m;
            struct Bounds02031118 box;
            struct Struct_020733d8_3 base;
            GameObject* monster;
            int k;
            int counts[4];
            int idx;
            int found;
            int slot;
            GameObject* member;
            int j;
            GameObject* unknown;
            int candIds[4];
            int var44;
            int var45[4];
            int* counter;
            GameState* gs;

            gs = GameState::GetInstance();
            counter = (int*)LinkSession_GetInstance();
            VectorizedInvertedMemcpy(weights.v, var45, 0x10);

            var44 = 0;
            if (LinkSession_IsActive(counter) == 0) {
                unknown = gs->GetLeader();
                if (unknown != 0 && var45[0] == -1) {
                    candIds[0] = unknown->obj3D_.actorIndex_;
                    var44 = 1;
                }
            } else {
                for (j = 0; j < 4; j++) {
                    if (!LinkSession_IsSlotMember((struct SearchStruct*)counter, j)) {
                        continue;
                    }
                    member = gs->GetPartyMemberByIndex(j);
                    if (member == 0) {
                        continue;
                    }
                    if (*(unsigned short*)self != member->obj3D_.GetField06()) {
                        continue;
                    }

                    if (GameObject_GetLineLeader(member) < 0) {
                        slot = j;
                    } else {
                        slot = GameObject_GetLineLeader(member);
                    }

                    found = 0;
                    for (idx = 0; idx < 4; idx++) {
                        if (slot == var45[idx]) {
                            found = 1;
                            break;
                        }
                    }
                    if (found) {
                        continue;
                    }
                    if (slot != -1) {
                        candIds[var44++] = slot;
                    }
                }
            }

            if (var44 == 0) {
                var9 = -1;
                break;
            }

            for (k = 0; k < var44; k++) {
                counts[k] = 0;
                monster = gs->GetWanderingMonsterByIndex(candIds[k]);
                func_02034104(&var21, monster);
                base = var21;

                box.unknown_0_.x = base.v[0] + 0xf000;
                box.unknown_0_.y = base.v[1] + 0x1800;
                box.unknown_0_.z = base.v[2] + 0xf000;
                SET_VEC3(&box.max, base.v[0] - 0xf000, base.v[1] - 0x800, base.v[2] - 0xf000);

                for (m = 0; m < 0xc; m++) {
                    obj = gs->GetGameObjectByIndex(m + (SELF_MODE(self) * 0xc + 0x70));
                    if (obj == 0) {
                        continue;
                    }
                    if (!obj->obj3D_.IsVisible()) {
                        continue;
                    }
                    if (Bounds3D_ContainsPoint(&obj->obj3D_.position_, &box)) {
                        counts[k]++;
                    }
                }
            }

            outCount = 0;
            for (c = 0; c < var44; c++) {
                count = counts[c];
                if (count < 3) {
                    ids[outCount] = candIds[c];
                    var28[outCount] = count;
                    outCount++;
                }
            }

            if (outCount == 0) {
                var9 = -1;
                break;
            }

            var24 = 0xc;
            best = -1;
            for (d = 0; d < outCount; d++) {
                if (var28[d] < var24) {
                    best = ids[d];
                    var24 = var28[d];
                }
            }
            var9 = best;
        } while (0);

        if (var9 < 0) {
            return;
        }
        weights.v[var8++] = var9;

        do {
            struct Struct_020733d8_3 var48;
            Vector3i zoneTmp;
            int len;
            Vector3i diff;
            int var52;
            int closestDist;
            Vector3i closest;
            Vector3i entryPos;
            struct ZoneNode020733d8* entry;
            int dot;
            Vector3i dir;
            Vector3i nodePos;
            int var60;
            int q;
            struct ZoneNode020733d8* node;
            int i;
            int var64;
            unsigned char zoneId;
            Vector3i zonePos;
            int p;
            struct ZoneNode020733d8* var68[16];
            int pick;
            int matchCount;
            Vector3i facing;
            struct Struct_020733d8_3 selfPos;
            int closestIdx;
            struct ZoneNode020733d8* zone;
            GameObject* slotObj;

            slotObj = func_0200ff1c(GameState::GetInstance(), var9);
            if (slotObj == 0) {
                status = -1;
                break;
            }
            if (!((struct Struct_020733d8_5*)((char*)slotObj + 0xc2))->unknown_0_6_) {
                status = -1;
                break;
            }

            zone = (struct ZoneNode020733d8*)NodeGraph_GetNode(
                (struct List_02028430*)(self + regionalOffsetList), *(unsigned short*)((char*)slotObj + 0xb8));
            if (zone == 0) {
                func_02034104(&zoneTmp, slotObj);
                closestIdx = NodeGraph_FindClosestNode((struct SearchCtx_02028460*)(self + regionalOffsetList), &zoneTmp);
                if (closestIdx < 0) {
                    status = -1;
                    break;
                }
                zone = (struct ZoneNode020733d8*)NodeGraph_GetNode((struct List_02028430*)(self + regionalOffsetList), closestIdx);
                if (zone == 0) {
                    status = -1;
                    break;
                }
                *(unsigned short*)((char*)slotObj + 0xb8) = closestIdx;
            }
            if (zone == 0 || zone->count == 0) {
                status = -1;
                break;
            }

            func_02034104(&var48, slotObj);
            selfPos = var48;
            __clear(&facing, sizeof(facing));
            facing.x = fix32sin(slotObj->obj3D_.rotation_.y);
            facing.z = fix32cos(slotObj->obj3D_.rotation_.y);

            pick = -1;
            matchCount = 0;
            for (p = 0; p < zone->count; p++) {
                if (func_02073d58(zone->unknown_c_[p]->id, self, pick) != 0) {
                    continue;
                }
                var68[matchCount++] = zone->unknown_c_[p];
            }

            zonePos.x = zone->x << 12;
            zonePos.y = zone->y << 12;
            zonePos.z = zone->z << 12;
            if (Vector3fix_Distance(&zonePos, (Vector3fix*)&selfPos) > 0x5000) {
                zoneId = zone->id;
                var64 = 1;
                for (i = 0; i < matchCount; i++) {
                    if (zoneId == var68[i]->id) {
                        var64 = 0;
                        break;
                    }
                }
                if (var64) {
                    if (func_02073d58(zoneId, self, -1) == 0) {
                        var68[matchCount++] = zone;
                    }
                }
            }

            var60 = 0;
            for (q = 0; q < matchCount; q++) {
                node = var68[q];
                SET_VEC3(&nodePos, node->x << 12, node->y << 12, node->z << 12);
                Vector3fix_Subtract(&nodePos, (Vector3fix*)&selfPos, &dir);
                facing.y = 0;
                Vector3fix_Normalize(&dir, &dir);
                dot = Vector3fix_InnerProduct(&facing, &dir);
                if (dot <= 0) {
                    continue;
                }
                if (var60 < dot) {
                    var60 = dot;
                    pick = node->id;
                }
            }

            if (pick < 0) {
                if (matchCount == 0) {
                    status = -1;
                    break;
                }
                pick = var68[rand() % matchCount]->id;
            }

            entry = (struct ZoneNode020733d8*)func_020283c0((struct Struct_0201a300_11*)(self + regionalOffsetList), pick);
            if (entry == 0) {
                status = -1;
                break;
            }

            entryPos.x = entry->x << 12;
            entryPos.y = entry->y << 12;
            entryPos.z = entry->z << 12;
            var5 = entryPos;

            if (zone != entry && Vector3fix_Distance(&entryPos, (Vector3fix*)&selfPos) > 0xa000) {
                closestDist = Vector3fix_DistanceToSegment(&entryPos, &zonePos, (Vector3fix*)&selfPos, &closest);
                if (closestDist > 0) {
                    if (closestDist < 0xa000) {
                        var52 = FIX32_MULTIPLY(fix32_Sqrt(0x1000 - fix32_Divide(FIX32_MULTIPLY(closestDist, closestDist), 0x64000)), 0xa000);
                        if (var52 > 0x5000) {
                            Vector3fix_Subtract(&entryPos, &closest, &diff);
                            len = Vector3fix_Length(&diff);
                            Vector3fix_Normalize(&diff, &diff);
                            if (len < var52) {
                                Vector3fixMultiplyScalar(&diff, len, &diff);
                            } else {
                                Vector3fixMultiplyScalar(&diff, var52, &diff);
                            }
                            Vector3fix_Add(&closest, &diff, &var5);
                        }
                    } else {
                        status = -1;
                        break;
                    }
                }
            }

            if (func_02073dfc(self, &var5) != 0 && inline_020733d8(self) > 4) {
                status = -1;
                break;
            }
            status = pick;
        } while (0);

        if (status < 0) {
            continue;
        }
        if (func_02073dfc(self, &var5) != 0) {
            continue;
        }

        int var76;
        {
            GameObject* obj;
            int i;
            struct Bounds02031118 area;
            GameState* gs;

            gs = GameState::GetInstance();
            SET_VEC3(&area.unknown_0_, var5.x + 0x3000, var5.y + 0x5000, var5.z + 0x3000);
            SET_VEC3(&area.max, var5.x - 0x3000, var5.y - 0x5000, var5.z - 0x3000);
            for (i = 0; i < 0xc; i++) {
                obj = gs->GetGameObjectByIndex(i + (SELF_MODE(self) * 0xc + 0x70));
                if (obj == 0) {
                    continue;
                }
                if (!obj->obj3D_.IsVisible()) {
                    continue;
                }
                if (Bounds3D_ContainsPoint(&obj->obj3D_.position_, &area)) {
                    var76 = 1;
                    goto crowdChecked;
                }
            }
            var76 = 0;
        }
    crowdChecked:
        if (var76) {
            continue;
        }

        dest = (struct ZoneNode020733d8*)func_020283c0((struct Struct_0201a300_11*)(self + regionalOffsetList), status);
        if (dest == 0) {
            continue;
        }
        if (dest != 0 && (dest->flags & 2)) {
            continue;
        }
        var6 = func_02073ec4(dest->mask, self + Enum_020733d8_96);
        if (var6 == 0) {
            continue;
        }

        level = ((struct Struct_020733d8_6*)((char*)var6 + 4))->level;
        wait = 6 - level;
        wait = wait + 1;
        if (*(int*)(self + 8) >= wait * 0x3e8) {
            break;
        }
    }

    if (var6 == 0) {
        return;
    }
    var15 = func_02073fdc(var6);
    if (var15 == -1) {
        return;
    }

    combatant = func_0200ff1c(gameState, var9);
    angle = 0;
    if (combatant != 0) {
        func_02034104(&var20, combatant);
        var18 = var20;
        Vector3fix_Subtract((Vector3fix*)&var18, &var5, &var19);
        Vector3fix_Normalize(&var19, &var19);
        angle = fix32_Atan2(var19.x, var19.z);
    }

    if (func_ov017_021a2128(var2, var3, var15, *(unsigned short*)var6, &var5, angle,
                            (unsigned short)status, 0) != 0) {
        *(int*)(self + 8) = 0;
    }
}
