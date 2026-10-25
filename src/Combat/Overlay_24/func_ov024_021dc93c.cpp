#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
void* GameState_GetParty(GameState*);
struct ArrayContainsByteStruct;
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct*, int);
void IncrementByteCounterCapped0x63_0215a8d4(unsigned char*, int);
int CheckField0x14FiveFlagsClear020881c4(unsigned char*);
int CheckField0x14FiveFlagsClear0208810c(unsigned char*);
void SetFlag0x800000AndByte0x24_02088220(void*, int);
int SetFlag0x800000AndCall02088208(void*, int);
void ResetAndSetFlag0x1000000_02088150(void*);
int GetCodeForCategory_021e8c48(void*, signed char);
unsigned short SelectByIndexRange0to3_021da644(int,int,int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_0215a88c(void*,void*,int);
extern "C" void func_ov000_0215ffc4(void*,void*,int);
extern "C" void func_ov000_02159eac(void*,unsigned long long*,int);
extern "C" void func_ov000_0215cd44(void*,void*,GameObject*,short,unsigned long long,unsigned char);
extern "C" void func_ov000_0215af54(void*,int,int);
struct Struct_ov024_021dc93c {char unknown_0_[0x1c];unsigned char unknown_1c_0_:7;unsigned char unknown_1c_7_:1;};
struct Struct_ov024_021dc93c_2 {char unknown_0_[0xc];Struct_ov024_021dc93c* unknown_c_;void* unknown_10_;char unknown_14_[0x71-0x14];unsigned char unknown_71_;char unknown_72_[2];unsigned char unknown_74_;};
struct Struct_ov024_021dc93c_3 {unsigned int unknown_0_0_:12;unsigned int unknown_1_4_:20;};
struct Struct_ov024_021dc93c_4 {unsigned int unknown_0_0_:10;unsigned int unknown_1_2_:10;unsigned int unknown_2_4_:10;unsigned int unknown_3_6_:2;};
struct Struct_ov024_021dc93c_5 {char unknown_0_[4];Struct_ov024_021dc93c_3 unknown_4_;char unknown_8_[0x1c];Struct_ov024_021dc93c_4 unknown_24_;char unknown_28_[8];short unknown_30_;};
struct Struct_ov024_021dc93c_6 {char unknown_0_[0x24];unsigned char unknown_24_;};
static inline void* inline_ov024_021dc93c(Struct_ov024_021dc93c_2* arg0){ SDK_NULL_ASSERT(arg0); return arg0->unknown_10_; }
static inline int inline_ov000_02156cc4_2(int arg0){ return arg0>=0 && arg0<=3; }
// USA: func_ov024_021dc93c
extern "C" ARM void* func_ov024_021dc93c(Struct_ov024_021dc93c_2* arg0,short arg1,int arg2,Struct_ov024_021dc93c_5* arg3,int arg4,int arg5,unsigned char arg6){
 GameObject* var0=GetCombatantByID((int)arg0->unknown_10_,arg2);
 if(!var0)return 0;
 int var1=0;
 int var2=0;
 int var3;
 unsigned long long var4=0;
 unsigned short var5=arg3->unknown_4_.unknown_0_0_;
 if(arg6){
  if(var5==0x151 || var5==0x152){
   if(var5==0x151){
    if(func_020881c4((unsigned char*)var0->currentStats_))var2=1;
   }else if(var5==0x152){
    if(func_0208810c((unsigned char*)var0->currentStats_))var2=1;
   }
   int var6;
   int var7=arg3->unknown_30_;
   var6=((Struct_ov024_021dc93c_6*)var0->currentStats_)->unknown_24_;
   if(var6>=var7)var2=0;
   if(var2){
    void* var8=func_ov000_0215e958(arg0->unknown_10_);
    if(!var8)return 0;
    func_ov000_0215cd44(arg0->unknown_10_,var8,var0,var6,var4,arg0->unknown_c_->unknown_1c_7_!=0);
    func_ov000_0215ffc4(arg0->unknown_c_,var8,0);
    ++*((unsigned char*)arg0->unknown_10_+0x8e02);
    func_ov000_0215a88c(arg0->unknown_10_,var8,0x152);
    if(var6<var7){
     var3=0;
     while(var6<3){
      ++var6;
      switch(var6){case 1:var3=0x31;break;case 2:var3=0x32;break;case 3:var3=0x33;break;}
      var4=0;
      func_ov000_02159eac(arg0->unknown_10_,&var4,0x23);
      void* var9=func_ov000_0215e958(arg0->unknown_10_);
      if(!var9)return 0;
      func_ov000_0215cd44(arg0->unknown_10_,var9,var0,var6,var4,arg0->unknown_c_->unknown_1c_7_!=0);
      func_ov000_0215ffc4(arg0->unknown_c_,var9,0);
      ++*((unsigned char*)arg0->unknown_10_+0x8e02);
      arg0->unknown_74_=1;
      func_ov000_0215a88c(arg0->unknown_10_,var9,var3);
     }
     if(var7>=4){
      var8=func_ov000_0215e958(arg0->unknown_10_);
      if(!var8)return 0;
      func_02088150(var0->currentStats_);
      func_ov000_0215a88c(arg0->unknown_10_,var8,0x34);
      func_ov000_02159eac(arg0->unknown_10_,&var4,7);
      func_ov000_0215cd44(arg0->unknown_10_,var8,var0,var6,var4,arg0->unknown_c_->unknown_1c_7_!=0);
      func_ov000_0215ffc4(arg0->unknown_c_,var8,0);
      ++*((unsigned char*)arg0->unknown_10_+0x8e02);
      arg0->unknown_74_=1;
      func_ov000_0215a88c(arg0->unknown_10_,var8,var3);
      func_ov000_0215af54(arg0->unknown_10_,arg2,0);
     }else{
      func_02088220(var0->currentStats_, var7);
     }
    }
   }
  }else if(CheckField0x14FiveFlagsClear020881c4((unsigned char*)target->currentStats_)){
   int count=params->count;
   int total=((Stats021dc93c*)target->currentStats_)->stage+count;
   if(total>4)count-=total-4;
   for(;count>0;count--){
    int result=SetFlag0x800000AndCall02088208(target->currentStats_, (int)GetCtx(obj));
    effects=0;
    message=GetCodeForCategory_021e8c48(obj, result);
    void* entry=func_ov000_0215e958(obj->context);
    if(!entry)return 0;
    if(result>0){
     func_ov000_02159eac(obj->context,&effects,0x23);
     if(result==4){
      func_ov000_02159eac(obj->context,&effects,7);
      func_ov000_0215af54(obj->context,id,0);
      void* list=GameState_GetParty(GameState::GetInstance());
      if(ArrayContainsByte_02086ef0((ArrayContainsByteStruct*)list, sourceID) && code==0xa8)
       IncrementByteCounterCapped0x63_0215a8d4((unsigned char*)obj->context, 3);
     }
    }else{
     var4=0;
     var12=0;
    }
    func_ov000_0215cd44(arg0->unknown_10_,var13,var0,var12,var4,arg0->unknown_c_->unknown_1c_7_!=0);
    func_ov000_0215ffc4(arg0->unknown_c_,var13,0);
    ++*((unsigned char*)arg0->unknown_10_+0x8e02);
    arg0->unknown_74_=1;
    func_ov000_0215a88c(arg0->unknown_10_,var13,var3);
   }
   var1=1;
  }else{
   void* var15=func_ov000_0215e958(arg0->unknown_10_);
   if(!var15)return 0;
   func_ov000_0215cd44(arg0->unknown_10_,var15,var0,0,0,arg0->unknown_c_->unknown_1c_7_!=0);
   func_ov000_0215ffc4(arg0->unknown_c_,var15,0);
   ++*((unsigned char*)arg0->unknown_10_+0x8e02);
   arg0->unknown_74_=1;
   func_ov000_0215a88c(arg0->unknown_10_,var15,func_ov024_021da644(arg2,arg3->unknown_24_.unknown_1_2_,arg3->unknown_24_.unknown_2_4_));
  }
 }
 if(inline_ov000_02156cc4_2(arg2) && var1)arg0->unknown_71_=1;
 return 0;
}
