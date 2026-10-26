#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "Resource/GameResources.h"

struct FlagWord02046708;
struct Obj020397cc;
struct Obj02033874;
struct SearchStruct0202c1a4;

struct Struct_ov017_02190884 {
    unsigned int flags;
};

struct Struct_ov017_02190884_2 {
    Object3D obj3D_;
    char padAC[4];
    short fieldB0;
    char unknown_b2_[2];
    short fieldB4;
    short fieldB6;
    char unknown_b8_[0xc1 - 0xb8];
    unsigned char unknown_c1_0_ : 2;
    char unknown_c2_[0x130 - 0xc2];
    Struct_ov017_02190884* status;
#if defined(jpn)
    char unknown_134_[0x2c6 - 0x134];
#else
    char unknown1_134_[0x2d2 - 0x134];
#endif
    unsigned char unknown_2d2_;
};

struct Flags02190884 {
    char pad0[3];
    unsigned char active;
};

struct Struct_ov017_021d61dc {
    int v[8];
};

extern "C" FlagWord02046708* GlobalFlags_GetInstance();
extern "C" int FlagWord_TestBits(FlagWord02046708* flags, unsigned int mask);
extern "C" void func_020dc548(signed char id, signed char* list, signed char* count);
extern "C" int GameObject_IsClimbingLadder(char* obj);
extern "C" SearchStruct0202c1a4* LinkSession_GetInstance();
extern "C" GameObject* func_0200fee0(GameState* battleStruct, int id);
extern "C" char* Zone3D_GetInstance();
extern "C" int func_020981e4(int obj, int id);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int id);
extern "C" int func_020546a8(void* obj);
extern "C" int func_ov017_02190818(int id);
extern "C" int GameObject_GetLineLeader(void* obj);
extern "C" int GameObject_IsControlEnabled(void* obj);
extern "C" int GameObject_IsControlPending(void* obj);
extern "C" int func_02010038(GameState* battleStruct, unsigned char* out);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" void func_020531f0(void* obj);
extern "C" int GameObject_GetLinePosition(void* obj);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
extern "C" void func_020340f4(unsigned char* obj);
extern "C" void GameObject_SetFollowedMember(unsigned char*, int);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void GameObject_DisableControl(Obj020397cc* obj, int flag);
extern "C" void GameObject_ClearHidden(unsigned char* obj);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int LinkSession_GetOwnSlot(SearchStruct0202c1a4* search);
extern "C" void func_020340e4(unsigned char* obj);
extern "C" void GameObject_ResetTrail(unsigned char* obj);
extern "C" void GameObject_SetLinePosition(unsigned char*, int);
extern "C" void GameObject_SetLineLeader(unsigned char*, int);
extern "C" void GameObject_ResumeFollowing(unsigned char* obj);
extern "C" void GameObject_SnapFacing(Obj02033874* obj, int value);
extern "C" void MapDisplay_RequestMemberRedraw(unsigned char* obj, int value);

#if defined(jpn)
#define data_ov017_021d61dc data_ov017_021d662c
#endif
extern Struct_ov017_021d61dc data_ov017_021d61dc;

