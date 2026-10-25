#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
void* GameState_GetParty(GameState*);
struct ArrayContainsByteStruct;
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct*, int);
void IncrementByteCounterCapped0x63_0215a8d4(unsigned char*, int);
short ApplyHPDelta0215a16c(void*,int,int,short*);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_0215a004(void*,int,int,int,void*,void*,int,int);
extern "C" void func_ov000_02159eac(void*,void*,int);
extern "C" void func_ov000_0215a88c(void*,void*,int);
extern "C" unsigned short func_ov024_021da644(int,int,int);
extern "C" void func_ov000_0215ccbc(void*,void*,GameObject*,short,short,short,unsigned long long,unsigned char);
struct Struct_ov024_021dc700_3 {char unknown_0_[0x1c];unsigned char unknown_1c_0_:7;unsigned char unknown_1c_7_:1;};
struct Struct_ov024_021dc700_4 {char unknown_0_[0xc];Struct_ov024_021dc700_3* unknown_c_;void* unknown_10_;char unknown_14_[0x6d-0x14];unsigned char unknown_6d_;};
struct Struct_ov024_021dc700_5 {unsigned int unknown_0_0_:10;unsigned int unknown_1_2_:10;unsigned int unknown_2_4_:10;unsigned int unknown_3_6_:2;};
struct Struct_ov024_021dc700 {unsigned int unknown_0_0_:12;unsigned int unknown_1_4_:20;};
struct Struct_ov024_021dc700_2 {char unknown_0_[4];Struct_ov024_021dc700 unknown_4_;char unknown_8_[0x18];Struct_ov024_021dc700_5 unknown_20_;Struct_ov024_021dc700_5 unknown_24_;};
static inline unsigned short inline_ov024_021dc700(GameObject* arg0){ return arg0->currentStats_->primaryStats.maxHP; }
// USA: func_ov024_021dc700
extern "C" ARM void* func_ov024_021dc700(Obj021dc700* obj,int sourceID,int id,Params021dc700* params,int amount,int unused,unsigned char enabled){
    GameObject* source=GetCombatantByID((int)obj->context,sourceID);
    if(!source)return 0;
    GameObject* target=GetCombatantByID((int)obj->context,id);
    if(!target)return 0;
    unsigned short maxHP=GetMaxHP(target);
    if(target->currentStats_->primaryStats.currHP>=maxHP)amount=0;
    unsigned short sourceHP=source->currentStats_->primaryStats.currHP;
    if(sourceHP<=1)amount=0;
    if(id==sourceID)amount=0;
    if(amount>sourceHP)amount=sourceHP-1;
    unsigned short selection;
    if(enabled && amount>0){
        selection=SelectByIndexRange0to3_021da644(id,params->field20.c,params->field24.a);
        void* list=GameState_GetParty(GameState::GetInstance());
        if(ArrayContainsByte_02086ef0((ArrayContainsByteStruct*)list, sourceID) && target->currentStats_->primaryStats.currHP==1 && params->code.value==0xb7)
            IncrementByteCounterCapped0x63_0215a8d4((unsigned char*)obj->context, 2);
    }else{
        arg4=0;
        var4=func_ov024_021da644(arg2,arg3->unknown_24_.unknown_1_2_,arg3->unknown_24_.unknown_2_4_);
        arg0->unknown_6d_=0;
    }
    void* var6=func_ov000_0215e958(arg0->unknown_10_);
    if(!var6)return 0;
    func_ov000_0215a88c(arg0->unknown_10_,var6,var4);
    union {struct{int unknown_0_;int unknown_4_;};unsigned long long unknown1_0_;} var7;
    var7.unknown_0_=0;var7.unknown_4_=0;
    func_ov000_0215a004(arg0->unknown_10_,arg1,arg1,arg4,&var7,arg3,arg0->unknown_c_->unknown_1c_7_!=0,0);
    var7.unknown_0_=0;var7.unknown_4_=0;
    short var8=0;
    short var9=func_ov000_0215a16c(arg0->unknown_10_,arg2,arg4,&var8);
    func_ov000_02159eac(arg0->unknown_10_,&var7,0x25);
    unsigned short var10=var1->currentStats_->primaryStats.currMP;
    unsigned char var11;
    if(arg0->unknown_c_->unknown_1c_7_)var11=1;else var11=0;
    func_ov000_0215ccbc(arg0->unknown_10_,var6,var1,-var8,var9,var10,var7.unknown1_0_,var11);
    return var6;
}
