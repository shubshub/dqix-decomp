#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "Resource/GameResources.h"

struct Struct_02012de8;
struct Struct_02018300_3;
struct Struct_02033834;
struct Struct_0202c1a4;

struct Struct_ov017_02190884 {
    unsigned int unknown_0_;
};

struct Struct_ov017_02190884_2 {
    Object3D unknown_0_;
    char unknown_ac_[4];
    short unknown_b0_;
    char unknown_b2_[2];
    short unknown_b4_;
    short unknown_b6_;
    char unknown_b8_[0xc1 - 0xb8];
    unsigned char unknown_c1_0_ : 2;
    char unknown_c2_[0x130 - 0xc2];
    Struct_ov017_02190884* unknown_130_;
#if defined(jpn)
    char unknown_134_[0x2c6 - 0x134];
#else
    char unknown1_134_[0x2d2 - 0x134];
#endif
    unsigned char unknown_2d2_;
};

struct Struct_ov017_02190884_3 {
    char unknown_0_[3];
    unsigned char unknown_3_;
};

struct Struct_ov017_021d61dc {
    int unknown_0_[8];
};

FlagWord02046708* GlobalFlags_GetInstance();
int FlagWord_TestBits(FlagWord02046708* flags, unsigned int mask);
extern "C" void func_020dc548(signed char id, signed char* list, signed char* count);
int GameObject_IsClimbingLadder(char* obj);
extern "C" SearchStruct0202c1a4* LinkSession_GetInstance();
GameObject* GetCombatantWithFlag0x200_0200fee0(GameState* battleStruct, int id);
extern "C" char* Zone3D_GetInstance();
int IsIdInRange020981e4(int obj, int id);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int id);
int GetSignedByte0x2d0_020546a8(void* obj);
int IsCombatantField2InMonsterRange_02190818(int id);
int GameObject_GetLineLeader(void* obj);
int GameObject_IsControlEnabled(void* obj);
int GameObject_IsControlPending(void* obj);
int CollectCombatantsWithFlag0x1000_02010038(GameState* battleStruct, unsigned char* out);
int GameObject_IsGesturing(signed char* obj);
extern "C" void func_020531f0(void* obj);
int GameObject_GetLinePosition(void* obj);
unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
void ClearByte0xc1Flag0x4_020340f4(unsigned char* obj);
void GameObject_SetFollowedMember(unsigned char*, int);
void GameObject_EnableControl(void* obj);
void GameObject_DisableControl(Obj020397cc* obj, int flag);
void GameObject_ClearHidden(unsigned char* obj);
int LinkSession_IsActive(int* obj);
int LinkSession_GetOwnSlot(SearchStruct0202c1a4* search);
void SetByte0xc1Flag0x4_020340e4(unsigned char* obj);
void GameObject_ResetTrail(unsigned char* obj);
void GameObject_SetLinePosition(unsigned char*, int);
void GameObject_SetLineLeader(unsigned char*, int);
void GameObject_ResumeFollowing(unsigned char* obj);
void GameObject_SnapFacing(Obj02033874* obj, int value);
void MapDisplay_RequestMemberRedraw(unsigned char* obj, int value);

#if defined(jpn)
#define data_ov017_021d61dc data_ov017_021d662c
#endif
extern Struct_ov017_021d61dc data_ov017_021d61dc;

