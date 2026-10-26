#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include "Graphics/Vector.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define data_020e88a8 data_020e89bc
struct Struct_020733d8_2;
enum { Enum_020733d8_24 = 0x14, Enum_020733d8_96 = 0x5c };
#else
enum { Enum_020733d8_24 = 0x18, Enum_020733d8_96 = 0x60 };
#endif

extern "C" void* Scenario_GetInstance(void);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
int FindCombatantWithNegativeField2_021a20c0(int unused, int mult, int limit);
extern "C" void* __clear(void* dst, int count);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void VectorizedInvertedMemcpy(const void* src, void* dst, unsigned int length);
int LinkSession_IsActive(int* obj);

struct SearchStruct;
int LinkSession_IsSlotMember(struct SearchStruct* obj, int value);
int GameObject_GetLineLeader(void* obj);

extern "C" void func_02034104(void* arg0, GameObject* arg1);

struct ListEntry_02028430 { unsigned char id; unsigned char unk[0xF]; };
struct List_02028430 { unsigned char unk0[2]; unsigned char count; unsigned char unk3; struct ListEntry_02028430* entries; };
struct ListEntry_02028430* NodeGraph_GetNode(struct List_02028430* list, int index);

struct Struct_020283c0 { unsigned char unknown_0_; unsigned char unknown_1_[0xF]; };
struct Struct_0201a300_11 { unsigned char unknown_0_[2]; unsigned char unknown_2_; unsigned char unknown_3_; struct Struct_020283c0* unknown_4_; };
extern "C" struct Struct_020283c0* func_020283c0(struct Struct_0201a300_11* arg0, int arg1);

struct SearchCtx_02028460 { unsigned char pad0[2]; unsigned char count; unsigned char pad1[1]; void* nodes; };
extern "C" int NodeGraph_FindClosestNode(struct SearchCtx_02028460* ctx, Vector3i* pos);

struct Bounds02031118 { Vector3i min; Vector3i max; };
extern "C" int Bounds3D_ContainsPoint(Vector3i* p, struct Bounds02031118* b);
extern "C" int Vector3fix_DistanceToSegment(Vector3i* a, Vector3i* b, Vector3i* p, Vector3i* out);

extern "C" void func_02073d50(struct Struct_020733d8_2* arg0, int arg1, int arg2, int arg3);
extern "C" int func_02073d58(int arg0, void* arg1, int arg2);
extern "C" int func_02073dfc(unsigned char* arg0, Vector3i* arg1);
extern "C" void* func_02073ec4(int arg0, void* arg1);
extern "C" int func_02073fdc(void* arg0);
extern "C" int func_ov017_021a2128(void* arg0, int arg1, int arg2, int arg3, Vector3i* arg4, int arg5, int arg6, int arg7);

extern "C" int rand(void);

struct Struct_020e88a8 { int unknown_0_[4]; };
extern struct Struct_020e88a8 data_020e88a8;

struct Struct_020733d8_3 { int unknown_0_[3]; };

struct Struct_020733d8_4 {
    unsigned short unknown_0_0_ : 2;
    unsigned short unknown_0_2_ : 14;
};

struct Struct_020733d8_5 {
    unsigned char unknown_0_0_ : 6;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

struct Struct_020733d8_6 {
    unsigned int unknown_0_0_ : 21;
    unsigned int unknown_2_5_ : 4;
    unsigned int unknown_3_1_ : 7;
};

struct Struct_020733d8_7 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    unsigned char unknown_a_[2];
    struct Struct_020733d8_7** unknown_c_;
};

static inline int inline_020733d8(unsigned char* arg0) {
    return ((struct Struct_0201a300_11*)(arg0 + Enum_020733d8_24))->unknown_2_;
}

#define SELF_MODE(self) (((struct Struct_020733d8_4*)((self) + 2))->unknown_0_0_)
#define SET_VEC3(v, x, y, z) func_02073d50((struct Struct_020733d8_2*)(v), x, y, z)

