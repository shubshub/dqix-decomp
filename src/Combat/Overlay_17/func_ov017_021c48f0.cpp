#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
struct Struct_02040774_2; struct Struct_02033834; struct Struct_02010604; struct Struct_0202c1a4;
struct Struct_020fdd44 { unsigned short unknown_0_; unsigned short unknown_2_0_:2,unknown_2_2_:14; };
struct Struct_ov017_021c48f0_3 { int unknown_0_,unknown_4_,unknown_8_; };
union Struct_ov017_021c48f0_4 { Struct_ov017_021c48f0_3 unknown_0_; Vector3i unknown1_0_; };
struct Struct_ov017_021c48f0_5 { unsigned char unknown_0_,unknown_1_[3]; unsigned short unknown_4_; unsigned char unknown_6_,unknown_7_; unsigned short unknown_8_; short unknown_a_,unknown_c_,unknown_e_,unknown_10_; };
struct Struct_ov017_021c48f0_6 { Object3D unknown_0_; char unknown_ac_[2]; short unknown_ae_; char unknown_b0_[0xd4-0xb0]; Vector3i unknown_d4_; unsigned char unknown_e0_; char unknown_e1_[0x130-0xe1]; unsigned int unknown_130_; char unknown_134_[0x158-0x134]; Vector3i unknown_158_; unsigned short unknown_164_,unknown_166_; };
struct Struct_ov017_021c48f0_7 { char unknown_0_[0x130]; unsigned int* unknown_130_; };
#if defined(jpn)
struct Struct_ov017_021c48f0_8 { char unknown_0_[3]; unsigned char unknown_3_; char unknown_4_[0xfd-4]; unsigned char unknown_101_; };
#else
struct Struct_ov017_021c48f0_8 { char unknown_0_[3]; unsigned char unknown_3_; char unknown_4_[0x101-4]; unsigned char unknown_101_; };
#endif
struct Struct_ov017_021c48f0 { char unknown_0_[0xf7d]; unsigned char unknown_f7d_; };
#if defined(jpn)
struct Struct_ov017_021c48f0_2 { char unknown_0_[0x34c0]; unsigned char* unknown_36d0_; char unknown_34c4_[0x3524-0x34c4]; Struct_ov017_021c48f0_8* unknown_3734_; };
#else
struct Struct_ov017_021c48f0_2 { char unknown_0_[0x36d0]; unsigned char* unknown_36d0_; char unknown_36d4_[0x3734-0x36d4]; Struct_ov017_021c48f0_8* unknown_3734_; };
#endif
int GameObject_GetLineLeader(void*); void GameObject_ClearHidden(unsigned char*);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState*,int); int GetSignedByte0x2d0_020546a8(void*);
extern "C" unsigned short* Zone3D_GetInstance(); void GameObject_ResetTrail(unsigned char*);
void SetFields0x44(Fields020407b4*,int,int,int); void GameObject_SnapFacing(Obj02033874*,int); void GameObject_ForceMotionState(Bytes02033b88*,int);
void DispatchWithZeroExtras_02193428(void*,void*); void MapDisplay_RecheckMember(unsigned char*,int);
int LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void func_ov017_0219dc90(GameResources*,int,int,int,int);
Entry_02028bd0* ZoneRecords_GetInstance(); Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0*,int);
extern "C" void func_ov017_021c8f3c(int,int); extern "C" void __clear(void*,int);
extern "C" void func_ov017_021c95ec(int,int,int,int,int,Vec48f0,int,int,int);
extern "C" void func_ov017_021c9168(int,int,int,int,Vec48f0,Vec48f0,int);
extern "C" void func_ov017_021c927c(int,int,int,Vec48f0,int,int,int);
extern "C" int LinkSession_IsHostOrSolo(void*); extern "C" void func_ov017_021ce400(int,int);
int GetByteFieldMasked0x1ce_02039790(void*,int); extern "C" void func_ov017_021bd4d0(void*,int,int,int); extern "C" void func_ov017_021c3e18(unsigned char);

