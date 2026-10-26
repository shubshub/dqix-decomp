#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#if defined(jpn)
enum { Enum_ov003_02154af4_400=0x18c, Enum_ov003_02154af4_336=0x144, Enum_ov003_02154af4_2384=0x8b8, Enum_ov003_02154af4_54=0x2a, kGlobalFlag=0x17de };
#else
enum { Enum_ov003_02154af4_400=0x190, Enum_ov003_02154af4_336=0x150, Enum_ov003_02154af4_2384=0x950, Enum_ov003_02154af4_54=0x36, kGlobalFlag=0x19ae };
#endif
struct Status { unsigned int flags; unsigned short hp; unsigned short mp; };
struct Struct_ov003_02154af4_4 { char pad[0x30]; unsigned short hp; unsigned short mp; };
struct Vocation { char pad[Enum_ov003_02154af4_2384]; unsigned int value; };
struct Struct_ov000_0217c638 { char pad[0x130]; Status* status; Struct_ov003_02154af4_4* profile; char unknown_138_[Enum_ov003_02154af4_336-0x138]; Vocation* vocation;
 unsigned int inline_ov003_02154af4() const { return status->hp; }
 unsigned int MaxHP() const { return profile->hp; }
 unsigned int MP() const { return status->mp; }
 unsigned int MaxMP() const { return profile->mp; }
 unsigned int Voc() const { return vocation->value; }
 unsigned int Flags() const { return status->flags; }
};
struct Struct_ov003_02154af4 { unsigned int flags; unsigned short hp, maxHP; unsigned short mp,maxMP; unsigned char table, vocation; char pad[2]; };
struct Struct_ov003_02154af4_2 { char pad[Enum_ov003_02154af4_54]; short selected; };
struct Scene {
 void* unknown_0_; void* controller; short* selection; char unknown_c_[0x18-0xc]; Struct_ov003_02154af4_2* model; void* inner;
 char pad20[0x80-0x20]; char selector[0xc]; unsigned short unknown_8c_; unsigned char unknown_8e_;
 char unknown_8f_[Enum_ov003_02154af4_400-0x8f]; Struct_ov003_02154af4 cache[4]; int task; int unknown_1d4_; int changed; unsigned int scale;
 char unknown_1e0_[6]; short element; short previous; short unknown_1ea_; short pending, unknown_1ee_;
 char unknown_1f0_[8]; unsigned char state, flag; char unknown_1fa_[2]; unsigned int flags; int unknown_200_; int unknown_204_;
 char unknown_208_[0x334-0x204]; unsigned char blocked, reset, started;
};
struct Party { char pad[0xf78]; unsigned char ids[4]; unsigned char count; };
struct Struct_020e6d5c_13 { unsigned int fn, unknown_4_; };
struct Struct_ov003_0217f340 { Struct_020e6d5c_13 entries[8]; };
extern short data_ov003_0217f2a8[3];
extern Struct_ov003_0217f340 data_ov003_0217f340;
extern Struct_020e6d5c_13 __ptmf_null;
extern "C" int func_ov017_021959b4();
extern "C" char* MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char*);
struct Struct_020e28dc;
extern "C" int func_020e28dc(Struct_020e28dc*);
struct Struct_020e25e8;
extern "C" void func_020e25e8(Struct_020e25e8*);
extern "C" void func_ov003_021537d4(void*,unsigned int);
extern "C" void func_ov003_021552b8(Scene*);
struct Struct_0207fc6c;
extern "C" void func_0207fc6c(Struct_0207fc6c*, int);
extern "C" unsigned int GameObject_GetPartyMemberLevel(void*);
struct Struct_0207fdcc_2;
extern "C" int func_020811d0(Struct_0207fdcc_2*, int);
extern "C" void func_ov003_02158334(Scene*);
extern "C" void func_02081f20(void*,unsigned int);
extern "C" int func_020800fc(Struct_ov003_02154af4_2*,short*,int,unsigned short,unsigned char,int);
extern "C" void func_020804fc(void*, int);
extern "C" void func_020813ec(Struct_ov003_02154af4_2*,int);
struct Struct_020e263c_2;
extern "C" void func_020e263c(Struct_020e263c_2*, int);
// USA: func_ov003_02154af4
extern "C" ARM int func_ov003_02154af4(Scene* self,unsigned int scale) {
 self->scale=scale;
 if (!self->started && func_ov017_021959b4()) { self->started=1; self->reset=1; }
 if (self->reset && !self->blocked) {
  if(self->selection) *self->selection=-1;
  self->selection=0;
  MessageSystem_Reset(MessageSystem_GetInstance());
  self->unknown_1ee_=-1; self->pending=self->unknown_1ee_;
  if(self->inner && func_020e28dc((Struct_020e28dc*)self->inner)) func_020e25e8((Struct_020e25e8*)self->inner);
  self->state=6; self->flag=0; self->reset=0;
 }
 if(!self->unknown_204_) func_ov003_021537d4(self->controller,scale);
 if(self->pending>=0) { func_ov003_021552b8(self); return 0; }
 if(self->state) MessageSystem_GetInstance()[kGlobalFlag]=0;
 Struct_ov003_02154af4_2* model=self->model;
 if(model) {
  if(!self->unknown_204_) func_0207fc6c((Struct_0207fc6c*)model, scale);
  int i; Struct_ov003_02154af4* c; Struct_ov000_0217c638* member; bool changed; int id; Party* party; GameState* gs;
  changed=false;
  gs=GameState::GetInstance();
  party=(Party*)GameState_GetParty(gs);
  int count=party->count;
  for(i=0;i<count;i++) {
   id=party->ids[i];
   member=(Struct_ov000_0217c638*)gs->GetPartyMemberByIndex(id);
   if(member) {
    c=&self->cache[id];
    unsigned int hp=member->inline_ov003_02154af4();
    unsigned int maxhp,mp,maxmp,voc,flags;
    if(!(c->hp==hp && ((maxhp=member->MaxHP()), c->maxHP==maxhp) && ((mp=member->MP()), c->mp==mp) && ((maxmp=member->MaxMP()), c->maxMP==maxmp) && ((voc=member->Voc()), c->vocation==voc) && c->table==GameObject_GetPartyMemberLevel(member) && ((flags=member->Flags()), c->flags==flags))) {
     c->hp=member->status->hp; c->maxHP=member->profile->hp; c->mp=member->status->mp; c->maxMP=member->profile->mp;
     c->vocation=member->vocation->value; c->table=GameObject_GetPartyMemberLevel(member); changed=true; c->flags=member->status->flags;
    }
   }
  }
  if(changed) for(int i=0;i<3;i++) if(func_020811d0((Struct_0207fdcc_2*)model, data_ov003_0217f2a8[i])) { func_ov003_02158334(self);break; }
 }
 if(self->selection) {
  func_02081f20(self->selector,scale);
  self->previous=*self->selection;
  self->changed=func_020800fc(model,self->selection,self->previous,self->unknown_8c_,self->unknown_8e_,(self->flags&4)!=0);
  model->selected=*self->selection;
  if(self->changed) func_020804fc(model, self->element);
  if(self->previous!=*self->selection) func_020813ec(model,self->element);
 }
 if(self->inner && func_020e28dc((Struct_020e28dc*)self->inner)) func_020e263c((Struct_020e263c_2*)self->inner, self->scale);
 Struct_ov003_0217f340 buf; buf=data_ov003_0217f340;
 unsigned int var17=__ptmf_null.unknown_4_;
 unsigned int fn=__ptmf_null.fn;
 buf.entries[7].unknown_4_=var17; buf.entries[7].fn=fn;
 if(!buf.entries[self->state].fn) {
  BackgroundLoader::GetInstance()->RemoveTask(self->task);self->task=-1;return 1;
 }
 Struct_020e6d5c_13* d=&buf.entries[self->state];
 void* base=(char*)self+((int)d->unknown_4_>>1);
 void* callback;
 if(d->unknown_4_&1) callback=*(void**)((char*)*(void**)base+d->fn);else callback=(void*)d->fn;
 ((void(*)(void*))callback)(base);
 return 0;
}
