#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "std_library_functions.h"
struct Struct_ov000_021537b8_5 {char p[0x22];unsigned short lo:12,mode:2,hi:2;char q[0x12];short skill;char r[3];unsigned char flags;};
struct GameObject {char p[0x138];Struct_ov000_021537b8_5* stats;
#if defined(jpn)
char q[8];
#else
char q[20];
#endif
unsigned char* actor;};
class GameState {public:static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
struct ActionEntry {char p[0x1c];short unknown_1c_,pad;unsigned short id;char q[0xe];int tail;};
struct Struct_ov000_0215767c_9 {char p[0xe];short id;char q[7];unsigned char active;char r[0xc];};
struct Struct_ov000_0215767c_10 {unsigned short action;char p[7];unsigned char unknown_9_;char q;unsigned char flag:1,other:7;char r[4];ActionEntry* entry;char s[0x14];};
struct Struct_ov000_0215767c_2 {char p[0x8e00];unsigned char tableCount;char q[0x17];char* unknown_8e18_;char r[0x58];Struct_ov000_0215767c_9* targets;char s[8];unsigned char unknown_8e80_,unknown_8e81_;char t[0x14];unsigned char mode;};
struct Struct_ov000_0215767c {char p[0x18];unsigned int low:5,type:7,high:20;char q[0x14];short linked;};
struct Struct_ov000_02182ae4 {short v[8];};struct Party {short v[4];};struct Struct_ov000_0215767c_3 {char buf[0x678];};
extern "C" GameObject* func_0200ff1c(GameState*,int);extern "C" GameObject* func_0200fea4(GameState*,int);
extern "C" int func_ov000_02159c58(void*,int);extern "C" int func_0208555c(unsigned char*);struct Random;int NextRandomMax(Random*,int);
struct Struct_02088418;extern "C" int func_02088418(Struct_02088418*,int,int);extern "C" int func_ov000_02157cc4(GameObject*);extern "C" void func_02088474(void*,int,int);
extern "C" int func_ov000_02159d94(void*, int);extern "C" void func_0208a910(int*);struct Struct_02070b6c_3;extern "C" void* func_02070fd0(Struct_02070b6c_3*,int);
struct Struct_0204887c;extern "C" void func_0204887c(Struct_0204887c*,char*);extern "C" Struct_ov000_0215767c* func_02079e2c(char*,int);
extern "C" void func_ov000_02157cdc(void*);extern "C" void* func_ov000_0215e918(void*);extern "C" void func_02089758(unsigned char*);
extern "C" int func_ov000_02156050(GameObject*);extern "C" int func_ov000_021543f4(GameObject*);
struct Struct_ov000_0215767c_5;struct Struct_ov000_0215767c_4;extern "C" void func_ov000_021600cc(Struct_ov000_0215767c_5*,Struct_ov000_0215767c_4*);
struct Struct_ov000_0215767c_7;struct Struct_ov000_0215767c_6;extern "C" void func_ov000_02160068(Struct_ov000_0215767c_7*,Struct_ov000_0215767c_6*);
extern "C" {
extern const Struct_ov000_02182ae4 data_ov000_02182c54,data_ov000_02182c64;extern const Party data_ov000_02182a74;
int func_ov000_0215e9fc(void*,short*,int,int);int func_ov000_02159cb4(void*,int);int func_ov000_02155f9c(void*,int,int);
void func_ov024_021f73b8(Struct_ov000_0215767c_3*);void func_ov024_021f8f20(Struct_ov000_0215767c_3*,void*,int,Struct_ov000_0215767c_10*);
int func_ov000_0215704c(void*,int);int func_0208a91c(int*,void*,int,int*,short*);
int func_ov000_0215833c(void*,int,Struct_ov000_0215767c_10*);int func_ov000_0215f67c(void*,int);
}
inline int inline_ov000_021537b8(int id){return (id>=0&&id<=3)?1:0;}
// USA: func_ov000_0215767c
extern "C" ARM void func_ov000_0215767c(Struct_ov000_0215767c_2* self,Struct_ov000_0215767c_10* src,Struct_ov000_0215767c_10* dst){
 GameState* gs=GameState::GetInstance();ActionDataTables* data = func_020797dc();int id=(short)src->entry->id;GameObject* unit=GameState::GetInstance()->GetCombatantByIndex(id);if(!unit)return;
 Struct_ov000_02182ae4 ids(data_ov000_02182c54);signed char count=0;bool special=false;bool var7=false;self->mode=0;
 if(inline_ov000_021537b8(id)){
  if(func_ov000_02159c58(self,src->action)){
   ids.v[count++]=id;Party party(data_ov000_02182a74);int total=func_ov000_0215e9fc(self,party.v,4,1);
   if(total!=4)src->action=func_ov000_02159cb4(self,id);
   else {var7=true;for(int i=0;i<total;i++){int next=party.v[i];if(ids.v[0]!=next)ids.v[count++]=next;}}
  }else{
   ids.v[count++]=id;GameObject* member=func_0200ff1c(gs,id);int handled=0;
   if(member&&func_0208555c(member->actor)&&!func_ov000_02155f9c(self,id,0)&&!NextRandomMax((Random*)self,4)&&func_02088418((Struct_02088418*)member->stats,9,0)){
    self->mode=func_ov000_02157cc4(member);func_02088474(member->stats,9,0);handled=1;
   }
   if(!handled&&src->action!=0x1f6){Struct_ov000_0215767c_3 big;func_ov024_021f73b8(&big);func_ov024_021f8f20(&big,self,id,src);}
  }
 }else{
  ids.v[count++]=id;GameObject* enemy=func_0200fea4(GameState::GetInstance(),id);int kind=func_ov000_02159d94(self, id);int var17=1;
  if(func_ov000_0215704c(self,id))special=true;
  else if(src->action==0x1f7&&!func_ov000_02155f9c(self,id,1))var17=0;
  else if(kind==2)var17=0;
  if(!var17){
   Struct_ov000_02182ae4 targets(data_ov000_02182c64);int num=0;int work;func_0208a910(&work);
   src->action=func_0208a91c(&work,self,(unsigned short)id,&num,targets.v);Struct_ov000_0215767c* skill=func_02079e2c((char*)data,(short)src->action);
   if(skill){while(skill->type==0x22){void* entry=func_02070fd0((Struct_02070b6c_3*)(self->unknown_8e18_+0x684),skill->linked);if(entry){func_0204887c((Struct_0204887c*)enemy,(char*)entry);enemy->stats->skill=skill->linked;}
    memset(targets.v,-1,16);num=0;src->action=func_0208a91c(&work,self,(unsigned short)id,&num,targets.v);skill=func_02079e2c((char*)data,(short)src->action);if(!skill)break;
   }}
   src->unknown_9_=0;for(int i=0;i<num;i++){Struct_ov000_0215767c_9* target=&self->targets[self->unknown_8e81_];func_ov000_02157cdc(target);target->id=targets.v[i];target->active=1;func_ov000_021600cc((Struct_ov000_0215767c_5*)src,(Struct_ov000_0215767c_4*)target);self->unknown_8e81_++;}
  }
 }
 for(signed char i=0;i<count;i++){
  ActionEntry* entry=(ActionEntry*)func_ov000_0215e918(self);if(!entry)break;memset(entry,0,0x30);entry->unknown_1c_=-1;entry->tail=0;int current=ids.v[i];int handled=0;entry->id=current;
  if(!var7)handled=func_ov000_0215833c(self,current,src);
  GameObject* other=GameState::GetInstance()->GetCombatantByIndex(current);if(other)func_02089758((unsigned char*)other->stats);
  if(!handled){
   if(func_ov000_02155f9c(self,current,0)){src->action=0x1f7;src->unknown_9_=0;if(func_ov000_02156050(unit))unit->stats->flags|=2;}
   else if(special){src->action=0x1f7;src->unknown_9_=0;if((unsigned char)unit->stats->mode==1){self->mode=func_ov000_02157cc4(unit);func_02088474(unit->stats,10,0);unit->stats->flags|=2;}}
   else if(func_ov000_021543f4(unit)){src->action=func_ov000_0215f67c(self,current);src->unknown_9_=0;}
  }
  func_ov000_02160068((Struct_ov000_0215767c_7*)dst,(Struct_ov000_0215767c_6*)entry);self->tableCount++;
 }
 dst->action=src->action;dst->flag=src->flag;
}
