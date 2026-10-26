#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "std_library_functions.h"
struct GameObject {char p[0x138];void* stats;
#if defined(jpn)
char q[8];
#else
char q[20];
#endif
unsigned char* actor;};
class GameState {public:static GameState* GetInstance();};
struct Struct_ov000_021537b8_4 {char p[8];unsigned int unknown_8_0_:8,unknown_9_0_:2,unknown_9_2_:22;char q[8];unsigned int unknown_14_0_:28,mode:4;unsigned int unknown_18_0_:5,type:7,rest18:20;unsigned int unknown_1c_0_:14,unknown_1d_6_:5,unknown_1e_3_:13;};
extern "C" Struct_ov000_021537b8_4* func_02079e2c(char*,int);extern "C" GameObject* func_0200ff1c(GameState*,int);extern "C" int func_ov000_021543f4(GameObject*);
struct Struct_ov000_021540fc {unsigned short action;unsigned char target,group;};struct Struct_02053dc0;extern "C" Struct_ov000_021540fc* func_02053dc0(Struct_02053dc0*);
extern "C" int func_02083b00(unsigned char*,int);extern "C" void func_ov000_02153cc0(int,int,int*);
struct Random;extern "C" int func_ov000_0215fbe0(Random*,int);int NextRandomMax(Random*,int);
struct Struct_ov000_021540fc_2 {unsigned int first:1,second:1,rest:30;};struct Struct_ov000_02182ae4 {short v[8];};
extern "C" {extern const Struct_ov000_02182ae4 data_ov000_02182b74;int func_ov000_02153f98(void*,int,int,short*);void func_ov000_02153aa4(void*,int,int*);void func_ov000_02153c24(void*,int*);int func_ov000_02153e78(void*,short*,int,int,int);int func_ov000_0215eb1c(void*,short*,int,int);int func_ov000_0215e9fc(void*,short*,int,int);}
// USA: func_ov000_021540fc
extern "C" ARM int func_ov000_021540fc(Random* self,int id,int action,short* output){
 GameState* gs=GameState::GetInstance();Struct_ov000_021537b8_4* skill=func_02079e2c((char*)func_020797dc(),(short)action);if(!skill)return 0;
 GameObject* unit=func_0200ff1c(gs,id);if(!unit)return 0;
 if(func_ov000_021543f4(unit))return func_ov000_02153f98(self,id,action,output);
 Struct_ov000_021540fc* info=func_02053dc0((Struct_02053dc0*)unit);if(!info)return 0;
 int count=0;int var5=skill->unknown_9_0_;int mode=skill->mode;
 if(mode==6){if(func_02083b00(unit->actor,0xe6))mode=3;else mode=2;}
 if(mode==5){Struct_ov000_021540fc_2* bits=(Struct_ov000_021540fc_2*)(unit->actor+0x2f4);if(!bits)return 0;if(bits->second)mode=3;else if(bits->first)mode=4;else mode=2;}
 if(mode==1){output[count++]=id;}
 else if(var5==1){
  if(mode==2){int target=info->target;func_ov000_02153aa4(self,info->group,&target);output[count++]=target;}
  else if(mode==4){int group=info->group;func_ov000_02153c24(self,&group);count=func_ov000_02153e78(self,output,8,group,1);}
  else if(mode==3)count=func_ov000_0215eb1c(self,output,8,1);
 }else if(var5==2){
  if(mode==2||mode==7||mode==8){int target=info->target;if(skill->type!=0x12)func_ov000_02153cc0((int)self,id,&target);output[count++]=target;}
  else if(mode==3||mode==4){if(skill->type!=0x21)count=func_ov000_0215e9fc(self,output,8,1);else count=func_ov000_0215e9fc(self,output,8,0);}
 }
 Struct_ov000_02182ae4 selected(data_ov000_02182b74);short* ptr=selected.v;int repeat=func_ov000_0215fbe0(self,(signed char)skill->unknown_1d_6_);
 if(repeat>0){for(int i=0;i<repeat;i++){ptr[i]=output[NextRandomMax(self,count)];}memset(output,0,count*2);memcpy(output,selected.v,repeat*2);count=repeat;}
 return count;
}
