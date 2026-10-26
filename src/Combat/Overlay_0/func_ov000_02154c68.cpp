#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
struct GameObject { char p[0x17c]; unsigned char group; };
class GameState {public: static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
struct S_10088;extern "C" int func_02010088(S_10088*);
extern "C" int func_ov000_02153c0c(GameObject*);
extern "C" GameObject* func_0200fea4(GameState*,int);

struct Random;int NextRandomMax(Random*,int);
struct Struct_ov000_0215440c_3 { int p[2]; unsigned int p8:8,unknown_9_0_:2,unknown_9_2_:22;int q[2];unsigned int unknown_14_0_:28,type:4;int unknown_18_;unsigned int unknown_1c_0_:14,target:5,unknown_1e_3_:13; };
struct Struct_ov000_02182ae4 { short values[8]; };
extern "C" { extern const Struct_ov000_02182ae4 data_ov000_02182b34;int func_ov000_0215e9fc(Random*,short*,int,int);int func_ov000_02153e78(Random*,short*,int,int,int);int func_ov000_0215eb1c(Random*,short*,int,int); }
#define IsParty(n) ((n)>=0 && (n)<=3 ? 1 : 0)
// USA: func_ov000_02154c68
extern "C" ARM int func_ov000_02154c68(Random* self,int id,Struct_ov000_0215440c_3* action){
 if(!action)return -1;
 GameState* gs=GameState::GetInstance();func_020797dc();
 GameObject* unit=GameState::GetInstance()->GetCombatantByIndex(id);
 if(unit&&!func_02010088((S_10088*)unit)&&!func_ov000_02153c0c(unit))return id;
 switch(action->target){case 3:case 4:case 5:case 7:case 8:case 11:break;default:return id;}
 int var2=action->unknown_9_0_;int type=action->type;int group=0;
 if(!IsParty(id)){unit=func_0200fea4(gs,id);if(!unit)return id;group=unit->group;}
 Struct_ov000_02182ae4 ids(data_ov000_02182b34);int count;
 if(var2==1){
  if(type==4){if(IsParty(id))count=func_ov000_0215e9fc(self,ids.values,8,1);else count=func_ov000_02153e78(self,ids.values,8,group,1);}
  else if(type==3){if(IsParty(id))count=func_ov000_0215e9fc(self,ids.values,8,1);else count=func_ov000_0215eb1c(self,ids.values,8,1);}
  else return id;
 }else if(var2==2){
  if(type==4){if(IsParty(id))count=func_ov000_0215e9fc(self,ids.values,8,1);else count=func_ov000_02153e78(self,ids.values,8,group,1);}
  else if(type==3){if(IsParty(id))count=func_ov000_0215e9fc(self,ids.values,8,1);else count=func_ov000_0215eb1c(self,ids.values,8,1);}
  else return id;
 }else return id;
 if(count>0)id=ids.values[NextRandomMax(self,count)];return id;
}
