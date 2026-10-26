#include <globaldefs.h>
struct Struct_ov000_021537b8_5 {char p[0x10];unsigned int p10:10,first:10,second:10,unknown_13_6_:2;unsigned int flags;};
struct GameObject {char p[0x138];Struct_ov000_021537b8_5* stats;
#if defined(jpn)
char q[8];
#else
char q[20];
#endif
unsigned char* actor;
};
class GameState {public:static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
extern "C" GameObject* func_0200ff1c(GameState*,int);
extern "C" int func_ov000_02156af0(GameObject*);extern "C" int func_ov000_02156b08(GameObject*);extern "C" int func_ov000_02156b20(GameObject*);
extern "C" void func_02088aa8(unsigned char*);extern "C" void func_02088af0(unsigned char*);
extern "C" int func_020851d8(unsigned char*);extern "C" int func_02085204(unsigned char*);
struct Random {char p[0x8e95];unsigned char unknown_8e95_;};int NextRandomMax(Random*,int);float NextRandomFloatBetween(Random*,float,float);
struct Struct_ov000_02156648 {char p[0x1c];unsigned char flags;};
struct Struct_ov000_021537b8 {char p[0xa];unsigned char flags;};
struct Struct_ov000_0215440c_3 {unsigned int zero;unsigned int id:12,minimum:10,maximum:10;unsigned int unknown_8_0_:8,unknown_9_0_:2,unknown_9_2_:22;unsigned int c;unsigned int flags;unsigned int base:7,lower:7,upper:7,unknown_16_5_:11;unsigned int unknown_18_0_:16,mode:2,rest18:9,element:5;};
extern "C" {int func_ov000_02156068(void*,int,int,int);float func_ov000_02156b38(void*,int,int);}
#define IsParty(n) ((n)>=0&&(n)<=3?1:0)
struct Struct_02000c9c_27 {char p[0xe95];unsigned char unknown_e95_;};
inline void inline_ov000_02156648(Random* self,int value){((Struct_02000c9c_27*)((char*)self+0x8000))->unknown_e95_=value;}
// USA: func_ov000_02156648
extern "C" ARM int func_ov000_02156648(Random* self,int attacker,int target,Struct_ov000_02156648* out,Struct_ov000_0215440c_3* action,Struct_ov000_021537b8* work,unsigned char force){
 GameState* gs=GameState::GetInstance();GameObject* unit=GameState::GetInstance()->GetCombatantByIndex(target);
 self->unknown_8e95_=0;
 if(action->id!=0x150){
  if(unit&&func_ov000_02156af0(unit)&&action->unknown_9_0_==1){out->flags|=0x40;return 0;}
  if(unit&&func_ov000_02156b08(unit)&&action->unknown_9_0_==1){out->flags|=0x20;return 0;}
 }
 if((action->flags&0x40)&&unit){
  if(unit->stats->flags&0x100000){work->flags|=8;out->flags|=8;func_02088aa8((unsigned char*)unit->stats);return 0;}
  if(unit->stats->flags&0x200000){work->flags|=0x10;out->flags|=0x10;func_02088af0((unsigned char*)unit->stats);return 0;}
 }
 if(force)return 1;
 if(func_ov000_02156068(self,target,0,1)&&!(action->flags&0x1000000))return 0;
 float var2=100.0f;int roll=NextRandomMax(self,100);
 if(IsParty(attacker)){
  GameObject* actor=func_0200ff1c(gs,attacker);if(!actor)return 0;
  if((action->flags&0x40000)&&func_020851d8(actor->actor))return 1;
  if((action->flags&0x10000)&&func_02085204(actor->actor)){if(NextRandomMax(self,4)==0)return 0;}
 }
 if(action->mode==1){
  if(IsParty(attacker)){
   GameObject* actor=func_0200ff1c(gs,attacker);if(!actor)return 0;
   unsigned int first=(unsigned short)actor->stats->first;unsigned int second=(unsigned short)actor->stats->second;
   unsigned int selected=0;int var9=0;
   if(action->flags&0x4000){selected=first;var9=1;}else if(action->flags&0x8000){selected=second;var9=1;}
   if(var9){
    if(selected<=action->minimum)var2=(float)action->lower;
    else if(selected>=action->maximum)var2=(float)action->upper;
    else {unsigned int lower=action->lower;float position=(float)(selected-action->minimum);float delta=(float)(action->upper-lower);float width=(float)(action->maximum-action->minimum);var2=(float)(lower+(int)(position*(delta/width)));}
   }else{float lower=(float)action->lower;float upper=(float)action->upper;var2=(float)(int)NextRandomFloatBetween(self,lower,upper);}
  }else var2=(float)action->base;
  float var16=func_ov000_02156b38(self,target,action->element);
  if(var16>0.0f){if(work->flags&1)return 1;if(var16<1.0f)inline_ov000_02156648(self,1);if(var2<100.0f)inline_ov000_02156648(self,1);}
  var2=0.5f+var2*var16;
 }
 if(action->flags&8){GameObject* actor=GameState::GetInstance()->GetCombatantByIndex(attacker);if(func_ov000_02156b20(actor)){if(NextRandomMax(self,8)<5)return 0;}}
 return roll<(int)var2;
}
