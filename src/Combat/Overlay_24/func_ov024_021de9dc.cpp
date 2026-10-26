#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
struct Struct_ov024_021de9dc_2;
struct Struct_ov024_021de9dc_3;
struct Struct_ov024_021dd028_6;
struct Struct_ov024_021dd028_7;
extern "C" int func_ov024_021ea78c(Struct_ov024_021dd028_7*, int, Struct_ov024_021dd028_6*);
extern "C" short func_ov000_0215a004(void*,int,int,int,void*,Struct_ov024_021de9dc_3*,int,int);
extern "C" void func_ov000_02159eac(void*,void*,int);
extern "C" int func_ov000_02159f18(void*,unsigned long long,int);
extern "C" void func_02088b34(unsigned char*);
extern "C" unsigned short func_ov024_021da644(int,int,int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov024_021e8bf0(Struct_ov024_021de9dc_2*,void*,unsigned short*);
extern "C" void func_ov000_0215a88c(void*,void*,int);
extern "C" void func_ov000_0215ccbc(void*,void*,GameObject*,short,short,short,unsigned long long,unsigned char);
struct Struct_ov024_021de9dc_4 {char pad[0x1c];unsigned char unused:7;unsigned char flag:1;};
struct Struct_ov024_021de9dc_2 {char pad[0xc];Struct_ov024_021de9dc_4* action;void* context;};
struct Struct_ov024_021de9dc {unsigned int a:10;unsigned int b:10;unsigned int c:10;unsigned int rest:2;};
struct Struct_ov024_021de9dc_3 {char pad[0x20];Struct_ov024_021de9dc field20;Struct_ov024_021de9dc field24;Struct_ov024_021de9dc field28;};
static inline unsigned short inline_ov000_0215a908_2(GameObject* c){ SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currHP; }
// USA: func_ov024_021de9dc
extern "C" ARM void* func_ov024_021de9dc(Struct_ov024_021de9dc_2* obj,int arg1,int id,Struct_ov024_021de9dc_3* params,int amount,int unused,unsigned char enabled){
    GameObject* c=GetCombatantByID((int)obj->context,id);
    if(!c)return 0;
    short hp;
    int handled=0;
    unsigned short selection=0;
    union {struct{int low;int high;};unsigned long long value;} effects;
    effects.low=0;effects.high=0;
    hp=c->currentStats_->primaryStats.currHP;
    if(enabled && amount>0){
        if(((unsigned char*)obj->context)[0x8e94] && func_ov024_021ea78c((Struct_ov024_021dd028_7*)obj, id, (Struct_ov024_021dd028_6*)params)){
            amount=0;
            hp=func_ov000_0215a004(obj->context,arg1,id,inline_ov000_0215a908_2(c)-1,&effects,params,obj->action->flag!=0,0x20);
            func_ov000_02159eac(obj->context,&effects,0x29);
            func_02088b34((unsigned char*)c->currentStats_);
            selection=0xc8;
            handled=1;
        }
        if(!handled){
            hp=func_ov000_0215a004(obj->context,arg1,id,amount,&effects,params,obj->action->flag!=0,0x20);
            if(func_ov000_02159f18(obj->context,effects.value,2)){
                amount=0;
                selection=func_ov024_021da644(id,params->field28.a,params->field28.b);
            }else{
                selection=func_ov024_021da644(id,params->field20.c,params->field24.a);
            }
        }
    }else{
        selection=func_ov024_021da644(id,params->field24.b,params->field24.c);
    }
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    func_ov024_021e8bf0(obj,obj->action,&selection);
    func_ov000_0215a88c(obj->context,entry,selection);
    unsigned short mp=c->currentStats_->primaryStats.currMP;
    unsigned char flag;
    if(obj->action->flag)flag=1;else flag=0;
    func_ov000_0215ccbc(obj->context,entry,c,amount,hp,mp,effects.value,flag);
    return entry;
}