// USA: func_ov017_02190884
extern "C" ARM void func_ov017_02190884(int arg0, int* arg1, int* arg2, int arg3, int arg4, int arg5) {
    GameState* var0 = GameState::GetInstance();

    if (FlagWord_TestBits(GlobalFlags_GetInstance(), 0x2000) != 0) {
        unsigned char* base = (unsigned char*)GameState_GetParty(gs);
        int i;
        for (i = 0; i < base[0xf7c]; i++) {
            out[i] = (base + i)[0xf78];
        }
        *arg2 = var1[0xf7c];
        return;
    }

    signed char nearCount;
    signed char nearList[6];
    unsigned char party[5];
    nearCount = 0;
    func_020dc548((signed char)id, nearList, &nearCount);
    for (int i = 0; i < nearCount; i++) {
        GameObject* m = gs->GetPartyMemberByIndex(nearList[i]);
        if (m != NULL && GameObject_IsClimbingLadder((char*)m) != 0) {
            return;
        }
    }

    SearchStruct0202c1a4* search = LinkSession_GetInstance();
    GameResources* ctx = GetGameResources();
    if (ctx == NULL) {
        return;
    }
    Struct_ov017_02190884_2* var10 = (Struct_ov017_02190884_2*)func_0200fee0(var0, arg0);
    if (var10 == NULL) {
        return;
    }

    char* map = Zone3D_GetInstance();
    int inRange = 0;
    int restore;
    GameObject* obj;
    if (IsIdInRange020981e4((int)((Zone3D*)map)->unk_840, *(unsigned short*)map)) {
        inRange = 1;
    }

    int listA[4];
    int listB[4];
    int nA = 0;
    int nB = 0;
    Flags02190884* f718 = (Flags02190884*)ctx->unknown_ptr_3718;
    Flags02190884* f734 = (Flags02190884*)ctx->unknown_ptr_array_371c[6];
    Flags02190884* fB30 = (Flags02190884*)ctx->fieldTasks_[13];
    if (!(self->status->flags & 1)) {
        listA[nA++] = id;
    } else {
        var16[var18++] = arg0;
    }

    for (int var22 = 3; var22 >= 0; var22--) {
        Struct_ov017_02190884_2* var23 = (Struct_ov017_02190884_2*)func_0200ff58(var0, var22);
        if (var23 != NULL && arg0 == func_020546a8(var23)) {
            if (!(var23->unknown_130_->unknown_0_ & 1)) {
                var15[var17++] = var22;
            } else {
                var16[var18++] = var22;
            }
        }
    }

    Struct_ov017_021d61dc var24 = data_ov017_021d61dc;
    int* var25 = var15;
    for (int var26 = 0; var26 < var17; var26++, var25++) {
        Struct_ov017_02190884_2* var27 = (Struct_ov017_02190884_2*)func_0200ff58(var0, *var25);
        if (var27 != NULL) {
            var24.unknown_0_[var27->unknown_2d2_] = *var25;
        } else {
            var24.unknown_0_[0] = *var25;
        }
    }
    var25 = var16;
    for (int var28 = 0; var28 < var18; var28++, var25++) {
        Struct_ov017_02190884_2* var29 = (Struct_ov017_02190884_2*)func_0200ff58(var0, *var25);
        if (var29 != NULL) {
            var24.unknown_0_[var29->unknown_2d2_ + 4] = *var25;
        } else {
            var24.unknown_0_[4] = *var25;
        }
    }

    *arg2 = 0;
    var25 = var24.unknown_0_;
    for (int var30 = 0; var30 < 8; var30++, var25++) {
        if (*var25 >= 0) {
            arg1[(*arg2)++] = *var25;
        }
    }

    if (var12 != 0 && func_ov017_02190818(arg1[0])) {
        for (int var31 = 1; var31 < *arg2; var31++) {
            if (!func_ov017_02190818(arg1[var31])) {
                int var32 = arg1[var31];
                arg1[var31] = arg1[0];
                arg1[0] = var32;
                break;
            }
        }
    }

    GameState_GetParty(gs);
    gs->GetProtagonist();
    int keep = 1;
    GameObject* leader = gs->GetPartyMemberByIndex(GameObject_GetLineLeader(self));
    if (leader != NULL) {
        if (GameObject_IsControlEnabled(leader) == 0) {
            keep = 0;
        } else {
            var33 = 1;
        }
        if (GameObject_IsControlPending(leader) != 0) {
            keep = 1;
        }
    }

    if (leader != NULL && out[0] != leader->obj3D_.actorIndex_) {
        GameObject* own = GetCombatantWithFlag0x1000_0200ff58(gs, id);
        int n;
        if (id == 0 || own != NULL) {
            n = CollectCombatantsWithFlag0x1000_02010038(gs, party);
        } else {
            var5[0] = arg0;
            var36 = 1;
        }
        for (int i = 0; i < n; i++) {
            GameObject* m = gs->GetPartyMemberByIndex(party[i]);
            if (m != NULL && GameObject_IsGesturing((signed char*)m)) {
                func_020531f0(m);
            }
        }
    }

    Vector3i pos[4];
    int rotY[4];
    for (int i = 0; i < *count; i++) {
        GameObject* m = gs->GetPartyMemberByIndex(out[i]);
        if (m != NULL) {
            pos[GameObject_GetLinePosition(m)] = m->obj3D_.position_;
            rotY[GameObject_GetLinePosition(m)] = m->obj3D_.rotation_.y;
        }
    }

    restore = 0;
    if (out[0] != GameState_GetLeaderIndex(gs)) {
        restore = 1;
    }

    int var43;
    if (var10->unknown_c1_0_ & 2) {
        var43 = 1;
    } else {
        var43 = 0;
    }
    short var44 = 0;
    int var45 = 0;
    for (; var45 < *arg2; var45++) {
        Struct_ov017_02190884_2* var46 = (Struct_ov017_02190884_2*)var0->GetPartyMemberByIndex(arg1[var45]);
        var14 = var0->GetGameObjectByIndex(arg1[var45] * 0xc + 0x14);
        if (var46 == NULL) {
            continue;
        }
        ClearByte0xc1Flag0x4_020340f4((unsigned char*)m);
        if (i == 0) {
            GameObject_SetFollowedMember((unsigned char*)m, -1);
            m->fieldB6 = 0x28;
            m->fieldB0 = 0x324;
            if (cancel != 0) {
                if (keep != 0) {
                    GameObject_EnableControl(m);
                    m->obj3D_.DisableFlag(0x1000000);
                } else {
                    GameObject_DisableControl((Obj020397cc*)m, 1);
                }
            }
            GameObject_ClearHidden((unsigned char*)m);
            m->obj3D_.SetInheritedAlpha(0x1f);
            if (LinkSession_IsActive((int*)search) && id != LinkSession_GetOwnSlot(search)) {
                SetByte0xc1Flag0x4_020340e4((unsigned char*)m);
            }
        } else {
            GameObject_SetFollowedMember((unsigned char*)m, out[shown - 1]);
            m->fieldB6 = 0x66;
            m->fieldB0 = 0x648;
            if (reset != 0) {
                GameObject_ResetTrail((unsigned char*)m);
            }
            if (cancel != 0) {
                GameObject_DisableControl((Obj020397cc*)m, 1);
            }
            var46->unknown_0_.EnableFlag(0x80);
        }
        GameObject_SetLinePosition((unsigned char*)m, i);
        m->fieldB4 = 0x189;
        GameObject_SetLineLeader((unsigned char*)m, out[0]);
        if (clearBit1 != 0) {
            GameObject_ResumeFollowing((unsigned char*)m);
        }
        if (var20->unknown_3_ != 0) {
            if (var43 != 0) {
                var46->unknown_c1_0_ |= 2;
            } else {
                var46->unknown_c1_0_ &= ~2;
            }
        }
        if (var14 != NULL) {
            short var47 = var14->obj3D_.unknown_2_;
            if (var47 != 0x2347 && var47 != 0x2348 && var47 != 0x2349) {
                var44++;
            } else if (var12 != 0) {
                var46->unknown_0_.SetInheritedAlpha(0);
            } else {
                if (m->obj3D_.GetInheritedAlpha() == 0) {
                    GameObject_ClearHidden((unsigned char*)m);
                    m->obj3D_.SetInheritedAlpha(0x1f);
                }
                var44++;
            }
        } else {
            var44++;
        }
    }

    unsigned char total = *count;
    unsigned char last = out[*count - 1];
    if (id == 0 && gs->GetPartyMemberByIndex(0xce) != NULL) {
        Member02190884* m = (Member02190884*)gs->GetPartyMemberByIndex(0xce);
        if (m != NULL) {
            GameObject_SetFollowedMember((unsigned char*)m, last);
            m->fieldB6 = 0x66;
            m->fieldB0 = 0x648;
            GameObject_ResetTrail((unsigned char*)m);
            if (cancel != 0) {
                GameObject_DisableControl((Obj020397cc*)m, 1);
            }
            GameObject_SetLinePosition((unsigned char*)m, total);
            m->fieldB4 = 0x189;
            GameObject_SetLineLeader((unsigned char*)m, out[0]);
            m->obj3D_.EnableFlag(0x80);
            if (clearBit1 != 0) {
                GameObject_ResumeFollowing((unsigned char*)m);
            }
        }
    }

    if (var19->unknown_3_ != 0 || var20->unknown_3_ != 0 || var21->unknown_3_ != 0) {
        var13 = 0;
    }
    if (restore != 0) {
        for (int i = 0; i < *count; i++) {
            GameObject* m = gs->GetPartyMemberByIndex(out[i]);
            if (m != NULL) {
                m->obj3D_.position_ = pos[i];
                GameObject_SnapFacing((Obj02033874*)m, rotY[i]);
            }
        }
    }

    if (ctx->unknown_ptr_36d0 != NULL) {
        MapDisplay_RequestMemberRedraw((unsigned char*)ctx->unknown_ptr_36d0, 1);
    }
}
