#include <globaldefs.h>
struct Struct_ov000_021573a8_2 { unsigned short first,current,unknown_4_,unknown_6_; char p[0x41];unsigned char unknown_49_; };
struct Struct_ov000_021573a8 { char p[0x10];unsigned int a:19,enabled:1,b:12; };
struct GameObject { char p[0x138];Struct_ov000_021573a8_2* detail;char q[0xc];Struct_ov000_021573a8* extra; unsigned int Current()const{return detail->current;} unsigned int inline_ov000_021573a8_2()const{return detail->unknown_6_;} };
class GameState {public:static GameState* GetInstance();GameObject* GetCombatantByIndex(int);};
extern "C" GameObject* func_0200ff1c(GameState*,int);extern "C" GameObject* func_0200fea4(GameState*,int);
struct Struct_02085c80 {char p[0x29c];unsigned int a:4,mode:5,b:23;char q[0xc];short enabled;};
extern "C" unsigned char* func_02053c6c(unsigned char*);
extern "C" float func_02084fc8(char*);extern "C" int func_02085c80(Struct_02085c80*);
struct Random;int NextRandomMax(Random*,int);float NextRandomFloatBetween(Random*,float,float);
#define IsParty(n) ((n)>=0&&(n)<=3?1:0)
// USA: func_ov000_021573a8
extern "C" ARM int func_ov000_021573a8(Random* self,int id,int other,int amount){
 if(amount<=0)return 0;
 GameState* gs=GameState::GetInstance();
 GameObject* target=GameState::GetInstance()->GetCombatantByIndex(other);
 if(!target)return 0;
 float result;
 if(IsParty(id)) {
  GameObject* unit=func_0200ff1c(gs,id);if(!unit)return 0;
  Struct_02085c80* actor=(Struct_02085c80*)func_02053c6c((unsigned char*)unit);if(!actor)return 0;
  if(actor->enabled<=0)return 0;if(actor->mode!=3)return 0;
  {unsigned int maximum=unit->inline_ov000_021573a8_2();unsigned int current=unit->Current();if(current>=maximum)return 0;}
  float var7=(float)(int)target->detail->unknown_49_;if(var7<=0)return 0;
  var7/=100.0f;
  float bonus=func_02084fc8((char*)actor);
  float bits=(float)func_02085c80(actor);
  float scale=(bonus+bits)/100.0f;
  float var11=(float)amount*scale;
  int var12=NextRandomMax(self,2);
  float var13=NextRandomFloatBetween(self,0,var11);
  result=1.0f+(float)var12;
  result+=var7*var13;
  if(bonus+bits<result)result=bonus+bits;
  unsigned int current=target->detail->current;if((float)current<result)result=(float)current;
 }else {
  GameObject* unit=func_0200fea4(GameState::GetInstance(),id);if(!unit)return 0;
  if(!unit->extra)return 0;if(!unit->extra->enabled)return 0;
  if(unit->detail->current<0xff&&unit->detail->current>=unit->detail->unknown_6_)return 0;
  int var16=NextRandomMax(self,2);
  result=0.1f*(float)amount;
  result+=1.0f+(float)var16;
  unsigned int current=target->detail->current;if((float)current<result)result=(float)current;
 }
 return (int)result;
}