// USA: func_020733d8
extern "C" ARM void func_020733d8(unsigned char* arg0, int arg1) {
    if (arg0 == 0 || arg0[0xc] == 0) {
        return;
    }

    void* dataBase = Scenario_GetInstance();
    if (Scenario_TestFlag((int)dataBase, (unsigned char*)dataBase + 0x8c, 0x79a) != 0 &&
        *(unsigned short*)self >= 0x190 && *(unsigned short*)self <= 0x199) {
        return;
    }

    GameState* var1 = GameState::GetInstance();
    GameResources* var2 = GetGameResources();
    unsigned short var3 = *(unsigned short*)arg0;
    int var4 = *(int*)(arg0 + 8) + var1->GetTrueDeltaTime();
    *(int*)(arg0 + 8) = var4;
    if (var4 < 0x3e8) {
        return;
    }

    if (func_ov017_021a20c0((int)var2, SELF_MODE(arg0), 0xc) < 0) {
        return;
    }

    Vector3i var5;
    void* var6 = 0;
    __clear(&var5, sizeof(var5));

    struct Struct_020e88a8 var7 = data_020e88a8;
    int var8;
    int var9 = -1;
    int var10 = -1;
    var8 = 0;
    int var11;
    struct Struct_020733d8_7* var12;
    int var13;
    int var14;
    int var15;
    GameObject* var16;
    int var17;
    struct Struct_020733d8_3 var18;
    Vector3i var19;
    struct Struct_020733d8_3 var20;

    for (var11 = 0; var11 < 4; var11++) {
#if !defined(jpn)
        var6 = 0;
#endif

        do {
            struct Struct_020733d8_3 var21;
            int var22;
            int var23;
            int var24;
            int var25;
            int var26;
            int var27;
            int var28[4];
            int var29[4];
            GameObject* var30;
            int var31;
            struct Struct_020733d8 var32;
            struct Struct_020733d8_3 var33;
            GameObject* var34;
            int var35;
            int var36[4];
            int var37;
            int var38;
            int var39;
            GameObject* var40;
            int var41;
            GameObject* var42;
            int var43[4];
            int var44;
            int var45[4];
            int* var46;
            GameState* var47;

            gs = GameState::GetInstance();
            counter = (int*)LinkSession_GetInstance();
            VectorizedInvertedMemcpy(weights.v, localWeights, 0x10);

            candCount = 0;
            if (LinkSession_IsActive(counter) == 0) {
                unknown = gs->GetLeader();
                if (unknown != 0 && localWeights[0] == -1) {
                    candIds[0] = unknown->obj3D_.actorIndex_;
                    candCount = 1;
                }
            } else {
                for (j = 0; j < 4; j++) {
                    if (!LinkSession_IsSlotMember((struct SearchStruct*)counter, j)) {
                        continue;
                    }
                    var40 = var47->GetPartyMemberByIndex(var41);
                    if (var40 == 0) {
                        continue;
                    }
                    if (*(unsigned short*)arg0 != var40->obj3D_.GetField06()) {
                        continue;
                    }

                    if (GameObject_GetLineLeader(member) < 0) {
                        slot = j;
                    } else {
                        slot = GameObject_GetLineLeader(member);
                    }

                    var38 = 0;
                    for (var37 = 0; var37 < 4; var37++) {
                        if (var39 == var45[var37]) {
                            var38 = 1;
                            break;
                        }
                    }
                    if (var38) {
                        continue;
                    }
                    if (var39 != -1) {
                        var43[var44++] = var39;
                    }
                }
            }

            if (var44 == 0) {
                var9 = -1;
                break;
            }

            for (k = 0; k < candCount; k++) {
                counts[k] = 0;
                monster = gs->GetWanderingMonsterByIndex(candIds[k]);
                func_02034104(&baseTmp, monster);
                base = baseTmp;

                var32.unknown_0_.x = var33.unknown_0_[0] + 0xf000;
                var32.unknown_0_.y = var33.unknown_0_[1] + 0x1800;
                var32.unknown_0_.z = var33.unknown_0_[2] + 0xf000;
                SET_VEC3(&var32.unknown_c_, var33.unknown_0_[0] - 0xf000, var33.unknown_0_[1] - 0x800, var33.unknown_0_[2] - 0xf000);

                for (var31 = 0; var31 < 0xc; var31++) {
                    var30 = var47->GetGameObjectByIndex(var31 + (SELF_MODE(arg0) * 0xc + 0x70));
                    if (var30 == 0) {
                        continue;
                    }
                    if (!var30->obj3D_.IsVisible()) {
                        continue;
                    }
                    if (Bounds3D_ContainsPoint(&obj->obj3D_.position_, &box)) {
                        counts[k]++;
                    }
                }
            }

            var27 = 0;
            for (var26 = 0; var26 < var44; var26++) {
                var25 = var36[var26];
                if (var25 < 3) {
                    var29[var27] = var43[var26];
                    var28[var27] = var25;
                    var27++;
                }
            }

            if (var27 == 0) {
                var9 = -1;
                break;
            }

            var24 = 0xc;
            var23 = -1;
            for (var22 = 0; var22 < var27; var22++) {
                if (var28[var22] < var24) {
                    var23 = var29[var22];
                    var24 = var28[var22];
                }
            }
            var9 = var23;
        } while (0);

        if (var9 < 0) {
            return;
        }
        var7.unknown_0_[var8++] = var9;

        do {
            struct Struct_020733d8_3 var48;
            Vector3i var49;
            int var50;
            Vector3i var51;
            int var52;
            int var53;
            Vector3i var54;
            Vector3i var55;
            struct Struct_020733d8_7* var56;
            int var57;
            Vector3i var58;
            Vector3i var59;
            int var60;
            int var61;
            struct Struct_020733d8_7* var62;
            int var63;
            int var64;
            unsigned char var65;
            Vector3i var66;
            int var67;
            struct Struct_020733d8_7* var68[16];
            int var69;
            int var70;
            Vector3i var71;
            struct Struct_020733d8_3 var72;
            int var73;
            struct Struct_020733d8_7* var74;
            GameObject* var75;

            var75 = func_0200ff1c(GameState::GetInstance(), var9);
            if (var75 == 0) {
                var10 = -1;
                break;
            }
            if (!((struct Struct_020733d8_5*)((char*)var75 + 0xc2))->unknown_0_6_) {
                var10 = -1;
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
                *(unsigned short*)((char*)var75 + 0xb8) = var73;
            }
            if (var74 == 0 || var74->unknown_2_ == 0) {
                var10 = -1;
                break;
            }

            func_02034104(&var48, var75);
            var72 = var48;
            __clear(&var71, sizeof(var71));
            var71.x = fix32sin(var75->obj3D_.rotation_.y);
            var71.z = fix32cos(var75->obj3D_.rotation_.y);

            var69 = -1;
            var70 = 0;
            for (var67 = 0; var67 < var74->unknown_2_; var67++) {
                if (func_02073d58(var74->unknown_c_[var67]->unknown_0_, arg0, var69) != 0) {
                    continue;
                }
                var68[var70++] = var74->unknown_c_[var67];
            }

            var66.x = var74->unknown_4_ << 12;
            var66.y = var74->unknown_6_ << 12;
            var66.z = var74->unknown_8_ << 12;
            if (Vector3fix_Distance(&var66, (Vector3fix*)&var72) > 0x5000) {
                var65 = var74->unknown_0_;
                var64 = 1;
                for (var63 = 0; var63 < var70; var63++) {
                    if (var65 == var68[var63]->unknown_0_) {
                        var64 = 0;
                        break;
                    }
                }
                if (var64) {
                    if (func_02073d58(var65, arg0, -1) == 0) {
                        var68[var70++] = var74;
                    }
                }
            }

            var60 = 0;
            for (var61 = 0; var61 < var70; var61++) {
                var62 = var68[var61];
                SET_VEC3(&var59, var62->unknown_4_ << 12, var62->unknown_6_ << 12, var62->unknown_8_ << 12);
                Vector3fix_Subtract(&var59, (Vector3fix*)&var72, &var58);
                var71.y = 0;
                Vector3fix_Normalize(&var58, &var58);
                var57 = Vector3fix_InnerProduct(&var71, &var58);
                if (var57 <= 0) {
                    continue;
                }
                if (var60 < var57) {
                    var60 = var57;
                    var69 = var62->unknown_0_;
                }
            }

            if (var69 < 0) {
                if (var70 == 0) {
                    var10 = -1;
                    break;
                }
                var69 = var68[rand() % var70]->unknown_0_;
            }

            var56 = (struct Struct_020733d8_7*)func_020283c0((struct Struct_0201a300_11*)(arg0 + Enum_020733d8_24), var69);
            if (var56 == 0) {
                var10 = -1;
                break;
            }

            var55.x = var56->unknown_4_ << 12;
            var55.y = var56->unknown_6_ << 12;
            var55.z = var56->unknown_8_ << 12;
            var5 = var55;

            if (zone != entry && Vector3fix_Distance(&entryPos, (Vector3fix*)&selfPos) > 0xa000) {
                closestDist = Vector3fix_DistanceToSegment(&entryPos, &zonePos, (Vector3fix*)&selfPos, &closest);
                if (closestDist > 0) {
                    if (closestDist < 0xa000) {
                        reach = FIX32_MULTIPLY(fix32_Sqrt(0x1000 - fix32_Divide(FIX32_MULTIPLY(closestDist, closestDist), 0x64000)), 0xa000);
                        if (reach > 0x5000) {
                            Vector3fix_Subtract(&entryPos, &closest, &diff);
                            len = Vector3fix_Length(&diff);
                            Vector3fix_Normalize(&diff, &diff);
                            if (len < reach) {
                                Vector3fixMultiplyScalar(&diff, len, &diff);
                            } else {
                                Vector3fixMultiplyScalar(&var51, var52, &var51);
                            }
                            Vector3fix_Add(&var54, &var51, &var5);
                        }
                    } else {
                        var10 = -1;
                        break;
                    }
                }
            }

            if (func_02073dfc(arg0, &var5) != 0 && inline_020733d8(arg0) > 4) {
                var10 = -1;
                break;
            }
            var10 = var69;
        } while (0);

        if (var10 < 0) {
            continue;
        }
        if (func_02073dfc(arg0, &var5) != 0) {
            continue;
        }

        int var76;
        {
            GameObject* var77;
            int var78;
            struct Struct_020733d8 var79;
            GameState* var80;

            var80 = GameState::GetInstance();
            SET_VEC3(&var79.unknown_0_, var5.x + 0x3000, var5.y + 0x5000, var5.z + 0x3000);
            SET_VEC3(&var79.unknown_c_, var5.x - 0x3000, var5.y - 0x5000, var5.z - 0x3000);
            for (var78 = 0; var78 < 0xc; var78++) {
                var77 = var80->GetGameObjectByIndex(var78 + (SELF_MODE(arg0) * 0xc + 0x70));
                if (var77 == 0) {
                    continue;
                }
                if (!var77->obj3D_.IsVisible()) {
                    continue;
                }
                if (Bounds3D_ContainsPoint(&obj->obj3D_.position_, &area)) {
                    crowded = 1;
                    goto crowdChecked;
                }
            }
            var76 = 0;
        }
    crowdChecked:
        if (var76) {
            continue;
        }

        var12 = (struct Struct_020733d8_7*)func_020283c0((struct Struct_0201a300_11*)(arg0 + Enum_020733d8_24), var10);
        if (var12 == 0) {
            continue;
        }
        if (var12 != 0 && (var12->unknown_3_ & 2)) {
            continue;
        }
        var6 = func_02073ec4(var12->unknown_1_, arg0 + Enum_020733d8_96);
        if (var6 == 0) {
            continue;
        }

        var13 = ((struct Struct_020733d8_6*)((char*)var6 + 4))->unknown_2_5_;
        var14 = 6 - var13;
        var14 = var14 + 1;
        if (*(int*)(arg0 + 8) >= var14 * 0x3e8) {
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

    var16 = func_0200ff1c(var1, var9);
    var17 = 0;
    if (var16 != 0) {
        func_02034104(&var20, var16);
        var18 = var20;
        Vector3fix_Subtract((Vector3fix*)&var18, &var5, &var19);
        Vector3fix_Normalize(&var19, &var19);
        var17 = fix32_Atan2(var19.x, var19.z);
    }

    if (func_ov017_021a2128(var2, var3, var15, *(unsigned short*)var6, &var5, var17,
                            (unsigned short)var10, 0) != 0) {
        *(int*)(arg0 + 8) = 0;
    }
}
