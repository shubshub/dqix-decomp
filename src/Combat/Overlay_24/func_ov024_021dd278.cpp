#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
struct S_10088;
extern "C" int func_02010088(S_10088*);
extern "C" void func_0208902c(unsigned char*, int);
extern "C" void func_ov000_02159eac(void*,void*,int);
extern "C" GameObject* func_0200ff1c(GameState*,int);
extern "C" unsigned short func_ov024_021da644(int,int,int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_0215a88c(void*,void*,int);
extern "C" void func_ov000_0215cd44(void*,void*,GameObject*,int,unsigned long long,unsigned char);
struct Struct_ov024_021dd278_3 {char pad[0x1c];unsigned char unused:7;unsigned char flag:1;};
struct Struct_ov024_021dd278_4 {char pad[0xc];Struct_ov024_021dd278_3* action;void* context;int count;};
struct Struct_ov024_021dd278_5 {unsigned int code:12;unsigned int lower:10;unsigned int upper:10;};
struct Struct_ov024_021dd278_6 {unsigned int a:10;unsigned int b:10;unsigned int c:10;unsigned int rest:2;};
struct Struct_ov024_021dd278_7 {char pad[4];Struct_ov024_021dd278_5 field4;char pad8[0x18];Struct_ov024_021dd278_6 field20;Struct_ov024_021dd278_6 field24;};
struct Struct_ov024_021dd278 {unsigned int low:20;unsigned int value:10;unsigned int high:2;};
struct Struct_ov024_021dd278_2 {char pad[0x10];Struct_ov024_021dd278 field10;char unknown_14_[0x26];unsigned char unknown_3a_;unsigned char changed:1;unsigned char rest:7;};
static inline int inline_ov000_021537b8(int id){return id>=0 && id<=3;}
// USA: func_ov024_021dd278
extern "C" ARM void* func_ov024_021dd278(Struct_ov024_021dd278_4* obj,int arg1,int id,Struct_ov024_021dd278_7* params,int unused,int arg5,unsigned char enabled){
    GameObject* source=GetCombatantByID((int)obj->context,arg1);
    if(!source)return 0;
    GameObject* target=GetCombatantByID((int)obj->context,id);
    if(!target)return 0;
    int active=0;
    if(func_02010088((S_10088*)target))active=1;
    unsigned short code=params->field4.code;
    union {struct{int low;int high;};unsigned long long value;} effects;
    effects.low=0;effects.high=0;
    unsigned short selection;
    if(enabled && active){
        float var6=1.0f;
        switch(code){
        case 0x27:var6=0.5f;break;
        case 0x26:
        case 0x54:
            if(inline_ov000_021537b8(arg1)){
                unsigned short value=((Struct_ov024_021dd278_2*)source->currentStats_)->field10.value;
                if(value<=params->field4.lower)var6=0.25f;
                else if(value>=params->field4.upper)var6=0.5f;
                else var6=(25.0f+(float)(int)((25.0f/(params->field4.upper-params->field4.lower))*(value-params->field4.lower)))/100.0f;
            }else var6=0.5f;
            break;
        }
        short hp=(int)(var6*(float)(unsigned int)target->currentStats_->primaryStats.maxHP);
        func_0208902c((unsigned char*)target->currentStats_, hp);
        func_ov000_02159eac(obj->context,&effects,3);
        ((Struct_ov024_021dd278_2*)target->currentStats_)->changed=1;
        if(inline_ov000_021537b8(id)){
            GameObject* member=func_0200ff1c(GameState::GetInstance(),id);
            if(member)((Struct_ov024_021dd278_2*)member->currentStats_)->unknown_3a_=1;
        }
        selection=func_ov024_021da644(id,params->field20.c,params->field24.a);
        obj->count++;
    }else{
        if(active)selection=0x21;
        else selection=func_ov024_021da644(id,params->field24.b,params->field24.c);
    }
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    func_ov000_0215a88c(obj->context,entry,selection);
    func_ov000_0215cd44(obj->context,entry,target,0,effects.value,obj->action->flag!=0);
    return entry;
}
