#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
extern "C" void* GameState_GetParty(GameState*);
struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void func_ov000_0215a8d4(unsigned char*, int);
extern "C" int func_020881c4(unsigned char*);
extern "C" int func_0208810c(unsigned char*);
extern "C" void func_02088220(void*, int);
extern "C" int func_02088208(void*, int);
extern "C" void func_02088150(void*);
extern "C" int func_ov024_021e8c48(void*, signed char);
extern "C" unsigned short func_ov024_021da644(int,int,int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_0215a88c(void*,void*,int);
extern "C" void func_ov000_0215ffc4(void*,void*,int);
extern "C" void func_ov000_02159eac(void*,unsigned long long*,int);
extern "C" void func_ov000_0215cd44(void*,void*,GameObject*,short,unsigned long long,unsigned char);
extern "C" void func_ov000_0215af54(void*,int,int);
struct Struct_ov024_021dc93c {char pad[0x1c];unsigned char unused:7;unsigned char flag:1;};
struct Struct_ov024_021dc93c_2 {char pad[0xc];Struct_ov024_021dc93c* action;void* context;char unknown_14_[0x71-0x14];unsigned char done;char unknown_72_[2];unsigned char changed;};
struct Struct_ov024_021dc93c_3 {unsigned int code:12;unsigned int rest:20;};
struct Struct_ov024_021dc93c_4 {unsigned int a:10;unsigned int b:10;unsigned int c:10;unsigned int rest:2;};
struct Struct_ov024_021dc93c_5 {char pad[4];Struct_ov024_021dc93c_3 field4;char pad8[0x1c];Struct_ov024_021dc93c_4 field24;char pad28[8];short count;};
struct Struct_ov024_021dc93c_6 {char pad[0x24];unsigned char stage;};
static inline void* inline_ov024_021dc93c(Struct_ov024_021dc93c_2* o){ SDK_NULL_ASSERT(o); return o->context; }
static inline int inline_ov000_02156cc4_2(int id){ return id>=0 && id<=3; }
// USA: func_ov024_021dc93c
extern "C" ARM void* func_ov024_021dc93c(Struct_ov024_021dc93c_2* obj,short arg1,int id,Struct_ov024_021dc93c_5* params,int amount,int unused,unsigned char enabled){
 GameObject* target=GetCombatantByID((int)obj->context,id);
 if(!target)return 0;
 int done=0;
 int ok=0;
 int message;
 unsigned long long effects=0;
 unsigned short code=params->field4.code;
 if(enabled){
  if(code==0x151 || code==0x152){
   if(code==0x151){
    if(func_020881c4((unsigned char*)target->currentStats_))ok=1;
   }else if(code==0x152){
    if(func_0208810c((unsigned char*)target->currentStats_))ok=1;
   }
   int stage;
   int count=params->count;
   stage=((Struct_ov024_021dc93c_6*)target->currentStats_)->stage;
   if(stage>=count)ok=0;
   if(ok){
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    func_ov000_0215cd44(obj->context,entry,target,stage,effects,obj->action->flag!=0);
    func_ov000_0215ffc4(obj->action,entry,0);
    ++*((unsigned char*)obj->context+0x8e02);
    func_ov000_0215a88c(obj->context,entry,0x152);
    if(stage<count){
     message=0;
     while(stage<3){
      ++stage;
      switch(stage){case 1:message=0x31;break;case 2:message=0x32;break;case 3:message=0x33;break;}
      effects=0;
      func_ov000_02159eac(obj->context,&effects,0x23);
      void* step=func_ov000_0215e958(obj->context);
      if(!step)return 0;
      func_ov000_0215cd44(obj->context,step,target,stage,effects,obj->action->flag!=0);
      func_ov000_0215ffc4(obj->action,step,0);
      ++*((unsigned char*)obj->context+0x8e02);
      obj->changed=1;
      func_ov000_0215a88c(obj->context,step,message);
     }
     if(count>=4){
      entry=func_ov000_0215e958(obj->context);
      if(!entry)return 0;
      func_02088150(target->currentStats_);
      func_ov000_0215a88c(obj->context,entry,0x34);
      func_ov000_02159eac(obj->context,&effects,7);
      func_ov000_0215cd44(obj->context,entry,target,stage,effects,obj->action->flag!=0);
      func_ov000_0215ffc4(obj->action,entry,0);
      ++*((unsigned char*)obj->context+0x8e02);
      obj->changed=1;
      func_ov000_0215a88c(obj->context,entry,message);
      func_ov000_0215af54(obj->context,id,0);
     }else{
      func_02088220(target->currentStats_, count);
     }
    }
   }
  }else if(func_020881c4((unsigned char*)target->currentStats_)){
   int count=params->count;
   int total=((Struct_ov024_021dc93c_6*)target->currentStats_)->stage+count;
   if(total>4)count-=total-4;
   for(;count>0;count--){
    int result=func_02088208(target->currentStats_, (int)inline_ov024_021dc93c(obj));
    effects=0;
    message=func_ov024_021e8c48(obj, result);
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    if(result>0){
     func_ov000_02159eac(obj->context,&effects,0x23);
     if(result==4){
      func_ov000_02159eac(obj->context,&effects,7);
      func_ov000_0215af54(obj->context,id,0);
      void* list=GameState_GetParty(GameState::GetInstance());
      if(func_02086ef0((ArrayContainsByteStruct*)list, arg1) && code==0xa8)
       func_ov000_0215a8d4((unsigned char*)obj->context, 3);
     }
    }else{
     effects=0;
     result=0;
    }
    func_ov000_0215cd44(obj->context,entry,target,result,effects,obj->action->flag!=0);
    func_ov000_0215ffc4(obj->action,entry,0);
    ++*((unsigned char*)obj->context+0x8e02);
    obj->changed=1;
    func_ov000_0215a88c(obj->context,entry,message);
   }
   done=1;
  }else{
   void* entry=func_ov000_0215e958(obj->context);
   if(!entry)return 0;
   func_ov000_0215cd44(obj->context,entry,target,0,0,obj->action->flag!=0);
   func_ov000_0215ffc4(obj->action,entry,0);
   ++*((unsigned char*)obj->context+0x8e02);
   obj->changed=1;
   func_ov000_0215a88c(obj->context,entry,func_ov024_021da644(id,params->field24.b,params->field24.c));
  }
 }
 if(inline_ov000_02156cc4_2(id) && done)obj->done=1;
 return 0;
}
