#include <globaldefs.h>
#include "Input/Input.h"
struct Struct_ov000_021700dc {char unknown_0_[0x10];signed char unknown_10_[8],unknown_18_;char unknown_19_[0x17];signed char* unknown_30_;signed char unknown_34_;char unknown_35_[3];void* unknown_38_;char unknown_3c_[0x10];int unknown_4c_;
#if defined(jpn)
char unknown_50_[0x431];
#else
char unknown1_50_[0x3f1];
#endif
unsigned char flag;char u[6];};
struct Root {char p[0x6c];signed char order[4];char q[4];signed char ids[4],count;char r[0x9f];int flag;char s[0x60];int activeId;char t[0x7d8];Slot slots[4];};
struct Struct_0205d81c;unsigned char* FindElementByC40205d81c(Struct_0205d81c*,int);struct S02171698;int CountNonZero02171698(S02171698*);struct S021719c0;int CountNonZero021719c0(S021719c0*);int GridCursor_GetCount(void*);void SetField0xd8State_02050400(unsigned char*,int);void ProcessCombatantEntry0217f78c(void*);
extern "C" {void func_ov000_0217fa60(void*);void func_ov000_02174c14(void*);void func_ov000_0217f304(void*,int,int,void*);int func_ov000_021700dc(void*);void func_ov000_0217edd4(void*,signed char*,signed char*);void func_ov000_0217ee7c(signed char*,signed char*,signed char,int);void func_ov000_02176634(void*,void*,int,int,int);int func_ov000_0217c158(void*);void func_ov000_02177038(void*,void*,int,int,int);}
// USA: func_ov000_0217f00c
extern "C" ARM void func_ov000_0217f00c(Struct_ov000_021682ec_5* arg0,int arg1,int arg2){
 if(arg0->unknown_17c_<0){if(g_keyManager.TestKeysPressed(0x802)||g_touchInput.pressed_){func_ov000_0217fa60(arg0);func_ov000_02174c14(arg0);}return;}
 for(int var0=0;var0<4;var0++){
  Struct_ov000_021700dc* var1=&arg0->unknown_958_[arg0->unknown_6c_[var0]];if(arg0->unknown_17c_!=var1->unknown_4c_)continue;
  unsigned char* var2;func_ov000_0217f304(arg0,arg1,arg2,var1);int var3=func_ov000_021700dc(var1);
  switch(var3){
  case -3:func_ov000_0217fa60(arg0);func_ov000_02174c14(arg0);break;
  case -2:func_ov000_0217f78c(arg0);break;
  case 15:case 16:case 17:case 18:{
   int active=0;func_ov000_0217edd4(self,self->ids,&self->count);signed char num=self->count;slot->ids=self->ids;slot->count=num;slot->flag=mode;func_ov000_02176634(self,slot,result,mode,count);
   entry=FindElementByC40205d81c((Struct_0205d81c*)slot->menu,(unsigned char)result);
   if(result==15){if(CountNonZero02171698((S02171698*)slot)>4)active=1;}
   else if(result==16){if(CountNonZero021719c0((S021719c0*)slot)>4)active=1;}
   else if(result==17){if(GridCursor_GetCount((char*)slot->menu+0x54)>4)active=1;}
   if(entry)SetField0xd8State_02050400(entry,active);break;
  }
  case 19:{
   func_ov000_0217edd4(arg0,arg0->unknown_74_,&arg0->unknown_78_);func_ov000_0217ee7c(arg0->unknown_74_,&arg0->unknown_78_,-1,1);signed char var6=arg0->unknown_78_;var1->unknown_30_=arg0->unknown_74_;var1->unknown_34_=var6;var1->unknown_441_=arg1;func_ov000_02176634(arg0,var1,var3,arg1,arg2);break;}
  case 20:{
   func_ov000_0217edd4(arg0,arg0->unknown_74_,&arg0->unknown_78_);func_ov000_0217ee7c(arg0->unknown_74_,&arg0->unknown_78_,(signed char)var1->unknown_4c_,2);signed char var7=arg0->unknown_78_;var1->unknown_30_=arg0->unknown_74_;var1->unknown_34_=var7;var1->unknown_441_=arg1;func_ov000_02176634(arg0,var1,var3,arg1,arg2);break;}
  default:func_ov000_02176634(arg0,var1,var3,arg1,arg2);break;
  }
  if(func_ov000_0217c158(var1))arg0->unknown_118_=1;
  func_ov000_02177038(arg0,var1,var1->unknown_10_[var1->unknown_18_],arg1,arg2);break;
 }
}
