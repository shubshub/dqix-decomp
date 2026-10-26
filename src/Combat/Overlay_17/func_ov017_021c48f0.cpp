#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
struct Fields020407b4; struct Obj02033874; struct Bytes02033b88; struct SearchStruct0202c1a4;
struct Entry_02028bd0 { unsigned short id; unsigned short group:2,rest:14; };
struct Struct_ov017_021c48f0_3 { int x,y,z; };
union Struct_ov017_021c48f0_4 { Struct_ov017_021c48f0_3 unknown_0_; Vector3i vector; };
struct Struct_ov017_021c48f0_5 { unsigned char tag,pad[3]; unsigned short zone; unsigned char unknown_6_,byte7; unsigned short field8; short x,y,z,angle; };
struct Struct_ov017_021c48f0_6 { Object3D object; char unknown_ac_[2]; short height; char unknown_b0_[0xd4-0xb0]; Vector3i previous; unsigned char flags; char unknown_e1_[0x130-0xe1]; unsigned int state; char unknown_134_[0x158-0x134]; Vector3i target; unsigned short unknown_164_,slot; };
struct ActorHead48f0 { char pad0[0x130]; unsigned int* stats; };
#if defined(jpn)
struct Struct_ov017_021c48f0_8 { char pad0[3]; unsigned char active; char pad4[0xfd-4]; unsigned char unknown_101_; };
#else
struct Struct_ov017_021c48f0_8 { char pad0[3]; unsigned char active; char pad4[0x101-4]; unsigned char unknown_101_; };
#endif
struct Party48f0 { char pad0[0xf7d]; unsigned char flag; };
#if defined(jpn)
struct Resource48f0 { char pad0[0x34c0]; unsigned char* bits; char unknown_34c4_[0x3524-0x34c4]; Struct_ov017_021c48f0_8* work; };
#else
struct Resource48f0 { char pad0[0x36d0]; unsigned char* bits; char unknown_36d4_[0x3734-0x36d4]; Struct_ov017_021c48f0_8* work; };
#endif
extern "C" int GameObject_GetLineLeader(void*); extern "C" void GameObject_ClearHidden(unsigned char*);
extern "C" GameObject* func_0200ff58(GameState*,int); extern "C" int func_020546a8(void*);
extern "C" unsigned short* Zone3D_GetInstance(); extern "C" void GameObject_ResetTrail(unsigned char*);
extern "C" void func_020407b4(Fields020407b4*,int,int,int); extern "C" void GameObject_SnapFacing(Obj02033874*,int); extern "C" void GameObject_ForceMotionState(Bytes02033b88*,int);
extern "C" void func_ov017_02193428(void*,void*); extern "C" void MapDisplay_RecheckMember(unsigned char*,int);
extern "C" int LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void func_ov017_0219dc90(GameResources*,int,int,int,int);
extern "C" Entry_02028bd0* ZoneRecords_GetInstance(); extern "C" Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0*,int);
extern "C" void func_ov017_021c8f3c(int,int); extern "C" void __clear(void*,int);
extern "C" void func_ov017_021c95ec(int,int,int,int,int,Struct_ov017_021c48f0_3,int,int,int);
extern "C" void func_ov017_021c9168(int,int,int,int,Struct_ov017_021c48f0_3,Struct_ov017_021c48f0_3,int);
extern "C" void func_ov017_021c927c(int,int,int,Struct_ov017_021c48f0_3,int,int,int);
extern "C" int LinkSession_IsHostOrSolo(void*); extern "C" void func_ov017_021ce400(int,int);
extern "C" int func_02039790(void*,int); extern "C" void func_ov017_021bd4d0(void*,int,int,int); extern "C" void func_ov017_021c3e18(unsigned char);

