#include <globaldefs.h>
#include "GameState/GameState.h"
#if defined(jpn)
enum { Enum_ov003_02154720_76=0x48 };
#else
enum { Enum_ov003_02154720_76=0x4c };
#endif
struct Struct_02000c9c_81 { unsigned int unknown_0_; unsigned short unknown_4_,unknown_6_,unknown_8_,unknown_a_; unsigned char unknown_c_,unknown_d_,unknown_e_[2]; };
struct Struct_ov003_02154720 { char unknown_0_[0xf78]; unsigned char unknown_f78_[4],unknown_f7c_; };
struct Struct_ov003_02154720_2 {
 void* unknown_0_;void* unknown_4_;void* unknown_8_;void* unknown_c_;void* unknown_10_;void* unknown_14_;void* unknown_18_;void* unknown_1c_;void* unknown_20_;void* unknown_24_;void* unknown_28_;
 char unknown_2c_[0x54];char unknown_80_[0xc];char unknown_8c_[4];char unknown_90_[0x54];char unknown_e4_[0x18];char unknown_fc_[0x18];char unknown_114_[Enum_ov003_02154720_76];
 char unknown_160_[0x10];unsigned char unknown_170_,unknown_171_;char unknown_172_[2];unsigned int unknown_174_;
 char unknown_178_[0x18];Struct_02000c9c_81 unknown_190_[4];int unknown_1d0_,unknown_1d4_,unknown_1d8_;unsigned int unknown_1dc_;
 short unknown_1e0_,unknown_1e2_,unknown_1e4_,unknown_1e6_,unknown_1e8_,unknown_1ea_,unknown_1ec_,unknown_1ee_,unknown_1f0_;
 unsigned char unknown_1f2_[4],unknown_1f6_,unknown_1f7_,unknown_1f8_,unknown_1f9_,unknown_1fa_,unknown_1fb_;unsigned int unknown_1fc_;int unknown_200_,unknown_204_;
 char unknown_208_[0x330-0x208];int unknown_330_,unknown_334_;unsigned char unknown_338_,unknown_339_,unknown_33a_;
};
extern "C" void func_02074af4(void*);
void SpriteContext_Init(char*);
struct Obj02081ee4;
struct Sub02081ee4;
void InitWithSub02081ee4(Obj02081ee4*, Sub02081ee4*);
void ResourceScriptEntry_Init(void*);
struct Struct020dfc40;
void KeyTable_Reset(Struct020dfc40*);
void ClearFields_021e20c0(void*);
void ItemTable_Init(void*);
unsigned int GameState_GetProtagonistIndex(GameState*);
extern "C" void* memset(void*,int,unsigned int);
extern "C" unsigned int func_020114ec(char*, void*);
extern "C" void func_ov003_0215873c(void*);
// USA: func_ov003_02154720
extern "C" ARM void func_ov003_02154720(void* arg0,unsigned char arg1) {
 unsigned char var0=arg1;
 Struct_ov003_02154720_2* var1=(Struct_ov003_02154720_2*)arg0;
 Struct_ov003_02154720* var2;
 unsigned char var3;
 int var4;
 GameState* var5;
 int var6;
 var1->unknown_170_=0;var1->unknown_171_=0;func_02074af4(var1->unknown_160_);
 var1->unknown_174_=(*(volatile unsigned int*)0x04000000&0x1f00)>>8;
 *(volatile unsigned int*)0x04000000=(*(volatile unsigned int*)0x04000000&~0x1f00)|0x100;
 gs=GameState::GetInstance();
 party=(Party02154720*)GameState_GetParty(gs);
 self->p0=0;self->p4=0;self->pc=0;self->p8=0;self->p10=0;self->p14=0;self->p18=0;self->p20=0;self->p24=0;self->p28=0;
 SpriteContext_Init((char*)self->init2c);
 InitWithSub02081ee4((Obj02081ee4*)self->selector, (Sub02081ee4*)self->sub);
 ResourceScriptEntry_Init(self->clear90);
 KeyTable_Reset((Struct020dfc40*)self->resetE4);
 KeyTable_Reset((Struct020dfc40*)self->resetFc);
 ClearFields_021e20c0(self->clear114);
 ItemTable_Init(self->zero178);
 self->task=-1;self->field1d4=0;self->changed=0;self->scale=0;
 self->field1e0=-1;self->field1e2=-1;self->field1e4=-1;self->element=-1;self->previous=-1;self->field1ea=-1;self->field1ee=-1;self->pending=self->field1ee;self->field1f0=-1;
 self->current=GameState_GetProtagonistIndex(gs);
 self->state=0;self->flag1f9=0;self->flag1fa=0;self->multiplayer=0;self->flags=0;self->field200=0;self->skip=0;
 self->field330=0;self->field334=0;self->blocked=0;self->reset=0;self->started=0;
 for(init=0;init<4;init++) { self->ids[init]=0;memset(&self->cache[init],0,4); }
 self->count=CopyOutRegion0x571d_020114ec((char*)gs, self->ids);
 Party02154720* currentParty=(Party02154720*)GameState_GetParty(gs);
 count=self->count;
 for(int i=0;i<count;i++) {
  int id;
  bool found=false;
  id=(signed char)self->ids[i];
  for(int j=0;j<currentParty->count;j++) if(id==currentParty->ids[j]) found=true;
  if(!found) { self->ids[i]=0xff;self->count--; }
 }
 for(var4=0;var4<var3-1;var4++) {
  if(var1->unknown_1f2_[var4]==0xff) for(int var12=var4+1;var12<var3;var12++) if(var1->unknown_1f2_[var12]!=0xff) {var1->unknown_1f2_[var4]=var1->unknown_1f2_[var12];var1->unknown_1f2_[var12]=0xff;break;}
 }
 func_ov003_0215873c(var1);
 if(var0) var1->unknown_1fc_|=1;
 var1->unknown_1fb_=var2->unknown_f7c_!=1;
}
