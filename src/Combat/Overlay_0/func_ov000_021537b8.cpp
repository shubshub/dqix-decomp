#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
struct Struct_ov000_021537b8_5 {unsigned short hp,mp;char p[0x1d];unsigned char state;char q[0x1a];unsigned char flags;};
struct GameObject {char p[0xc1];unsigned char low:4,state:4;char q[0x76];Struct_ov000_021537b8_5* stats;
#if defined(jpn)
char r[8];
#else
char r[20];
#endif
unsigned char* actor;};
class GameState {public:static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
extern "C" GameObject* func_0200ff1c(GameState*,int);extern "C" int func_ov000_02153a8c(GameObject*);extern "C" int func_ov000_0215fc60(char*);
struct Struct_ov000_021537b8_4 {char p[8];unsigned int unknown_8_0_:8,unknown_9_0_:24;unsigned int c,flags;char q[4];unsigned int low:12,type:4,high:16;};
extern "C" Struct_ov000_021537b8_4* func_02079e2c(char*,int);extern "C" int func_02083b00(unsigned char*,int);extern "C" unsigned int func_020dd290(void*,unsigned int);extern "C" void func_ov000_0215a124(void*,int,int);extern "C" void* func_ov000_02160130();extern "C" void* func_ov000_02160f08(void*);
struct Obj02176150;extern "C" void func_ov000_02176150(Obj02176150*,unsigned short);extern "C" void func_02088db8(unsigned char*);struct Bytes02033b88;extern "C" void GameObject_ForceMotionState(Bytes02033b88*,int);
struct Struct_ov000_021537b8 {unsigned short action,previous;char p[5];unsigned char count;};
struct Struct_ov000_021537b8_2 {char p[0xe];short mp;char q[0x3c];int id;
#if defined(jpn)
char r[0x438];
#else
char r[0x3f8];
#endif
};
struct Struct_ov000_021537b8_3 {char p[0x958];Struct_ov000_021537b8_2 slots[4];};
struct Struct_ov000_02182e24 {short action,state,mode;};extern "C" const Struct_ov000_02182e24 data_ov000_02182e24[];
inline int inline_ov000_021537b8(int id){return (id>=0&&id<=3)?1:0;}
inline GameObject* inline_ov000_021537b8_2(int id){GameState* gs=GameState::GetInstance();return gs->GetCombatantByIndex(id);}
// USA: func_ov000_021537b8
extern "C" ARM void func_ov000_021537b8(void* self,int id,Struct_ov000_021537b8* work){
 GameState* gs=GameState::GetInstance();GameObject* unit=inline_ov000_021537b8_2(id);if(!unit)return;if(func_ov000_0215fc60((char*)self))return;
 Struct_ov000_021537b8_4* skill=func_02079e2c((char*)func_020797dc(),(short)work->action);if(!skill)return;
 int var3=1;if(!inline_ov000_021537b8(id)&&unit->stats->mp>=255)var3=0;if(func_ov000_02153a8c(unit))var3=0;
 if(var3){
  int var4=skill->unknown_8_0_;if(inline_ov000_021537b8(id)){GameObject* member=func_0200ff1c(gs,id);if(member&&func_02083b00(member->actor,0x106))var4=func_020dd290(member,var4);}
  int var6=0;if(skill->unknown_8_0_<255){if(unit->stats->mp<var4)var6=1;}else if(unit->stats->mp==0)var6=1;
  if(!var6){
   func_ov000_0215a124(self,id,var4);Struct_ov000_021537b8_3* hud=(Struct_ov000_021537b8_3*)func_ov000_02160f08(func_ov000_02160130());Struct_ov000_021537b8_2* slot;
   if(inline_ov000_021537b8(id)){for(int i=0;i<4;i++){if(hud->slots[i].id==id){slot=&hud->slots[i];goto found;}}}
   slot=0;
found:
   if(slot){int mp=unit->stats->mp;func_ov000_02176150((Obj02176150*)slot,mp);slot->mp=mp;}
  }else{
   unsigned short action=0x1f8;if(skill->type==1)action=0x3a9;work->previous=work->action;work->count=0;work->action=action;
   if(skill->flags&1)unit->stats->flags|=8;else unit->stats->flags|=0x20;return;
  }
 }
 if(work->action==0x1dc){func_02088db8((unsigned char*)unit->stats);unit->state=1;GameObject_ForceMotionState((Bytes02033b88*)unit,0);return;}
 unsigned char state=0;int mode=0;const Struct_ov000_02182e24* row=data_ov000_02182e24;
 while(row->action!=-1){if(row->action==work->action){state=(unsigned char)row->state;mode=(unsigned char)row->mode;break;}row++;}
 unit->stats->state=state;unit->state=(unsigned char)mode;GameObject_ForceMotionState((Bytes02033b88*)unit,0);
}