// USA: func_ov017_02190884
extern "C" ARM void func_ov017_02190884(int id, int* out, int* count, int arg3, int cancel, int reset) {
    GameState* gs = GameState::GetInstance();

    if (FlagWord_TestBits(GlobalFlags_GetInstance(), 0x2000) != 0) {
        unsigned char* base = (unsigned char*)GameState_GetParty(gs);
        int i;
        for (i = 0; i < base[0xf7c]; i++) {
            out[i] = (base + i)[0xf78];
        }
        *count = base[0xf7c];
        return;
    }

    signed char var3;
    signed char var4[6];
    unsigned char party[5];
    var3 = 0;
    func_020dc548((signed char)id, var4, &var3);
    for (int i = 0; i < var3; i++) {
        GameObject* m = gs->GetPartyMemberByIndex(var4[i]);
        if (m != NULL && GameObject_IsClimbingLadder((char*)m) != 0) {
            return;
        }
    }

    SearchStruct0202c1a4* search = LinkSession_GetInstance();
    GameResources* ctx = GetGameResources();
    if (ctx == NULL) {
        return;
    }
    Struct_ov017_02190884_2* self = (Struct_ov017_02190884_2*)func_0200fee0(gs, id);
    if (self == NULL) {
        return;
    }

    char* map = Zone3D_GetInstance();
    int inRange = 0;
    int var13;
    GameObject* obj;
    if (func_020981e4((int)((Zone3D*)map)->unk_840, *(unsigned short*)map)) {
        inRange = 1;
    }

    int listA[4];
    int listB[4];
    int var17 = 0;
    int var18 = 0;
    Flags02190884* var19 = (Flags02190884*)ctx->unknown_ptr_3718;
    Flags02190884* f734 = (Flags02190884*)ctx->unknown_ptr_array_371c[6];
    Flags02190884* fB30 = (Flags02190884*)ctx->fieldTasks_[13];
    if (!(self->status->flags & 1)) {
        listA[var17++] = id;
    } else {
        listB[var18++] = id;
    }

    for (int i = 3; i >= 0; i--) {
        Struct_ov017_02190884_2* m = (Struct_ov017_02190884_2*)func_0200ff58(gs, i);
        if (m != NULL && id == func_020546a8(m)) {
            if (!(m->status->flags & 1)) {
                listA[var17++] = i;
            } else {
                listB[var18++] = i;
            }
        }
    }

    Struct_ov017_021d61dc order = data_ov017_021d61dc;
    int* p = listA;
    for (int i = 0; i < var17; i++, p++) {
        Struct_ov017_02190884_2* m = (Struct_ov017_02190884_2*)func_0200ff58(gs, *p);
        if (m != NULL) {
            order.v[m->unknown_2d2_] = *p;
        } else {
            order.v[0] = *p;
        }
    }
    p = listB;
    for (int i = 0; i < var18; i++, p++) {
        Struct_ov017_02190884_2* m = (Struct_ov017_02190884_2*)func_0200ff58(gs, *p);
        if (m != NULL) {
            order.v[m->unknown_2d2_ + 4] = *p;
        } else {
            order.v[4] = *p;
        }
    }

    *count = 0;
    p = order.v;
    for (int i = 0; i < 8; i++, p++) {
        if (*p >= 0) {
            out[(*count)++] = *p;
        }
    }

    if (inRange != 0 && func_ov017_02190818(out[0])) {
        for (int i = 1; i < *count; i++) {
            if (!func_ov017_02190818(out[i])) {
                int t = out[i];
                out[i] = out[0];
                out[0] = t;
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
            keep = 1;
        }
        if (GameObject_IsControlPending(leader) != 0) {
            keep = 1;
        }
    }

    if (leader != NULL && out[0] != leader->obj3D_.actorIndex_) {
        GameObject* own = func_0200ff58(gs, id);
        int n;
        if (id == 0 || own != NULL) {
            n = func_02010038(gs, party);
        } else {
            party[0] = id;
            n = 1;
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

    var13 = 0;
    if (out[0] != GameState_GetLeaderIndex(gs)) {
        var13 = 1;
    }

    int bit;
    if (self->unknown_c1_0_ & 2) {
        bit = 1;
    } else {
        bit = 0;
    }
    short shown = 0;
    int i = 0;
    for (; i < *count; i++) {
        Struct_ov017_02190884_2* m = (Struct_ov017_02190884_2*)gs->GetPartyMemberByIndex(out[i]);
        obj = gs->GetGameObjectByIndex(out[i] * 0xc + 0x14);
        if (m == NULL) {
            continue;
        }
        func_020340f4((unsigned char*)m);
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
                func_020340e4((unsigned char*)m);
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
            m->obj3D_.EnableFlag(0x80);
        }
        GameObject_SetLinePosition((unsigned char*)m, i);
        m->fieldB4 = 0x189;
        GameObject_SetLineLeader((unsigned char*)m, out[0]);
        if (arg3 != 0) {
            GameObject_ResumeFollowing((unsigned char*)m);
        }
        if (f734->active != 0) {
            if (bit != 0) {
                m->unknown_c1_0_ |= 2;
            } else {
                m->unknown_c1_0_ &= ~2;
            }
        }
        if (obj != NULL) {
            short kind = obj->obj3D_.unknown_2_;
            if (kind != 0x2347 && kind != 0x2348 && kind != 0x2349) {
                shown++;
            } else if (inRange != 0) {
                m->obj3D_.SetInheritedAlpha(0);
            } else {
                if (m->obj3D_.GetInheritedAlpha() == 0) {
                    GameObject_ClearHidden((unsigned char*)m);
                    m->obj3D_.SetInheritedAlpha(0x1f);
                }
                shown++;
            }
        } else {
            shown++;
        }
    }

    unsigned char total = *count;
    unsigned char last = out[*count - 1];
    if (id == 0 && gs->GetPartyMemberByIndex(0xce) != NULL) {
        Struct_ov017_02190884_2* m = (Struct_ov017_02190884_2*)gs->GetPartyMemberByIndex(0xce);
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
            if (arg3 != 0) {
                GameObject_ResumeFollowing((unsigned char*)m);
            }
        }
    }

    if (var19->active != 0 || f734->active != 0 || fB30->active != 0) {
        var13 = 0;
    }
    if (var13 != 0) {
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
