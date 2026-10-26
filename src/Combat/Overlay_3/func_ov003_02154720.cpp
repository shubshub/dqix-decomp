#include <globaldefs.h>
#include "GameState/GameState.h"
#if defined(jpn)
enum { Enum_ov003_02154720_76=0x48 };
#else
enum { Enum_ov003_02154720_76=0x4c };
#endif
struct Struct_02000c9c_81 { unsigned int flags; unsigned short hp,maxHP,mp,maxMP; unsigned char table,vocation,pad[2]; };
struct Party02154720 { char pad[0xf78]; unsigned char ids[4],count; };
struct Struct_ov003_02154720_2 {
 void* p0;void* p4;void* p8;void* pc;void* p10;void* unknown_14_;void* unknown_18_;void* unknown_1c_;void* unknown_20_;void* unknown_24_;void* unknown_28_;
 char init2c[0x54];char selector[0xc];char sub[4];char clear90[0x54];char resetE4[0x18];char resetFc[0x18];char unknown_114_[Enum_ov003_02154720_76];
 char controller[0x10];unsigned char unknown_170_,unknown_171_;char unknown_172_[2];unsigned int display;
 char zero178[0x18];Struct_02000c9c_81 cache[4];int task,unknown_1d4_,changed;unsigned int scale;
 short unknown_1e0_,unknown_1e2_,unknown_1e4_,element,previous,unknown_1ea_,pending,unknown_1ee_,unknown_1f0_;
 unsigned char ids[4],count,current,state,unknown_1f9_,unknown_1fa_,unknown_1fb_;unsigned int flags;int unknown_200_,unknown_204_;
 char unknown_208_[0x330-0x208];int unknown_330_,unknown_334_;unsigned char blocked,reset,started;
};
extern "C" void func_02074af4(void*);
extern "C" void SpriteContext_Init(char*);
struct Struct_02081ee4;
struct Struct_02081ee4_2;
extern "C" void func_02081ee4(Struct_02081ee4*, Struct_02081ee4_2*);
extern "C" void ResourceScriptEntry_Init(void*);
struct Struct020dfc40;
extern "C" void KeyTable_Reset(Struct020dfc40*);
extern "C" void func_ov023_021e20c0(void*);
extern "C" void ItemTable_Init(void*);
extern "C" unsigned int GameState_GetProtagonistIndex(GameState*);
extern "C" void* memset(void*,int,unsigned int);
extern "C" unsigned int GameState_GetPartyOrder(char*, void*);
extern "C" void func_ov003_0215873c(void*);
// USA: func_ov003_02154720
extern "C" ARM void func_ov003_02154720(void* memory,unsigned char arg1) {
 unsigned char flag=arg1;
 Struct_ov003_02154720_2* self=(Struct_ov003_02154720_2*)memory;
 Party02154720* party;
 unsigned char count;
 int k;
 GameState* gs;
 int var6;
 self->unknown_170_=0;self->unknown_171_=0;func_02074af4(self->controller);
 self->display=(*(volatile unsigned int*)0x04000000&0x1f00)>>8;
 *(volatile unsigned int*)0x04000000=(*(volatile unsigned int*)0x04000000&~0x1f00)|0x100;
 gs=GameState::GetInstance();
 party=(Party02154720*)GameState_GetParty(gs);
 self->p0=0;self->p4=0;self->pc=0;self->p8=0;self->p10=0;self->unknown_14_=0;self->unknown_18_=0;self->unknown_20_=0;self->unknown_24_=0;self->unknown_28_=0;
 SpriteContext_Init((char*)self->init2c);
 func_02081ee4((Struct_02081ee4*)self->selector, (Struct_02081ee4_2*)self->sub);
 ResourceScriptEntry_Init(self->clear90);
 KeyTable_Reset((Struct020dfc40*)self->resetE4);
 KeyTable_Reset((Struct020dfc40*)self->resetFc);
 func_ov023_021e20c0(self->unknown_114_);
 ItemTable_Init(self->zero178);
 self->task=-1;self->unknown_1d4_=0;self->changed=0;self->scale=0;
 self->unknown_1e0_=-1;self->unknown_1e2_=-1;self->unknown_1e4_=-1;self->element=-1;self->previous=-1;self->unknown_1ea_=-1;self->unknown_1ee_=-1;self->pending=self->unknown_1ee_;self->unknown_1f0_=-1;
 self->current=GameState_GetProtagonistIndex(gs);
 self->state=0;self->unknown_1f9_=0;self->unknown_1fa_=0;self->unknown_1fb_=0;self->flags=0;self->unknown_200_=0;self->unknown_204_=0;
 self->unknown_330_=0;self->unknown_334_=0;self->blocked=0;self->reset=0;self->started=0;
 for(var6=0;var6<4;var6++) { self->ids[var6]=0;memset(&self->cache[var6],0,4); }
 self->count=GameState_GetPartyOrder((char*)gs, self->ids);
 Party02154720* currentParty=(Party02154720*)GameState_GetParty(gs);
 count=self->count;
 for(int i=0;i<count;i++) {
  int id;
  bool found=false;
  id=(signed char)self->ids[i];
  for(int j=0;j<currentParty->count;j++) if(id==currentParty->ids[j]) found=true;
  if(!found) { self->ids[i]=0xff;self->count--; }
 }
 for(k=0;k<count-1;k++) {
  if(self->ids[k]==0xff) for(int j=k+1;j<count;j++) if(self->ids[j]!=0xff) {self->ids[k]=self->ids[j];self->ids[j]=0xff;break;}
 }
 func_ov003_0215873c(self);
 if(flag) self->flags|=1;
 self->unknown_1fb_=party->count!=1;
}
