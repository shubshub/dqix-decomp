#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "std_library_functions.h"
struct Struct_ov000_021537b8_5 { char p[0x2e]; short id; };
struct GameObject { char p[0x138]; Struct_ov000_021537b8_5* stats; char q[0x17c - 0x13c]; unsigned char group; char r[2]; unsigned char linked; unsigned char unknown_180_; };
class GameState {public: static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
struct S_10088;extern "C" int func_02010088(S_10088*);
extern "C" int func_ov000_02153c0c(GameObject*);
extern "C" GameObject* func_0200fea4(GameState*,int);
extern "C" int func_ov000_0215fc60(char*);
struct Struct_ov000_021537b8_4 {char p[8];unsigned int unknown_8_0_:8,unknown_9_0_:2,unknown_9_2_:22;char q[8];unsigned int unknown_14_0_:28,mode:4;unsigned int unknown_18_0_:5,type:7,rest18:20;unsigned int unknown_1c_0_:14,unknown_1d_6_:5,unknown_1e_3_:13;};
extern "C" Struct_ov000_021537b8_4* func_02079e2c(char*,int);extern "C" int func_ov000_02159d94(void*, int);
struct Random;extern "C" int func_ov000_0215fbe0(Random*,int);int NextRandomMax(Random*,int);
struct Entry { char p[0x20]; short id; };
struct Struct_ov000_0215440c_3 { short id; char p[7]; unsigned char count; char q[6]; Entry* entry; };
struct Struct_ov000_0215440c_2;struct Struct_ov000_0215440c_4 { char p[0x20]; unsigned short id; };extern "C" Struct_ov000_0215440c_4* func_ov000_02160094(Struct_ov000_0215440c_2*,int);
struct Struct_ov000_0215440c;struct Struct_ov000_0215440c_5 { char p[0xe]; short id; };extern "C" Struct_ov000_0215440c_5* func_ov000_021600f8(Struct_ov000_0215440c*,int);
struct Struct_ov000_0215440c_6 { unsigned char pad0; unsigned char flags:4,count:2,pad1:2; char pad2[4]; unsigned char ids[8]; unsigned char memberCount:4,weight:4; char unknown_f_[0x18-0xf]; };
struct Struct_ov000_02182ae4 { short v[8]; };
extern "C" {extern const Struct_ov000_02182ae4 data_ov000_02182c84;extern const Struct_ov000_02182ae4 data_ov000_02182b64;extern const Struct_ov000_02182ae4 data_ov000_02182ae4;
int func_ov000_02153e78(Random*,short*,int,int,int);int func_ov000_0215eb1c(Random*,short*,int,int);int func_ov000_0215e9fc(Random*,short*,int,int);int func_ov000_02154a04(Random*,int,int,short*);}
inline int inline_ov000_0215440c(Entry* e){return e->id;}
inline int inline_ov000_0215440c(Struct_ov000_021537b8_5* s){return s->id;}
inline int inline_ov000_0215440c(Struct_ov000_0215440c_5* n){return n->id;}
inline int inline_ov000_0215440c(Struct_ov000_02182ae4* ids,int i){return ids->v[i];}
inline GameObject* inline_ov000_0215440c_2(int id){return func_0200fea4(GameState::GetInstance(),id);}
inline GameObject* inline_ov000_021537b8_2(int id){return GameState::GetInstance()->GetCombatantByIndex(id);}
// USA: func_ov000_0215440c
extern "C" ARM int func_ov000_0215440c(Random* self,Struct_ov000_0215440c_3* action,short* output){
 ActionDataTables* tables = func_020797dc();
 if(func_ov000_0215fc60((char*)self)){
  Struct_ov000_0215440c_4* var1=func_ov000_02160094((Struct_ov000_0215440c_2*)action,0);
  if(var1){int party=(var1->id>=0xc0&&var1->id<=0xc7)?1:0;if(party){output[0]=0;return 1;}}
 }
 Struct_ov000_021537b8_4* skill=func_02079e2c((char*)tables,action->id);if(!skill)return 0;
 int count=0;
 GameObject* unit=inline_ov000_0215440c_2(inline_ov000_0215440c(action->entry));if(!unit)return count;
 int done=0;
 if(func_ov000_02159d94(self, inline_ov000_0215440c(action->entry))!=2){
  if(unit->linked){
   if((skill->mode==2||skill->mode==5)&&skill->unknown_9_0_==1){
    GameObject* partner=inline_ov000_021537b8_2(inline_ov000_0215440c(unit->stats));
    if(partner&&!func_02010088((S_10088*)partner)&&!func_ov000_02153c0c(partner)){output[0]=inline_ov000_0215440c(unit->stats);count++;done=1;}
   }
  }else if(unit->unknown_180_)done=1;
 }
 if(!done){
  if(skill->mode==4||skill->mode==3){
   Struct_ov000_02182ae4 ids=data_ov000_02182c84;short* p=ids.v;int group=unit->group;short n=0;
   if(skill->unknown_9_0_==2){
    if(action->count){
     Struct_ov000_0215440c_5* node=func_ov000_021600f8((Struct_ov000_0215440c*)action,0);
     if(node){GameObject* target=inline_ov000_0215440c_2(inline_ov000_0215440c(node));if(target)group=target->group;}
    }
    if(skill->mode==4)n=func_ov000_02153e78(self,ids.v,8,group,0);
    else if(skill->mode==3)n=func_ov000_0215eb1c(self,ids.v,8,0);
   }else if(skill->unknown_9_0_==1){
    n=func_ov000_0215e9fc(self,p,8,0);
   }
   if(skill->type==0x21){
    Struct_ov000_0215440c_6* groups=(Struct_ov000_0215440c_6*)((char*)self+0x81b0);int weight=0;int var16=0;
    for(int i=0;i<groups->count;i++){weight+=groups[i].weight;Struct_ov000_02182ae4 buf=data_ov000_02182b64;var16+=func_ov000_02153e78(self,buf.v,8,i,0);}
    if(weight>=5){memcpy(output,&ids,sizeof(ids));return n;}
    if(var16>5)var16=5;
    count=0;int var19=var16-weight;
    for(int i=0;i<groups->count;i++){
     for(int j=0;j<groups[i].memberCount;j++){
      int id=groups[i].ids[j]+0xc0;
      GameObject* c=GameState::GetInstance()->GetCombatantByIndex((short)id);
      if(!c)continue;
      if(func_ov000_02153c0c(c))continue;
      if(func_02010088((S_10088*)c)){if(var19>0){output[count]=id;count++;var19--;}}
      else{output[count]=id;count++;}
      if(count>=5)break;
     }
    }
   }else{
    for(long i=0;i<n;i++){
     short cid=p[i];
     GameState* gs=GameState::GetInstance();
     GameObject* c=gs->GetCombatantByIndex(cid);
     if(skill->type==0x12||skill->type==0x21||(!func_02010088((S_10088*)c)&&!func_ov000_02153c0c(c))){output[count]=p[i];count++;}
    }
   }
  }else{
   for(int i=0;i<action->count;i++){
    Struct_ov000_0215440c_5* node=func_ov000_021600f8((Struct_ov000_0215440c*)action,i);
    GameObject* c=inline_ov000_021537b8_2(inline_ov000_0215440c(node));
    if(!c)continue;
    if(skill->type==0x12||skill->type==0x21||(!func_02010088((S_10088*)c)&&!func_ov000_02153c0c(c))){output[count]=inline_ov000_0215440c(node);count++;}
   }
  }
 }
 if(count>0){
  Struct_ov000_02182ae4 selected=data_ov000_02182ae4;short* ptr=selected.v;
  int repeat=func_ov000_0215fbe0(self,(signed char)skill->unknown_1d_6_);
  if(repeat>0){for(int i=0;i<repeat;i++){ptr[i]=output[NextRandomMax(self,count)];}memset(output,0,count*2);memcpy(output,selected.v,repeat*2);count=repeat;}
  return count;
 }
 return func_ov000_02154a04(self,(unsigned short)inline_ov000_0215440c(action->entry),(unsigned short)action->id,output);
}
