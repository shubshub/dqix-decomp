#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#if defined(jpn)
enum { Enum_ov003_02154af4_400=0x18c, Enum_ov003_02154af4_336=0x144, Enum_ov003_02154af4_2384=0x8b8, Enum_ov003_02154af4_54=0x2a, Enum_ov003_02154af4_6574=0x17de };
#else
enum { Enum_ov003_02154af4_400=0x190, Enum_ov003_02154af4_336=0x150, Enum_ov003_02154af4_2384=0x950, Enum_ov003_02154af4_54=0x36, Enum_ov003_02154af4_6574=0x19ae };
#endif
struct Status { unsigned int unknown_0_; unsigned short unknown_4_; unsigned short unknown_6_; };
struct Struct_ov003_02154af4_4 { char unknown_0_[0x30]; unsigned short unknown_30_; unsigned short unknown_32_; };
struct Struct_ov003_02154af4_5 { char unknown_0_[Enum_ov003_02154af4_2384]; unsigned int unknown_950_; };
struct Struct_ov000_0217c638 { char unknown_0_[0x130]; Status* unknown_130_; Struct_ov003_02154af4_4* unknown_134_; char unknown_138_[Enum_ov003_02154af4_336-0x138]; Struct_ov003_02154af4_5* unknown_150_;
 unsigned int inline_ov003_02154af4() const { return unknown_130_->unknown_4_; }
 unsigned int inline_ov003_02154af4_2() const { return unknown_134_->unknown_30_; }
 unsigned int inline_ov003_02154af4_3() const { return unknown_130_->unknown_6_; }
 unsigned int inline_ov003_02154af4_4() const { return unknown_134_->unknown_32_; }
 unsigned int inline_ov003_02154af4_5() const { return unknown_150_->unknown_950_; }
 unsigned int inline_ov003_02154af4_6() const { return unknown_130_->unknown_0_; }
};
struct Struct_ov003_02154af4 { unsigned int unknown_0_; unsigned short unknown_4_, unknown_6_; unsigned short unknown_8_,unknown_a_; unsigned char unknown_c_, unknown_d_; char unknown_e_[2]; };
struct Struct_ov003_02154af4_2 { char unknown_0_[Enum_ov003_02154af4_54]; short unknown_36_; };
struct Struct_ov003_02154af4_3 {
 void* unknown_0_; void* unknown_4_; short* unknown_8_; char unknown_c_[0x18-0xc]; Struct_ov003_02154af4_2* unknown_18_; void* unknown_1c_;
 char unknown_20_[0x80-0x20]; char unknown_80_[0xc]; unsigned short unknown_8c_; unsigned char unknown_8e_;
 char unknown_8f_[Enum_ov003_02154af4_400-0x8f]; Struct_ov003_02154af4 unknown_190_[4]; int unknown_1d0_; int unknown_1d4_; int unknown_1d8_; unsigned int unknown_1dc_;
 char unknown_1e0_[6]; short unknown_1e6_; short unknown_1e8_; short unknown_1ea_; short unknown_1ec_, unknown_1ee_;
 char unknown_1f0_[8]; unsigned char unknown_1f8_, unknown_1f9_; char unknown_1fa_[2]; unsigned int unknown_1fc_; int unknown_200_; int unknown_204_;
 char unknown_208_[0x334-0x204]; unsigned char unknown_338_, unknown_339_, unknown_33a_;
};
struct Struct_ov000_02182a74 { char unknown_0_[0xf78]; unsigned char unknown_f78_[4]; unsigned char unknown_f7c_; };
struct Struct_020e6d5c_13 { unsigned int unknown_0_, unknown_4_; };
struct Struct_ov003_0217f340 { Struct_020e6d5c_13 unknown_0_[8]; };
extern short data_ov003_0217f2a8[3];
extern Table data_ov003_0217f340;
extern Dispatch __ptmf_null;
extern "C" int func_ov017_021959b4();
extern "C" char* func_020421a0();
extern "C" void func_02043204(char*);
struct Struct_020e28dc;
extern "C" int func_020e28dc(Struct_020e28dc*);
struct Struct_020e25e8;
extern "C" void func_020e25e8(Struct_020e25e8*);
extern "C" void func_ov003_021537d4(void*,unsigned int);
extern "C" void func_ov003_021552b8(Struct_ov003_02154af4_3*);
struct Struct_0207fc6c;
extern "C" void func_0207fc6c(Struct_0207fc6c*, int);
extern "C" unsigned int func_0202053c(void*);
struct Struct_0207fdcc_2;
extern "C" int func_020811d0(Struct_0207fdcc_2*, int);
extern "C" void func_ov003_02158334(Struct_ov003_02154af4_3*);
extern "C" void func_02081f20(void*,unsigned int);
extern "C" int func_020800fc(Struct_ov003_02154af4_2*,short*,int,unsigned short,unsigned char,int);
extern "C" void func_020804fc(void*, int);
extern "C" void func_020813ec(Struct_ov003_02154af4_2*,int);
struct Struct_020e263c_2;
extern "C" void func_020e263c(Struct_020e263c_2*, int);
// USA: func_ov003_02154af4
extern "C" ARM int func_ov003_02154af4(Struct_ov003_02154af4_3* arg0,unsigned int arg1) {
 arg0->unknown_1dc_=arg1;
 if (!arg0->unknown_33a_ && func_ov017_021959b4()) { arg0->unknown_33a_=1; arg0->unknown_339_=1; }
 if (arg0->unknown_339_ && !arg0->unknown_338_) {
  if(arg0->unknown_8_) *arg0->unknown_8_=-1;
  arg0->unknown_8_=0;
  func_02043204(func_020421a0());
  arg0->unknown_1ee_=-1; arg0->unknown_1ec_=arg0->unknown_1ee_;
  if(arg0->unknown_1c_ && func_020e28dc((Struct_020e28dc*)arg0->unknown_1c_)) func_020e25e8((Struct_020e25e8*)arg0->unknown_1c_);
  arg0->unknown_1f8_=6; arg0->unknown_1f9_=0; arg0->unknown_339_=0;
 }
 if(!arg0->unknown_204_) func_ov003_021537d4(arg0->unknown_4_,arg1);
 if(arg0->unknown_1ec_>=0) { func_ov003_021552b8(arg0); return 0; }
 if(arg0->unknown_1f8_) func_020421a0()[Enum_ov003_02154af4_6574]=0;
 Struct_ov003_02154af4_2* var0=arg0->unknown_18_;
 if(var0) {
  if(!arg0->unknown_204_) func_0207fc6c((Struct_0207fc6c*)var0, arg1);
  int var1; Struct_ov003_02154af4* var2; Struct_ov000_0217c638* var3; bool var4; int var5; Struct_ov000_02182a74* var6; GameState* var7;
  var4=false;
  var7=GameState::GetInstance();
  var6=(Struct_ov000_02182a74*)func_02010828(var7);
  int var8=var6->unknown_f7c_;
  for(var1=0;var1<var8;var1++) {
   var5=var6->unknown_f78_[var1];
   var3=(Struct_ov000_0217c638*)var7->GetPartyMemberByIndex(var5);
   if(var3) {
    var2=&arg0->unknown_190_[var5];
    unsigned int var9=var3->inline_ov003_02154af4();
    unsigned int var10,var11,var12,var13,var14;
    if(!(var2->unknown_4_==var9 && ((var10=var3->inline_ov003_02154af4_2()), var2->unknown_6_==var10) && ((var11=var3->inline_ov003_02154af4_3()), var2->unknown_8_==var11) && ((var12=var3->inline_ov003_02154af4_4()), var2->unknown_a_==var12) && ((var13=var3->inline_ov003_02154af4_5()), var2->unknown_d_==var13) && var2->unknown_c_==func_0202053c(var3) && ((var14=var3->inline_ov003_02154af4_6()), var2->unknown_0_==var14))) {
     var2->unknown_4_=var3->unknown_130_->unknown_4_; var2->unknown_6_=var3->unknown_134_->unknown_30_; var2->unknown_8_=var3->unknown_130_->unknown_6_; var2->unknown_a_=var3->unknown_134_->unknown_32_;
     var2->unknown_d_=var3->unknown_150_->unknown_950_; var2->unknown_c_=func_0202053c(var3); var4=true; var2->unknown_0_=var3->unknown_130_->unknown_0_;
    }
   }
  }
  if(var4) for(int var15=0;var15<3;var15++) if(func_020811d0((Struct_0207fdcc_2*)var0, data_ov003_0217f2a8[var15])) { func_ov003_02158334(arg0);break; }
 }
 if(arg0->unknown_8_) {
  func_02081f20(arg0->unknown_80_,arg1);
  arg0->unknown_1e8_=*arg0->unknown_8_;
  arg0->unknown_1d8_=func_020800fc(var0,arg0->unknown_8_,arg0->unknown_1e8_,arg0->unknown_8c_,arg0->unknown_8e_,(arg0->unknown_1fc_&4)!=0);
  var0->unknown_36_=*arg0->unknown_8_;
  if(arg0->unknown_1d8_) func_020804fc(var0, arg0->unknown_1e6_);
  if(arg0->unknown_1e8_!=*arg0->unknown_8_) func_020813ec(var0,arg0->unknown_1e6_);
 }
 if(self->inner && GetInnerFlagBit0020e28dc((Outer020e28dc*)self->inner)) UpdateEntryStateAndPosition((Ctx020e263c*)self->inner, self->scale);
 Table buf; buf=data_ov003_0217f340;
 unsigned int locator=__ptmf_null.locator;
 unsigned int fn=__ptmf_null.fn;
 buf.entries[7].locator=locator; buf.entries[7].fn=fn;
 if(!buf.entries[self->state].fn) {
  BackgroundLoader::GetInstance()->RemoveTask(self->task);self->task=-1;return 1;
 }
 Struct_020e6d5c_13* var19=&var16.unknown_0_[arg0->unknown_1f8_];
 void* var20=(char*)arg0+((int)var19->unknown_4_>>1);
 void* var21;
 if(var19->unknown_4_&1) var21=*(void**)((char*)*(void**)var20+var19->unknown_0_);else var21=(void*)var19->unknown_0_;
 ((void(*)(void*))var21)(var20);
 return 0;
}
