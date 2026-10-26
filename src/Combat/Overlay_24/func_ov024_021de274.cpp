#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021de274 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Struct_ov024_021de274_2 {
    char pad[0x20];
    struct Struct_ov024_021de274 f20;
    struct Struct_ov024_021de274 f24;
};

struct Struct_ov024_021de274_3 { unsigned char pad : 7; unsigned char flag : 1; };

struct Struct_ov024_021de274_4 {char pad[0x20]; short id;};
struct Struct_ov024_021de274_5 {char pad[0x10];Struct_ov024_021de274_4* info;};
struct Struct_ov024_021de274_6 {char pad[4];Struct_ov024_021de274_5* source;void* unknown_8_;void* action;void* world;char unknown_14_[0x61];unsigned char flag;};

struct Struct_ov000_021584e8;

extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" struct Struct_ov000_021584e8* func_ov000_0215e958(void* world);
extern "C" void func_ov000_0215a88c(void* world, void* entry, int msg);
extern "C" short func_ov000_0215a1d4(void* world, int id, int delta, short* arg3);
extern "C" void func_ov000_02159eac(void* world, unsigned long long* bits, int bit);
extern "C" short func_ov000_0215a124(void* world, int id, int amount);
extern "C" void func_ov000_0215ccbc(void* world, struct Struct_ov000_021584e8* out, GameObject* combatant,
                            short arg3, short valA, short valB, unsigned long long words, unsigned char arg7);

static inline int inline_ov024_021dc540(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currHP; }

extern "C" void func_ov000_0215fe84(void*,void*,int);
extern "C" void func_ov024_021e8bf0(Struct_ov024_021de274_6*,void*,unsigned short*);
static inline int inline_ov000_021537b8(int id){return id>=0 && id<=3;}
// USA: func_ov024_021de274
extern "C" ARM Struct_ov000_021584e8* func_ov024_021de274(Struct_ov024_021de274_6* obj,short arg1,int id,Struct_ov024_021de274_2* params,int amount,int unused,unsigned char enabled){
 GameObject* source;
 GameObject* target;
 int active;
 int original=amount;
 source=GetCombatantByID((int)obj->world,obj->source->info->id);
 if(!source)return 0;
 target=GetCombatantByID((int)obj->world,id);
 if(!target)return 0;
 active=enabled;
 int current=target->currentStats_->primaryStats.currMP;
 if(current<amount)amount=current;
 unsigned long long effects=0;
 unsigned long long var6=0;
 unsigned short selection=0;
 if(active && amount>0){
  selection=func_ov024_021da644(id,params->f20.c,params->f24.a);
  func_ov000_02159eac(obj->world,&effects,1);
  func_ov000_02159eac(obj->world,&effects,0x2a);
 }else{
#if defined(jpn)
  if(original<=0)selection=0x1b;
  else selection=0x1f;
#else
  if(original>0)selection=0x1f;
  else selection=func_ov024_021da644(id,0x26d,0x1b);
#endif
  amount=0;
  obj->flag=0;
 }
 short mp=target->currentStats_->primaryStats.currMP;
 int var9=1;
 if(!inline_ov000_021537b8(id) && target->currentStats_->primaryStats.currMP>=0xff)var9=0;
 if(var9)mp=func_ov000_0215a124(obj->world,id,amount);
 if((unsigned short)obj->source->info->id!=id){
  short var10=0;
  short var11=func_ov000_0215a1d4(obj->world,arg1,amount,&var10);
  if(active && amount>0){
   func_ov000_02159eac(obj->world,&var6,0x22);
   Struct_ov000_021584e8* entry=func_ov000_0215e958(obj->world);
   if(!entry)return 0;
   func_ov000_0215a88c(obj->world,entry,0x26c);
   func_ov000_0215ccbc(obj->world,entry,source,-amount,source->currentStats_->primaryStats.currHP,var11,var6,0);
   func_ov000_0215fe84(obj->unknown_8_,entry,0);
   ++*((unsigned char*)obj->world+0x8e02);
  }
 }
 Struct_ov000_021584e8* entry=func_ov000_0215e958(obj->world);
 if(!entry)return 0;
 func_ov024_021e8bf0(obj,obj->action,&selection);
 func_ov000_0215a88c(obj->world,entry,selection);
 Struct_ov024_021de274_3* flag=(Struct_ov024_021de274_3*)((char*)obj->action+0x1c);
 func_ov000_0215ccbc(obj->world,entry,target,amount,inline_ov024_021dc540(target),mp,effects,flag->flag!=0);
 return entry;
}