// USA: func_ov017_021c48f0
extern "C" ARM void func_ov017_021c48f0(int memberId,Event48f0* event,GameState* game,GameResources* resources,SearchStruct0202c1a4* search) {
    int leader;
    Entry_02028bd0* entry;
    Work48f0* work;
    work=((Resource48f0*)resources)->work;
    int zone=event->zone;
    Vector3i position;
    position.x=event->x<<5; position.y=event->y<<5; position.z=event->z<<5;
    if(zone==10000) zone=0x170c; else if(zone==10100) zone=0x1901;
    int count=0; leader=0;
    GameObject* actors[4]; actors[count++]=game->GetPartyMemberByIndex(memberId);
    if(actors[0]!=NULL) {
        GameObject* first=actors[0];
        if(*((ActorHead48f0*)first)->stats&1) { leader=GameObject_GetLineLeader(first); GameObject* actor=game->GetPartyMemberByIndex(leader); if(actor!=NULL) GameObject_ClearHidden((unsigned char*)actor); }
        else { GameObject_ClearHidden((unsigned char*)first); leader=memberId; }
        for(int i=0;i<4;i++) { GameObject* actor=GetCombatantWithFlag0x1000_0200ff58(game,i); if(actor!=NULL && memberId==GetSignedByte0x2d0_020546a8(actor)) actors[count++]=actor; }
        int reveal=(work->active==0 || work->ready==0)?1:0;
        for(int i=0;i<count;i++) {
            GameObject* actor=actors[i];
            if(actor==NULL) continue;
            if(!actor->obj3D_.IsVisible() && reveal) {
                if(event->byte7==0 || zone!=*Zone3D_GetInstance()) actor->obj3D_.MakeVisible();
                GameObject_ResetTrail((unsigned char*)actor);
                if(event->zone==10000 && GameObject_GetLineLeader(actor)!=-1) SetFields0x44((Fields020407b4*)actor,0xff000,0,0xff000);
                else actor->obj3D_.position_=position;
                GameObject_SnapFacing((Obj02033874*)actor,event->angle);
                if(i!=0) GameObject_ForceMotionState((Bytes02033b88*)actor,0);
                ((Actor48f0*)actors[i])->previous=position;
                ((Actor48f0*)actors[i])->flags|=0x20;
            }
            if(event->zone==10000 && leader==actor->obj3D_.actorIndex_ && reveal) {
                SetFields0x44((Fields020407b4*)actors[i],0x5f0a,0x3614,0x570);
                GameObject_SnapFacing((Obj02033874*)actors[i],0x4b66);
            }
            actor->obj3D_.EnableFlag(0x4000000);
            if(work->active==0) DispatchWithZeroExtras_02193428(actor,0);
            MapDisplay_RecheckMember(((Resource48f0*)resources)->bits,actor->obj3D_.actorIndex_);
        }
    }
    if(LinkSession_GetOwnSlot(search)==0) {
        func_ov017_0219dc90(resources,memberId,event->zone,event->byte6,event->field8);
        entry=ZoneRecords_Find(ZoneRecords_GetInstance(),zone);
        if(entry!=NULL) {
            int height;
            Position48f0 actorPosition,rotation,target;
            Vec48f0 zero1,zero4,zero9;
            for(int i=0;i<12;i++) {
                int base=entry->group*12+0x70;
                GameObject* monster=game->GetFieldMonsterByIndex(i+base);
                if(monster==NULL || monster->obj3D_.unknown_2_<0) continue;
                int slot;
                int kind=monster->obj3D_.unknown_2_;
                actorPosition=*(Position48f0*)&monster->obj3D_.position_;
                rotation=*(Position48f0*)&monster->obj3D_.rotation_;
                slot=((Actor48f0*)monster)->slot;
                func_ov017_021c8f3c(i+base,memberId);
                switch(((Actor48f0*)monster)->state) {
                case 1: __clear(&zero1,12); func_ov017_021c95ec(zone,i,kind,1,-1,zero1,0,0,0); break;
                case 2: func_ov017_021c9168(zone,i,kind,((Actor48f0*)monster)->field164,actorPosition.plain,rotation.plain,memberId); break;
                case 3: target.vector=((Actor48f0*)monster)->target; func_ov017_021c927c(zone,i,kind,target.plain,height,3,-1); break;
                case 4: __clear(&zero4,12); func_ov017_021c95ec(zone,i,kind,4,slot,zero4,0,0,0); break;
                case 5: height=((Actor48f0*)monster)->height; target.vector=((Actor48f0*)monster)->target; func_ov017_021c927c(zone,i,kind,target.plain,height,5,slot); break;
                case 6: height=((Actor48f0*)monster)->height; target.vector=((Actor48f0*)monster)->target; func_ov017_021c927c(zone,i,kind,target.plain,height,6,slot); break;
                case 7: height=((Actor48f0*)monster)->height; target.vector=((Actor48f0*)monster)->target; func_ov017_021c927c(zone,i,kind,target.plain,height,7,slot); break;
                case 9: __clear(&zero9,12); func_ov017_021c95ec(zone,i,kind,9,memberId,zero9,0,0,0); break;
                }
            }
        }
    }
    Party48f0* party=(Party48f0*)GameState_GetParty(game);
    if(LinkSession_IsHostOrSolo(search) && party->flag!=0) func_ov017_021ce400(party->flag,*Zone3D_GetInstance());
    if(game->GetPartyMemberByIndex(leader)!=NULL && GetByteFieldMasked0x1ce_02039790(game->GetPartyMemberByIndex(leader),0x20)) func_ov017_021bd4d0(work,(unsigned char)leader,0,1);
    if(zone==*Zone3D_GetInstance()) func_ov017_021c3e18(0);
}