// USA: func_ov017_021c48f0
extern "C" ARM void func_ov017_021c48f0(int memberId,Struct_ov017_021c48f0_5* event,GameState* game,GameResources* resources,SearchStruct0202c1a4* search) {
    int leader;
    Entry_02028bd0* entry;
    Struct_ov017_021c48f0_8* work;
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
        for(int i=0;i<4;i++) { GameObject* actor=func_0200ff58(game,i); if(actor!=NULL && memberId==func_020546a8(actor)) actors[count++]=actor; }
        int reveal=(work->active==0 || work->unknown_101_==0)?1:0;
        for(int i=0;i<count;i++) {
            GameObject* actor=actors[i];
            if(actor==NULL) continue;
            if(!actor->obj3D_.IsVisible() && reveal) {
                if(event->byte7==0 || zone!=*Zone3D_GetInstance()) actor->obj3D_.MakeVisible();
                GameObject_ResetTrail((unsigned char*)actor);
                if(event->zone==10000 && GameObject_GetLineLeader(actor)!=-1) func_020407b4((Fields020407b4*)actor,0xff000,0,0xff000);
                else actor->obj3D_.position_=position;
                GameObject_SnapFacing((Obj02033874*)actor,event->angle);
                if(i!=0) GameObject_ForceMotionState((Bytes02033b88*)actor,0);
                ((Struct_ov017_021c48f0_6*)actors[i])->previous=position;
                ((Struct_ov017_021c48f0_6*)actors[i])->flags|=0x20;
            }
            if(event->zone==10000 && leader==actor->obj3D_.actorIndex_ && reveal) {
                func_020407b4((Fields020407b4*)actors[i],0x5f0a,0x3614,0x570);
                GameObject_SnapFacing((Obj02033874*)actors[i],0x4b66);
            }
            actor->obj3D_.EnableFlag(0x4000000);
            if(work->active==0) func_ov017_02193428(actor,0);
            MapDisplay_RecheckMember(((Resource48f0*)resources)->bits,actor->obj3D_.actorIndex_);
        }
    }
    if(LinkSession_GetOwnSlot(search)==0) {
        func_ov017_0219dc90(resources,memberId,event->zone,event->unknown_6_,event->field8);
        entry=ZoneRecords_Find(ZoneRecords_GetInstance(),zone);
        if(entry!=NULL) {
            int height;
            Struct_ov017_021c48f0_4 actorPosition,rotation,target;
            Struct_ov017_021c48f0_3 var18,var19,var20;
            for(int i=0;i<12;i++) {
                int base=entry->group*12+0x70;
                GameObject* monster=game->GetFieldMonsterByIndex(i+base);
                if(monster==NULL || monster->obj3D_.unknown_2_<0) continue;
                int slot;
                int kind=monster->obj3D_.unknown_2_;
                actorPosition=*(Struct_ov017_021c48f0_4*)&monster->obj3D_.position_;
                rotation=*(Struct_ov017_021c48f0_4*)&monster->obj3D_.rotation_;
                slot=((Struct_ov017_021c48f0_6*)monster)->slot;
                func_ov017_021c8f3c(i+base,memberId);
                switch(((Struct_ov017_021c48f0_6*)monster)->state) {
                case 1: __clear(&var18,12); func_ov017_021c95ec(zone,i,kind,1,-1,var18,0,0,0); break;
                case 2: func_ov017_021c9168(zone,i,kind,((Struct_ov017_021c48f0_6*)monster)->unknown_164_,actorPosition.unknown_0_,rotation.unknown_0_,memberId); break;
                case 3: target.vector=((Struct_ov017_021c48f0_6*)monster)->target; func_ov017_021c927c(zone,i,kind,target.unknown_0_,height,3,-1); break;
                case 4: __clear(&var19,12); func_ov017_021c95ec(zone,i,kind,4,slot,var19,0,0,0); break;
                case 5: height=((Struct_ov017_021c48f0_6*)monster)->height; target.vector=((Struct_ov017_021c48f0_6*)monster)->target; func_ov017_021c927c(zone,i,kind,target.unknown_0_,height,5,slot); break;
                case 6: height=((Struct_ov017_021c48f0_6*)monster)->height; target.vector=((Struct_ov017_021c48f0_6*)monster)->target; func_ov017_021c927c(zone,i,kind,target.unknown_0_,height,6,slot); break;
                case 7: height=((Struct_ov017_021c48f0_6*)monster)->height; target.vector=((Struct_ov017_021c48f0_6*)monster)->target; func_ov017_021c927c(zone,i,kind,target.unknown_0_,height,7,slot); break;
                case 9: __clear(&var20,12); func_ov017_021c95ec(zone,i,kind,9,memberId,var20,0,0,0); break;
                }
            }
        }
    }
    Party48f0* party=(Party48f0*)GameState_GetParty(game);
    if(LinkSession_IsHostOrSolo(search) && party->flag!=0) func_ov017_021ce400(party->flag,*Zone3D_GetInstance());
    if(game->GetPartyMemberByIndex(leader)!=NULL && func_02039790(game->GetPartyMemberByIndex(leader),0x20)) func_ov017_021bd4d0(work,(unsigned char)leader,0,1);
    if(zone==*Zone3D_GetInstance()) func_ov017_021c3e18(0);
}
