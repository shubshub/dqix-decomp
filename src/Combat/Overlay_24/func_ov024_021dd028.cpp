#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
struct Struct_ov024_021dd028_2;
struct Struct_ov024_021dd028_4;
struct Struct_ov024_021dd028_5;
extern "C" int func_ov024_021dd260(Struct_ov024_021dd028_5*);
struct Struct_ov024_021dd028_6;
struct Struct_ov024_021dd028_7;
extern "C" int func_ov024_021ea78c(Struct_ov024_021dd028_7*, int, Struct_ov024_021dd028_6*);
extern "C" void func_ov000_02159eac(void*,void*,int);
extern "C" void func_ov000_0215a004(void*,int,int,int,void*,Struct_ov024_021dd028_4*,int,int);
extern "C" void func_02088b34(unsigned char*);
extern "C" unsigned short func_ov024_021da644(int,int,int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov024_021e8bf0(Struct_ov024_021dd028_2*,void*,unsigned short*);
extern "C" void func_ov000_0215a88c(void*,void*,int);
extern "C" void func_ov000_0215cd44(void*,void*,GameObject*,int,unsigned long long,unsigned char);
struct Struct_ov024_021dd028_8 {char pad[0x1c]; unsigned char unused:7; unsigned char flag:1;};
struct Struct_ov024_021dd028_2 {char pad[0xc];Struct_ov024_021dd028_8* action;void* context;int count;char pad18[0x75-0x18];unsigned char unknown_75_;};
struct Struct_ov024_021dd028 {unsigned int a:10;unsigned int b:10;unsigned int c:10;unsigned int rest:2;};
struct Struct_ov024_021dd028_3 {unsigned int low:19;unsigned int value:5;unsigned int high:8;};
struct Struct_ov024_021dd028_4 {char pad[0x1c];Struct_ov024_021dd028_3 field1c;int field20;Struct_ov024_021dd028 field24;Struct_ov024_021dd028 field28;};
static inline unsigned short inline_ov000_0215a908_2(GameObject* c){ SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currHP; }
// USA: func_ov024_021dd028
extern "C" ARM void* func_ov024_021dd028(Struct_ov024_021dd028_2* obj,int arg1,int id,Struct_ov024_021dd028_4* params,int unused,int arg5,unsigned char enabled){
    GameObject* c=GetCombatantByID((int)obj->context,id);
    if(!c)return 0;
    int var1=1;
    if(func_ov024_021dd260((Struct_ov024_021dd028_5*)c)){
        if(params->field1c.value==7)var1=0;
    }
    union {struct {int low;int high;};unsigned long long value;} effects;
    effects.low=0;
    effects.high=0;
    unsigned short selection=0;
    if(enabled && var1){
        if(func_ov024_021ea78c((Struct_ov024_021dd028_7*)obj, id, (Struct_ov024_021dd028_6*)params)){
            func_ov000_02159eac(obj->context,&effects,0x29);
            func_ov000_0215a004(obj->context,arg1,id,inline_ov000_0215a908_2(c)-1,&effects,params,obj->action->flag!=0,0);
            func_ov000_02159eac(obj->context,&effects,0xfe);
            func_02088b34((unsigned char*)c->currentStats_);
            selection=0xc8;
        }else{
            func_ov000_0215a004(obj->context,arg1,id,0xffff,&effects,params,obj->action->flag!=0,8);
            effects.low=0;
            effects.high=0;
            func_ov000_02159eac(obj->context,&effects,0xd);
            selection=func_ov024_021da644(id,params->field28.a,params->field28.b);
        }
        obj->count++;
    }else{
        selection=func_ov024_021da644(id,params->field24.b,params->field24.c);
        obj->unknown_75_=0;
    }
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    func_ov024_021e8bf0(obj,obj->action,&selection);
    func_ov000_0215a88c(obj->context,entry,selection);
    func_ov000_0215cd44(obj->context,entry,c,0,effects.value,obj->action->flag!=0);
    return entry;
}
