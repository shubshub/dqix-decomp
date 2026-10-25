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
int TestFlags02046708(FlagWord02046708* flags, unsigned int mask);
extern "C" void func_020dc548(signed char id, signed char* list, signed char* count);
int GetByte0x26c_02039d7c(char* obj);
extern "C" SearchStruct0202c1a4* func_0202ae18();
GameObject* GetCombatantWithFlag0x200_0200fee0(GameState* battleStruct, int id);
extern "C" char* Zone3D_GetInstance();
int IsIdInRange020981e4(int obj, int id);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int id);
int GetSignedByte0x2d0_020546a8(void* obj);
int IsCombatantField2InMonsterRange_02190818(int id);
int GetSignedByte0x1ca_02039888(void* obj);
int GetByteField0x252_02039820(void* obj);
int GetByteField0x253_02039828(void* obj);
int CollectCombatantsWithFlag0x1000_02010038(GameState* battleStruct, unsigned char* out);
int CheckSubstructByte0x7cPositive_020535c8(signed char* obj);
extern "C" void func_020531f0(void* obj);
int GetSignedByte0x1c9_02039874(void* obj);
unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
void ClearByte0xc1Flag0x4_020340f4(unsigned char* obj);
void SetByte0x1c8_02039858(unsigned char*, int);
void GameObject_EnableControl(void* obj);
void GameObject_DisableControl(Obj020397cc* obj, int flag);
void ClearFlag0x1ceBit0x4_02039d58(unsigned char* obj);
int CheckField0NonZero_0202b7d8(int* obj);
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* search);
void SetByte0xc1Flag0x4_020340e4(unsigned char* obj);
void ClearBytesAndZeroBlock02039d24(unsigned char* obj);
void SetByte0x1c9_0203986c(unsigned char*, int);
void SetByte0x1ca_02039880(unsigned char*, int);
void ClearFlag0x1ceBit0x1_020398a4(unsigned char* obj);
void SetVecYFromValue02033874(Obj02033874* obj, int value);
void SetFlagBits0x55e_0202006c(unsigned char* obj, int value);

#if defined(jpn)
#define data_ov017_021d61dc data_ov017_021d662c
#endif
extern Struct_ov017_021d61dc data_ov017_021d61dc;

// USA: func_ov017_02190884
extern "C" ARM void func_ov017_02190884(int arg0, int* arg1, int* arg2, int arg3, int arg4, int arg5) {
    GameState* var0 = GameState::GetInstance();

    if (TestFlags02046708(GlobalFlags_GetInstance(), 0x2000) != 0) {
        unsigned char* base = (unsigned char*)GameState_GetParty(gs);
        int i;
        for (i = 0; i < base[0xf7c]; i++) {
            out[i] = (base + i)[0xf78];
        }
        *arg2 = var1[0xf7c];
        return;
    }

    signed char var3;
    signed char var4[6];
    unsigned char var5[5];
    var3 = 0;
    func_020dc548((signed char)arg0, var4, &var3);
    for (int var6 = 0; var6 < var3; var6++) {
        GameObject* var7 = var0->GetPartyMemberByIndex(var4[var6]);
        if (var7 != NULL && func_02039d7c((char*)var7) != 0) {
            return;
        }
    }

    Struct_0202c1a4* var8 = func_0202ae18();
    GameResources* var9 = GetGameResources();
    if (var9 == NULL) {
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
    GameObject* leader = gs->GetPartyMemberByIndex(GetSignedByte0x1ca_02039888(self));
    if (leader != NULL) {
        if (GetByteField0x252_02039820(leader) == 0) {
            keep = 0;
        } else {
            var33 = 1;
        }
        if (func_02039828(var34) != 0) {
            var33 = 1;
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
        for (int var37 = 0; var37 < var36; var37++) {
            GameObject* var38 = var0->GetPartyMemberByIndex(var5[var37]);
            if (var38 != NULL && func_020535c8((signed char*)var38)) {
                func_020531f0(var38);
            }
        }
    }

    Vector3i var39[4];
    int var40[4];
    for (int var41 = 0; var41 < *arg2; var41++) {
        GameObject* var42 = var0->GetPartyMemberByIndex(arg1[var41]);
        if (var42 != NULL) {
            var39[func_02039874(var42)] = var42->obj3D_.position_;
            var40[func_02039874(var42)] = var42->obj3D_.rotation_.y;
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
            SetByte0x1c8_02039858((unsigned char*)m, -1);
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
            func_02039d58((unsigned char*)var46);
            var46->unknown_0_.SetInheritedAlpha(0x1f);
            if (func_0202b7d8((int*)var8) && arg0 != func_0202c1a4(var8)) {
                func_020340e4((unsigned char*)var46);
            }
        } else {
            func_02039858((unsigned char*)var46, arg1[var44 - 1]);
            var46->unknown_b6_ = 0x66;
            var46->unknown_b0_ = 0x648;
            if (arg5 != 0) {
                func_02039d24((unsigned char*)var46);
            }
            if (cancel != 0) {
                GameObject_DisableControl((Obj020397cc*)m, 1);
            }
            var46->unknown_0_.EnableFlag(0x80);
        }
        func_0203986c((unsigned char*)var46, var45);
        var46->unknown_b4_ = 0x189;
        func_02039880((unsigned char*)var46, arg1[0]);
        if (arg3 != 0) {
            func_020398a4((unsigned char*)var46);
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
                if (var46->unknown_0_.GetInheritedAlpha() == 0) {
                    func_02039d58((unsigned char*)var46);
                    var46->unknown_0_.SetInheritedAlpha(0x1f);
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
            SetByte0x1c8_02039858((unsigned char*)m, last);
            m->fieldB6 = 0x66;
            m->fieldB0 = 0x648;
            ClearBytesAndZeroBlock02039d24((unsigned char*)m);
            if (cancel != 0) {
                GameObject_DisableControl((Obj020397cc*)m, 1);
            }
            func_0203986c((unsigned char*)var50, var48);
            var50->unknown_b4_ = 0x189;
            func_02039880((unsigned char*)var50, arg1[0]);
            var50->unknown_0_.EnableFlag(0x80);
            if (arg3 != 0) {
                func_020398a4((unsigned char*)var50);
            }
        }
    }

    if (var19->unknown_3_ != 0 || var20->unknown_3_ != 0 || var21->unknown_3_ != 0) {
        var13 = 0;
    }
    if (var13 != 0) {
        for (int var51 = 0; var51 < *arg2; var51++) {
            GameObject* var52 = var0->GetPartyMemberByIndex(arg1[var51]);
            if (var52 != NULL) {
                var52->obj3D_.position_ = var39[var51];
                func_02033874((Struct_02033834*)var52, var40[var51]);
            }
        }
    }

    if (var9->unknown_ptr_36d0 != NULL) {
        func_0202006c((unsigned char*)var9->unknown_ptr_36d0, 1);
    }
}
