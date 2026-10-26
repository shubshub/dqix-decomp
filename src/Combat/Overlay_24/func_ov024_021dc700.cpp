#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
extern "C" void* GameState_GetParty(GameState*);
struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void func_ov000_0215a8d4(unsigned char*, int);
extern "C" short func_ov000_0215a16c(void*,int,int,short*);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_0215a004(void*,int,int,int,void*,void*,int,int);
extern "C" void func_ov000_02159eac(void*,void*,int);
extern "C" void func_ov000_0215a88c(void*,void*,int);
extern "C" unsigned short func_ov024_021da644(int,int,int);
extern "C" void func_ov000_0215ccbc(void*,void*,GameObject*,short,short,short,unsigned long long,unsigned char);
struct Struct_ov024_021dc700_3 {char pad[0x1c];unsigned char unused:7;unsigned char flag:1;};
struct Struct_ov024_021dc700_4 {char pad[0xc];Struct_ov024_021dc700_3* action;void* context;char unknown_14_[0x6d-0x14];unsigned char unknown_6d_;};
struct Struct_ov024_021dc700_5 {unsigned int a:10;unsigned int b:10;unsigned int c:10;unsigned int rest:2;};
struct Struct_ov024_021dc700 {unsigned int value:12;unsigned int rest:20;};
struct Struct_ov024_021dc700_2 {char pad[4];Struct_ov024_021dc700 code;char pad8[0x18];Struct_ov024_021dc700_5 field20;Struct_ov024_021dc700_5 field24;};
static inline unsigned short inline_ov024_021dc700(GameObject* c){ return c->currentStats_->primaryStats.maxHP; }
// USA: func_ov024_021dc700
extern "C" ARM void* func_ov024_021dc700(Struct_ov024_021dc700_4* obj,int arg1,int id,Struct_ov024_021dc700_2* params,int amount,int unused,unsigned char enabled){
    GameObject* source=GetCombatantByID((int)obj->context,arg1);
    if(!source)return 0;
    GameObject* target=GetCombatantByID((int)obj->context,id);
    if(!target)return 0;
    unsigned short maxHP=inline_ov024_021dc700(target);
    if(target->currentStats_->primaryStats.currHP>=maxHP)amount=0;
    unsigned short var3=source->currentStats_->primaryStats.currHP;
    if(var3<=1)amount=0;
    if(id==arg1)amount=0;
    if(amount>var3)amount=var3-1;
    unsigned short selection;
    if(enabled && amount>0){
        selection=func_ov024_021da644(id,params->field20.c,params->field24.a);
        void* list=GameState_GetParty(GameState::GetInstance());
        if(func_02086ef0((ArrayContainsByteStruct*)list, arg1) && target->currentStats_->primaryStats.currHP==1 && params->code.value==0xb7)
            func_ov000_0215a8d4((unsigned char*)obj->context, 2);
    }else{
        amount=0;
        selection=func_ov024_021da644(id,params->field24.b,params->field24.c);
        obj->unknown_6d_=0;
    }
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    func_ov000_0215a88c(obj->context,entry,selection);
    union {struct{int low;int high;};unsigned long long value;} effects;
    effects.low=0;effects.high=0;
    func_ov000_0215a004(obj->context,arg1,arg1,amount,&effects,params,obj->action->flag!=0,0);
    effects.low=0;effects.high=0;
    short var8=0;
    short hp=func_ov000_0215a16c(obj->context,id,amount,&var8);
    func_ov000_02159eac(obj->context,&effects,0x25);
    unsigned short mp=target->currentStats_->primaryStats.currMP;
    unsigned char flag;
    if(obj->action->flag)flag=1;else flag=0;
    func_ov000_0215ccbc(obj->context,entry,target,-var8,hp,mp,effects.value,flag);
    return entry;
}
