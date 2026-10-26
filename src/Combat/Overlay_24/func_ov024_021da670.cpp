#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
struct Struct_ov024_021da670;
struct Struct_ov024_021da670_3;
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_02159eac(void*,void*,int);
extern "C" void func_ov000_0215cd44(void*,void*,GameObject*,int,unsigned long long,int);
extern "C" void func_ov000_021554f4(void*,int,int,Struct_ov024_021da670_3*,int,int);
struct Struct_02088f68;
extern "C" void func_02088f68(Struct_02088f68*);
extern "C" void func_02088474(void*,int,int);
struct Struct_ov024_021da670_6;
extern "C" int func_ov024_021da998(Struct_ov024_021da670_6*);
extern "C" void func_0208826c(unsigned char*);
extern "C" void func_020883cc(unsigned char*);
struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(Struct_ov024_021da670_7*);
extern "C" int func_020882f8(unsigned char*);
struct Struct_ov024_021da670_8;
extern "C" int func_ov024_021da9c8(Struct_ov024_021da670_8*);
extern "C" unsigned short func_ov024_021e9018(Struct_ov024_021da670*,int,int,int);
extern "C" void func_ov024_021e8cfc(Struct_ov024_021da670*,GameObject*,int,int);
extern "C" void func_ov000_0215a88c(void*,void*,int);
struct Struct_ov024_021da670 {char pad[0x10];void* context;};
struct Struct_ov024_021da670_2 {unsigned int value:12;unsigned int rest:20;};
struct Struct_ov024_021da670_3 {char pad[4];Struct_ov024_021da670_2 code;};
struct Struct_ov024_021da670_4 {unsigned short low:2;unsigned short kind:4;unsigned short middle:6;unsigned short state:2;unsigned short upper:2;};
struct Struct_ov024_021da670_5 {char pad[0x22];Struct_ov024_021da670_4 flags;};
static inline unsigned char inline_ov017_021c6d50_4(Struct_ov024_021da670_5* stats){ return stats->flags.state; }
// USA: func_ov024_021da670
extern "C" ARM void* func_ov024_021da670(Struct_ov024_021da670* obj,int arg1,int id,Struct_ov024_021da670_3* params){
    GameObject* c=GetCombatantByID((int)obj->context,id);
    if(!c)return 0;
    unsigned short code=params->code.value;
    int message=0;
    union {struct{int low;int high;};unsigned long long value;} effects;
    effects.low=0;effects.high=0;
    if(id!=arg1){
        void* entry=func_ov000_0215e958(obj->context);
        if(!entry)return 0;
        if(code==0x150)func_ov000_02159eac(obj->context,&effects,4);
        func_ov000_0215cd44(obj->context,entry,c,0,effects.value,0);
        return entry;
    }
    if(code==0xe1 || code==0x395){
        GameObject* source=GetCombatantByID((int)obj->context,arg1);
        if(source){
            func_ov000_021554f4(obj->context,arg1,arg1,params,0,2);
            source->currentStats_->primaryStats.currHP=0;
            func_02088f68((Struct_02088f68*)source->currentStats_);
        }
    }else if(code==0x384){
        func_ov000_02159eac(obj->context,&effects,0x1a);
    }else if(code==0x385){
        func_ov000_02159eac(obj->context,&effects,0x10);
    }else if(code==0x3aa){
        func_ov000_02159eac(obj->context,&effects,0x19);
    }else if(inline_ov017_021c6d50_4((Struct_ov024_021da670_5*)c->currentStats_)){
        func_ov000_02159eac(obj->context,&effects,0xb);
        switch(inline_ov017_021c6d50_4((Struct_ov024_021da670_5*)c->currentStats_)){
        case 1:
            message=0x93;
            func_02088474(c->currentStats_,10,0);
            break;
        case 2:
            ((unsigned char*)obj->context)[0x8e96]=func_ov024_021da998((Struct_ov024_021da670_6*)c);
            message=0x94;
            func_0208826c((unsigned char*)c->currentStats_);
            func_ov000_02159eac(obj->context,&effects,0x18);
            break;
        case 3:
            message=0x95;
            func_020883cc((unsigned char*)c->currentStats_);
            func_ov000_02159eac(obj->context,&effects,0x17);
            break;
        }
        ((Struct_ov024_021da670_5*)c->currentStats_)->flags.state=0;
    }else if(func_ov024_021da9b0((Struct_ov024_021da670_7*)c)){
        message=0x70;
    }else if(func_020882f8((unsigned char*)c->currentStats_)){
        message=0x44;
    }else if(func_ov024_021da9c8((Struct_ov024_021da670_8*)c)){
        message=func_ov024_021e9018(obj,id,((Struct_ov024_021da670_5*)c->currentStats_)->flags.kind,1);
        func_ov000_02159eac(obj->context,&effects,0x27);
    }
    if(((unsigned char*)obj->context)[0x8e96])func_ov024_021e8cfc(obj,c,0,0);
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    if(message)func_ov000_0215a88c(obj->context,entry,message);
    func_ov000_0215cd44(obj->context,entry,c,0,effects.value,0);
    return entry;
}
